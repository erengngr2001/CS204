// This program demonstrates the IntQueue class
#include <iostream>
#include "IntQueue.h"
using namespace std;

int main()
{
	IntQueue iQueue(5);
	int value;

	cout << "Enqueuing items...\n";
	
	// Enqueue 5 items.
	for (int k = 1; k <= 5; k++)
		iQueue.enqueue(k*k);  
	
	iQueue.enqueue(100); //trying to enqueue to a full queue
		
	// Deqeue and retrieve all items in the queue.
	cout << "\nThe values in the queue were: ";
	while (!iQueue.isEmpty())
	{
		iQueue.dequeue(value);
		cout << value << "  ";
	}
	cout << endl;
	cout << "Trying to dequeue on an empty queue\n";
	iQueue.dequeue(value);  //queue is empty, dequeue should fail
	cout << value << endl;  //so what will print?

	return 0;
}