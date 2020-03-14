#include<iostream>
#include<algorithm>
using namespace std;

int a[100000]={0};
int sub[99999]={0};
int n;

void SUB(int *a)
{
	for(int i=0;i<n-1;i++)
		sub[i]=a[i+1]-a[i];
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	SUB(a);
	sort(sub,sub+n-1);
	int a1=sub[0];
	int a2=sub[1];
	while(true)
	{
		int b=a2%a1;
		if(b==0)
			break;
		a2=a1;
		a1=b;
	}
	int num;
	num=(a[n-1]-a[0])/a1+1;
	cout<<num;
	return 0;
}
