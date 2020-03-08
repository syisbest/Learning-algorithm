#include<iostream>
#include<algorithm>
using namespace std;

void print_permutation(int n,int *A,int *P,int cur)
{
	if(cur==n)
	{
		for(int i=0;i<n;i++)
			cout<<A[i];
		cout<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		if(!i||P[i]!=P[i-1])
		{
			int c1=0,c2=0;
			for(int j=0;j<cur;j++)	if(A[j]==P[i])	c1++;
			for(int j=0;j<n;j++)	if(P[j]==P[i])	c2++;
			if(c2>c1)
			{
				A[cur]=P[i];
				print_permutation(n,A,P,cur+1);
			}
		}
	}
}
int main()
{
	int n;
	int A[4]={0};
	int P[4]={0,1,1,1};
	print_permutation(4,A,P,0);
	return 0;
}
