#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	long long x,y;
	cin>>x>>y;
	long n,d;
	if(y>0&&abs(x)<=y)
	{
		n=y;
		d=y-x+2*y;
	}
	else if(x>0&&abs(y)<=x)
	{
		n=x;
		d=x+y;
	}
	else if(y<=0&&x<=abs(y)&&x>=(y-1))
	{
		n=y-1;
		d=2*abs(y)+1+x-(y-1);
	}
	else if(x<0&&y>=(x+1)&&y<=abs(x))
	{
		n=x;
		d=abs(x)-y;
	}
	long long ans=0;
	if(n>0)
	{
		ans=(4+n*4)*n/2+(2+2+4*(n-1))*n/2-d;
	}
	if(n<0)
	{
		ans=(2+2+4*(abs(n)-1))*abs(n)/2+(4+(abs(n)-1)*4)*(abs(n)-1)/2-d;
	}
	cout<<ans;
	return 0;
}
