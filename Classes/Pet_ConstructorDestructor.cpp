#include <iostream>
#include <string>
using namespace std;

//Pet is the base class
class Pet
{
public:
    // Constructors, Destructors
    Pet(): weight(1), food("Pet Chow") 
	{
		cout << "Pet constructor called" << endl;
	}

    ~Pet() 
	{
		cout << "Pet destructor called" << endl;
	}

    //Accessors and mutators
    void setWeight(int w) {weight = w;}
    int getWeight() const
		{return weight;}

    void setfood(string f) {food = f;}
    string getFood() const
		{return food;}

    //General methods
    void eat();
    void speak();

protected:
    int weight;
    string food;

};

void Pet::eat()
{
    cout << "Eating " << food << endl;
}

void Pet::speak()
{
    cout << "Growl" << endl;
}

class Rat: public Pet
{
public:
	Rat() : Pet()
	{
		cout << "Rat constructor called" << endl;
	}

    ~Rat() 
	{
		cout << "Rat destructor called" << endl;
	}


    //Other methods
    void sicken() {cout << "Speading Plague" << endl;}

};

class Cat: public Pet
{
public:
    Cat() : numberToes(5) 
	{
		cout << "Cat constructor called" << endl;
	}

    ~Cat() 
	{
		cout << "Cat destructor called" << endl;
	}


    //Other methods
    void setNumberToes(int toes) {numberToes = toes;}
    int getNumberToes() {return numberToes;}

private:
    int numberToes;
};


int main()
{
    Rat charles;
    Cat fluffy;

    return 0;
}
