#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(a<b)
	{
		int c=a;
		a=b;
		b=c;
	}
	while(true)
	{
		if(a%b==0)
			break;
		int k=a%b;
		a=b;
		b=k;
	}
	return b;
}

int main()
{
	int ans=0;
	for(int a=1;a<=9;a++)
		for(int b=1;b<=9;b++)
		{
			if(a==b)	continue;
			for(int c=1;c<=9;c++)
				for(int d=1;d<=9;d++)
				{
					if(c==d)	continue;
					int g1=gcd(a*c,b*d);
					int g2=gcd(a*10+c,b*10+d);
					if(a*c/g1==(a*10+c)/g2&&b*d/g1==(b*10+d)/g2)
					{
						ans++;
						cout<<a<<"/"<<b<<" "<<c<<"/"<<d<<endl;	
					}
				}
		}
	cout<<ans;
	return 0;
}
