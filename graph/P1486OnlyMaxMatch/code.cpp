#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define MAXN 100
using namespace std;
int G[MAXN][MAXN];
int vis[MAXN],match[MAXN],orig[MAXN],xl[MAXN],xr[MAXN],yl[MAXN],yr[MAXN],out_p[MAXN];
int n,m;
bool flag;

int aug(int k){
	
	for(int i=1;i<=n;i++){
		if(G[k][i] && !vis[i]){
			vis[i]=1;
			if(match[i]==-1 || aug(match[i])){
				match[i]=k;
				return 1;				
				}
			}
		}

	return 0;
}

int hungary(){
	memset(match,-1,sizeof(match));
	int ans=0;
	
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(aug(i)) ans++;
		}
	return ans;	
}

void solve(){
	flag=false;
	m=hungary();
	memcpy(orig,match,sizeof(match));
	memset(out_p,0,sizeof(out_p));	


	for(int i=1;i<=n;i++){
		G[orig[i]][i]=0;
		if(hungary()<m) {flag=true;out_p[i]=1;}
		
		G[orig[i]][i]=1;
		}
	
}

void include(int a,int b,int idx){
	for(int i=1;i<=n;i++){
		
		if(xl[i]<a && a<xr[i] && yl[i]<b && b<yr[i]){
			G[idx][i]=1;		
			}
		}
	
}

int main(){
	freopen("in.txt","r",stdin);
	int px,py;
	int cnt=0;
	while(~scanf("%d",&n)){
			if(n==0) break;
			memset(G,0,sizeof(G));
			for(int i=1;i<=n;i++){
				scanf("%d%d%d%d",xl+i,xr+i,yl+i,yr+i);
				
		}

			for(int i=1;i<=n;i++){
				scanf("%d%d",&px,&py);{
					include(px,py,i);
						}}

			solve();
			cnt++;
			printf("Heap %d\n",cnt);
			if(flag) {
				for(int i=1;i<n;i++) {if(out_p[i]){printf("(%c,%d) ",'A'+i-1,orig[i]);}}
				if(out_p[n])printf("(%c,%d)",'A'+n-1,orig[n]);
				printf("\n\n");
					}
			else printf("none\n\n");
			}
		


	return 0;}
