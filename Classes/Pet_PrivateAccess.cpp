#include <iostream>
#include <string>
using namespace std;

//Pet is the base class
class Pet
{
public:
    // Constructors, Destructors
    Pet(): weight(1), food("Pet Chow") {}
    ~Pet() {}

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

//protected:
private:  
    int weight;
    string food;
//friend class Cat;
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
	Rat() {}
    ~Rat() {}

    //Other methods
    void sicken() {cout << "Speading Plague" << endl;}

};

class Cat: public Pet
{
public:
    Cat() : numberToes(5) {}
    ~Cat() {}

    //Other methods
    void setNumberToes(int toes) {numberToes = toes;}
    int getNumberToes() {return numberToes;}
	
	//does not compile as long as weight is private in Pet class
	//Solution1: change the private: label as protected: in Pet class
	//Solution2: change the growCat's definition as follows so that it uses existing accessors/mutators
	//	    void growCat() {
	//		int current = getWeight();
	//		setWeight(++current);}
	//Solution3: declare class Cat as friend in class Pet
	void growCat() {weight++;}

private:
    int numberToes;
};


int main()
{
    Cat fluffy;

	fluffy.setWeight(5);
    cout << "Fluffy weighs " << fluffy.getWeight() << " kilos." << endl;
	fluffy.growCat(); 
	cout << "Fluffy grows and now weighs " << fluffy.getWeight() << " kilos." << endl;

    return 0;
}
