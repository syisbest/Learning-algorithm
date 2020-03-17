#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int A[100];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>A[i];
	sort(A,A+n);
	int p,q;
	for(int i=0;i<m;i++)
	{
		cin>>p>>q;
		cout<<upper_bound(A,A+n,q)-lower_bound(A,A+n,p)<<endl;
	}
	return 0;
}
