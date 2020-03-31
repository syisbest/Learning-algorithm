#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int ans=0;
	int a[9]={1,2,3,4,5,6,7,8,9};
	do{
		int A=a[0];
		int B=a[1];
		int C=a[2];
		int D=a[3]*100+a[4]*10+a[5];
		int E=a[6]*100+a[7]*10+a[8];
		int F=A+(B*E+C*D)/(C*E);
		if((B*E+C*D)%(C*E)==0&&F==10)
			{
				cout<<A<<"+"<<B<<"/"<<C<<"+"<<D<<"/"<<E<<"=10"<<endl;
				ans++;
			}
	} while(next_permutation(a,a+9));
	cout<<ans;
	return 0;
}
