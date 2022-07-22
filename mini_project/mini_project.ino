/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-date-time-ntp-client-server-arduino/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <WiFi.h>
#include "time.h"

const char* ssid     = "vernon-gg";
const char* password = "nikilvgoveas";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 19800;//  in India, where the timezone is 5 hours and 30 mins ahead of the UTC, the gmtOffset_sec will be (5+0.5)*3600 = 19800.
const int   daylightOffset_sec = 0;// no daylight saving in India
int hour;
void setup(){
  Serial.begin(115200);

  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  
  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop(){
  delay(1000);
    struct tm timeinfo;
  if(!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return;
  }

  char timeHour[3];
  strftime(timeHour,3, "%H", &timeinfo);
 

    char timeMin[3];
  strftime(timeMin,3, "%M", &timeinfo);
int hour = atoi(timeHour);

if (hour == 15)
{
  Serial.println("noice");
  }
//else 
//{Serial.println(timeHour);}

}






void printLocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
//  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
//  Serial.print("Day of week: ");
//  Serial.println(&timeinfo, "%A");
//  Serial.print("Month: ");
//  Serial.println(&timeinfo, "%B");
//  Serial.print("Day of Month: ");
//  Serial.println(&timeinfo, "%d");
//  Serial.print("Year: ");
//  Serial.println(&timeinfo, "%Y");
//  Serial.print("Hour: ");
//  Serial.println(&timeinfo, "%H");
//  Serial.print("Hour (12 hour format): ");
//  Serial.println(&timeinfo, "%I");
//  Serial.print("Minute: ");
//  Serial.println(&timeinfo, "%M");
//  Serial.print("Second: ");
//  Serial.println(&timeinfo, "%S");

//  Serial.println("Time variables");
//  char timeHour[3];
//  strftime(timeHour,3, "%H", &timeinfo);
  
//  Serial.println(timeHour);
//  char timeWeekDay[10];
//  strftime(timeWeekDay,10, "%A", &timeinfo);
//  Serial.println(timeWeekDay);
//  Serial.println();
//  return 
}
