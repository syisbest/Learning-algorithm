#include<iostream>

using namespace std;

void merge_sort(int *A,int x,int y,int *T)
{
	if(y-x>1)
	{
		int mid=(x+y)/2;
		int p=x,q=mid,i=x;
		merge_sort(A,x,mid,T);
		merge_sort(A,mid,y,T);
		while(p<mid||q<y)
		{
			if(p>=mid||(q<y&&A[p]>A[q]))
				T[i++]=A[q++];
			else
				T[i++]=A[p++];
		}
		for(i=x;i<y;i++)
			A[i]=T[i];
	}
}
int main()
{
	int n;
	cin>>n;
	int A[100]={0};
	int T[100]={0};
	for(int i=0;i<n;i++)
		cin>>A[i];
	merge_sort(A,0,n,T);
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	return 0;
}
