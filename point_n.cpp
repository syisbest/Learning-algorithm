#include<iostream>
#include<vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b;
	long long n;
	cin>>a>>b>>n;
	while(a>=b)
	{
		a-=b;
	}
	long long i=0;
	int ans[3];
	int j=0;
	long long t=n+3;
	while(a<b)
	{
		a*=10;
		i++;
		if(i>=n)
		{
			ans[j++]=(a/b);
		}	
		if(i==t)
			break;
		if(a>=b)
		{
			a%=b;
		}
	}
	for(int k=0;k<3;k++)
		cout<<ans[k];
	return 0;
}
