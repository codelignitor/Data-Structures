/*

Q#1 Let’s say you have a linked list. You swap the left side element from the right side.
In order to determine the left and right you need to find the midpoint of the linked list.
Example:
Input List: 1->2->3-4>-5>6->7->8->9
Midpoint: ceil(total-length/2) = ceil(9/2) = 5
Output: 6->7->8->9->5->1->2->3-4
*/

#include <iostream>
using namespace std;

class node{
	public:
		int info;
		node *next;
};

class SinglyLinkedList{
	node *head,*current,*temp;
	int len;
	int cell;
	
	public:
		SinglyLinkedList(){
			head = NULL;
			temp = NULL;
			len = 0;
		}
		
		void add(){
			if(head == NULL){
				head = new node;
				cout<<"Enter value: ";
				cin>>head->info;
				head->next = NULL;
				current = head;
				len++;
				return;
			}
			
			while(current->next != NULL){
				current = current->next;
			
			}
			
			temp = new node;
			cout<<"Enter value: ";
			cin>>temp->info;
			temp->next = NULL;
			current->next = temp;
			len++;
			return;
		}
		
		
		void print(){
			if(head == NULL){
				cout<<"List is empty";
				return;
			}
			temp = head;
			while(temp != NULL){
				cout<<temp->info<<" ";
				temp = temp->next;
				//len++;
			}
			cout<<endl;
			cout<<"length: "<<len<<"\n";
		}
		
		void midpoint(){
			
			cell=len/2;
		}
		
		void swap(){
			int count = 0;
			node *temp2,*temp1;
			temp=temp1=temp2=head;
			while(count!=cell)
			{
				temp=temp->next;
				count++;
			}
			count = 0;
			temp2=temp->next;
			while(count != cell)
			{
				int x=temp1->info;
				temp1->info=temp2->info;
				temp2->info=x;
				temp1=temp1->next;
				temp2=temp2->next;
				count++;
			}
			
		}
};

int main(){
	
	SinglyLinkedList s1;
	s1.add();
	s1.add();
	s1.add();
	s1.add();
	s1.add();
	s1.add();
	s1.add();
	s1.add();
	s1.add();
	s1.print();
	s1.midpoint();
	s1.swap();
	s1.print();
	return 0;
}
