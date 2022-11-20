
#include<iostream>
using namespace std;


class node{
	public:
		int key;
    	node* left;
    	node* right;
    	int count;
    	node(){
    		key=0;
    		count=0;
    		left=right=NULL;
		}
};

class BST {
	public:
		node* root;
		node* pos;
		
    	node* Empty(node* pos) {
        	if(pos == NULL)
            	return NULL;
        	else
			{	
            	Empty(pos->left);
            	Empty(pos->right);
            	delete pos;
        	}
        	return NULL;
    	}
	
	

    node *insert(int val, node* pos)
    {
        if(pos == NULL)
        {
            pos = new node;
            pos->key = val;
            pos->left = pos->right = NULL;
        }
        else if(val < pos->key)
            pos->left = insert(val, pos->left);
        
		else if(val > pos->key)
            pos->right = insert(val, pos->right);
        
		if (val == pos->key)
		{
			(pos->count)++;
			
		}
		return pos;
    }

    node *findMin(node* pos)
    {
        if(pos == NULL)
            return NULL;
        
		else if(pos->left == NULL)
            return pos;
        
		else
            return findMin(pos->left);
    }
	
		 

   
    node *deleteNode(int val, node* pos) {
        node* temp;
        if(pos == NULL)
            return NULL;
        
		else if(val < pos->key)
            pos->left = deleteNode(val, pos->left);
        
		else if(val > pos->key)
            pos->right = deleteNode(val, pos->right);
        
		else if(pos->left && pos->right)
        {
            temp = findMin(pos->right);
            pos->key = temp->key;
            pos->right = deleteNode(pos->key, pos->right);
        }
        else if (root->count > 1) 
        { 
           	(root->count)--; 
           	return root; 
        } 
		else
        {
            temp = pos;
            if(pos->left == NULL)
                pos = pos->right;
            else if(pos->right == NULL)
                pos = pos->left;
            delete temp;
        }

        return pos;
    }

    void inorder(node* pos) {
        if(pos == NULL)
            return;
        {
			inorder(pos->left);
       		cout << pos->key << " ";
        	inorder(pos->right);
    	}
	}
	
    void preorder(node* pos) {
        if(pos == NULL)
            return;
        {
        	cout << pos->key << " ";
			preorder(pos->left);
        	preorder(pos->right);
    	}
	}
	
	void postorder(node* pos) {
        if(pos == NULL)
            return;
        {
        	preorder(pos->left);
        	preorder(pos->right);
    		cout<<pos->key << " ";
		}
	}


    BST() {
        root = NULL;
    }

    ~BST() {
        root = Empty(root);
    }
	
	void insert(int val) {
        root = insert(val, root);
    }

    void deleteion(int val) {
        root = deleteNode(val, root);
    }

    void display() {
        cout<<"inorder Traversal"<<endl;
		inorder(root);
        cout<<"\nPre-order Traversal"<<endl;
		preorder(root);
		cout<<"\nPost-order Traversal"<<endl;
		postorder(root);
		cout<< endl<<endl;
		{
			cout<<"Duplicqate Appears =("<<root->count<<")\n";
		}
		
	}

};


int main() {
    BST T1;
	
    T1.insert(14);
    T1.insert(15);
    T1.insert(4);
    T1.insert(9);
    T1.insert(7);
    T1.insert(18);
    T1.insert(3);
    T1.insert(5);
    T1.insert(19);
    T1.insert(20);
	T1.display(); 
	T1.deleteion(18);
	T1.display();
	T1.deleteion(7);
	T1.display();
	  
    return 0; 
}
