#include<iostream>
using namespace std;

bool f[10000];
int gcd(int a,int b)
{
	if(b>a)
	{
		int t=a;
		a=b;
		b=t;
	}
	while(b)
	{
		int c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	int A[N];
	int g;
	f[0]=true;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		if(i==0)g=A[i];
		else	g=gcd(g,A[i]);
		for(int j=0;j<10000;j++)
		{
			if(f[j]==true)	f[j+A[i]]=true;
		}	
	}
	int ans=0;
	if(g==1)
	{
		for(int i=0;i<10000;i++)
		{
			if(!f[i])
			{
				cout<<i<<endl;
				ans++;
			}
		}
		cout<<ans;
	}
	else
	{
		cout<<"INF";
	}
	return 0;
}
