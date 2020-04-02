#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

map<int,int> cache;
int main()
{
	int n;
	cin>>n;
	for(int c=0;c*c<=n/2;c++)
		for(int d=0;c*c+d*d<=n;d++)
			if(cache.find(c*c+d*d)==cache.end())
				cache[c*c+d*d]=c;
	for(int a=0;a*a<=n/4;a++)
		for(int b=0;a*a+b*b<=n/3;b++)
			if(cache.find(n-a*a-b*b)!=cache.end())
			{
				int c=cache[n-a*a-b*b];
				int d=int(sqrt(n-a*a-b*b-c*c));
				cout<<a<<" "<<b<<" "<<c<<" "<<d;
				return 0;
			}
	return 0;
}
