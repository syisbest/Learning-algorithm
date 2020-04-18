#include<iostream>
#include<vector>
using namespace std;

int n;
const int MAX=10e5+1;
int value[MAX];
int newvalue[MAX];
vector<int> g[MAX];
int ans;

void dfs(int root,int fa)
{
	newvalue[root]=value[root];
	for(int i=0;i<g[root].size();i++)
	{
		int son=g[root][i];
		if(son!=fa)
			dfs(son,root);
		if(value[son]>0)
			newvalue[root]+=value[son];
	}
	if(newvalue[root]>ans)
		ans=newvalue[root];
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>value[i];
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

