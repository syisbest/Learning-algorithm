#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[9];
	a[0]=2;
	for(int i=1;i<5;i++)
		a[i]=i+3;
	for(int i=5;i<9;i++)
		a[i]=i+4;
	do{
		int r1=1+a[0]+a[3]+a[5];
		int r2=1+a[1]+a[4]+a[8];
		int r3=a[5]+a[6]+a[7]+a[8];
		int r4=8+a[0]+a[1]+a[2];
		int r5=8+a[3]+a[6]+3;
		int r6=3+a[2]+a[4]+a[7];
		if(r1==r2&&r2==r3&&r3==r4&&r4==r5&&r5==r6)
			for(int i=0;i<9;i++)
				cout<<a[i]<<endl;
	}while(next_permutation(a,a+9));
	return 0;
}
