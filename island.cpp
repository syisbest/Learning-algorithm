#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int visit[1000][1000];
char c[1000][1000];
int ans;
int a[4]={-1,0,1,0};
int b[4]={0,-1,0,1};
struct point
{
	int i,j;
};

void bfs(int i,int j)
{
	visit[i][j]=1;
	queue<point> q;
	q.push({i,j});
	int cut1=0;
	int cut2=0;
	while(!q.empty())
	{
		point nowp=q.front();
		q.pop();
		cut1++;
		bool flag=false;
		for(int k=0;k<4;k++)
		{
			int x=nowp.i+a[k];
			int y=nowp.j+b[k];
			if(x>=0&&x<=(N-1)&&y>=0&&y<=(N-1)&&!visit[x][y]&&c[x][y]=='#')
			{
				visit[x][y]=1;
				q.push({x,y});
			}
			if(x>=0&&x<=(N-1)&&y>=0&&y<=(N-1)&&c[x][y]=='.')
				flag=true;
		}
		if(flag)
			cut2++;
	}
	if(cut1==cut2)
		ans++;
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>c[i][j];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(!visit[i][j]&&c[i][j]=='#')
				bfs(i,j);
	cout<<ans;
	return 0;
}

