#include<iostream>
#include<map>
using namespace std;


//O(n2)
/*int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,K;
	cin>>N>>K;
	int A[N];
	long long S[N+1];
	S[0]=0;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	long long ans=0;
	for(int i=0;i<N+1;i++)
	{
		for(int j=i+1;j<N+1;j++)
		{
			if((S[j]-S[i])%K==0)
				ans++;
		}
	}
	cout<<ans;
	return 0;
}*/

//O(n)
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,K;
	cin>>N>>K;
	int A[N];
	long long S[N+1];
	S[0]=0;
	map<int ,int> P;
	P[0]=1;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		S[i+1]=(S[i]+A[i])%K;
		P[S[i+1]]++;
	}
	long long ans=0;
	for(int i=0;i<K;i++)
	{
		if(P[i]!=0)
			ans+=(P[i]*(P[i]-1))/2;
	}
	cout<<ans;
	return 0;
}
