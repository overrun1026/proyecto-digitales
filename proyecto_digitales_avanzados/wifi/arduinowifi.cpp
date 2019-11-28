#include "UbidotsMicroESP8266.h"

#define TOKEN  "BBFF-Nkw87nsCTGjrdBpiQckUpTaDwdLHH8"  // Put here your Ubidots TOKEN
#define WIFISSID "leopro" // Put here your Wi-Fi SSID
#define PASSWORD "leopro123" // Put here your Wi-Fi password

Ubidots client(TOKEN);
 //en el ESP8266 RX GPIO3 y TX GPIO1

void setup(){
    Serial.begin(9600);
    client.wifiConnection(WIFISSID, PASSWORD);
    //client.setDebug(true); // Uncomment this line to set DEBUG on
    

}
void loop(){

  /*if(WiFi.status == WL_CONNECTED){
    Serial.write(0x4A);
  }else{
    Serial.write(0x4B);
  }*/
  //Serial.write(0x4A);
      float dato;
      dato=Serial.read();
      client.add("5ddfcd908683d524e82769b8", dato);//ID variable
      //Serial.println(dato);
      client.sendAll();
      delay(5000);

      }