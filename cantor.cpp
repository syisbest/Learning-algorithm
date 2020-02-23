#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		int k=1,s=0;
		while(true)
		{
			s += k;
			if(s>=n)
			{
				if(k%2==1)
					cout<<s-n+1<<"/"<<k-s+n<<endl;
				else
					cout<<k-s+n<<"/"<<s-n+1<<endl;
				break;
			}
			k++;
		}
		
	}
	return 0;
}
