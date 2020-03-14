#include<iostream>
using namespace std;

bool is_true(int n)
{
	while(n)
	{
		int a=n%10;
		if(a==2||a==0||a==1||a==9)
			return true;
		else
			n/=10;
	}
	return false;
}
int main()
{
	int num=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(is_true(i))
			num+=i;
	}
	cout<<num;
	return 0; 
}
