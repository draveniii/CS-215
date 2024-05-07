#include "AssortedSorter.h"

#include <iostream>

using namespace std;

void AssortedSorter::bubbleSort(int inputArray[], int arraySize, long& count, long& swap)
{
	int maxElement; //The largest index in an array that needs to be sorted
	int temp; //Holds value at a particular index for swapping items in array
	int index;

	count = 0; //Keeps track of how many iterations of the inner for loop occur
	swap = 0; //Keeps track of how many times two values swap places in the array

	//Copys input array to array in class
	for (index = 0; index < arraySize; index++)
	{
		classArray[index] = inputArray[index];
	}

	//Bubble Sort Algorithm
	for (maxElement = arraySize - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			count++;
			if (classArray[index] > classArray[index + 1])
			{
				swap++;
				temp = classArray[index];
				classArray[index] = classArray[index + 1];
				classArray[index + 1] = temp;
			}
		}
	}
}

void AssortedSorter::selectionSort(int inputArray[], int arraySize, long& count, long& swap)
{
	int minIndex; //Keeps track of the smallest index that has not been sorted
	int minValue; //Keeps track of the smallest value in the unsorted portion of the array
	int start; //Marks the latest index to not be sorted for each iteration
	int temp; //Holds value at a particular index for swapping items in array
	int index;

	count = 0; //Keeps track of how many iterations of the inner for loop occur
	swap = 0; //Keeps track of how many times two values swap places in the array

	//Copys input array to array in class
	for (index = 0; index < arraySize; index++)
	{
		classArray[index] = inputArray[index];
	}
	
	//Selection Sort Algorithm
	for (start = 0; start < arraySize - 1; start++)
	{
		minIndex = start;
		minValue = classArray[start];

		for (index = start + 1; index < arraySize; index++)
		{
			count++;
			if (classArray[index] < minValue)
			{
				minValue = classArray[index];
				minIndex = index;
			}
		}
		swap++;
		temp = classArray[minIndex];
		classArray[minIndex] = classArray[start];
		classArray[start] = temp;
	}
}

void AssortedSorter::shellShort(int inputArray[], int sequence[], int arraySize, long& count, long& swap)
{
	int copyIndex; 
	int comparisonIndex;
	int incrementer;
	int temp;
	int stepIncrementer;

	int start = 0; //start of the array
	int stop = arraySize - 1; //End of the array
	int step = 0; 
	
	count = 0; //Keeps track of how many iterations of the inner for loop occur
	swap = 0; //Keeps track of how many times two values swap places in the array

	//Copys input array to array in class
	for (copyIndex = 0; copyIndex < arraySize; copyIndex++)
	{
		classArray[copyIndex] = inputArray[copyIndex];
	}

	//Shell Sort Algorithm
	for (step = 0; sequence[step] >= 1; step++)
	{
		incrementer = sequence[step];

		for (stepIncrementer = start + incrementer; stepIncrementer <= stop; stepIncrementer++)
		{
			comparisonIndex = stepIncrementer;
			temp = classArray[stepIncrementer];

			while ((comparisonIndex >= start + incrementer) && temp < classArray[comparisonIndex - incrementer])
			{
				count++;
				classArray[comparisonIndex] = classArray[comparisonIndex - incrementer];
				comparisonIndex -= incrementer;
			}
			swap++;
			classArray[comparisonIndex] = temp;
		}
	}
}

void AssortedSorter::quickSort(int inputArray[], int arraySize, long& count, long& swap)
{
	int index;
	int pivot;

	int stack[20001]; //Maximum size of array this function can sort
	int currentStackPosition = 0;
	int start = 0;
	int stop = arraySize - 1;

	count = 0; //Keeps track of how many iterations of the inner for loop occur
	swap = 0; //Keeps track of how many times two values swap places in the array

	//Copys input array to array in class
	for (index = 0; index < arraySize; index++)
	{
		classArray[index] = inputArray[index];
	}

	//Quick Sort Algorithm
	stack[currentStackPosition++] = start;
	stack[currentStackPosition++] = stop;

	while (currentStackPosition > 0)
	{
		stop = stack[--currentStackPosition];
		start = stack[--currentStackPosition];

		if (start >= stop) continue;

		//Creates a pivot location where all the values to the left of the pivot are smaller than the pivot value
		//and all the values to the right of the pivot are larger than the pivto value
		pivot = partition(classArray, start, stop, count, swap);

		if (pivot - start > stop - pivot)
		{
			stack[currentStackPosition++] = start; stack[currentStackPosition++] = pivot - 1;
			stack[currentStackPosition++] = pivot + 1; stack[currentStackPosition++] = stop;
		}
		else {
			stack[currentStackPosition++] = pivot + 1; stack[currentStackPosition++] = stop;
			stack[currentStackPosition++] = start; stack[currentStackPosition++] = pivot - 1;
		}
	}
}

//Creates a pivot location where all the values to the left of the pivot are smaller than the pivot value
//and all the values to the right of the pivot are larger than the pivto value
int AssortedSorter::partition(int array[], int start, int stop, long& count, long& countSwap)
{
	int up = start;
	int down = stop - 1;
	int part = array[stop];

	if (stop <= start)
		return start;
	while (true)
	{
		while (array[up] < part)
		{
			count++;
			up++;
		}
		while ((part < array[down]) && (up < down))
		{
			count++;
			down--;
		}
		if (up >= down)
		{
			break;
		}
		countSwap++;
		swap(array[up], array[down]);
		up++;
		down--;

	}
	countSwap++;
	swap(array[up], array[stop]);
	return up;
}

