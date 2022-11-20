#include<iostream>
using namespace std;

int main()

{
	float *arr;
	
	int x;
	cin>>x;
	
	arr= new float[x];
	
	for (int i=1; i<x; i++)
	
	{
		arr[i]=i*i;
	}
	
	
	for (int i=1; i<x; i++)
	
	{
		cout<<arr[i]<<endl;
	}
	
	return 0;
}
