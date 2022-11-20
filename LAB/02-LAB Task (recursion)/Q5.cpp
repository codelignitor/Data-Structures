#include <iostream>
using namespace std;

int multiply(int a, int b){
	
	
	if(a == 0 || b == 0){
		return 0;
	}
	//Base Condition
	else if (b == 1){
		return b;
	}
	return  multiply(a -1, b) + b;
}

int main(){
	
	int a,b;
	cout<<"Enter input of a: ";
	cin>>a;
	
	cout<<"Enter input of b: ";
	cin>>b;
	
	cout<<"Multiple of "<<a <<" & "<<b<<" is "<<multiply(a,b);
	
	return 0;
}
