#include<iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	char c[n+2][m+2];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int j=0;j<m+2;j++)
	{
		c[0][j]='0';
		c[n+1][j]='0';
	}
	for(int i=1;i<=n;i++)
	{
		c[i][0]='0';
		c[i][m+1]='0';
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int cur=0;
			if(c[i][j]!='*')
			{
				if(c[i-1][j-1]=='*')
					cur++;
				if(c[i-1][j]=='*')
					cur++;
				if(c[i-1][j+1]=='*')
					cur++;
				if(c[i][j-1]=='*')
					cur++;
				if(c[i][j+1]=='*')
					cur++;
				if(c[i+1][j-1]=='*')
					cur++;
				if(c[i+1][j]=='*')
					cur++;
				if(c[i+1][j+1]=='*')
					cur++;	
			}
			if(cur!=0)
				c[i][j]=cur+'0';
		}
	for(int i=1;i<n+1;i++)	
		for(int j=1;j<m+1;j++)
			if(c[i][j]=='.')
				c[i][j]='0';
	for(int i=1;i<n+1;i++)
	{	
		for(int j=1;j<m+1;j++)
			cout<<c[i][j];
		cout<<endl;
	}
	return 0;
}
