/*#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int m,n;
int k;
int cut;
const int MAX=1000001;
int visit[1001][1001];
vector<int> v[MAX];

void dfs(int i,int j)
{
	visit[i][j]=1;
	for(int k=0;k<v[i*n+j+1].size();k++)
	{	
		int newi=(v[i*n+j+1][k]-1)/n;
		int newj=(v[i*n+j+1][k]-1)%n;
		if(visit[newi][newj]==0)
			dfs(newi,newj);
	}
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n>>k;
	for(int i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(visit[i][j]==0)
			{
				dfs(i,j);
				cut++;
			}
		}
	}
	cout<<cut;
	return 0;
} */


#include<iostream>
using namespace std;
int num[1000001];
int find(int a)
{
	if(num[a]==a)
		return a;
	else
		return find(num[a]);
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,n,k;
	cin>>m>>n>>k;
	for(int i=1;i<=m*n;i++)
		num[i]=i;
	for(int i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		int newa=find(a);
		int newb=find(b);
		
		num[newb]=newa;
	}
	int ans=0;
	for(int i=1;i<=m*n;i++)
		if(num[i]==i)
			ans++;
	cout<<ans;
}
