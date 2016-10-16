#include "SPI.h"
#include <WiFi.h>
#include <SD.h>
#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출

#define PORT 12604

String SERIAL_NO ="SMARTDOORLOCK_27"; // 도어락 시리얼 넘버 원래는 상수로 저장해야 되는데 일단은 이렇게 해놨다.
char server1[] = "211.239.124.243"; //스프링 웹서버 iP

char ssid[] = "Yoon01";      //  your network SSID (name)
char pass[] = "xodud15*";   // your network password

int status = WL_IDLE_STATUS;
WiFiClient client;
File myFile;

int blueTx=2;   //Tx (보내는핀 설정)
int blueRx=3;   //Rx (받는핀 설정)

SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언

String key_id="";  //NFC를 통해 받을 key_id를 저장할 변수
String DATA=""; // HTTP통신을 통해 임시로 저장하기 위해 선언한 변수

unsigned long lastConnectionTime = 0;            // 서버에 마지막으로 연결한 시간
const unsigned long postingInterval = 1800000; // 30분에 한번씩 리스트 갱신한다.

boolean connected = true;


void setup() {
    Serial.begin(9600);
     mySerial.begin(9600); //블루투스 시리얼 개방
   // 이거 지우면 안됨 , SD카드 안열린다.
    if (!SD.begin(4)) {
      return;
    }

    while (status != WL_CONNECTED) {
      Serial.print(F("Connecting : "));
      Serial.println(ssid);
      status = WiFi.begin(ssid, pass);
      //status = WiFi.begin(ssid);
      delay(1000);
    }                 
    Serial.println(F("Wifi Connected"));
    
}

void loop() {
    unsigned long currentMillis = millis(); 
   // 이 조건문은 OK가 떨어지면 문을 열어준다. -> 다시 서버에 요청해 키 리스트를 SD카드에 최신으로 업데이트 한다.
    if(DATA!=""){       
        if(DATA=="OK"){
           Serial.println(F("\nOpen the Door!!!!!!!!!!!!"));
           KeyListhttpRequest(); // 키 리스트 요청
         }
         else if(DATA=="FAIL"){
             Serial.println(F("\nNot Open the Door~~~~"));
             DATA = "";
         }
         else {
             writeFile();
             DATA = "";
         }
     }
    
      while(mySerial.available()) {  //myString 값이 있다면
          char myChar = (char)mySerial.read();  //mySerial int 값을 char 형식으로 변환
          key_id+=myChar;
          delay(5);   
          Serial.println("input value: "+key_id); //시리얼모니터에 myString값 출력
      }

        if( key_id.length() == 6  && status == WL_CONNECTED){  //연결 상태이면서 key_id 길이가 일치할때
              keyExistHttpRequest(key_id);  // 도어락 키 존재 여부 확인
              key_id = "";
         } else if(key_id.length() == 6 && status != WL_CONNECTED){  // 연결상태가 아니면
              Serial.println(F("\n Not connect WIFI!!!!!!!!!!!! "));
              readFile();  // SD카드에서 JSON을 가져온다.
              
               if(parseJson(DATA,key_id)){
                   Serial.println(F("\nOpen the Door!!!!!!!!!!!! "));
                   DATA = "";
               } else{
                    Serial.println(F("\nNot Open the Door~~~~"));
                   DATA = "";
               }
               key_id="";
         } 
         
          while (client.available()) {
              char c = client.read();
              Serial.write(c); //읽은 내용 볼때, 실제 서비스시에는 메모리 때문이라도 없애는게 좋을 듯
              DATA+=c;
          }

          // 몇 분에 한번씩 리스트를 갱신한다.
          if (millis() - lastConnectionTime > postingInterval) {
               KeyListhttpRequest();
          }
      
}

void keyExistHttpRequest(String key_id) {
   DATA = "";
   client.stop();
    String url = "POST /hw/key/check?serial_no="+SERIAL_NO+"&key_id="+key_id;
   if (client.connect(server1, PORT)) {
    Serial.println(F("\nconnecting..."));
    client.println(url);
    client.println("HTTP/1.1");
    client.println("Connection: close");
    client.println();
   }else {
    Serial.println(F("connection failed"));
    
  }
}

void KeyListhttpRequest() {
     DATA = "";  //OK삭제
     client.stop();
      String url = "POST /hw/key/list?serial_no="+SERIAL_NO;
     if (client.connect(server1, PORT)) {
      Serial.println(F("\nconnecting..."));
      client.println(url);
      client.println("HTTP/1.1");
      client.println("Connection: close");
      client.println();

      lastConnectionTime = millis();
     }else {
      Serial.println(F("connection failed"));
    }
}

void readFile(){
  // re-open the file for reading:
    myFile = SD.open("key_list.txt");
    if (myFile) {
      while (myFile.available()) {
        char c = myFile.read();
        Serial.write(c); 
        DATA += c;
      }
        myFile.close();
    } else {
          Serial.println(F("error opening key_list.txt"));
    }
}


void writeFile(){
   // 새로 갱신하기 위해 전에 있던 파일은 삭제한다.
   if(SD.exists("key_list.txt")){
       SD.remove("key_list.txt");  
    }
    
   // 파일을 만들고 새로 받아온 JSON을 기록한다.
    myFile = SD.open("key_list.txt", FILE_WRITE);
    if (myFile) {
      myFile.println(DATA);
      myFile.close();
      Serial.println(F("\nwrite success."));
    } else {
      Serial.println(F("error opening key_list.txt"));
    }
    DATA = "";
}

// JSON 파서, 주로 인터넷 끊겼을시 파일을 읽어 검사할때 쓰인다.
boolean parseJson(String resultText, String key_id) {
  String jsonString = resultText;
  String key = key_id;
  String temp = "";
  int c = 0; // Index counter while parsing
  int d = -1; // Dimension counter while parsing
  boolean registerValue = false;
  jsonString.trim();
  
  while( c < jsonString.length() ) {
    // Loop
    if( jsonString.charAt(c) == '{' ) {
      c++; // Increase index counter by one
      d++; // Increase dimension by one
    }
    else if( jsonString.charAt(c) == '[' ) {
      c++; // Increase index counter by one
      d++; // Increase dimension by one
    }
    else if( jsonString.charAt(c) == ':' ) {
      c++; // Increase index counter by one 
      registerValue = true;
    }
    else if( jsonString.charAt(c) == '"' ) {
      c++; // Increase index counter by one
      int stringEnd = jsonString.indexOf('"', c );
      String parsedString = jsonString.substring( c, stringEnd );
      c = stringEnd + 1;

      // value값을 찾아내는 조건문
      // 여기다가 key_id 값을 걸면 된다.
      // 헤더로 만들어서 이거 사용하면 파싱 가능하다.
      if( registerValue ) {
        registerValue = false;
        if(temp=="key_id" && parsedString == key){
            temp = "";
            return true;
        }
      } else {
        temp = parsedString; //속성값 저장 key_id 속성의 value가 맞는지 검사하려고 집어넣음
      }
    }
    else if( jsonString.charAt(c) > 47 && jsonString.charAt(c) < 58 ) {      
      if( registerValue ) { registerValue = false; }
    }
    else if( jsonString.indexOf( "true", c ) == c ) {
      c = c + 4;
      if( registerValue ) { registerValue = false; }
    }
    else if( jsonString.indexOf( "false", c ) == c ) {
      c = c + 5;   
      if( registerValue ) { registerValue = false; }
    }
    else if( jsonString.indexOf( "null", c ) == c ) {
      c = c + 4;
      if( registerValue ) { registerValue = false; }
    }
    else if( jsonString.charAt(c) == ',' ) {
      c++;      
      if( registerValue ) { registerValue = false; }
    }    
    else if( jsonString.charAt(c) == '}' ) {
      c++; // Increase index counter by one
      d--; // Decrease dimension by one
    }
    else if( jsonString.charAt(c) == ']' ) {
      c++; // Increase index counter by one
      d--; // Decrease dimension by one
    }
    else {
      c++; // Increase index counter by one
    }    
  }
  return false;
}

