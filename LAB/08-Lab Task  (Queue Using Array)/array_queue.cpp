#include <iostream>
using namespace std;

class arrayqueue{
	private:
		int *front, *rear,size;
		
	public:
		int *arr,length;
		
		arrayqueue(){
			front=NULL;
			rear=NULL;
			length=0;
			size=10;
			arr = new int[size];
			
		}
		
		void enqueue(int value)
		{
			if(rear==NULL)
			{
				rear = arr;
				*rear=value;
				front=rear;
				length++;
				front--;
				return;
				
			}
			else if(rear==arr+(size-1))
			{
				rear=arr;
				*rear=value;
				length++;
				//return;
			}
			else if(rear==arr+(size-1) && front == arr)
				cout<<"Queue is Overflow.\n";
			else
			{
				rear++;
				*rear=value;
				length++;
			}
			
		}
		
		int dequeue()
		{
			int *temp;
			
			if(rear!= NULL)
			{	
				rear=front;
				front=front+1;
				cout<<*arr<<endl;
				rear--;				
			}
			
			if(front==arr+(size-1) and rear!=arr+(size-1))
   			{
        		front=arr;
        		temp=front;
         		length--;
        		return *temp;
    		}
    		
			else if(front==arr+(size-1) && length==size)
 		   	{
        		front=arr;
        		temp=front;
         		length--;
       			return *temp;
   	 		}
    		
			else if(rear==front && length==0)
    		{
       			cout<<"queue is underflow.\n";
        		return 1;
    		}
			cout<<"length= "<<length<<endl;
		}
	
};

int main()
{
	arrayqueue aq1;
	aq1.enqueue(2);
	aq1.enqueue(3);
	aq1.enqueue(4);
	aq1.enqueue(5);
	aq1.dequeue();
	aq1.dequeue();
	
	return 0;
}
