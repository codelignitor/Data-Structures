
/* SinglyCircular List in String*/

#include<iostream>
using namespace std;

struct node{
    string data;
    node *next;
};

class SinglyCircularLinkList{
    private:
        node* head;
    public:
    	
    	char A[7];
        SinglyCircularLinkList(){
            head = NULL;
            int index = 7;
        }

        node* create_node(string info){						//node *temp= new node; temp->data=data;
            node* link_node = new node();
            link_node->data = info;
            return link_node;
        }
												// insertion at last_node	
        void add_node_to_tail(string info){
            if (head == NULL){
                head = create_node(info);
                head->next = head;
                return;
            }
            node* tail = get_tail();
            node* link_node = create_node(info);
            link_node->next = head;// tail->next;
            head = link_node;
            tail->next = head;
        }

        node* get_tail(){
            node* iter = head;
            while(iter->next != head){
                iter = iter->next;
            }
            return iter;
        }

        void print(){
            node* iter = head;
            if (head == NULL) return;
            do{
                cout<<iter->data<<" ";
                iter = iter->next;
            }
            while(iter != head);
            cout<<endl;

        }

        node* search_node(string key){
            node* iter = head;
            while(iter->data !=key){
                iter = iter->next;
                if (iter == head) return NULL;
             }
             return iter;
        }
														//insertion at value given
        void insert_at_value(string info, string key){
            if (head == NULL) return;
            node* search = search_node(key);
            node* link_node = create_node(info);
            link_node->next = search->next;
            search->next = link_node;

        }

        node* get_prev(node* random_node){
            node* temp_iter = head;
            if (random_node==NULL)
                    return NULL;
            if (random_node==head)return head;
            while(temp_iter->next!=random_node){
                temp_iter=temp_iter->next;
            }
            return temp_iter;
        }
        
        void result()
        {
        	cout<<endl;
        	node* temp = head;
        	if(head != NULL)
        	{
        		cout<<temp->data;
        		
        		//A[index++] = temp->data;
			}
        	
		}
        
        void  delete_node(string key){
            node* del_node = search_node(key);
            node* tail = get_tail();
            node * prev = get_prev(del_node);
            if (del_node == head){
                tail->next = del_node->next;
                if(head->next==head)head=NULL;
                else head = head->next;

                delete del_node;
                del_node = NULL;
            }
            else {
                prev->next = del_node->next;
                delete del_node;
                del_node = NULL;
            }
        }

};
int main(){

    SinglyCircularLinkList 	Ring;
    
	Ring.add_node_to_tail("is");

	Ring.add_node_to_tail("in");

    Ring.add_node_to_tail("bell");
    Ring.add_node_to_tail("aiopss");	
	Ring.add_node_to_tail("devops");
    Ring.print();
   // Ring.result();

  
    Ring.delete_node("bell");
    Ring.print();

}
