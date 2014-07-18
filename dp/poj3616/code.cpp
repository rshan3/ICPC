/*
	OK,got some trouble here.
	First, U cannnot using 01BAG pattern here,when you use 2-dim d[i][j], where i for the interval and j for the starting time.. U may find the algorithm takes O(n^2) time(equally for the one d version or for any thing you do for optimize j...
	So, just consider these intervals, after sorting them according to the start time, u find some interval structs can be linked.. Therefore, dp on them. forget the TIME.
	Fix some interval, and initial it to its efficiency, check from the next itv until end to find the MAX chain(be careful with the start time).

*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,r;
int d[1005];

struct interval{

	int s,e,q;
}itv[1005];


void dp(){

	for(int i=m;i>=1;i--){
		d[i]=itv[i].q;
		for(int j=i+1;j<=m;j++){
			if(itv[j].s>=itv[i].e+r)
			d[i]=max(d[i],d[j]+itv[i].q);
			else
			d[i]=max(d[j],d[i]);
				}
		
			}
		
}

bool cmp(const interval & a,const interval & b){

	return a.s<b.s;
	
	}

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&n,&m,&r)==3){

		for(int i=1;i<=m;i++) scanf("%d%d%d",&itv[i].s,&itv[i].e,&itv[i].q);
		sort(itv+1,itv+1+m,cmp);
		dp();
		printf("%d\n",d[1]);
		
	}

	return 0;}
