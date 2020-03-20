#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int a[50000];

bool is_true(int i,int j)
{
	int min=a[i];
	int max=a[i];
	for(int k=i;k<=j;k++)
	{
		if(a[k]>max)
		max=a[k];
		if(a[k]<min)
		min=a[k];
	}
	if((max-min)==(j-i))
		return true;
	else
		return false;
}
int main()
{
	int n;
	int ans=0;
	cin>>n;
 	for(int i=0;i<n;i++)
 		cin>>a[i];
 	for(int i=0;i<n;i++)
 		for(int j=i;j<n;j++)
		{
			if(i==j)
			{
				ans++;
				continue;
			}
			if(is_true(i,j))
				ans++;
		} 
	cout<<ans;
	return 0;
}
