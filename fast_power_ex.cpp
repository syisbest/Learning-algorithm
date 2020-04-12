#include<iostream>
using namespace std;

int main()
{
	long long n,m,k,x;
	cin>>n>>m>>k>>x;
	long long ans=1;
	long long now=10;
	while(k)
	{
		if(k%2==1)
			ans=ans*now%n;
		k/=2;
		now=now*now%n;
	}
	ans=m*ans%n;
	ans=(x+ans)%n;
	cout<<ans;
	return 0;
} 
