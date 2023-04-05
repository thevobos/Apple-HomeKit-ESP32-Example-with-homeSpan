#include "HomeSpan.h"  
#include "DEV_OUTLET.h"  
#include "DEV_LIGHT.h" 
#include "DEV_LOCK.h" 
#include "DEV_LED_RGB.h"  
#include "DEV_Sensors.h" 
#include "DEV_DoorsWindows.h" 

const char* ssid     = "AKCAN";
const char* password = "dombili123";

/* 
ESP32 Version : 2.0.4
homeSpan Version : 1.6.0

*/

void setup() {

  Serial.begin(115200);
 
  homeSpan.begin(Category::Lighting,"WEIOT HOME 2");

  homeSpan.setWifiCredentials(ssid, password);

  homeSpan.setQRID("WEIOT 2");
  homeSpan.setPairingCode("14736925"); 


  new SpanAccessory();
    new Service::AccessoryInformation();            
      new Characteristic::Identify();


  new SpanAccessory();
    new Service::AccessoryInformation();            
      new Characteristic::Identify();
      new Characteristic::Name("Kilit 1");              
   new DEV_LOCK(27);           

  new SpanAccessory();
    new Service::AccessoryInformation();            
      new Characteristic::Identify();
      new Characteristic::Name("Lamba 1");              
   new DEV_LIGHT(2);     

  new SpanAccessory();
    new Service::AccessoryInformation();            
      new Characteristic::Identify();
      new Characteristic::Name("Anahtar 1");              
   new DEV_OUTLET(26);     

  new SpanAccessory();
    new Service::AccessoryInformation();            
      new Characteristic::Identify();
      new Characteristic::Name("Anahtar 2");              
   new DEV_OUTLET(25);     

  new SpanAccessory();
    new Service::AccessoryInformation();            
      new Characteristic::Identify();
      new Characteristic::Name("Anahtar 3");              
   new DEV_OUTLET(32);     

  new SpanAccessory();
    new Service::AccessoryInformation();            
      new Characteristic::Identify();
      new Characteristic::Name("Anahtar 4");              
   new DEV_OUTLET(33);     

  new SpanAccessory();
    new Service::AccessoryInformation();            
      new Characteristic::Identify();   
      new Characteristic::Name("Renkli Led 1");           
   new DEV_RGB(25,32,33);

  new SpanAccessory();
    new Service::AccessoryInformation();            
      new Characteristic::Identify();   
      new Characteristic::Name("Renkli Led 2");           
   new DEV_RGB(25,32,33);

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify(); 
      new Characteristic::Name("Sicaklık Sensörü 1");
    new DEV_TempSensor();

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify(); 
      new Characteristic::Name("Sicaklık Sensörü 2");
    new DEV_TempSensor();

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify(); 
      new Characteristic::Name("Hava Kalitesi 1");  
    new DEV_AirQualitySensor();  

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify(); 
      new Characteristic::Name("Hava Kalitesi 2");  
    new DEV_AirQualitySensor();  


  new SpanAccessory();                                                          
    new Service::AccessoryInformation();
      new Characteristic::Identify(); 
      new Characteristic::Name("Tente 1");
    new DEV_WindowShade(18);                                                            

  new SpanAccessory();                                                          
    new Service::AccessoryInformation();
      new Characteristic::Identify(); 
      new Characteristic::Name("Tente 2");
    new DEV_WindowShade(18);                                                            


} // end of setup()

//////////////////////////////////////

void loop(){
  
  homeSpan.poll();
  
} // end of loop()
