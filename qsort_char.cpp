#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
using namespace std;

int cmp_char(const void *_a,const void *_b)
{
	char *a = (char*)_a;
	char *b = (char*)_b;
	return *a-*b;
}
int cmp_str(const void *_a,const void *_b)
{
	char *a = (char*)_a;
	char *b = (char*)_b;
	return strcmp(a,b);
}
int main()
{
	int n = 0;
	char word[2000][10],sorted[2000][10];
	while(true)
	{
		cin>>word[n];
		if(word[n][0]=='*')
			break;
		n++;
	}
	qsort(word,n,sizeof(word[0]),cmp_str);
	for(int i=0;i<n;i++)
	{
		strcpy(sorted[i],word[i]);
		qsort(sorted[i],strlen(sorted[i]),sizeof(char),cmp_char);
	}
	char s[10];
	while(cin>>s)
	{
		bool found = false;
		qsort(s,strlen(s),sizeof(char),cmp_char);
		for(int i=0;i<n;i++)
		{
			if(strcmp(s,sorted[i])==0)
			{
				found = true;
				cout<<word[i]<<" ";
			}
		}
		cout<<endl;
		if(!found) cout<<":)";
	}
	return 0;
}
