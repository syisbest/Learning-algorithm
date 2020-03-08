#include<iostream>
#include<string.h>
using namespace std;

/*int main()
{
	int D,I;
	int d[1<<10];
	while(cin>>D>>I)
	{
		memset(d,0,sizeof(d));
		int number = (1<<D)-1;
		int k;
		for(int i=0;i<I;i++)
		{
			k=1;
			while(true)
			{
				d[k] = !d[k];
				if(d[k]==1)
					k=2*k;
				else
					k=2*k+1;
				if(k>number)
					break;
			}
		}
		cout<<k/2;
	} 
    return 0;
}*/

int main()
{
	int D,I;
	while(cin>>D>>I)
	{
		int k=1;
		for(int i=0;i<D-1;i++)
		{
			if(I%2==1)
			{
				k=2*k;
				I = (I+1)/2;
			}
			else
			{
				k=2*k+1;
				I=I/2;
			}
		}
		cout<<k;
	}
	return 0;
}
