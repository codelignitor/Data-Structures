#include <bits/stdc++.h>
using namespace std;

class node{
public:
	
	int info;
    node *down;
    node *next;
	
	node(int val){
		info = val;
		down = NULL;
		next = NULL;
	}
};

class Graph{
private:
    int size;
    node *head;

public:
    Graph()
    {
        head = NULL;
        int size =0;
    }


    node *traverse_to_end()
    {
        node *point = head;
        while (point->down != NULL)
        {
            point = point->down;
        }
        return point;
    }

    void add_vertex(int val)
    {
        if (head == NULL)
        {
            head = new node(val);
            head->next = NULL;
            head->down = NULL;
            return;
        }
        
        node *tail = traverse_to_end();
        node *newnode = new node(val);
        newnode->next = NULL;
        newnode->down = NULL;
        tail->down = newnode;
        size++;
    }

    void add_edge(int v, int e)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->info == e)
            {
                node *newnode = new node(v);
				newnode->next = NULL;
				
                while (temp != NULL)
                {
                    if (temp->next == NULL)
                    {
                        temp->next = newnode;
                        return;
                    }
                    temp = temp->next;
                }
                break;
            }
            temp = temp->down;
        }
    }

    int out_Degree(int val)
    {
        int count = 0;
        node *temp = head;
        node *temp2;
        while (temp != NULL)
        {
            temp2 = temp;
            if (temp->info == val)
            {
                while (temp2->next != NULL)
                {
                    temp2 = temp2->next;
                    count++;
                }
                return count;
            }
            temp = temp->down;
        }
    }

    int in_Degree(int val)
    {
        int counter =0;
        node *temp = head;
        node *ptr;
        while (temp != NULL)
        {
            ptr = temp->next;
            while (ptr != NULL)
            {
                if (ptr->info == val)
                {
                    counter++;
                }
                ptr = ptr->next;
            }
            temp = temp->down;
        }
        return counter;
    }

    void print()
    {
        node *temp = head;
        node *ptr2;
        while (temp != NULL)
        {
            ptr2 = temp;
            cout << "vertex  " << temp->info << "  ";
            while (ptr2->next != NULL)
            {
                ptr2 = ptr2->next;
                cout << " -> " << ptr2->info;
            }
            cout << endl;
            temp = temp->down;
        }
        cout<<"\n'size' = "<<size<<"\n";
    }
};
int main()
{
    int in, out;
    Graph g1;
    g1.add_vertex(1);
    g1.add_vertex(2);
    g1.add_vertex(3);
    g1.add_vertex(4);
    g1.add_vertex(5);
    g1.print();
	
	cout<<endl;
    g1.add_edge(3, 1);
    g1.add_edge(5, 2);
    g1.add_edge(1, 2);
    g1.add_edge(2, 2);
    g1.add_edge(7, 5);
    g1.add_edge(6, 3);
    g1.add_edge(2, 5);
    g1.print();
	
	cout<<endl;
	
    cout<<"Enter out_degree vertex: "<<endl;
    cin>>in;
    cout<< g1.out_Degree(in) << endl;

    cout<<"Enter in_degree vertex: "<<endl;
    cin>>out;
    cout<<g1.in_Degree(out) <<endl;

    return 0;
}
