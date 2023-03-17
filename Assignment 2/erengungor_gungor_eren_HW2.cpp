//Eren Güngör
//29465
//Lab Section C2
//Homework1 with VS2012

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

struct node
{
	char ch;	//stores one character of a word
	node* next;		//points to the next node in the linked list

	node() //Default constructor
	{
		next = NULL;
		ch = ' ';
	}
	
};

void openFile(ifstream& inFile, int fileNum, node*& head);
void createLinkedList(ifstream& inFile, node*& head);
void returnFullWord(node*& head);
int checkSim(node*& head1, node*& head2);
void clearLinkedlist(node*& head);
void deleteLetter(node*& head, char letterToDelete, int whichList);
string insertLetter(node*& head, char letterToAdd, char letterNextTo, int whichList);

int main()
{
	ifstream inFile1, inFile2;
	node* head1; //head of the linkedlist1
	head1 = new node;
	node* head2; //head of the linkedlist2
	head2 = new node;
	string input;
	char letterToDelete, letterToAdd, letterNextTo;

	openFile(inFile1, 1, head1); //open first file
	openFile(inFile2, 2, head2); // open second file
	cout << "List1: ";
	returnFullWord(head1);
	cout << endl << "List2: ";
	returnFullWord(head2);
	cout << endl;

	while ("exit" != input)
	{
		cout << endl << "Enter a command and its corresponding argument(s), if any: ";
		cin >> input;

		if ("sim" == input)
		{
			cout << "Displaying the contents of the two lists: " << endl;
			cout << "List1: ";
			returnFullWord(head1);
			cout << endl << "List2: ";
			returnFullWord(head2);
			cout << endl;
			cout << "There is/are " << checkSim(head1, head2) << " matched in the same positions in both lists." << endl;
		}
		else if ("del" == input.substr(0, input.length() - 1))
		{
			int whichList = input[input.length() - 1] - '0';
			cin >> letterToDelete;
			if (islower(letterToDelete)) //check for case sensitivity
			{
				if (1 == whichList)
					deleteLetter(head1, letterToDelete, whichList);
				else if (2 == whichList)
					deleteLetter(head2, letterToDelete, whichList);
				else
					cout << "Invalid command." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				cout << "Invalid arguments." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		else if ("insert" == input.substr(0, input.length() - 1))
		{
			int whichList = input[input.length() - 1] - '0';
			cin >> letterToAdd >> letterNextTo;
			if (islower(letterToAdd) && islower(letterNextTo)) //check for case sensitivity
			{
				if (1 == whichList)
					insertLetter(head1, letterToAdd, letterNextTo, whichList);
				else if (2 == whichList)
					insertLetter(head2, letterToAdd, letterNextTo, whichList);
				else
					cout << "Invalid command." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				cout << "Invalid arguments." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		else 
		{ 
			cout << "Invalid command." << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	//Means user tpyed "exit"; clear the linkedlists and exit program.
	clearLinkedlist(head1);
	clearLinkedlist(head2);
	cout << "Clearing the two lists and saying Goodbye!" << endl;

	return 0;
}

//Open the file with given (appropriate) file name.
void openFile(ifstream& inFile, int fileNum, node*& head)
{
	string filename;
	inFile.open(filename.c_str());
	while (inFile.fail())
	{
		cout << "Please enter the file " << fileNum << "  name: ";
		cin >> filename;
		inFile.open(filename.c_str());
	}

	createLinkedList(inFile, head);

	inFile.close();
}

//Read the file and create linked list with each read letter.
void createLinkedList(ifstream& inFile, node*& head)
{
	node* p = head;
	//read the letter from file
	char letter;

	while (inFile >> letter)
	{
		//create linkedlist
		p->ch = letter;
		p->next = new node;
		p = p->next;
	}
}

//utilize "sim" command and find the number of similar letters
int checkSim(node*& head1, node*& head2)
{
	int ct = 0; //increases by similarity
	node* p = head1;
	node* q = head2;
	while (' ' != p->ch && ' ' != q->ch) //while there exists at least one element in the both lists, otherwise return zero defaultly.
	{
		if (p->ch == q->ch)
		{
			ct++;
		}
		p = p->next;
		q = q->next;
	}
	return ct;
}

//Return a linkedlist as a full word,
void returnFullWord(node*& head)
{
	node* p = head;
	while (NULL != p)
	{
		cout << p->ch;
		p = p->next;
	}
}

//Clear a linkedlist
void clearLinkedlist(node*& head)
{
	node* p = head;
	while (NULL != head)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

//Delete letter given by the user in the linkedlist specified by the user.
void deleteLetter(node*&head, char letterToDelete, int whichList)
{
	bool isThereLetter = false;		//checks if the letter exists in the linkedlist
	node* p = head; //keeps track of each step
	node* prev = head; //follows p
	node* temp;
	while (NULL != p)
	{
		if (NULL != p->next)
		{
			if (letterToDelete == p->ch)
			{
				isThereLetter = true;
				temp = p->next;
				if (p == head)
				{
					head = temp;
				}
				else
				{
					prev->next = temp;
				}
				delete p;
				p = temp;
			}
			else
			{
				prev = p;
				p = p->next;
			}
		}
		else
		{
			if (letterToDelete == p->ch)
			{
				prev->next = p->next;
				delete p;
			}
			p = p->next;
		}
	}
	//Check if any character is deleted or not, and return response accordingly.
	if (false == isThereLetter)
	{
		cout << "No deletion as the value " << letterToDelete << " was not found in the list" << endl;
	}
	else
	{
		cout << "Deleting all occurrences of " << letterToDelete << " in List" << whichList << "." << endl;
		cout << "The current content of List" << whichList << " is: ";
		returnFullWord(head);
		cout << endl;
	} 
}

//Inserts a letter after another letter (if exists), or to the beginning depending on user input.
string insertLetter(node * &head, char letterToAdd, char letterNextTo, int whichList)
{
	bool letterFound = false;
	node* p = head;
	node* newnode = new node; //node to add
	newnode->ch = letterToAdd;

	while (NULL != p)
	{ 
		if (letterNextTo == p->ch)
		{
			letterFound = true;
			newnode->next = p->next;
			p->next = newnode;
			cout << "Inserting " << letterToAdd << " after " << letterNextTo << " in List" << whichList << "." << endl;
			cout << "The node with "  << letterToAdd << " has been inserted after the first occurrence of a node with " << letterNextTo << " value." << endl;
			cout << "The current content of List" << whichList << " is: ";
			returnFullWord(head);
			cout << endl;
			return "";
		}
		p = p->next;
	}
	if (!letterFound)
	{
		newnode->next = head;
		head = newnode;
		cout << "Inserting " << letterToAdd << " after " << letterNextTo << " in List" << whichList << "." << endl;
		cout << "The node with " << letterNextTo << " value does not exist.Therefore, Inserting " << letterToAdd << " at the beginning of the list." << endl;
		cout << "The current content of List" << whichList << " is: ";
		returnFullWord(head);
		cout << endl;
		return "";
	}
	return "";
}