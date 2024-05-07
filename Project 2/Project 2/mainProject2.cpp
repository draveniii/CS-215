#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "AssortedSorter.h"

using namespace std;

void displayDataHeader();
void displayBubbleData(long, long);
void displaySelectionData(long, long);
void displayShellData(long, long);
void displayQuickData(long, long);
void pad(long, int);
int getUserInput();
void generateRandomArray(int[], int);

int main() 
{
	//Variable definitions
	long bubbleCount;
	long bubbleSwap;
	long selectionCount;
	long selectionSwap;
	long shellCount;
	long shellSwap;
	long quickCount;
	long quickSwap;
	int userNumOfNumbers;
	int sequence[7] = { 364, 121, 40, 13, 4, 1, 0 }; //Determines the size between each segment to sort for the shell short
	static const int MAXARRAYSIZE = 20001; 
	int array[MAXARRAYSIZE];

	//Creates sorting object
	AssortedSorter Sorter;

	//Gets user input
	userNumOfNumbers = getUserInput();

	//Generates random numbers in the array
	generateRandomArray(array, userNumOfNumbers);

	//Sorts array using each sorting method and 
	Sorter.bubbleSort(array, userNumOfNumbers, bubbleCount, bubbleSwap);
	Sorter.selectionSort(array, userNumOfNumbers, selectionCount, selectionSwap);
	Sorter.shellShort(array, sequence, userNumOfNumbers, shellCount, shellSwap);
	Sorter.quickSort(array, userNumOfNumbers, quickCount, quickSwap);

	//Displays the formatted sorting efficiency results
	displayDataHeader();
	displayBubbleData(bubbleCount, bubbleSwap);
	displaySelectionData(selectionCount, selectionSwap);
	displayShellData(shellCount, shellSwap);
	displayQuickData(quickCount, quickSwap);

	return 0;
}

//Prints out the formatted bubble sort results
void displayBubbleData(long count, long swap)
{
	const int maxCountLength = 20;
	const int maxSwapLength = 19;

	cout << "Bubble";
	pad(count, maxCountLength);
	cout << count;
	pad(swap, maxSwapLength);
	cout << swap << endl;
}

//Prints out the formatted selection sort results
void displaySelectionData(long count, long swap)
{
	const int maxCountLength = 17;
	const int maxSwapLength = 19;

	cout << "Selection";
	pad(count, maxCountLength);
	cout << count;
	pad(swap, maxSwapLength);
	cout << swap << endl;
}

//Prints out the formatted shell sort results
void displayShellData(long count, long swap)
{
	const int maxCountLength = 21;
	const int maxSwapLength = 19;

	cout << "Shell";
	pad(count, maxCountLength);
	cout << count;
	pad(swap, maxSwapLength);
	cout << swap << endl;
}

//Prints out the formatted quick sort results
void displayQuickData(long count, long swap)
{
	const int maxCountLength = 21;
	const int maxSwapLength = 19;

	cout << "Quick";
	pad(count, maxCountLength);
	cout << count;
	pad(swap, maxSwapLength);
	cout << swap << endl;
} 
 
//Prints out header for sort results 
void displayDataHeader()
{
	cout << "SORT ALGORITHM RUN EFFICIENCY\n";
	cout << "ALGORITHM	LOOP COUNT	DATA MOVEMENT\n";
	cout << "---------------------------------------------\n";
}
 
//Generates the white space needed between each of the data items
void pad(long data, int maxDataLength)
{
	int dataLength = to_string(data).length(); //converts the data into a string to find the length of the data
	int paddingNeeded = maxDataLength - dataLength;
	for (int space = 0; space < paddingNeeded; space++)
	{
		cout << " ";
	}
}

//Gets the number of numbers to generate from the user
int getUserInput()
{
	int userInput;
	int defaultNums = 10000;

	cout << "Enter the amount of numbers to be generated between 10 to 20,000.\n";
	cout << "Enter a number outside that range to use default number of number (10,000): ";
	cin >> userInput; //Gets user input

	//Simple data validation that checks to see if the input array is too small or too large
	//And if it is, uses the default array size of 10,000
	if (userInput > 10 && userInput < 20000)
	{
		return userInput;
	}
	else
	{
		return defaultNums;
	}
}


void generateRandomArray(int array[], int numsToGenerate)
{
	srand(time(0)); //Seed the time

	//Generates a random int and stores it in an array until it generates the given amount of numbers to generate
	for (int index = 0; index < numsToGenerate; index++)
	{
		array[index] = rand() % 1000000 + 1;
	}
}
