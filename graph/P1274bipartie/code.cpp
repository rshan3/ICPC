#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int G[505][505];
int vis[505];
int match[505];
int n,m,ans;

int aug(int k){
	
	for(int i=1;i<=m;i++){
		if(G[k][i] && !vis[i]){
			vis[i]=1;
			if(match[i]==0||aug(match[i])){
				match[i]=k;
				return 1;
				}
			
		}
	}
	return 0;
}

int main(){
	freopen("in.txt","r",stdin);
	int num,t;
	while(scanf("%d%d",&n,&m)==2){
		memset(match,0,sizeof(match));
		memset(G,0,sizeof(G));
		for(int i=1;i<=n;i++){
			scanf("%d",&num);
			for(int j=0;j<num;j++){
				scanf("%d",&t);
				G[i][t]=1;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			if(aug(i)){
				ans++;}
			}
		
		printf("%d\n",ans);
		
	}
	

	return 0;}
