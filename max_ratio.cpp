#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;

class fraction
{
public:
	LL x,y;
	fraction(LL _x,LL _y)
	{
		LL _gcd=gcd(_x,_y);
		x=_x/_gcd;
		y=_y/_gcd;
	}
	LL gcd(LL a,LL b)
	{
		if(b==0)	return a;
		gcd(b,a%b);
	}
};
int n;
LL a[100];
vector<fraction> fractions;
map<LL,map<LL,LL> > all_base;
map<LL,map<LL,LL> > all_log;

void init()
{
	for(int base=2;base<=1e6;base++)
	{
		LL cut=(LL)base*base;
		int pow=2;
		while(cut<1e12)
		{
			all_base[cut][pow]=base;
			all_log[cut][base]=pow;
			pow++;
			cut*=base;
		}
	}
}
LL sqrtPower(LL x,int pow)
{
	if(x==1)	return 1;
	if(pow==1)	return x;
	if(all_base[x].find(pow)!=all_base[x].end())
		return all_base[x][pow];
	else
		return -1;
}
LL getPow(LL fx,LL xi)
{
	if(fx==1)	return 1;
	if(fx==xi)	return 1;
	if(all_log[xi].find(fx)!=all_log[xi].end())
		return all_log[xi][fx];
	return -1;
}
int main()
{
	init();
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	if(n==2)
	{
		cout<<a[1]<<"/"<<a[0]<<endl;
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		if(a[i+1]!=a[i])
		{
			fraction sub(a[i+1],a[i]);
			fractions.push_back(sub);
		}
	}
	for(int pow=1;pow<=40;pow++)
	{
		LL x=fractions[0].x;
		LL y=fractions[0].y;
		LL fx=sqrtPower(x,pow);
		LL fy=sqrtPower(y,pow);
		if(fx==-1||fy==-1)	continue;
		bool is_true=true;
		for(int i=1;i<fractions.size();i++)
		{
			LL xi=fractions[i].x;
			LL yi=fractions[i].y;
			LL power_x=getPow(fx,xi);
			LL power_y=getPow(fy,yi);
			if(y==1)	power_y=power_x;
			if(power_x==-1||power_y==-1||power_x!=power_y)
			{
				is_true=false;
				break;
			}
		}
		if(is_true)
		{
			cout<<fx<<"/"<<fy<<endl;
			return 0;
		}
	}
	return 0;
}

