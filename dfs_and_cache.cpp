#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[50][50];
int n,m,k;
long long ans;
long long cache[50][50][14][13];

long long dfs(int x,int y,int max,int ant)
{
	if(cache[x][y][max+1][ant]!=-1)
		return cache[x][y][max+1][ant];
	if(x==n||y==m||ant>k)
		return 0;
	long long ans=0;
	int now=a[x][y];
	if(x==n-1&&y==m-1)
	{
		if(ant==k)
			ans++;
		if(ant==k-1&&a[x][y]>max)
			ans++;
		ans%=1000000007;
		return ans;
	}
	if(now>max)
	{
		ans+=dfs(x+1,y,now,ant+1);
		ans+=dfs(x,y+1,now,ant+1);
	}
	ans+=dfs(x+1,y,max,ant);
	ans+=dfs(x,y+1,max,ant);
	
	cache[x][y][max+1][ant]=ans%1000000007;
	return cache[x][y][max+1][ant];
}

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	memset(cache,-1,sizeof(cache));
	cout<<dfs(0,0,-1,0);
	return 0;
}
