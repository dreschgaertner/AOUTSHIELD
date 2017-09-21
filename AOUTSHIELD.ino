//https://www.tindie.com/products/AislerHQ/the-ultimate-arduino-uno-expansion-kit/
//  =================================================
//  A I N S H I E L D    &    A O U T S H I E L D
//  =================================================
//  Additional analogue Output PIN's for
//  Arduino Uno, Mega, Due...
//  AOUTSHIELD: SPI using MCP4922
//  Library   : AH_MCP4922.h from A.Hinkel 28.12.2011
//  SCADA     : SerialComInstruments  Version 4.1.0.0
//              © Software from U.Maassen
//  http://www.serialcominstruments.com/download.php
//  =================================================
//  L I B R A R Y S
   #include "AH_MCP4922.h"//-------------------------Remove "Delay(1)" Inside Lib,
//                                                   otherwise it would run very slow.
//  =================================================
//  G L O B A L   S E T T I N G S
//  AOUTSHIELD
    AH_MCP4922 AA0(11,13,8,LOW,HIGH);//---------(..., CS-Signal, GAIN)
    AH_MCP4922 AA1(11,13,8,HIGH,HIGH);//--------(..., CS-Signal, GAIN)
    AH_MCP4922 AA2(11,13,10,LOW,HIGH);//--------(..., CS-Signal, GAIN)
    AH_MCP4922 AA3(11,13,10,HIGH,HIGH);//-------(..., CS-Signal, GAIN)
    int AA0_Val = 0;//-------------------------------Analogue Output 0 Value
    int AA1_Val = 0;//-------------------------------Analogue Output 1 Value
    int AA2_Val = 0;//-------------------------------Analogue Output 2 Value
    int AA3_Val = 0;//-------------------------------Analogue Output 3 Value
//  =================================================
//  S E T U P   
    void setup()
    {
    Serial.begin(57600);//---------------------------Monitor and Scada seriell
    }
//  =================================================    
//  M A I N    P R O G R A M
//  =================================================     
    void loop()
    {
    AOUT();//----------------------------------------Function
    SCADA_SER();//-----------------------------------Function
    AA0_Val = 2048;
    }
//  ================================================= 
//  F U N C T I O N   A O U T S H I E L D
//  =================================================
    void AOUT()
    {
    AA0.setValue(AA0_Val);//-------------------------Set Value AA0_Val
    AA1.setValue(AA1_Val);//-------------------------Set Value AA1_Val
    AA2.setValue(AA2_Val);//-------------------------Set Value AA2_Val
    AA3.setValue(AA3_Val);//-------------------------Set Value AA3_Val
    }
//  =================================================
//  F U N C T I O N   S C A D A
//  =================================================
    void SCADA_SER()//-------------------------------only for Test
    {
    Serial.print("#81M");
    Serial.print(AA0_Val);
    Serial.println("<");
    }




 

