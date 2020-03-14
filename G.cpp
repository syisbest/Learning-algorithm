#include<iostream>
using namespace std;

int a[100001]={0};

int deep(int n)
{
	int sum=0;
	int deepth=1;
	for(int i=0;i<20;i++)
	{
		sum+=1<<i;
		if(n>sum)
			deepth++;
		else
			break;
	}
	return deepth;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int deepth=deep(n);
	long long max=-100001;
	int num=1;
	for(int i=0;i<deepth;i++)
	{
		long long sum=0;
		for(int j=1<<i;j<1<<(i+1);j++)
		{
			sum+=a[j];
		}
		if(sum>max)
		{
			max=sum;
			num=i+1;
		}
	}
	cout<<num;
	return 0; 
}
