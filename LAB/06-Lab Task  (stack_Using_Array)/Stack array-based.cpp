#include<iostream>
using namespace std;


class Stack_Array{
	
	int top;
	
public:
	
	int Stk_Array[10];        //array max_size=10
	
	Stack_Array() 
	{ 
		top = -1;
	}


	bool isEmpty()				//stack empty or not
	{
		return (top < 0);
	}

	int push(int value) 		
	{
		if (top >= (10-1)) {			//
		cout << "Stack Overflow!";
		return 1;
		}
		else{
			Stk_Array[++top] = value;
			cout<<value<<endl;
   			return 1;
   		}
	}
  
	int pop()
	{
		if (top < 0) {
		cout <<"Stack Underflow!";
      	return 0;
   		}
		else {
			int value = Stk_Array[top--];
      		return value;
   		}
	}

	void print(){
		while(!isEmpty())
		{	
			cout<<pop()<<endl;
		}
	}
	
};
     
int main()
{
	Stack_Array s1;
	cout<<"The Stack Push "<<endl;
	s1.push(2);
	s1.push(4);
	s1.push(6);
	
	cout<<"The Stack Pop : "<<endl;
	s1.print();
	return 0;
}
