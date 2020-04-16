#include<iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,K;
	cin>>N>>K;
	int H[N],W[N];
	for(int i=0;i<N;i++)
		cin>>H[i]>>W[i];
	int low=1;
	int high=100001;
	int ans=0;
	while(low<=high)
	{
		int mid=(low+high)/2;
		int cur=0;
		for(int j=0;j<N;j++)
		{
			cur+=(H[j]/mid)*(W[j]/mid);
		}
		if(cur>=K)
		{
			low=mid+1;
			ans=mid;
		}
		else
		{
			high=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
