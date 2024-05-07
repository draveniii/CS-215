// Draven McConathy
// 04/26/2024
// This is a program used to keep track of an auto dealers inventory of cars
// The inventory is saved between runs of the program

#include <iostream>
#include "AutoDealer.h"

using namespace std;

int getMenuInput();

int main()
{
?>	AutoDealer dealershipInventory;
 
	dealershipInventory.readCarsFile();

	int menuInput;

	// Until user inputs option to quit get menuInput from user
	do
	{
		// Menu choices
		cout << "\n1) Input cars into inventory\n";
		cout << "2) Search for car in inventory\n";
		cout << "3) Display all cars in inventory\n";
		cout << "4) Quit Program\n";

		// Gets user menuInput
		menuInput = getMenuInput();

		// Allows user to input additional cars in the carInventory array until the user stops
		if (menuInput == 1)
		{
			dealershipInventory.inputCarInfo();
		}
		// Searches for a particular car in the carInventory array
		else if (menuInput == 2)
		{
			dealershipInventory.searchCar();
		}
		// Displays all cars in the carInventory array
		else if (menuInput == 3)
		{
			dealershipInventory.displayCars();
		}
		// Writes the carInventory array into a file and closes the program
		else if (menuInput == 4)
		{
			dealershipInventory.writeCarsFile();
		}
	} while (menuInput != 4);
  }

// Gets user input
int getMenuInput()
{
	int input;

	do
	{
		cin >> input;
		cin.ignore();

		// If the input is not an integer
		if (cin.fail())
		{
			// Clears input stream
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please enter a number 1-4: \n";
		}
		// If input is not within accepted range
		else if (input < 1 || input > 4)
		{
			cout << "Please enter a number 1-4: ";
		}

	} while (input < 1 && input > 5);

	return input;
}