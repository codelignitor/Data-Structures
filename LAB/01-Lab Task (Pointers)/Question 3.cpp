
# include <iostream>

using namespace std;

int main(){
	
	int size;
	char *ptr=NULL;
	cout<<"enter size of array: ";
	cin>>size;
	
	char *array= new char[size];
	ptr = array;	
	
	for (int i=0; i < size ;i++){
		cin>>array;
		ptr++;
	}
	
	for (int i=0 ; i< size; i++){
			ptr--;		
	}
	cout<<"elements of array"<<array<<endl;
	
}
