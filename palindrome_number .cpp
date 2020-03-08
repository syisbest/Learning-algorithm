#include<iostream>
using namespace std;
bool is_true(int *a,int n)//n=5,4
{
    bool check=true;
    for(int i=0;i<=n/2;i++)
    {
        if(a[i]!=a[n-i])
            check=false;
    }
    return check;
}
int add(int *a,int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
	return sum;
}
int abc(int *a,int n)
{
	int b=-1;
	int i;
	 for(i=10000;i<=999999;i++)
    {
        int j=0;
        int num=i;
        while(num)
        {
            int p = num%10;
            num /= 10;
            a[j++] = p;
        }
        int jj=j-1;
        if(is_true(a,jj))
        {
        	int sum=add(a,j);
        	if(sum==n)
        	{
        		cout<<i<<endl;
        		b=i;
        	}
                
        }          
    }
    return b;
}
int main()
{
    int a[6];
    int n;
    cin>>n;
    int b=abc(a,n);
    if(b==-1)
    	cout<<-1;
    return 0;
}
