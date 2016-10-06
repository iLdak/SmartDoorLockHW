/*
ESP8266 library

When you use with UNO board, uncomment the follow line in uartWIFI.h.
#define UNO

When you use with MEGA board, uncomment the follow line in uartWIFI.h.
#define MEGA

Connection:
When you use it with UNO board, the connection should be like these:
ESP8266_TX->D0
ESP8266_RX->D1
ESP8266_CH_PD->3.3V
ESP8266_VCC->3.3V
ESP8266_GND->GND

FTDI_RX->D3      //The baud rate of software serial can't be higher that 19200, so we use software serial as a debug port
FTDI_TX->D2

When you use it with MEGA board, the connection should be like these:
ESP8266_TX->RX1(D19)
ESP8266_RX->TX1(D18)
ESP8266_CH_PD->3.3V
ESP8266_VCC->3.3V
ESP8266_GND->GND

When you want to output the debug information, please use DebugSerial. For example,

DebugSerial.println("hello");


Note: The size of message from ESP8266 is too big for arduino sometimes, so the library can't receive the whole buffer because  
the size of the hardware serial buffer which is defined in HardwareSerial.h is too small.

Open the file from \arduino\hardware\arduino\avr\cores\arduino\HardwareSerial.h.
See the follow line in the HardwareSerial.h file.

#define SERIAL_BUFFER_SIZE 64

The default size of the buffer is 64. Change it into a bigger number, like 256 or more.





*/


#define SSID       "Yoon01"
#define PASSWORD   "xodud15*"
#define server      "192.168.0.10" 


#include "uartWIFI.h"
//#include <SoftwareSerial.h>
WIFI wifi;
String SERIAL_NO ="SMARTDOORLOCK_29";
unsigned long lastConnectionTime = 0;          // last time you connected to the server, in milliseconds
boolean lastConnected = false;                 // state of the connection last time through the main loop
const unsigned long postingInterval = 8*1000;  // delay between updates, in milliseconds

void setup()
{

  wifi.begin();
  bool b = wifi.Initialize(STA, SSID, PASSWORD);
  if(!b)
  {
    Serial.println("Init error");   
  }
  delay(8000);  
  String ipstring  = wifi.showIP();
  
  Serial.println(ipstring);
  Serial.println("connected");

}
void loop()
{
  char message[320];
  if((millis() - lastConnectionTime > postingInterval)) {
    httpRequest();
  } 


  if(wifi.ReceiveMessage(message)) 
  {
      Serial.println(message);   
  }
  delay(10);
}

// this method makes a HTTP connection to the server:
void httpRequest() {
  // if there's a successful connection:
  if (wifi.ipConfig(TCP,server,8081)) {
    Serial.println("connecting...");
    wifi.Send("POST /hw/key/list?serial_no="+SERIAL_NO+" HTTP/1.0\r\n\r\n" );
    lastConnectionTime = millis();
  } 
  else {
    Serial.println("connection failed");
    Serial.println("disconnecting.");
    wifi.closeMux();
  }
}
