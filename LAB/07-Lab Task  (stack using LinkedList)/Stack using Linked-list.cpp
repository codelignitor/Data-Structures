#include <iostream>
using namespace std;


class Node { 
public:	
	int data; 
	Node *next; 
	
	Node(){
		data=0;
		next=NULL;
	}
};


class Stack{
	Node* top = NULL;
			
public:
	
	void push(int val) {
   		Node* temp = new Node(); 
		temp->data = val; 
		temp->next = top; 
		top = temp;
	}

	void pop() {
   		if(top==NULL)
      		cout<<"Stack Underflow"<<endl;
   		else 
		{
      		cout<<"The element at top of the stack is "<< top->data <<endl;
      		top = top->next;
   		}
	}

	void display() {
   		Node* tmp;
   		if(top==NULL)
      		cout<<"Stack is Empty";
   		else 
		{   
			//cout<<"current "<<current<<endl;
      		tmp = top; 
      		cout<<"Stack elements are: ";
      		while (tmp != NULL) { 
         		cout<< tmp->data <<" "; 
         		tmp = tmp->next; 
      		}	 
   		}
   		cout<<endl;
	}
	
}; 
 
int main(){
	
	Stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
//	s1.pop();
//	s1.pop();
//	s1.pop();
	s1.display();
}


