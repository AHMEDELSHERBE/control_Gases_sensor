/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_ACCESS_PASSWORD "1234"

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 57 bytes
  { 255,0,0,4,0,50,0,16,31,0,69,0,3,5,23,23,1,72,44,61,
  7,31,31,134,26,92,44,0,0,0,0,0,0,72,66,0,0,0,0,1,
  0,0,0,0,0,0,200,66,70,21,42,31,21,17,1,37,2 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // output variables
  

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

  int Smoke=13;// output
  int value=A0 ; // input
  
int8_t circularbar_1;  // from 0 to 50 
bool sound_1; // =0 no sound, else ID of sound, =1001 for example, look sound list in app 
  
  bool led_1; // led state 0 .. 1 

void setup() 
{
  RemoteXY_Init (); 
  
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
     
}

void loop() 
{ 
  RemoteXY_Handler ();
  Smoke=analogRead(value);
  if(Smoke<=50)
  {
   circularbar_1=Smoke; 
   sound_1=0;
    led_1=0;
     
  }

  
  else if(Smoke>50)
  {
    circularbar_1=Smoke; 
    sound_1=1;
    led_1=1;
  }
  
  
  

}
