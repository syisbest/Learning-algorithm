#include<iostream>
#include<algorithm>
using namespace std;
int n=8;
int sum=0;
int c[8]={0};
void search(int cur)
{
	if(cur==n)	{for(int i=0;i<cur;i++)	cout<<c[i];cout<<endl;sum++;}
	else
	{
		for(int i=0;i<n;i++)
		{
			bool ok=true;
			c[cur]=i;
			for(int j=0;j<cur;j++)
				if(c[cur]==c[j]||cur-c[cur]==j-c[j]||cur+c[cur]==j+c[j])
				{
					ok=false;
					break;
				}
			if(ok)
				search(cur+1);
		}		
	}
}
int main()
{
	search(0);
	cout<<sum;
	return 0;
}
