#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string flag="o*";
void reverseC(char &s)
{
	if(s==flag[0])
		s=flag[1];
	else
		s=flag[0];
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int ans=0;
	int lens=s1.length();
	for(int i=0;i<lens-1;i++)
		if(s1[i]!=s2[i])
		{
			reverseC(s1[i]);
			reverseC(s1[i+1]);
			ans+=1;
		}
	cout<<ans;
	return 0;
}
