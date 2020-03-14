#include<iostream>

using namespace std;

int bsearch(int *A,int x,int y,int temp)
{
	int mid;
	while(x<y)
	{
		mid=(x+y)/2;
		if(A[mid]==temp)	return mid;
		else if(A[mid]>temp)	y=mid;
		else	x=mid+1;	
	}
	return -1;
}
int main()
{
	int A[10]={0,1,2,3,4,5,6,7,8,9};
	int find=bsearch(A,0,10,0);
	if(find!=-1)
		cout<<find;
	else
		cout<<"not find";
	return 0;
}
