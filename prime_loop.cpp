#include<iostream>
#include<algorithm>
using namespace std;

/*
int main()
{
	int n;
	cin>>n;
	int prime[100];
	prime[0]=prime[1]=1;
	int A[50];
	for(int i=2;i<=2*n;i++)
		prime[i]=is_prime(i);
	for(int i=0;i<n;i++)
		A[i]=i+1;
	do
	{
		int ok=1;
		for(int i=0;i<n;i++)	if(!prime[A[i]+A[(i+1)%n]]){ok=0;break;}
		if(ok)
			for(int i=0;i<n;i++)
				cout<<A[i];
	}while(next_permutation(A+1,A+n));
	return 0;
}
*/
int prime[100];
int A[50]={0};
int vis[50]={0};

int is_prime(int n)
{
	int ok=1;
	for(int i=2;i<n;i++)
		if(n%i==0)
			ok=0;
	return ok;
}

void dfs(int cur,int n)
{
	if(cur==n&&prime[A[0]+A[n-1]])
	{
		for(int i=0;i<n;i++)
			cout<<A[i]<<" ";
		cout<<endl;
	}else
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]&&prime[i+A[cur-1]])
		{
			A[cur]=i;
			vis[i]=1;
			dfs(cur+1,n);
			vis[i]=0;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	prime[0]=prime[1]=1;
	for(int i=2;i<2*n;i++)
		prime[i]=is_prime(i);
	A[0]=1;
	dfs(1,n);
	return 0;
}
