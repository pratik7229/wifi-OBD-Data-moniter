#include <WiFi.h>
#include "ELMduino.h"


const char* ssid = "WiFi_OBDII";
const char* password = "";


//IP Adress of your ELM327 Dongle
IPAddress server(192, 168, 0, 10);
WiFiClient client;
ELM327 myELM327;


float tempRPM = 0;
float Engine_coolant_temperature = 0;
float Fuel_pressure = 0;
float manifold_pressure = 0;
float timing_Advance = 0;
float Throttle = 0;
float Distance_travelled = 0;
float Oil_temperature = 0;
float Torque = 0;
float monitor_status = 0;
float control_MOD_Vo = 0;
float Engine_load = 0;

uint32_t rpm = 0;
uint32_t engineCoolantTemp = 0;
uint32_t fuelPressure = 0;
uint32_t manifoldPressure = 0;
uint32_t timingAdvance = 0;
uint32_t throttle = 0;
uint32_t distTravelWithMIL = 0;
uint32_t oilTemp = 0;
uint32_t torque = 0;
uint32_t monitorStatus = 0;
uint32_t ctrlModVoltage = 0;
int data_loop_counter = 0;

void setup()
{
  Serial.begin(115200);

  // Connecting to ELM327 WiFi
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_AP);
  WiFi.begin(ssid);
  // WiFi.begin(ssid, password); //Use this line if your ELM327 has a password protected WiFi

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to Wifi");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  if (client.connect(server, 35000))
    Serial.println("connected");
  else
  {
    Serial.println("connection failed");
    while(1);
  }

  myELM327.begin(client);
}


void loop()
{ 
  float tempRPM = myELM327.rpm();
  float Engine_load = myELM327.engineLoad();
  float Engine_coolant_temperature =  myELM327.engineCoolantTemp();
  float Fuel_pressure = myELM327.fuelPressure();
  float manifold_pressure = myELM327.manifoldPressure();
  float timing_Advance = myELM327.timingAdvance();
  float Throttle = myELM327.throttle();
  float Distance_travelled = myELM327.distTravelWithMIL();
  float Oil_temperature = myELM327.oilTemp();
  float Torque = myELM327.torque();
  float monitor_status = myELM327.monitorStatus();
  float control_MOD_Vo = myELM327.ctrlModVoltage();

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
  else
    printError();
}


void printError()
{
  Serial.print("Received: ");
  for (byte i = 0; i < myELM327.recBytes; i++)
    Serial.write(myELM327.payload[i]);
  Serial.println();
  
  if (myELM327.status == ELM_SUCCESS)
    Serial.println(F("\tELM_SUCCESS"));
  else if (myELM327.status == ELM_NO_RESPONSE)
    Serial.println(F("\tERROR: ELM_NO_RESPONSE"));
  else if (myELM327.status == ELM_BUFFER_OVERFLOW)
    Serial.println(F("\tERROR: ELM_BUFFER_OVERFLOW"));
  else if (myELM327.status == ELM_UNABLE_TO_CONNECT)
    Serial.println(F("\tERROR: ELM_UNABLE_TO_CONNECT"));
  else if (myELM327.status == ELM_NO_DATA)
    Serial.println(F("\tERROR: ELM_NO_DATA"));
  else if (myELM327.status == ELM_STOPPED)
    Serial.println(F("\tERROR: ELM_STOPPED"));
  else if (myELM327.status == ELM_TIMEOUT)
    Serial.println(F("\tERROR: ELM_TIMEOUT"));
  else if (myELM327.status == ELM_TIMEOUT)
    Serial.println(F("\tERROR: ELM_GENERAL_ERROR"));


float fuelLevel = 0; // in %
if (myELM327.queryPID(SERVICE_01, FUEL_TANK_LEVEL_INPUT))
  fuelLevel = myELM327.findResponse() * 100.0 / 255.0;

  Serial.println("Fuel level is");
  Serial.println(fuelLevel);

  delay(100);
}
