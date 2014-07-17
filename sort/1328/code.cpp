#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MIS 1e-9
using namespace std;
int n,d;

struct point{
	int x;int y;
}pts[1005];

struct interval{
	double s;double e;
}itv[1005];



bool cmp(const interval & a,const interval & b){
	 return a.s<b.s;


}




int main(){
	freopen("in.txt","r",stdin);
	int ks;
	while(cin >> n >> d){
	bool flag=true;
	if(n==0&& d==0) break;
	
	for(int i=0;i<n;i++) cin >> pts[i].x >> pts[i].y;

	for(int i=0;i<n;i++){
		if(pts[i].y>d) {flag=false;break;}
		double tx=sqrt(pow(d,2)-pow(pts[i].y,2));
		itv[i].s=pts[i].x-tx;
		itv[i].e=pts[i].x+tx;
	}
	if(!flag){printf("Case %d: -1\n",++ks); continue;}

	sort(itv,itv+n,cmp);
	int idx=0;double right;int cnt=0;
	while(idx<n){

		right=itv[idx].e;
		for(idx+=1;idx<n&&itv[idx].s<right+MIS;idx++){
			right=min(itv[idx].e,right);
			}
		cnt++;
		
			}
	printf("Case %d: %d\n",++ks,cnt);
	

	}
	
	return 0;}

