#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int count=2015-1225;
	for(int i=1;i<=46;i++)
	{
		for(int j=i+1;j<=49;j++)
			if((i*(i+1)-(i+i+1)+j*(j+1)-(j+j+1))==count)
				cout<<i<<" "<<i+1<<" "<<j<<" "<<j+1<<endl;
	}
	return 0;
}

