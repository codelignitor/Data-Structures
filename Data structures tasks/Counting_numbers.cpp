#include <iostream>
using namespace std;

int count_number(string str, char key){
	int count =0;
	int index=0;
	
	while(str[index] != 0){
	
		if(str[index]== key){
			index++;
			count+=1;		//count = count +1
			
		}
		else
			index++;
	}
	cout<<count;
}


int main(){
	
	count_number("2020145666",'6');
}
