#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
using namespace std;

int prime[100],count = 0;

bool is_prime(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}
int main()
{
	for(int i=2;i<=100;i++)
		if(is_prime(i))
			prime[count++] = i;
	int n;
	while(cin>>n)
	{
		cout<<n<<"!= ";
		int result[100],rmax = 0;
		memset(result,0,sizeof(result));
		for(int i=1;i<=n;i++)
		{
			int m=i;
			for(int j=0;j<count;j++)
				while(m%prime[j]==0)
				{
					m /= prime[j];
					result[j]++;
					if(j>rmax) rmax = j;
				}
		}
		for(int i=0;i<=rmax;i++)
			cout<<result[i]<<" ";
		cout<<endl;
	}
	return 0;
}
