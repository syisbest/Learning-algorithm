#include<iostream>

using namespace std;

int maxsum(int *A,int x,int y)
{
	if(y-x==1)	return A[x];
	int mid=(y+x)/2;
	int maxL=maxsum(A,x,mid);
	int maxR=maxsum(A,mid,y);
	int max=maxL;
	if(maxL<maxR)
		max=maxR;
	int L=A[mid-1];int sum=0;
	for(int i=mid-1;i>=x;i--)
	{
		sum+=A[i];
		if(sum>L)
			L=sum;
	}
	int R=A[mid];sum=0;
	for(int i=mid;i<y;i++)
	{
		sum+=A[i];
		if(sum>R)
			R=sum;
	}
	int maxM=L+R;
	if(max<maxM)
		max=maxM;
	return max;
} 

int main()
{
	int n;
	int A[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	int max=maxsum(A,0,n);
	cout<<max;
	return 0;
}
