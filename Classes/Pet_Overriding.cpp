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
    virtual void speak();  //if you do not use virtual here, it seems everything is OK,
						   //but it would not be real overriding, it is kind of overloading; you just hide Pet's speak in derived classes.

protected:
    int weight;
    string food;

};

void Pet::eat()
{
    cout << "Eating " << food << endl;
}

void Pet::speak ()
{
    cout << "Growl" << endl;
}

class Rat: public Pet
{
public:
	Rat() {}
    virtual ~Rat() {}

    //Other methods
    void sicken() {cout << "Speading Plague" << endl;}
	void speak();   
	            //if Pet's speak is not virtual, you can change the return type, parameters and const/non-const  
			    //of this function without any problem, but this does not mean that you are overriding; 
	            //in such a case, you actually overload the function and hide the base class (Pet) speak func.
				
			    //On the other hand, if Pet's speak is virtual, changing the return type of speak in derived class 
				//(by keeping parameters the same) causes a compiler error. 
				//If Pet's speak is virtual, changing the parameters and const/non-const
				//does not cause an error, but again this is not overriding, but just hiding the Pet's speak in derived class

};

void Rat::speak()
{
    cout << "Rat noise" << endl;
}

class Cat: public Pet
{
public:
    Cat() : numberToes(5) {}
    ~Cat() {}

    //Other methods
    void setNumberToes(int toes) {numberToes = toes;}
    int getNumberToes() {return numberToes;}
	void speak();

private:
    int numberToes;
};

void Cat::speak()
{
    cout << "Meow" << endl;
}

int main()
{
	Pet peter;
	Rat ralph;
	Cat chris;

	peter.speak();
	ralph.speak();	
	chris.speak(); 

    return 0;
}
