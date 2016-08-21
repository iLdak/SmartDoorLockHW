
#include <SPI.h>
#include <WiFi.h>

char ssid[] = "Yoon01";
char pass[] = "xodud15*";  
      

int status = WL_IDLE_STATUS;
WiFiServer server(80);
WiFiClient client;

void setup() {
  Serial.begin(9600);  
  
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);              
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
  server.begin();                        
  printWifiStatus();                      
}


void loop() {
  client = server.available();  
  if (client) {                            
    String currentLine = "";                
    while (client.connected()) {           
      if (client.available()) {          
        char c = client.read();                             
        currentLine += c;    
        
        if (currentLine.endsWith("POST /H")) {
          httpResponse();
          break;
        }
        if (currentLine.endsWith("POST /L")) {
          httpResponse();
          break;
        }
      }
    }
    client.stop();
  }
}

void printWifiStatus() {
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void httpResponse(){
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/plain");
  client.println();
  client.print("OK");
}

