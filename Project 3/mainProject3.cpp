#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void displayMenu();
int getMenuInput();
void newCustomerArrival(LinkedList*);
void customerLeft(LinkedList*);
void serveCustomer(LinkedList*);
void listAllCustomers(LinkedList*);
void pad(string name, int maxDataLength = 16);

int main()
{
	// Define LinkedList object and LinkedListPtr
	LinkedList customerList;
	LinkedList* customerListPtr = &customerList;

	int userInput;

	do
	{
		displayMenu();

		userInput = getMenuInput();

		// Processes userInput
		if (userInput == 1) // Adds input customer and service needed to wait list
		{
			newCustomerArrival(customerListPtr);
		}
		else if (userInput == 2) // Removes the first person added to the queue
		{
			serveCustomer(customerListPtr);
		}
		else if (userInput == 3) // User inputs a name to be deleted, if name is present in list deletes name. If name is not found display not found
		{
			customerLeft(customerListPtr);
		}
		else if (userInput == 4) // Shows all customers currently waiting
		{
			listAllCustomers(customerListPtr);
		}

	} while (userInput != 5); // Quits the Program
}

// Displays menu choices to user
void displayMenu()
{
	cout << "\n";
	cout << "1) New Customer Arrival\n";
	cout << "2) Serve Customer\n";
	cout << "3) Customer Left - Remove From Waiting List\n";
	cout << "4) List All Customers Waiting For Service\n";
	cout << "5) Quit\n\n";
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

			cout << "Please enter a number 1-5: ";
		}
		// If input is not within accepted range
		else if (input < 1 || input > 5)
		{
			cout << "Please enter a number 1-5: ";
		}

	} while (input < 1 && input > 5);

	return input;
}

// Gets new customers name and the service they need and stores it into the customerList
void newCustomerArrival(LinkedList* customerListPtr)
{
	string inputName;
	string inputServiceRequest;

	cout << "Enter a customer name then enter the service needed: \n";
	getline(cin, inputName);
	getline(cin, inputServiceRequest);
	cout << "\n";

	customerListPtr->insertNode(inputName, inputServiceRequest);
}

// Deletes a customer from the queue by name
void customerLeft(LinkedList* customerListPtr)
{
	string inputName;
	bool deleted;

	cout << "Enter a name to be deleted: ";

	// Gets name to delete
	getline(cin, inputName);

	// Deletes inputName if found in list
	deleted = customerListPtr->deleteNode(inputName);

	// If inputName was found deleteNode returns true and displays that the inputName was deleted
	if (deleted == true)
	{
		cout << inputName << " has not been served and has been removed from queue.\n";
	}
	else
	{
		cout << inputName << " was not found and may have already been served.\n";
	}
}

// Removes the customer that has been waiting longest from the queue
void serveCustomer(LinkedList* customerListPtr)
{
	bool deleted;

	deleted = customerListPtr->deleteNode();

	if (deleted == false)
	{
		cout << "There are currently no customers in queue to serve.\n\n";
	}
	else
	{
		cout << "A customer has been served!\n\n";
	}
}

// Prints queue header
void listAllCustomers(LinkedList* customerListPtr)
{
	cout << "APPLE CUSTOMER SERVICE WAITING LIST" << endl;
	cout << "SEQUENCE     NAME            ARRIVAL DATE/TIME      PURPOSE OF VISIT" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	customerListPtr->listAll();
}

