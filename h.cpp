#include<iostream>
#include<algorithm>
using namespace std;

int a[100000]={0};
int sub[99999]={0};

int gcd(int a,int b)
{
	while(true)
	{
		int c=b%a;
		if(c==0)
			break;
		b=a;
		a=c;
	}
	return a;
} 
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int num=gcd(a[1]-a[0],a[2]-a[1]);
	for(int i=2;i<n-1;i++)
		num=gcd(num,a[i+1]-a[i]);
	int ans;
	ans=(a[n-1]-a[0])/num+1;
	cout<<ans;
	return 0;
}