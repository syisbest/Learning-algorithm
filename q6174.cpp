#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

int get_next(int num)
{
	int a,b;
	char s[10];
	sprintf(s,"%d",num);
	int n=strlen(s);
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(s[i]<s[j])
			{
				char a = s[i];
				s[i] = s[j];
				s[j] = a;
			}
	sscanf(s,"%d",&a);
	for(int i=0;i<n/2;i++)
	{
		char a=s[i];
		s[i] = s[n-1-i];
		s[n-1-i] = a;
	}
	sscanf(s,"%d",&b);
	return a-b;
}
int main()
{
	int a[2000];
	int count=1;
	cin>>a[0];
	cout<<a[0];
	while(true)
	{
		a[count] = get_next(a[count-1]);
		cout<<"->"<<a[count];
		
		if(a[count] == a[count-1])
			break;
		count++;
	}
	return 0;
}
