#include<iostream>
#include<stack> 
using namespace std;

int main()
{
	stack<int> s;
	int n;
	int a[100];
	while(cin>>n)
	{
		int A=1,B=1;
		int ok=1;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		while(A<=n)
		{
			if(B==a[A]){A++;B++;}
			else if(B<=n){s.push(B++);}
			else if(!s.empty()&&s.top()==a[A]){s.pop();A++;}
			else{ok=0;break;}
		}
		if(ok)
			cout<<"yes";
		else
			cout<<"no";
	}
	
    return 0;
}
