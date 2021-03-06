/*****************************************************
* File : typewise-alert.c
* Author: xxx
* Created on: xx/yy/zzzz
*****************************************************/

#include <stdio.h>
#include "typewise-alert.h"

BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
  if(value < lowerLimit) 
  {
    return TOO_LOW;
  }
  else if(value > upperLimit) 
  {
    return TOO_HIGH;
  }
  else
  {
    return NORMAL;
  }
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  int lowerLimit = 0;
  int upperLimit = 0;
  
  if(coolingType == PASSIVE_COOLING)
  {
    upperLimit = 35;
  }
  else if(coolingType == HI_ACTIVE_COOLING)
  {
    upperLimit = 45;
  }
  else
  {
    upperLimit = 40;
  }
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}


void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
  if( (MED_ACTIVE_COOLING >= batteryChar.coolingType) && (TO_EMAIL >= alertTarget) )
  {
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
    SystemAlert(alertTarget, breachType);
  }
  else
  {
    /* Do Nothing*/
  }
}


void SystemAlert(AlertTarget alert, BreachType breach)
{
  switch(alert) 
  {
    case TO_CONTROLLER:
      sendToController(breach);
      break;
    case TO_EMAIL:
      sendToEmail(breach);
      break;
    default:
      /*Do Nothing */
      break;
  }
}

void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  switch(breachType) 
  {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
  }
}
