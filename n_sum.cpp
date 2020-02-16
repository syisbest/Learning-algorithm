#include <iostream>
using namespace std;

void Print(bool *b,int *a)
{
	for(int i=0;i<10;i++)
	{
		if(b[i]==true)
			cout<<a[i]<<" ";
	}
	cout<<endl;
}
void n_sum(int *a,bool *b,int i,int sum,int residue)
{
	if(i>=10)
		return ;
	if(a[i]==sum)
	{
		b[i] = true;
		Print(b,a);
		b[i] = false;
	}
	if(sum<=residue&&a[i]<=sum)
	{
		b[i] = true;
		n_sum(a,b,i+1,sum-a[i],residue-a[i]);
	}
	if(residue-a[i]>sum)
	{
		b[i] = false;
		n_sum(a,b,i+1,sum,residue-a[i]);
	}
	
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	bool b[10] = {0,0,0,0,0,0,0,0,0,0};
	int residue = 55;
	n_sum(a,b,0,20,residue);
	return 0;
}
