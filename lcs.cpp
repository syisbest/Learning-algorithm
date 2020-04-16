#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int LongestCommonSubstring(string s1,string s2)
{
	int dp[s1.length()+1][s2.length()+1];
	memset(dp,0,sizeof(dp));
	int max=0;
	for(int i=1;i<s1.length()+1;i++)
		for(int j=1;j<s2.length()+1;j++)
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]+=(dp[i-1][j-1]+1);
				if(dp[i][j]>max)
					max=dp[i][j];
			}
	return max;
}
int longestCommonSequence(string s1,string s2)
{
	int dp[s1.length()+1][s2.length()+1];
	memset(dp,0,sizeof(dp));
	int max=0;
	for(int i=1;i<s1.length()+1;i++)
		for(int j=1;j<s2.length()+1;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]+=(dp[i-1][j-1]+1);
				if(dp[i][j]>max)
					max=dp[i][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
			}
		}
			
	return max;
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1;
	string s2;
	cin>>s1>>s2;
	int ans=LongestCommonSubstring(s1,s2);
	int ans2=longestCommonSequence(s1,s2);
	cout<<ans<<endl;
	cout<<ans2<<endl;
	return 0;
}
