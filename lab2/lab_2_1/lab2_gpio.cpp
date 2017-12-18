// Filename: lab2_gpio.cpp
#include "lab2_gpio.h"
#include <iostream>

// ------------------------------------ LAB 2 Question 1 Class Definitions ------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------------------------

int lab2_gpio::pinMode(int pinNum, pinModes pMode)
{
// Purpose: This function sets the pin mode for the desired pin mode

	if (pinNum<10)
	{
		// ---------------------------ADD CODE HERE for pins 0-9 -------------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
	}
	else if(9<pinNum && pinNum<20)
	{
		// ---------------------------ADD CODE HERE for pins 10-19 ----------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
	}
	else if(19<pinNum && pinNum<30)
	{
		// ---------------------------ADD CODE HERE for pins 20-29 ----------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
	}
	else	if(29<pinNum && pinNum<40)
	{
		// ---------------------------ADD CODE HERE for pins 30-39 ----------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
	}
	else	if(39<pinNum && pinNum<50)
	{
		// ---------------------------ADD CODE HERE for pins 40-49 ----------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
	}
	else	if(49<pinNum && pinNum<54)
	{
		// ---------------------------ADD CODE HERE for pins 50-53 ----------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
	}
	else{
		printf("Pin number  %d out of range\n", pinNum);
		return -1;
	}	
	return 0;
}

int lab2_gpio::pinModeRead(int pinNum, pinModes pMode)
{
// Purpose: This function reads the current pin mode of pinNum and compares it to the 
//		   desired pin mode pMode, returns 1 if it matches and -1 if it does not
	unsigned long desired_result, read_result;
	if (pinNum<10)
	{
		// ---------------------------ADD CODE HERE for pins 0-9 -------------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else if(9<pinNum && pinNum<20)
	{
		// ---------------------------ADD CODE HERE for pins 10-19 ----------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else if(19<pinNum && pinNum<30)
	{
		// ---------------------------ADD CODE HERE for pins 20-29 ----------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else	if(29<pinNum && pinNum<40)
	{
		// ---------------------------ADD CODE HERE for pins 30-39 ----------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else	if(39<pinNum && pinNum<50)
	{
		// ---------------------------ADD CODE HERE for pins 40-49 ----------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else	if(49<pinNum && pinNum<54)
	{
		// ---------------------------ADD CODE HERE for pins 50-53 ----------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
		if(desired_result == read_result) return 1;
	}
	else{
		printf("Pin number  %d out of range\n", pinNum);
		return -1;
	}	
	return 0;
}


int lab2_gpio::digitalRead(int pinNum)
{
// Purpose: This function reads the value of the pin pinNum and returns 1 if high and 
//		   0 if low, if it is neither then return -1.
	unsigned long bitHigh, pinNvalue;
	if (0<= pinNum && pinNum<32)
	{
		// ---------------------------ADD CODE HERE for pins 0-31 -------------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
		if (pinNvalue == bitHigh)  return 1;
		else f(pinNvalue == 0) return 0;
		else{
			printf("Read value of pin %d is %X pinNvalue \n", pinNum, pinNvalue);
			return -1;
		}
	}
	else if(31< pinNum && pinNum<54)
	{
		// ---------------------------ADD CODE HERE for pins 32-53 -----------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
		if (pinNvalue == bitHigh)  return 1;
		else	if(pinNvalue == 0) return 0;
		else{
			printf("Read value of pin %d is %X pinNvalue\n", pinNum, pinNvalue);
			return -1;
		}
	}
	else{
		printf("Pin number  %d out of range\n", pinNum);
		return -1;
	}
}

int lab2_gpio::digitalWrite(int pinNum, outValue out_v)
{
// Purpose: This function first checks that the pin mode of the pin you wish to write to 
// 		   is set to OUTPUT. It then writes high or low to the pin.

	int status = lab2_gpio::pinModeRead(pinNum, OUTPUT);
	if(status == -1) 
	{
		printf("Pin mode is not in output mode\n");
		return -1;
	}
	if (0<= pinNum && pinNum<32)
	{
		if(out_v == HIGH)
		{
		// ---------------------------ADD CODE HERE for pins 0-31 -------------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
			return 1;
		}
		else if(out_v == LOW)
		{
		// ---------------------------ADD CODE HERE for pins 32-53-------------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
			return 1;
		}
	}
	else if(31< pinNum && pinNum<54)
	{
		if(out_v == HIGH)
		{
		// ---------------------------ADD CODE HERE for pins 0-31 -------------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
			return 1;
		}
		else if(out_v == LOW)
		{
		// ---------------------------ADD CODE HERE for pins 32-53-------------------------------------------
		
		// -----------------------------------------------------------------------------------------------------------------------
			return 1;
		}
	}
	else{
		printf("Pin number  %d out of range \n", pinNum);
		return -1;
	}
}

