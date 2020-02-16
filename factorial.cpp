#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
const int maxn = 3000;
int a[maxn];

int main()
{
	memset(a,0,maxn);
	int n,i,j;
	cin>>n;
	a[0] = 1;
	for(i=2;i<=n;i++)
	{
		int c=0;
		for(j=0;j<maxn;i++)
		{
			int s = a[j] * i + c;
			a[j] = s % 10;
			c = s / 10;
		}
	}	
	for(j=maxn-1;j>=0;j--)
	{
		if(a[j])
			break;
	}
	for(i = j;i>=0;i--)
		cout<<a[i];
	return 0;
}
