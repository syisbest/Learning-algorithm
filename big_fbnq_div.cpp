#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a,string b)//比较大小 
{
	if(a.length()>b.length())
		return true;
	else if(a.length()<b.length())
		return false;
	else if(a.length()==b.length())
	{
		for(int i=0;i<a.length();i++)
		{
			if(a[i]<b[i])
				return false;
			else if(a[i]>b[i])
				return true;
			else
				continue;
		}
	}
}
string add(string a,string b)//加法 
{
	a=a.substr(a.find_first_not_of('0'));
	b=b.substr(b.find_first_not_of('0'));
	
	int lenA=a.length();
	int lenB=b.length();
	int len=max(lenA,lenB)+5;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string ans(len,'0');
	for(int i=0;i<lenA;i++)
		ans[i]=a[i];
	int flag=0;
	for(int i=0;i<len;i++)
	{
		if(i<lenB)	flag+=(ans[i]-'0')+(b[i]-'0');
		else	flag+=(ans[i]-'0');
		ans[i]=flag%10+'0';
		flag/=10;
	}
	reverse(ans.begin(),ans.end());
	return ans.substr(ans.find_first_not_of('0'));
}

string sub(string a,string b)//减法，a-b 
{
	a=a.substr(a.find_first_not_of('0'));
	b=b.substr(b.find_first_not_of('0'));
	
	/*if(!cmp(a,b))//让a大于b 
	{
		string c=a;
		a=b;
		b=c;
	}*/
	
	int lenA=a.length();
	int lenB=b.length();
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string bns(lenA,'0');
	for(int i=0;i<lenB;i++)
		bns[i]=b[i];
	
	int flag=0;
	for(int i=0;i<lenA;i++)
	{
		a[i]=a[i]-'0'-flag+'0';
		if(a[i]>=bns[i])
		{
			a[i]=a[i]-bns[i]+'0';
			flag=0;
		}
		else
		{
			a[i]=a[i]-bns[i]+10+'0';
			flag=1;
		}
	}
	reverse(a.begin(),a.end());
	if(a.find_first_not_of('0')==string::npos)
		return "0";
	return a.substr(a.find_first_not_of('0'));
}

string div(string a,string b)
{
	a=a.substr(a.find_first_not_of('0'));
	b=b.substr(b.find_first_not_of('0'));
	
	string ans="0.";
	a+="0";
	for(int i=0;i<101;i++)
	{
		int count=0;
		while(cmp(a,b))
		{
			a=sub(a,b);
			//cout<<a<<endl;
			count++;	
		}
		a+="0";
		ans+=count+'0';
	}
	
	return ans;
}
int main()
{
	string a="1";
	string b="1";
	for(int i=0;i<300;i++)
	{
		string c=add(a,b);
		a=b;
		b=c;
		//cout<<c<<endl;
	}
	cout<<div(a,b);
	return 0;
}
