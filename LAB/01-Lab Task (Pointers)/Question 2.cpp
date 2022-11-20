#include <iostream>

using namespace std;

int main(){
	
	int *a = new int;
	cout<<"enter value of dynamic integer: ";
	cin>>*a;
	
	cout<<"value of dynamic integer = "<<*a<<endl;
	cout<<"Address of dynamic integer = "<<&a;
	
	delete a;
	
	return 0;
	
}
