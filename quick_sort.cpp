#include<iostream>

using namespace std;

void quick_sort(int *A,int low,int high)
{
	int i=low,j=high;
	int temp;
	if(low<high)
	{
		temp=A[i];
		while(i!=j)
		{
			while(A[j]>temp&&i!=j)
				j--;
			if(i<j)
				A[i++]=A[j];
			while(A[i]<temp&&i!=j)
				i++;
			if(i<j)
				A[j--]=A[i];
		}
		A[i]=temp;
		quick_sort(A,low,i-1);
		quick_sort(A,i+1,high);
	}
}
int main()
{
	int A[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	quick_sort(A,0,n-1);
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	return 0;
}
