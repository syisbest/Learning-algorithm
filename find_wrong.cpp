#include<iostream>
#include<stdio.h>
#include<string> 
#include<sstream>
#include<algorithm>
using namespace std;

int ans[10000];
int s2i(string &tmp)
{
	int a=0;
//	stringstream iss;
//	iss<<tmp;
//	iss>>a;
	int tlen=tmp.length();
	int num=1;
	for(int i=tlen-1;i>=0;i--)
	{
		int b=tmp[i]-'0';
		a+=b*num;
		num*=10;
	}
	return a;
}
int main()
{
	int n;
	cin>>n;
	int index=0;
	getchar();
	for(int i=0;i<n;i++)
	{
		string s;
		getline(cin,s);
		istringstream iss(s);
		string tmp;
		while(getline(iss,tmp,' '))
		{
			ans[index++]=s2i(tmp);
		}
	}
	sort(ans,ans+index);
	int a;
	int b;
	for(int i=0;i<index-1;i++)
	{
		if(ans[i]==ans[i+1])	a=ans[i];
		if(ans[i]+2==ans[i+1])	b=ans[i]+1;
	} 
	cout<<b<<" "<<a;
	return 0;
}
