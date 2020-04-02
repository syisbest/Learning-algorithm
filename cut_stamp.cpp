#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int a[12]={0,0,0,0,0,0,0,1,1,1,1,1};
int ans;

void dfs(int b[3][4],int i,int j)
{
	b[i][j]=0;
	if(i-1>=0&&b[i-1][j]==1)	dfs(b,i-1,j);
	if(i+1<=2&&b[i+1][j]==1)	dfs(b,i+1,j);
	if(j-1>=0&&b[i][j-1]==1)	dfs(b,i,j-1);
	if(j+1<=3&&b[i][j+1]==1)	dfs(b,i,j+1);
}

bool check()
{
	int b[3][4];
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
		{
			if(a[i*4+j]==1)	b[i][j]=1;
			else	b[i][j]=0;
		}
	int cnt=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
		{
			if(b[i][j]==1)
			{
				dfs(b,i,j);
				cnt++;
			}
		}
	return cnt==1;
}

int main()
{ 
	do{
		if(check())
			ans++;
	}while(next_permutation(a,a+12));
	cout<<ans;
	return 0;
}
