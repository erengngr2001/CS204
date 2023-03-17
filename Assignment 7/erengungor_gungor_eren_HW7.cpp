//Eren Güngör
//29465
//Lab Section C2
//Homework7 with VS2012

#include <random> 
#include <time.h>
#include <mutex>
#include "erengungor_gungor_eren_HW7_HW7PrintQueue.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void printingFunc(HW7PrintQueue& dynQueue);
void jobFunc(HW7PrintQueue& dynQueue, const int userNumber);
//string returnClock();

mutex coutMutex; //mutex for displaying an event on screen
mutex jobMutex; //mutex for ordering user and printer jobs
int minPages; //minimum pages to be printed
int maxPages; //maximum pages to be printed
int minWaitTime; //minimum waiting time for users
int maxWaitTime; //maximum waiting time for users
int maxPrintJobNumber; //states how many pages will be printed
int id = 1; //order of the job, i.e. id(th) element
int printingOrder = 1; //id number for printer jobs

//generates random number in the interval
int random_range(const int& min, const int& max)
{
	static mt19937 generator(time(0)); uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}

int main()
{
	//int enlistedJobs = 0;
	HW7PrintQueue dynQueue; //dynamic job queue
	thread user1, user2, user3, printer;
	cout << "Please enter the max number of print jobs: ";
	cin >> maxPrintJobNumber;
	cout << "Please enter the min and max values for the waiting time period (in seconds) after creating a print job:" << endl;
	cout << "Min: "; cin >> minWaitTime;
	cout << "Max: "; cin >> maxWaitTime;
	cout << "Please enter the min and max values for the number of pages in a printing job:" << endl;
	cout << "Min number of pages: "; cin >> minPages;
	cout << "Max number of pages: "; cin >> maxPages;

	time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
	struct tm* ptm = new struct tm;
	localtime_s(ptm, &tt);
	cout << "Simulation starts " << put_time(ptm, "%X") << endl;
	user1 = thread(&jobFunc, ref(dynQueue), 1);
	user2 = thread(&jobFunc, ref(dynQueue), 2);
	user3 = thread(&jobFunc, ref(dynQueue), 3);
	printer = thread(&printingFunc, ref(dynQueue));

	user1.join();
	user2.join();
	user3.join();
	printer.join();

	return 0;
}

//allows the users to work in a loop until given number of jobs are enqueued, keeps the users waiting after enqueueing and at the beginning
void jobFunc(HW7PrintQueue & dynQueue, const int userNumber)
{
	this_thread::sleep_for(chrono::seconds(random_range(minWaitTime,maxWaitTime)));
	while (maxPrintJobNumber >= id)
	{
		jobMutex.lock();
		if (maxPrintJobNumber >= id)
		{
			int randomPage = random_range(minPages, maxPages);
			dynQueue.enqueue(id, randomPage);
			id++;
			coutMutex.lock();
			time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
			struct tm* ptm = new struct tm;
			localtime_s(ptm, &tt);
			jobMutex.unlock();
			cout << "User " << userNumber << " sent new print job with ID " << printingOrder << " sent to the printer queue, number of pages: " << randomPage << " (print queue size: " << dynQueue.getCurrentSize() << ")  " << put_time(ptm, "%X") << endl;
			printingOrder++;
			coutMutex.unlock();
			this_thread::sleep_for(chrono::seconds(random_range(minWaitTime, maxWaitTime)));
		}
		else
			jobMutex.unlock();
	}
}

//allows the printer to do the printing job until it reaches the max number of jobs given by the users, and dequeues until the list is empty at last
void printingFunc(HW7PrintQueue &dynQueue)
{
	//bool flag = true;
	int donePrintingJobs = 0, printid, printedpage;
	while (donePrintingJobs != maxPrintJobNumber)
	{
		jobMutex.lock();
		if (!dynQueue.isEmpty())
		{
			dynQueue.dequeue(printid, printedpage);
			coutMutex.lock();
			time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
			struct tm* ptm = new struct tm;
			localtime_s(ptm, &tt);

			cout << "The printer started to print the job with ID: " << printid << ", number of pages: " << printedpage << "(queue size is: " << dynQueue.getCurrentSize() << ")  " << put_time(ptm, "%X") << endl;
			coutMutex.unlock();
			this_thread::sleep_for(chrono::seconds(printedpage));
			coutMutex.lock();
			cout << "The printer finished printing the job with ID: " << printid << ", number of pages: " << printedpage << "  " << put_time(ptm, "%X") << endl;
			coutMutex.unlock();

			donePrintingJobs++;
		}
		jobMutex.unlock();
	}
	coutMutex.lock();
	time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
	struct tm* ptm = new struct tm;
	localtime_s(ptm, &tt);
	cout << "End of the simulation ends  " << put_time(ptm, "%X") << endl;
	coutMutex.unlock();
}
