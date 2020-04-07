#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
 
class grass
{
	public:
		int i,j,k;
		grass(int _i,int _j,int _k)
		{
			i=_i;
			j=_j;
			k=_k;
		}
};
queue<grass> qg;
int main()
{
	int n,m;
	cin>>n>>m;
	char a[n][m];
	int visit[n][m];
	memset(visit,0,sizeof(visit));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	int k;
	cin>>k;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]=='g')
			{
				visit[i][j]=1;
				grass g(i,j,k);
				qg.push(g);
			}
			
	while(!qg.empty())
	{
		grass a1=qg.front();
		qg.pop();
		int i=a1.i;
		int j=a1.j;
		int k=a1.k;
		if(k>0)
		for(int x=0;x<4;x++)
		{
			
			{
				if(i-1>=0&&visit[i-1][j]!=1)
				{
					visit[i-1][j]=1;
					grass g(i-1,j,k-1);
					qg.push(g);
				}
				if(j-1>=0&&visit[i][j-1]!=1)
				{
					visit[i][j-1]=1;
					grass g(i,j-1,k-1);
					qg.push(g);
				}
				if(i+1<=n-1&&visit[i+1][j]!=1)
				{
					visit[i+1][j]=1;
					grass g(i+1,j,k-1);
					qg.push(g);
				}
				if(j+1<=m-1&&visit[i][j+1]!=1)
				{
					visit[i][j+1]=1;
					grass g(i,j+1,k-1);
					qg.push(g);
				}
			}
			
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(visit[i][j]==1)
				cout<<'g';
			else
				cout<<'.';
		}
		cout<<endl;
	}
	return 0;
}

