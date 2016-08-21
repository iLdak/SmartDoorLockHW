/*
  Adding Strings together

 Examples of how to add strings together
 You can also add several different data types to string, as shown here:

 created 27 July 2010
 modified 2 Apr 2012
 by Tom Igoe

 http://www.arduino.cc/en/Tutorial/StringAdditionOperator

 This example code is in the public domain.
 */

// declare three strings:
String stringOne, stringTwo, stringThree, stringFour;

void setup() {

  Serial.begin(9600);



}

void loop() {

   if (Serial.available()) {
    char temp[100];   
    String test=""; 
    byte leng = Serial.readBytes(temp, 20);
    
    Serial.print("Input data Lenght : ");
    Serial.println(leng);
    
    for(int i = 0; i < leng; i++){
        test+=temp[i];
    }

   
   }

  while (true);
}
