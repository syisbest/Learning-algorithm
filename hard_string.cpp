#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n,l;
int A[100];
int dfs(int cur)
{
	if(cur==n)
	{
		for(int i=0;i<cur;i++)
			cout<<char('A'+A[i]);
		cout<<endl;
		return 0;
	}
	else
	{
		for(int i=0;i<l;i++)
		{
			A[cur]=i;
			int ok=1;
			for(int j=1;j*2<=cur+1;j++)
			{
				int flag=1;
				for(int k=0;k<j;k++)
					if(A[cur-k]!=A[cur-j-k])
					{
						flag=0;
						break;
					}
				if(flag)
				{
					ok=0;
					break;
				}
			}
			if(ok)
				if(!dfs(cur+1))
					return 0;
		}
	}
	return 1;
} 
int main()
{
	cin>>n>>l;
	int a=dfs(0);
	if(a)
		cout<<"null";
	return 0;
}
