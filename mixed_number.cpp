#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int s2i(string s,int a,int b)
{
	int intab=0;
	int mut=1;
	int num;
	for(int i=b;i>=a;i--)
	{
		num=(s[i]-'0')*mut;
		mut*=10;
		intab+=num;
	}
	return intab;
}
int main()
{
	int n;
	cin>>n;
	int ans=0;
	int inta,intb,intc;
	string s="123456789";
	do{
		for(int i=0;i<=6;i++)
		{
			inta = s2i(s,0,i);
			if(inta>=n)break;
			for(int j=(i+8)/2;j<=7;j++)
			{
				intb=s2i(s,i+1,j);
				intc=s2i(s,j+1,8);
				if(intb%intc==0&&inta+intb/intc==n)
					ans++;
			}
		}
	} while(next_permutation(s.begin(),s.end()));
	cout<<ans;
	return 0;
}
