#include<iostream>
using namespace std;
int a[100];
int find(int x)
{
	for(int i=0;i<100;i++)
		if(a[i]==x)
			return i;
	return -1;
}
void right_left(int *a,int q,int p)
{
	for(int i=q;i<p-1;i++)
	{
		int j = a[i];
		a[i] = a[i+1];
		a[i+1] = j;
	}
}
void left_left(int *a,int q,int p)
{
	for(int i=q;i>p+1;i--)
	{
		int j = a[i];
		a[i] = a[i-1];
		a[i-1] = j;
	}
}
void right_right(int *a,int q,int p)
{
	for(int i=q;i<p;i++)
	{
		int j = a[i];
		a[i] = a[i+1];
		a[i+1] = j;
	}
}
void left_right(int *a,int q,int p)
{
	for(int i=q;i>p;i--)
	{
		int j = a[i];
		a[i] = a[i-1];
		a[i-1] = j;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		a[i] = i+1;
	char s;
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>s>>x>>y;
		int q=find(x);
		int p=find(y);
		if(p==-1||q==-1)
		{
			continue;
		}
		if(s=='A')
		{
			if(q<p)
				right_left(a,q,p);
			else
				left_left(a,q,p);
		}
		else if(s=='B')
		{
			if(q<p)
				right_right(a,q,p);
			else
				left_right(a,q,p);
		}
		for(int i=0;i<n;i++)
			cout<<a[i];
	}
    return 0;
}
