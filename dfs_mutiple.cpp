#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

char c[1000][1000];
int visit[1000][1000];
int m,n;

class ij
{
	public:
		int i,j;
		ij(int _i,int _j)
		{
			i=_i;
			j=_j;
		}
};
void dfs(int k,int i,int j)
{
	if(k==0)
		return ;
	visit[i][j]=1;
	if(i-1>=0&&visit[i-1][j]==0)	{c[i-1][j]='g';dfs(k-1,i-1,j);}
	if(i+1<=n-1&&visit[i+1][j]==0)	{c[i+1][j]='g';dfs(k-1,i+1,j);}
	if(j-1>=0&&visit[i][j-1]==0)	{c[i][j-1]='g';dfs(k-1,i,j-1);}
	if(j+1<=m-1&&visit[i][j+1]==0)	{c[i][j+1]='g';dfs(k-1,i,j+1);}
}
vector<ij> cij;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>c[i][j];
	int k;
	cin>>k;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(c[i][j]=='g')
			{
				ij m(i,j);
				cij.push_back(m);
			}
	for(int p=0;p<cij.size();p++)
		dfs(k,cij[p].i,cij[p].j);
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<m;j++)
			cout<<c[i][j];
		cout<<endl;
	}
	return 0;
}