#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
	char a[100];
	cin>>a;
	int l = strlen(a);
	for(int i=1;i<=l;i++)
	{
		if(l%i==0)
		{
			bool ok=true;
			for(int j=i;j<l;j++)
			{
				if(a[j]!=a[j%i])
				{
					ok=false;
					break;
				}
			}
			if(ok==true)
			{
				cout<<i;
				break;
			}
		}
	}
	return 0;
}
