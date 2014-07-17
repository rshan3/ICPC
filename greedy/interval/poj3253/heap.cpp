#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int n;

int main(){
	freopen("in.txt","r",stdin);
	while(cin >> n){
		vector<long long> c;
		long long t;
		for(int i=0;i<n;i++){cin >> t; c.push_back(t);}
		
		priority_queue<long long,vector<long long>,greater<long long> > q(c.begin(),c.end());

		long long cost=0;
		while(q.size()>1){
			long long a= q.top();q.pop();
			long long b=q.top();q.pop();
			cost+=(a+b);
			q.push(a+b);
			}		
		cout << cost << endl;
	}
	

	return 0;}
