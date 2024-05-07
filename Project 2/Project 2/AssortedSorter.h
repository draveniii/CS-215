#ifndef ASSORTEDSORTER_H
#define ASSORTEDSORTER_H

class AssortedSorter
{
private:
	static const int INTARRAYMAXSIZE = 20001;
	int classArray[INTARRAYMAXSIZE];
	int currentArraySize;
public:
	void bubbleSort(int[], int, long&, long&);
	void selectionSort(int[], int, long&, long&);
	void shellShort(int[], int[], int, long&, long&);
	void quickSort(int[], int, long&, long&);
	int partition(int[], int, int, long&, long&);
};

#endif // ASSORTEDSORTER_H 