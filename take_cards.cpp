#include<iostream>
#include<vector>
using namespace std;

int ans;
/*
int count(vector<int> v,int i)
{
	int cnt=0;
	for(int j=0;j<v.size();j++)
	{
		if(v[j]==i)
			cnt++;
	}
	return cnt;
}
void f(int n,vector<int> v)
{
	if(n==0)
	{
		ans++;
		return ;
	}
	for(int i=1;i<=13;i++)
	{
		if(count(v,i)==4)
			continue;
		v.push_back(i);
		f(n-1,v);
		v.pop_back();
	}
}
*/

void f(int n,int count)
{
	if(n<0||count>13)
		return ;
	if(n==0&&count==13)
	{
		ans++;
		return ;
	}
	for(int i=0;i<=4;i++)
	{
		f(n-1,count+i);
	}
}
int main()
{
	vector<int> v;
	f(13,0);
	cout<<ans; 
	return 0;
}

