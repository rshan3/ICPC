#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int pos[50005];int n;

struct cow{
	int s;int e;
	int idx;
	bool operator <(const cow & other) const{return e>other.e;}
	
}cows[50005];




bool cmp(const cow & a,const cow & b){

 return a.s<b.s;
		
}





int main(){
	freopen("in.txt","r",stdin);
	
	while(scanf("%d",&n)==1){

		for(int i=0;i<n;i++) {scanf("%d%d",&cows[i].s,&cows[i].e);cows[i].idx=i+1;}

		sort(cows,cows+n,cmp);
		priority_queue<cow> que;
		que.push(cows[0]);int cnt=1;pos[cows[0].idx]=cnt;
		for(int i=1;i<n;i++){
			if(cows[i].s<=que.top().e) {cnt++;que.push(cows[i]);pos[cows[i].idx]=cnt;}
			else {
				pos[cows[i].idx]=pos[que.top().idx];
				que.pop();que.push(cows[i]);
			}}
		
		printf("%d\n",cnt);
		for(int i=1;i<n+1;i++){
			printf("%d\n",pos[i] );
			}			
		}

	

	return 0;}
