#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

class LinkedList
{
private:
	// Structure for the nodes
	struct ListNode
	{
		unsigned int sequenceNumber;
		std::string name;
		std::string serviceRequired;
		struct ListNode* next = nullptr; // Points to the next node
		int month;
		int day;
		int year;
		int hour;
		int minute;
	};

	// Keeps track of the total number of customers that have been checked in for the sequence number
	static unsigned int currentSequence;

	// List head pointer 
	ListNode* head; 

public:
	// Constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Linked List Methods
	void insertNode(std::string, std::string);
	LinkedList::ListNode* searchList(std::string);
	bool deleteNode();
	bool deleteNode(std::string);
	void listAll();
	unsigned int getSequenceNumber();
	void pad(std::string name, int maxDataLength = 16);
};

#endif
