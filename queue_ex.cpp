#include<iostream>
#include<queue> 
using namespace std;

int main()
{
	queue<int> a;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		a.push(i+1);
	while(!a.empty())
	{
		cout<<a.front();
		a.pop();
		int b = a.front();
		a.pop();
		a.push(b);
	}
    
    return 0;
}
