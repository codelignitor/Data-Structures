# include <iostream>

using namespace std;

int main(){
	
	char a,b, *ptrA= NULL, *ptrB=NULL;
	cout<<"Enter Char for a: ";
	cin>>a;
	cout<<"Enter char for b: ";
	cin>>b;
	
	ptrA = &a;
	ptrB = &b;
	
	cout<<"Address of the variables (a & b) :"<<(void*)ptrA<<"   "<<(void*)ptrB<<endl;
	cout<<"Values of (a & b): "<<*ptrA<<" "<<*ptrB<<endl;
	
	cout<<"Addresses of pointers(ptrA & ptrB) :"<<&ptrA<<"  "<<&ptrB<<endl;
	
	return 0;
	
	
}

