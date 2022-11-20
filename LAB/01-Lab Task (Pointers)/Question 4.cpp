#include<iostream>
using namespace std;


void __init__(int row, int col, int count)
{

    int **arr= new int*[row];
    
	for (int i=1; i<=row; i++)
    {
        arr[i]=new int[col];
    }

    for (int i=1; i<=row; i++)
    {
        for (int j=1; j<=col; j++)
        {
            arr[i][j]= ++count;
            

        }
    }

}

void display(int row, int col, int count)
{
	int **arr= new int*[row];
	
	for (int i=1; i<=row; i++)
    {
        for (int j=1; j<=col; j++)
        {
            cout<<arr[i][j]<<endl;
            
        }
    
}



}
int main()
{
	int x=3, y=3, z=0;
	__init__(x,y,z);

	display(x,y,z);

}

