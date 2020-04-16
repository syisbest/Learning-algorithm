#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<iterator>
using namespace std;

bool is_leapyear(int a)
{
	if((a%4==0&&a%100!=0)||(a%400==0))
		return true;
	else
		return false;
}
string i2s(int i)
{
	string s;
	stringstream ss;
	ss<<i;
	ss>>s;
	return s;
}
string ymd(int a,int b,int c)
{
	string s="";
	if(a>=60&&a<=99)	a+=1900;
	else if(a>=0&&a<=59)	a+=2000;
	else	return "";
	s+=i2s(a);
	s+="-";
	if(b>=1&&b<=12)
	{
		s+=i2s(b);
		s+="-";
		if(b==1||b==3||b==5||b==7||b==8||b==10||b==12)
		{
			if(c>=1&&c<=31)	s+=i2s(c);
			else	return "";
		}
		else if(b==4||b==6||b==9||b==11)
		{
			if(c>=1&&c<=30)	s+=i2s(c);
			else	return "";
		}
		else if(b==2)
		{
			if(is_leapyear(a))
			{
				if(c>=1&&c<=29)	s+=i2s(c);
				else	return "";
			}
			else
			{
				if(c>=1&&c<=28)	s+=i2s(c);
				else	return "";
			}
		}
	}
	else	return "";
	
	return s;
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int a=(s[0]-'0')*10+(s[1]-'0');
	int b=(s[3]-'0')*10+(s[4]-'0');
	int c=(s[6]-'0')*10+(s[7]-'0');
	string s1=ymd(a,b,c);
	string s2=ymd(b,c,a);
	string s3=ymd(c,b,a);
	set<string> ans;
	if(s1!="")
		ans.insert(s1);
	if(s2!="")
		ans.insert(s2);
	if(s3!="")	
		ans.insert(s3);
	set<string>::iterator it;
	for(it=ans.begin();it!=ans.end();it++)
		cout<<*it<<endl;
	return 0;
}
