#include <iostream>
using namespace std;


class User
{
	private:
		int id;		//id of user
		static int next_id;  //common to all instances, but this is not a definition
							 //this is just a prototype-like declaration
	public:
		User()		//constructs user instances starting from id number 1
		{				
			id = next_id;  //assigns next id to the next instance
			next_id++;     // and then increments
		}
		void print ()
		{
			cout << id << endl;
		}
};
int User::next_id = 1;		//this is definition and initialization

int main()
{
	User theusers[10];
	for (int i=0; i<10; i++)
	{
		theusers[i].print();
	}
	return 0;
}
	