#include "AutoDealer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// When object is created set the total number of cars to zero
AutoDealer::AutoDealer()
{
	totalCars = 0;
}

// Tries to open a text file called carsFile and read the contents into the dealershipInventory array
void AutoDealer::readCarsFile()
{
	int index = 0;
	Car tempCar;

	fstream carsFile("carsFile.dat", ios::in | ios::binary);

	// If the carsFile fails to open, end function
	if (!carsFile)
	{
		return;
	}

	// Read the first record from the file
	carsFile.read(reinterpret_cast<char*>(&tempCar), sizeof(tempCar));

	// While not at the end of the cars file
	while (!carsFile.eof())
	{
		// Store tempCar in dealershipInventory
		carInventory[index] = tempCar;

		index++;
		totalCars++;

		// Read the next record in the cars file
		carsFile.read(reinterpret_cast<char*>(&tempCar), sizeof(tempCar));
	}

	carsFile.close();
}

// Gets user input for new cars in the dealership and stores the inputs in the dealershipInventory array
void AutoDealer::inputCarInfo()
{
	const int MAXSIZE = 12;
	int index;

	// Set the index to the end of the dealershipInventory array or equal to zero if there are no cars in the array
	if (totalCars == 0)
	{
		index = 0;
	}
	else
	{
		index = totalCars;
	}
	
	
	// Test condition for whether or not to continue inputing cars
	char again;

	// Get input for car structure until user stops
	do
	{
		cout << "\nPress enter twice between each data item.\n";
		cout << "Enter the cars model year: ";
		cin.getline(carInventory[index].year, MAXSIZE);
		// The cin.clear() and cin.ignore() function calls clear the input stream failbit and input buffer after each entry
		cin.clear(); 
		cin.ignore(80, '\n');

		cout << "\nEnter the cars Make: ";
		cin.getline(carInventory[index].make, MAXSIZE);
		cin.clear();
		cin.ignore(80, '\n');

		cout << "\nEnter the cars Model: ";
		cin.getline(carInventory[index].model, MAXSIZE);
		cin.clear();
		cin.ignore(80, '\n');

		cout << "\nEnter the cars Color: ";
		cin.getline(carInventory[index].color, MAXSIZE);
		cin.clear();
		cin.ignore(80, '\n');

		cout << "\nEnter the cars Class: ";
		cin.getline(carInventory[index].carClass, MAXSIZE);
		cin.clear();
		cin.ignore(80, '\n');

		cout << "\nEnter the cars Fuel Type: ";
		cin.getline(carInventory[index].fuelType, MAXSIZE);
		cin.clear();
		cin.ignore(80, '\n');

		cout << "\nEnter the cars Price: ";
		cin.getline(carInventory[index].price, MAXSIZE);
		cin.clear();
		cin.ignore(80, '\n');

		index++;

		cout << "\nWould you like to enter another car? (Type 'Y' to enter another car): ";
		cin >> again;
		cin.ignore();
	} while (again == 'Y' || again == 'y');

	// Set the totalCars to the current index
	totalCars = index;
}

void AutoDealer::searchCar()
{
	const int MAXSIZE = 12;

	char searchMake[MAXSIZE];
	char searchModel[MAXSIZE];
	char searchColor[MAXSIZE];
	char searchClass[MAXSIZE];

	bool carFound = false;

	int index = 0;

	// Get the input for the search make, model, color and class
	cout << "\nPress enter twice after each data item\n";
	cout << "Enter the cars Make: ";
	cin.getline(searchMake, MAXSIZE);
	// The cin.clear() and cin.ignore() function calls clear the input stream failbit and input buffer after each entry
	cin.clear();
	cin.ignore(80, '\n');

	cout << "\nEnter the cars Model: ";
	cin.getline(searchModel, MAXSIZE);
	cin.clear();
	cin.ignore(80, '\n');

	cout << "\nEnter the cars Color: ";
	cin.getline(searchColor, MAXSIZE);
	cin.clear();
	cin.ignore(80, '\n');

	cout << "\nEnter the cars Class: ";
	cin.getline(searchClass, MAXSIZE);
	cin.clear();
	cin.ignore(80, '\n');

	// Step through the carInventory array until a car that matches the input make, model, color and class
	while (carFound == false && index < totalCars)
	{
		if (strcmp(searchMake, carInventory[index].make) == 0) // Compares car make
		{
			if (strcmp(searchModel, carInventory[index].model) == 0) // Compares car model
			{
				if (strcmp(searchColor, carInventory[index].color) == 0) // Compares car color
				{
					if (strcmp(searchClass, carInventory[index].carClass) == 0) // Compares car class
					{
						// If a matching car is found print out the matching car
						cout << "This is the first matching car found: \n";
						cout << left << setw(12) << carInventory[index].year << setw(12) << carInventory[index].make << setw(12) << carInventory[index].model << setw(12);
						cout << carInventory[index].color << setw(12) << carInventory[index].carClass << setw(15) << carInventory[index].fuelType;
						cout << setw(12) << carInventory[index].price << endl;

						carFound = true;
					}
				}
			}
		}

		index++;
	}

	// If no matching car is found display that no matching car was found
	if (carFound == false)
	{
		cout << "No Matching car found.\n";
	}
}


void AutoDealer::displayCars()
{
	// Displays car list header
	cout << "                             Dealership Inventory\n";
	cout << "Year        Make        Model       Color       Class       Fuel-Type      Price\n";
	cout << "------------------------------------------------------------------------------------\n";
	
	// Print out each car in the carInventory array 
	for (int index = 0; index < totalCars; index++)
	{
		cout << left << setw(12) << carInventory[index].year << setw(12) << carInventory[index].make << setw(12) << carInventory[index].model << setw(12);
		cout << carInventory[index].color << setw(12) << carInventory[index].carClass << setw(15) <<  carInventory[index].fuelType;
		cout << setw(12) << carInventory[index].price << endl;
	}
}

// Write the contents of the dealershipInventory to the carsFile
void AutoDealer::writeCarsFile()
{

	fstream carsFile("carsFile.dat", ios::out | ios::binary);

	// For each item in the carInventory array, write that item into the carFile
	for (int index = 0; index < totalCars; index++)
	{
		carsFile.write(reinterpret_cast<char*>(&carInventory[index]), sizeof(carInventory[index]));
	}

	carsFile.close();
}
