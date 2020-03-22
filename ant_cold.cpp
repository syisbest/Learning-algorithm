#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int ant[n];
	for(int i=0;i<n;i++)
		cin>>ant[i];
	int x=ant[0];
	int ans=1;
	if(x>0)
	{
		for(int i=0;i<n;i++)
			if(ant[i]<0&&-ant[i]>x)
				ans++;
		if(ans>1)
			for(int i=0;i<n;i++)
				if(ant[i]<x&&ant[i]>0)
					ans++;
	}
	if(x<0)
	{
		for(int i=0;i<n;i++)
			if(ant[i]>0&&-ant[i]>x)
				ans++;
		if(ans>1)
			for(int i=0;i<n;i++)
				if(ant[i]<0&&ant[i]<x)
					ans++;
	}
	cout<<ans;
	return 0;
}
