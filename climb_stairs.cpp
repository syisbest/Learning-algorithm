#include<iostream>
#include<algorithm>
using namespace std;
int ans;
void f(int temp,int foot)
{
	if(temp<0)	return ;
	if(temp==0&&foot%2==0)
	{
		ans++;
		return ;
	}
	f(temp-1,foot+1);
	f(temp-2,foot+1);
}
int main()
{
	f(39,0);
	cout<<ans;
	return 0;
}
