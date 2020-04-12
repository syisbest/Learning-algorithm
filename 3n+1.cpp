#include<iostream>
using namespace std;

int three_n_and_one(int n)
{
	int cur=0;
	while(n!=1)
	{
		if(n%2==0)
		{
			n/=2;
			cur++;
		}
		else if(n%2==1)
		{
			n=n*3+1;
			cur++;
		}
	}
	cur++;
	return cur;
}
int main()
{
	int i,j;
	while(cin>>i>>j)
	{
		bool flag=false;
		if(i>j)
		{
			int t=i;
			i=j;
			j=t;
			flag=true;
		}
		int max=0;
		for(int p=i;p<=j;p++)
		{
			int cur=three_n_and_one(p);
			if(cur>max)
			max=cur;
		}
		if(flag)
		{
			int t=i;
			i=j;
			j=t;
		}
		cout<<i<<" "<<j<<" "<<max<<endl;
	}
	
	return 0;
}
