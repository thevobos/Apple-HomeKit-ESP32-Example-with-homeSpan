struct DEV_LOCK : Service::LockMechanism{

  int lockPin;                               

  SpanCharacteristic *lockStatus;     
  SpanCharacteristic *LockTargetState;       

  DEV_LOCK(int lockPin) : Service::LockMechanism(){       

    lockStatus      = new Characteristic::LockCurrentState(); 
    LockTargetState = new Characteristic::LockTargetState();
    
    this->lockPin=lockPin;                
    
    pinMode(lockPin,OUTPUT);                                     
    
  } // end constructor()
  
  boolean update(){  
     
    digitalWrite(lockPin,lockStatus->getNewVal() ? HIGH : LOW);  
     return(true);                           
  
  } 
  
};
 