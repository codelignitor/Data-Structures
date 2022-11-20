#include<iostream>
using namespace std;

class node{
public:
	int info;     
	node *next;
};

class SinglyLinkedList{
		node *head,*current,*temp;
	public:		
		SinglyLinkedList(){
			head=NULL;
			current=NULL;
			temp=NULL;
			
		}
		
		void is_empty(){
			if(head == NULL){
				cout<<"list is empty \n";
				return;
			}
		}
		
	void insert()
	{
		if (head == NULL)
		{
			
			head=new node;
			cout<<"Enter the value: ";
			cin>>head->info;
			head->next=NULL;
			current=head;
			return;
		}
		while (current->next!=NULL)
		{
			current=current->next;
		}
			temp=new node;
			cout<<"Enter new value: ";
			cin>>temp->info;
			temp->next=NULL;

			current->next=temp;
			return;
	}
	
	void insert_middle(){
		
		is_empty();
		int pos,val;
		
		cout<<"Enter position to insert:";
		cin>>pos;
		cout<<"Enter value to insert: ";
		cin>>val;
		
		node *temp = new node();
		temp->info=val;
		
		if(pos < 1){
			cout<<"invalid position given from user. \n";
			return;				
		}
		else if(pos == 1){
			temp->next  = head;
			head = temp;
		}
		else{
			node *current = head;
			for(int i = 1; i<=pos -1;i++){
				current = current->next;
			}
			node *temp = new node();
			temp->info= val;
			temp->next = current->next;
			current->next = temp;
		}
		
	}
	
	int searching(){
		
		is_empty();
		int val;
		
		cout<<"Enter value to search: ";
		cin>>val;
		
		temp=head;
		while(temp!=NULL){
			if(temp->info == val){
				cout<<"found";
				return 1;
			}
			temp = temp->next;
		}
		
	}
	
	void del()
	{
		int key;
		node *temp1; 
		if(head==NULL){
			cout<<"List have no node";
			return;
		}
		cout<<"Give delete key: ";
		cin>>key;
		temp=head;
		while(temp->next!= NULL){
			if(temp->next->info == key ){
				temp1 = temp->next;
				temp->next = temp1->next;
				temp1->next= NULL;
				delete temp1;
			}
			temp=temp->next;
		}
		//cout<<endl;
	}
	
	
	void print()
	{
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->info<<"->";
			temp=temp->next;
		}
	}
	
};

int main()
{
		
	SinglyLinkedList L1;
	
	L1.insert();
	L1.insert();
	L1.insert();
	L1.insert();
	L1.print();

	cout<<endl;
	L1.del();
	L1.print();
	
//	cout<<endl;
	L1.insert_middle();
	L1.print();
	
//	cout<<endl;
//	L1.searching();
	return 0;
	
}
