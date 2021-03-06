#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 50003
#define MAXM 500005
#define INF 1000000
using namespace std;
int res;
int s[MAXM];
int t[MAXM];
int n,m;
struct node{
	int l,r,v;
}sgt[MAXN<<4];

void bldt(int cur,int a,int b){
	sgt[cur].l=a;sgt[cur].r=b;sgt[cur].v=INF;	
	if(a==b) {
		return;
	}
	int mid=(a+b)>>1;
	bldt(cur<<1,a,mid);
	bldt(cur<<1|1,mid+1,b);
	
}

void upd(int cur,int a,int b,int d){
	if(sgt[cur].v<=d) return;
	
	if(sgt[cur].l==a && sgt[cur].r==b){
		sgt[cur].v=d;	
	}
	
	int mid=(sgt[cur].l+sgt[cur].r) >> 1;
	
	if(b<=mid) upd(cur<<1,a,b,d);
	else if(a>mid) upd(cur<<1|1,a,b,d);
	else{
		upd(cur<<1,a,mid,d);
		upd(cur<<1|1,mid+1,b,d);
	}
	
}

int query(int cur,int q,int poss){

	if(sgt[cur].l==q && sgt[cur].r==q){
		return min(poss,sgt[cur].v);	
	}
	
	int mid=(sgt[cur].l+sgt[cur].r) >> 1;
	int d=min(poss,sgt[cur].v);

	if(q<=mid) return query(cur<<1,q,d);
	else {
		return query(cur<<1|1,q,d);
	}
}

void dp(){
	
	for(int i=m-1;i>=0;i--){
		res=query(1,t[i],INF);
			
		upd(1,s[i],t[i],res+1);
		
			}
}

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<m;i++){
		scanf("%d%d",s+i,t+i);}
	bldt(1,1,n);
	
	upd(1,n,n,0);
	dp();
	printf("%d",query(1,1,INF));
	return 0;}
