#include <iostream>
using namespace std;

int Factorial(int N){
	
	if(N == 1) 		// base condition
		return N;
	return N * Factorial(N-1);
}

int main(){
	
	int num;
	cout<<"Enter number to calculate Factorial: ";
	cin>>num;
	cout<<"Factorial of "<<num <<" is "<<Factorial(num);
	
	return 0;
}
