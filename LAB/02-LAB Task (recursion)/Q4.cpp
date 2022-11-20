#include <iostream>
using namespace std;

char el_fish(string word){
	
	int i =0;
	if (word[i] == 'e' && word[i] == 'l' && word[i] == 'f'){
		cout<<"the word is elfish ";
		return 0;
	}
	else
	{
		cout<<"it's not elfish";
		i++;
	}
	
}

int main(){
	
	string word;
	cout<<"Enter word: ";
	cin>>word;
	cout<<el_fish(word);
	
	return 0;
}

