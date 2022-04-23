void Read_data()
{
  data_loop_counter ++;
  if(data_loop_counter == 1) 
  {
    tempRPM = myELM327.rpm(); 
  }
  if(data_loop_counter == 2)
  {
    Engine_load = myELM327.engineLoad();   
  }
  if(data_loop_counter == 3)
  {
    
    Engine_coolant_temperature =  myELM327.engineCoolantTemp();  
    }
    if(data_loop_counter == 4)
  {
    
    Fuel_pressure = myELM327.fuelPressure();  
    }
    if(data_loop_counter == 5)
  {
    manifold_pressure = myELM327.manifoldPressure();  
    
    }
    if(data_loop_counter == 6)
  {
    
    timing_Advance = myELM327.timingAdvance();  
    }
    if(data_loop_counter == 7)
  {
    
    Throttle = myELM327.throttle();  
    }
    if(data_loop_counter == 8)
  {
    
    Distance_travelled = myELM327.distTravelWithMIL();  
    }
   if(data_loop_counter == 9)
   {
    
    Oil_temperature = myELM327.oilTemp();  
    }
    if(data_loop_counter == 9)
   {
    Torque = myELM327.torque();  
    
    }
     if(data_loop_counter == 9)
   {
    monitor_status = myELM327.monitorStatus();  
    
    }
     if(data_loop_counter == 9)
   {
    control_MOD_Vo = myELM327.ctrlModVoltage();  
    }
    
  if (myELM327.status == ELM_SUCCESS)
  {
    rpm = (uint32_t)tempRPM;
    engineCoolantTemp = (uint32_t)Engine_coolant_temperature;
    fuelPressure = (uint32_t)Fuel_pressure;
    manifoldPressure = (uint32_t)manifold_pressure;
    timingAdvance = (uint32_t)timing_Advance;
    throttle = (uint32_t)Throttle;
    distTravelWithMIL = (uint32_t)Distance_travelled;
    oilTemp = (uint32_t)Oil_temperature;
    torque = (uint32_t)Torque;
    monitorStatus = (uint32_t)monitor_status;
    ctrlModVoltage = (uint32_t)control_MOD_Vo;
    
    Serial.print("RPM: ");                         Serial.println(rpm);
    Serial.print("Engine Collant Temperature : "); Serial.println(engineCoolantTemp);
    Serial.print("Fuel Pressure: ");               Serial.println(fuelPressure);
    Serial.print("mainfold Pressure: ");           Serial.println(manifoldPressure);
    Serial.print("Timing Advance: ");              Serial.println(timingAdvance);
    Serial.print("Throttle: ");                    Serial.println(throttle);
    Serial.print("Distance Travelled : ");         Serial.println(distTravelWithMIL);
    Serial.print("Oil Temperature: ");             Serial.println(oilTemp);
    Serial.print("Torque: ");                      Serial.println(torque);
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  }
