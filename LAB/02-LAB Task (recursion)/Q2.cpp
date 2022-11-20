#include <iostream>
using namespace std;

int natural_num(int N){
	
	
	if (N == 0){
	//	cout<< N;
		return N;
	}
	else
		return N + natural_num(N-1);
}

int main(){
	
	int num;
	cout<<"Enter number to calculate Sum of Natural numbers: ";
	cin>>num;
	cout<<"Sum of Natural Numbers upto "<<num <<" is: "<<natural_num(num);
	
	return 0;
} 



