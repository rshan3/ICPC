/*
	First segment tree code, seperete build tree and insert.
	Be careful;
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 50005
#define INF 1e9
using namespace std;
int minV,maxV;
struct Node{
	int l,r;int maxi,mini;
};

int n,q;
int h[MAXN];
Node segt[4*MAXN];

void buildtree(int root,int l,int r){
	segt[root].mini=INF;
	segt[root].maxi=-INF;
	segt[root].r=r;
	segt[root].l=l;
	if(l<r){
	buildtree(root*2,l,(r+l)>>1);
	buildtree(root*2+1,1+((r+l)>>1),r);}
	return;

}
void insert(int i,int root,int v){
		if(segt[root].l==segt[root].r) {segt[root].mini=v;segt[root].maxi=v;return;}
		
		segt[root].maxi=max(segt[root].maxi,v);
		segt[root].mini=min(segt[root].mini,v);
		
		int mid=(segt[root].l+segt[root].r)>>1;
		if(i<=mid){
			insert(i,root*2,v);
			}
		else insert(i,root*2+1,v);
		

}

void query(int root,int a,int b){
		if(segt[root].l==a && segt[root].r==b){
			minV=min(minV,segt[root].mini);
			maxV=max(maxV,segt[root].maxi);
			return;
		}	
			
		int mid=(segt[root].r+segt[root].l)>>1;
		if(b<=mid){
			query(root*2,a,b);
		}
		else if(a>mid){
			query(root*2+1,a,b);
				}
				
		else {
			query(root*2,a,mid);
			query(root*2+1,mid+1,b);
		}
				
}


int main(){
	freopen("in.txt","r",stdin);	
	while(scanf("%d%d",&n,&q)==2){
		buildtree(1,1,n);
		int t;
		for(int i=1;i<=n;i++){
			scanf("%d",&t);
			insert(i,1,t);
			}
		
		int a,b;
		for(int i=0;i<q;i++){
			scanf("%d%d",&a,&b);
			minV=INF;maxV=-INF;
			query(1,a,b);
			printf("%d\n",maxV-minV);
		}
	
	}

	return 0;
}
