#include <iostream>
using namespace std;

void reverse(string str)  
{  
	int i=0;
	if(str.size() == 0) 
        return;
	else if (str[i] == ' '){
        str = "";
    }
    else{
        str += str[i];
		reverse(str.substr(1)); 
    	cout << str[0]; 
	}
	i++;  
}

int main()  
{  
    string a = "Cat isrunning";  
    reverse(a);  
    return 0;  
}  
