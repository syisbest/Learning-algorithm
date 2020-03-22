#include<iostream>
using namespace std;

int ans;
void f(int dian,int hua,int jiu)
{
	if(dian==0&&hua==0&&jiu==1)
	{
		ans++;
		return ;
	}
	if(dian>0)	f(dian-1,hua,jiu*2);
	if(hua>0)	f(dian,hua-1,jiu-1);
}
int main()
{
	f(5,9,2);
	cout<<ans;
	return 0;
}
