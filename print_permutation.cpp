#include<iostream>
#include<algorithm>
using namespace std;

void print_permutation(int n,int *A,int cur)
{
	if(cur==n)
	{
		for(int i=0;i<n;i++)
			cout<<A[i];
		cout<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			bool ok=true;
			for(int j=0;j<cur;j++)
				if(A[j]==i)
					ok=false;
			if(ok)
			{
				A[cur]=i;
				print_permutation(n,A,cur+1);
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int A[100]={0};
	print_permutation(n,A,0);
	return 0;
}
