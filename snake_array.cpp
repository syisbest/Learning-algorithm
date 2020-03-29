#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int ib,ic;
	if(b%a==0)	ib=b/a-1;
	else	ib=b/a;
	if(c%a==0)	ic=c/a-1;
	else	ic=c/a;
	int jb,jc;
	if(ib%2==0)	jb=b-ib*a-1;
	else	jb=(ib+1)*a-b;
	if(ic%2==0)	jc=c-ic*a-1;
	else	jc=(ic+1)*a-c;
	cout<<ib<<" "<<jb<<endl;
	cout<<ic<<" "<<jc<<endl;
	cout<<abs(ib-ic)+abs(jb-jc);
	return 0;
}

