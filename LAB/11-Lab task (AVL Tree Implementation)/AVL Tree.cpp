
#include<iostream>
using namespace std;
 

class node{
public:
	
    int data;
    node *left;
    node *right;
    int height;
    
	node(){
    	data=0;
    	height=0;
    	left=right=NULL;
	}
};
 
class avlTree
{
	node *root;
    public:
        
		//Height of AVL Tree

		int height(node *temp)
        {
		    int h = 0;
    		if (temp != NULL)
    		{
        		int l_height = height (temp->left);
        		int r_height = height (temp->right);
        		int max_height = max (l_height, r_height);
       			h = max_height + 1;
    		}
    		return h;
		}


		int diff(node *temp)						//Height Difference
		{
    		int l_height = height (temp->left);
    		int r_height = height (temp->right);
    		int bal_factor= l_height - r_height;
    		return bal_factor;
		}
		
		
		
		 node *lr_rotation(node *parent)			//left- Right Rotation
		{
    		node *temp;
    		temp = parent->left;
    		parent->left = rr_rotation (temp);
    		return ll_rotation (parent);
		}

        node *rl_rotation(node *parent)				//Right- left Rotation
		{
    		node *temp;
    		temp = parent->right;
    		parent->right = ll_rotation (temp);
    		return rr_rotation (parent);
		}
		
											
       node *rr_rotation(node *parent)				//Right- Right Rotation
		{
    		node *temp;
    		temp = parent->right;
    		parent->right = temp->left;
    		temp->left = parent;
    		return temp;
		}
		
		
        node *ll_rotation(node *parent)				//left- left Rotation
		{
    		node *temp;
    		temp = parent->left;
    		parent->left = temp->right;
   			temp->right = parent;
    		return temp;
		}
		

        node* getbalance(node *temp)				//Balancing AVL Tree
		{
    		int bal_factor = diff (temp);
    		
			if (bal_factor > 1)
    		{
        		if (diff (temp->left) > 0)
            		temp = ll_rotation (temp);
        		else
            		temp = lr_rotation (temp);
    		}
    		
			else if (bal_factor < -1)
    		{
        		if (diff (temp->right) > 0)
            		temp = rl_rotation (temp);
        		else
            		temp = rr_rotation (temp);
    		}
    		
			return temp;
		}
		
		
		node* findMin(node* root)
    	{
        	if(root == NULL)
            	return NULL;
        	
			else if(root->left == NULL)
            	return root;
        	
			else
            	return findMin(root->left);
    	}


        node* insert(node *root, int value)				//insertion of an AVL-tree
		{
    		if (root == NULL)
    		{
        		root = new node;
        		root->data = value;
        		root->left = NULL;
        		root->right = NULL;
        		return root;
    		}
    		
    		else if (value < root->data)
    		{
        		root->left = insert(root->left, value);
        		root = getbalance(root);
    		}
    		
			else if (value >= root->data)
    		{
        		root->right = insert(root->right, value);
        		root = getbalance(root);
    		}
    		
			return root;
		}
		
		node* remove(int val, node* root)
    	{
        	node* temp;
			
        	if(root == NULL)
            	return NULL;
			
        	
        	else if(val < root->data)
            	root->left = remove(val, root->left);
        	
			else if(val > root->data)
            	root->right = remove(val, root->right);
			
        	
        	
        	else if(root->left && root->right)
        	{
            	temp = findMin(root->right);
            	root->data = temp->data;
            	root->right = remove(root->data, root->right);
        	}
        	
        	
        	else
        	{
            	temp = root;
            	if(root->left == NULL)
                	root = root->right;
            	else if(root->right == NULL)
                	root = root->left;
            	delete temp;
        	}
        	
        	if(root == NULL)											// case 1
            	return root;
			
        	root->height = max(height(root->left), height(root->right))+1;
			
        	
        	
        	if(height(root->left) - height(root->right) == 2)					// case 2
        	{
            	
            	if(height(root->left->left) - height(root->left->right) == 1)
                	return rl_rotation(root);
            	
            	else
                	return ll_rotation(root);
        	}
        	
        	
        	else if(height(root->right) - height(root->left) == 2) 				// case 3
        	{
        		
            	if(height(root->right->right) - height(root->right->left) == 1)
                	return lr_rotation(root);
            	
           	 	else
                	return rr_rotation(root);
        	}
        	return root;
    	}
		
 		
        void inorder(node *tree)			//Inorder Traversal of AVL Tree
		{
    		if (tree == NULL)
        		return;
    		inorder (tree->left);
    		cout<<tree->data<<"  ";
    		inorder (tree->right);
		}
        
		void preorder(node *tree)			//Preorder Traversal of AVL Tree
		{
    		if (tree == NULL)
        		return;
    		cout<<tree->data<<"  ";
   		 	preorder (tree->left);
    		preorder (tree->right);
		 
		}
 		
        void postorder(node *tree)			//Postorder Traversal of AVL Tree
		{
    		if (tree == NULL)
        		return;
    		postorder ( tree ->left );
   			postorder ( tree ->right );
    		cout<<tree->data<<"  ";
		}
		
		
		avlTree()
    	{
        	root = NULL;
    	}
		
   		void insert(int val)
    	{
        	root = insert(root,val);
    	}
    	
		void remove(int val)
    	{
        	root = remove(val, root);
    	}
		
		
		void display() {
			
			cout<<"inorder Traversal"<<endl;
			inorder(root);
        	cout<<"\nPre-order Traversal"<<endl;
			preorder(root);
			cout<<"\nPost-order Traversal"<<endl;
			postorder(root);
			cout<< endl<<endl;
		}
		
};


int main()
{	
	avlTree t;
    cout<<"A Balanced Binary search tree.(AVL Tree)\n\n";
	t.insert(21);
    t.insert(18);
    t.insert(8);
    t.insert(11);
    t.insert(17);
    t.insert(5);
    t.insert(4);
    t.insert(67);
    t.insert(43);
    t.insert(12);
    t.insert(10);
    t.insert(89);
    t.insert(38);
    t.insert(69);
    t.display();
	cout<<"AFTER DELETION\n\n";    
    t.remove(5);
    t.remove(35);
    t.remove(65);
    t.remove(89);
    t.remove(43);
    t.remove(88);
    t.remove(17);
    t.remove(38);
    t.display();

    return 0;
}
