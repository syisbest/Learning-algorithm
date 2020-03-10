#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int mat[100][100],vit[100][100];
void dfs(int x,int y)
{
	if(vit[x][y]||!mat[x][y])	return ;
	vit[x][y]=1;
	dfs(x-1,y-1);dfs(x-1,y);dfs(x-1,y+1);
	dfs(x,y-1);dfs(x,y+1);
	dfs(x+1,y-1);dfs(x+1,y);dfs(x+1,y+1);
} 

int main()
{
	int n;
	cin>>n;
	string s;
	memset(mat,0,sizeof(mat));
	memset(vit,0,sizeof(vit));
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int j=0;j<n;j++)
			mat[i+1][j+1]=s[j]-'0';
	}
	int count=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(!vit[i][j]&&mat[i][j])
			{
				count++;
				dfs(i,j);
			}
	cout<<count;
}
