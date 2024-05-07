#ifndef AUTODEALER_H
#define AUTODEALER_H

#include "Car.h"

const int MAXINVENTORYSIZE = 500;

class AutoDealer
{
private:
	Car carInventory[MAXINVENTORYSIZE];
	int totalCars;
public:
	AutoDealer();
	void readCarsFile();
	void inputCarInfo();
	void searchCar();
	void displayCars();
	void writeCarsFile();
};

#endif // AUTODEALER_H

