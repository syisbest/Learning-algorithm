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
	int a[8]={1,2,3,4,5,6,7,8};
	int c[9]={0};
	for(int i=0;i<8;i++)
		update(9,i+1,a[i],c);
	cout<<get_sum(c,4)-get_sum(c,2);
	return 0;
}

