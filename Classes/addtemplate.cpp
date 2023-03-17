#include <iostream>
#include <string>
using namespace std;

template <class OpType>
class Add
{
public:
	Add (OpType op1, OpType op2);
	OpType operand (int i) const; 
	OpType result () const;

private:
	OpType myOp1, myOp2;
};

template <class OpType>
Add<OpType>::Add (OpType a, OpType b)
	:myOp1(a), myOp2(b)
{}

template <class OpType>
OpType Add<OpType>::operand (int i) const
//pre: i = 1 or 2. 
//post: returns ith operand
{
	if (i==1)
		return myOp1;
	else if (i==2)
		return myOp2;
}

template <class OpType> 
OpType Add<OpType>::result () const
//post: returns result of addition
{
	return myOp1 + myOp2;
}



int main()
{
	Add<int> a(5, 12);
	cout << a.operand(1) << " + " << a.operand(2) 
		<< " = " << a.result() << endl;
	
	Add<string> b("cs", "204");
	cout << b.operand(1) << " + " << b.operand(2) 
		<< " = " << b.result() << endl;

	Add<char> c('2', '3');
	cout << c.operand(1) << " + " << c.operand(2) 
		<< " = " << c.result() << endl;

	return 0;

}