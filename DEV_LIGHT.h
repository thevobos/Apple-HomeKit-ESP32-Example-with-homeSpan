

struct DEV_LIGHT : Service::LightBulb{

  int lampPin;                               // store the pin number connected to a hypothetical relay that turns the Table Lamp on/off
  SpanCharacteristic *lampPower;             // store a reference to the On Characteristic
  
  DEV_LIGHT(int lampPin) : Service::LightBulb(){       // constructor() method for TableLamp defined with one parameter.  Note we also call the constructor() method for the LightBulb Service.

    lampPower=new Characteristic::On();      // instantiate the On Characteristic and save it as lampPower
    this->lampPin=lampPin;                   // save the pin number for the hypothetical relay
    pinMode(lampPin,OUTPUT);                 // configure the pin as an output using the standard Arduino pinMode function                       
    
  } // end constructor()
  
  boolean update(){  
 
    digitalWrite(lampPin,lampPower->getNewVal() ? HIGH : LOW);      // use standard Arduino digitalWrite function to change the ledPin to either high or low based on the value requested by HomeKit
     return(true);                            // return true to let HomeKit (and the Home App Client) know the update was successful
  
  } // end update()
  
};
