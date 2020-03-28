#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int lowbit(int n)
{
	return n-(n&(n-1));
}
void update(int n,int i,int v,int c[])
{
	for(int j=i;j<=n;j+=lowbit(j))
		c[j]+=v;
}
int get_sum(int c[],int i)
{
	int sum=0;
	for(int k=i;k>=1;k-=lowbit(k))
		sum+=c[k];
	return sum;
}
int main()
{
	int n;
	cin>>n;
	int high[n];
	for(int i=0;i<n;i++)
		cin>>high[i];
	int max=high[0];
	for(int i=0;i<n;i++)
		if(high[i]>max)
			max=high[i];
	int c[max+2];
	memset(c,0,sizeof(c));
	long long count[n];
	memset(count,0,sizeof(count));
	for(int i=0;i<n;i++)
	{
		update(max+1,high[i]+1,1,c);
		int sum=get_sum(c,high[i]+1);
		count[i]+=(i+1)-sum;
	}
	memset(c,0,sizeof(c));
	for(int i=n-1;i>=0;i--)
	{
		update(max+1,high[i]+1,1,c);
		int sum=get_sum(c,high[i]);
		count[i]+=sum;
	}
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=(1+count[i])*count[i]/2;
	}
	cout<<ans<<endl;
	return 0;
}

