#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
const int maxn = 3000;
string n1[10] = { "��","һ","��","��","��","��","��","��","��","��"};
string n2[14] = { "��","��","Բ","ʮ","��","ǧ","��","ʮ","��","ǧ","��" ,"ʮ","��","ǧ"};

string replaceString(string &Money, string replaced, string replace)
{
	while (Money.find(replaced)<Money.length())
	{
		Money.replace(Money.find(replaced), replaced.length(), replace);
	}
	return Money;
}
struct bign
{
	int len;
	int a[maxn];
	bign()
	{
		len=1;
		memset(a,0,sizeof(a));
	}
	bign(const char *num){*this = num;}
	bign(int num){*this = num;}
	bign(float num){*this=num;}
	bign operator = (const char *num)
	{
		len = strlen(num);
		for(int i=0;i<len;i++) a[i] = num[len-i-1] - '0';//����洢
		return *this; 
	}
	bign operator = (int num)
	{
		char s[maxn];
		sprintf(s,"%d",num);
		*this = s;
		return *this;
	}
		bign operator = (float num)
	{
		char s[maxn];
		sprintf(s,"%.0f",num);
		*this = s;
		return *this;
	}
	bign operator + (const bign &b) const
	{
		bign c;
		c.len = 0;
		for(int i=0,g=0;g||i<max(len,b.len);i++)
		{
			int x=g;
			if(i<len) x += a[i];
			if(i<b.len) x+= b.a[i];
			c.a[c.len] = x % 10;
			c.len++;
			g = x / 10;
		}
		return c;
	}
	bign operator += (const bign &b)
	{
		*this = *this + b;
		return *this;
	}
	bign operator < (const bign &b) const
	{
		if(len!=b.len) return len<b.len;
		for(int i=len-1;i>=0;i--)
			if(a[i]!=b.a[i])
				return a[i]<b.a[i];
		return false;
	}
	string str() const
	{
		string str = "";
		for(int i=0;i<len;i++) str = (char)(a[i]+'0')+str;
		if(str=="") str="0";
		return str;
	}
};
istream& operator >> (istream &in,bign &b)
{
	string s;
	in>>s;
	b = s.c_str();
	return in;
}
ostream& operator << (ostream &out,const bign &b)
{
	out<< b.str();
	return out;
}

int main()
{
	bign a;	 
	float moneyNum;
	cin >> moneyNum;
	a = (float(moneyNum * 100));
	cout << a<<endl;
	for (int j = 0; j < a.len; j++)
		cout << a.a[j];
	cout << endl;
	string MoneyNum;
	for (int j = 0; j < a.len; j++)
		MoneyNum.append(n1[a.a[j]]);
	cout << MoneyNum << endl;
	string MoneyUnit;
	for (int j = 0; j < a.len; j++)
		MoneyUnit.append(n2[j]);
	cout << MoneyUnit << endl;
	string Money;
	
	for (int j = a.len - 1; j >= 0; j--)
	{
		Money.append(n1[a.a[j]]);
		Money.append(n2[j]);
	}
	cout << Money << endl;
	Money = replaceString(Money, "���", "��");
	Money = replaceString(Money, "��ǧ", "��");
	Money = replaceString(Money, "��ʮ", "��");
	Money = replaceString(Money, "����", "��");
	Money = replaceString(Money, "��Բ", "Բ");
	Money = replaceString(Money, "����", "��");
	Money = replaceString(Money, "����", "��");
	Money = replaceString(Money, "����", "��");
	Money = replaceString(Money, "������", "");
	Money = replaceString(Money, "���", "��");
	Money = replaceString(Money, "���", "");
	cout << Money;	
	return 0;
}
