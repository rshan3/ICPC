/*
	Tricky question.
	I know greedy method may work. However, at first I did not find the right greedy way.
	Consider a lotion, any cow whose minum SPF less than its v may use it. We must choose the most proper cow to use it. By saying proper, I mean the cow has the least other options...
	When taking these interval problem, we usually sort them according to the left bound in order to make it easy to index, So we fix a lotion and push all the possible cow into a priority queue which constructed by the right bound( in order to find the one has least other options) and pop and push, you know it.
	Check the code!



*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int l,c,cnt;
struct cow{
	int lower,upper;
	bool operator < (const cow & other) const {

		return lower<other.lower;}

}cows[2505];

struct lotion{
	int v;int cov;
	
	bool operator < (const lotion & other) const{
		return v<other.v;}

	}lotions[2505];


struct cmp{

	bool operator ()(const cow & a,const cow & b){
			return a.upper>b.upper;
		}

};

int main(){
	freopen("in.txt","r",stdin);
	while(cin >> c >> l){

		for(int i=0;i<c;i++) cin >> cows[i].lower >> cows[i].upper;
		for(int i=0;i<l;i++) { cin >> lotions[i].v >> lotions[i].cov;
			}

		sort(cows,cows+c);
		sort(lotions,lotions+l);

		int i,j;cnt=0;
		priority_queue<cow, vector<cow>, cmp> q;
		i=0;j=0;
		while(i<l){
			while(lotions[i].cov--){
		
			for(;j<c&&cows[j].lower<=lotions[i].v;j++){
				if(lotions[i].v<=cows[j].upper) q.push(cows[j]);
				}

		
	
			while(!q.empty()){
				if(q.top().upper>=lotions[i].v){cnt++;q.pop();break;}
				else q.pop();
						}

			
				}
			i++;
		}
		cout << cnt << endl;
		}

	return 0;}
