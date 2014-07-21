#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int c,l,cnt;



struct cow{
	int high,low;
	cow (int xl,int xh){high=xh;low=xl;} 	
	
};

struct cmp{
	bool operator ()(const cow & a,const cow & b){
		if(a.low!=b.low){
			return a.low>b.low;}
		else return a.high<b.high;
	}

};
vector<cow> cows;
vector<int> lotions;

int main(){
	freopen("in.txt","r",stdin);

	int a,b;
	while(scanf("%d%d",&c,&l)==2){
		lotions.clear();
		cows.clear();
		for(int i=0;i<c;i++) {scanf("%d%d",&a,&b);
			cows.push_back(cow(a,b));
			}
		for(int i=0;i<l;i++){
			scanf("%d%d",&a,&b);
			for(int j=0;j<b;j++){
				lotions.push_back(a);	}
				}
			

		priority_queue<cow, vector<cow>, cmp> qc(cows.begin(),cows.end());
		priority_queue<int,vector<int>,greater<int> > ql(lotions.begin(),lotions.end());
		cnt=0;
		while(!ql.empty()&&!qc.empty()){
			if(ql.top()<qc.top().low){
				ql.pop();
			}
			else if(ql.top()>qc.top().high){
				qc.pop();
				}
			else{
				cnt++;
				ql.pop();
				qc.pop();
			}}
		printf("%d\n",cnt);
				
		}

	return 0;}
