#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[101];
int ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i)continue;
		else
		{
			ans++;
			int p=a[i];
			int q=a[a[i]];
			a[a[i]]=p;
			a[i]=q;
		}
	}
	cout<<ans;
	return 0;
}
