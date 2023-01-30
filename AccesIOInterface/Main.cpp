/*
#include <iostream>
#include <string>
#include <AIOUSB/AIOUSB.h>


const int IO_BOARD_INDEX = 0; // The index of the IO board in the list of devices
const int NUM_BYTES = 4; // The number of bytes to write to the IO board

int main()
{
	// Initialize the AIOUSB library
	AIOUSB_Init();

	// Write a block of data to the IO board
	unsigned char data[NUM_BYTES] = { 0xFF, 0x00, 0xFF, 0x00 };
	unsigned long bytesWritten = DACDirect(IO_BOARD_INDEX, NUM_BYTES, data);
	if (bytesWritten == NUM_BYTES)
	{
		std::cout << "Successfully wrote data to IO board" << std::endl;
	}
	else
	{
		std::cerr << "Error writing to IO board" << std::endl;
	}

	// Clean up the AIOUSB library
	AIOUSB_Exit();

	return 0;
}
*/

#include <accessio.h> // Include Access I/O library
#include <iostream>

// Define constants for the Access I/O board and autopilot amplifier
const int BOARD_NUMBER = 0;
const int AUTOPILOT_ADDRESS = 0x01;

const double REG_ROLL_ANGLE;

int main()
{
	// Initialize the Access I/O board
	int result = AccessIOInit(BOARD_NUMBER);
	if (result != 0)
	{
		// An error occurred during initialization
		// Handle the error and terminate the program
		return -1;
	}

	// Set the autopilot amplifier address
	AccessIOSetAddress(BOARD_NUMBER, AUTOPILOT_ADDRESS);

	// Read the current roll angle from the autopilot amplifier
	double rollAngle;
	result = AccessIORead(BOARD_NUMBER, REG_ROLL_ANGLE, &rollAngle);
	if (result != 0)
	{
		// An error occurred while reading the roll angle
		// Handle the error and terminate the program
		return -1;
	}

	// Print the roll angle to the console
	std::cout << "Current roll angle: %f\n", rollAngle) << std::endl;

	// Set the desired roll angle on the autopilot amplifier
	double newRollAngle = 45.0;
	result = AccessIOWrite(BOARD_NUMBER, REG_ROLL_ANGLE, newRollAngle);
	if (result != 0)
	{
		// An error occurred while writing the roll angle
		// Handle the error and terminate the program
		return -1;
	}

	// Read the updated roll angle from the autopilot amplifier
	result = AccessIORead(BOARD_NUMBER, REG_ROLL_ANGLE, &rollAngle);
	if (result != 0)
	{
		// An error occurred while reading the roll angle
		// Handle the error and terminate the program
		return -1;
	}

	// Print the updated roll angle to the console
	printf("New roll angle: %f\n", rollAngle);

	// Close the Access I/O board
	AccessIOClose(BOARD_NUMBER);

	return 0;
}