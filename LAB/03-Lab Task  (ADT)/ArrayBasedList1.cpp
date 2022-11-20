//  *****Array  data-structure implementation **** 
#include <iostream>
using namespace std;


class ArrayBasedList{
	private:
		int *arr; 
		int *curr,*head, len ,size;
		
	public:
		ArrayBasedList()
		{
			head = NULL;
			//arr = NULL;
			curr = NULL;
			len = 0;
			size = 8;
			arr =new int[size];

		}
		
		void start()
		{
			
			curr = head;
		}
		
		void end(){
			
			for(int i=1; i < len; i++)
			{
				next();						//curr++;
			}
		}
		
		void next(){
			curr++;
		}
		
		void back(){
			curr--;
		}
				
		void create_list(int size){
			arr = new int[size]; 			// max_size = 8
			
			for(int i=0; i < size; i++)
			{
				arr[i]=0;
			}
			head = arr;
			start();
			
		}
		
		int get(int pos){
			
			start();
			for(int i =1; i< pos ; i++)
			{
				next();
			}
			cout<<endl<<"Get no. at position is "<<*curr;
		}
		
		void clear(){
			
			start();
			for(int i=1; i<size; i++)
			{
				*curr=0;
				next();
			}
			//curr = NULL;
			//head = NULL;
		}
	
		void add(int val){					//simple insertion at position next to prev
			
			if(len == 0){
				curr=head;
				
				*curr = val;
				len++;
				next();
			}
			else{
				curr = head;
			    curr = curr + len;
				*curr = val;
				len++;
			}
					
			//start();
		}
		
		void insert(int val, int pos){
			
			if(len >= size){						//max_size = 8
				cout<<"Array is already Full";
				return;
			}
			
			end();											// to take current ptr at last value
			for (int i=(len - 1); i >= pos; i--)
			{
				*(curr +1) = *curr;
				back();
			}	
			
			*(curr +1)= val;
			start();
			len++;
		}
		
		void remove(int pos){
			
			if (pos > len)
			{	
				cout<<"Deleting at position(out of the size)";
				return;
			}
			if (len == 0){
				cout<<" Array is already Empty";
				return;
			}
			
			
			for(int i = 1; i<len;i++){
				next();
				if(i == pos){
					*curr = *(curr +1);
					next();
				}
				len--;
			}
			
		}
		
		void update(int pos, int key)
		{
			start();
			curr = curr + pos;
			*curr = key;
		}
		
		int length()
		{	
			int count=0;
			start();
			int *temp =head;
			temp = temp + len;
			while(curr != temp){
				count++;
				next();
			}
			cout<<" length = "<<count<<endl;
		}
		
		
		void find(int val){
			
			if(len == 0){
				cout<<"Array is empty(can't find anything)";
				return;
			}
			start();
			
			for(int i = 1; i < len; i++){
				if(*curr == val)
				{
					cout<<val<<": found in the list";
					return;
				}
				else
				{
					next();
				}
			}
			
			//start();
		}
		
		void display()
		{	
			int *temp;
			temp = head;
			for(int i=0; i<size ; i++)
			{
				cout<<*temp<<" ";
				temp++;
			}
		}
		
};

int main(){
	
	ArrayBasedList A1;
	A1.create_list(8);
	A1.add(1);
	A1.add(2);
	A1.add(3);
	A1.add(4);
	A1.add(5);
	A1.add(6);
	A1.display();
	//A1.length();
	cout<<"\nAfter-Updadtion:\n";
	A1.update(3,7);
	A1.display();	
	
//	A1.get(1);
	cout<<"\nInsertion at Middle:\n";
	A1.insert(8,3);
	A1.display();

	cout<<"\nRemove"<<endl;
	A1.remove(2);
	A1.display();
	cout<<"\n";
	A1.find(5);
	
	return 0;
}
