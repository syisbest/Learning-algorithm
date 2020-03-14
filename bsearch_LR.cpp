#include<iostream>

using namespace std;

int lower_bound(int *A,int x,int y,int temp)
{
	int mid;
	while(x<y)
	{
		mid=(x+y)/2;
		if(A[mid]>=temp)	y=mid;
		else	x=mid+1;	
	}
	return x;
}
int upper_bound(int *A,int x,int y,int temp)
{
	int mid;
	while(x<y)
	{
		mid=(x+y)/2;
		if(A[mid]<=temp)	x=mid+1;
		else	y=mid;	
	}
	return x;
}
int main()
{
	int A[10]={0,1,1,1,1,1,1,1,1,9};
	int L=lower_bound(A,0,10,1);
	int R=upper_bound(A,0,10,1);
	cout<<"("<<L<<","<<R<<")";
	return 0;
}
