#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct P
{
	int ts,id;	
};
bool cmp(P p1,P p2)
{
	return p1.ts<p2.ts;
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,D,K;
	cin>>N>>D>>K;
	vector<P> records(N);
	for(int p=0;p<N;p++)
		cin>>records[p].ts>>records[p].id;
	sort(records.begin(),records.end(),cmp);
//	for(int i=0;i<N;i++)
//		cout<<records[i].ts<<endl;
	map<int ,int> cut;//记录id出现个数 
	set<int> ans;//结果按顺序存好 
	int j=0;
	for(int i=0;i<N;i++)
	{
	 	while(j<N&&records[j].ts-records[i].ts<D)
	 	{
	 		cut[records[j].id]++;
	 		if(cut[records[j].id]>=K)
	 			ans.insert(records[j].id);
	 		j++;
	 	}
	 	cut[records[i].id]--;
	}
	for(set<int>::iterator it=ans.begin();it!=ans.end();it++)
		cout<<*it<<endl;
	return 0;
}

