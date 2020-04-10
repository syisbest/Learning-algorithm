#include<iostream>
#include<algorithm>
using namespace std;
	
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int N;
	cin>>N;
	int A[N],B[N],C[N];
	for(int i=0;i<N;i++)
		cin>>A[i]; 
	for(int i=0;i<N;i++)
		cin>>B[i];
	for(int i=0;i<N;i++)
		cin>>C[i];  
	sort(A,A+N);
	sort(B,B+N);
	sort(C,C+N);
	int i=0,k=0;
	long long ans=0;
	for(int j=0;j<N;j++)
	{
		while(i<N)
		{
			if(B[j]>A[i])
				i++;
			else
				break;
		}
		while(k<N)
		{
			if(C[k]<=B[j])
				k++;
			else
				break;
		}
		ans+=i*(N-k);
	}
	cout<<ans;
	return 0;
}

