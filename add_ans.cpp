#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(!a&&!b)
			break;
		int c=0,ans=0;
		while(a!=0||b!=0)
		{
			c=(a%10+b%10+c)>9?1:0;
			if(c==1)
				ans++;
			a/=10;b/=10;
		}
		cout<<ans;
	}
	return 0;
}
