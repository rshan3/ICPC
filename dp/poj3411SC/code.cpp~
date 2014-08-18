#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 10000000
using namespace std;
int r[15][6];
vector<int> G[15];
int d[1<<12][15];
int n,m;

void dp(){
	int* rd,cost,to;
	for(int S=0;S<(1<<n);S++){
		for(int k=0;k<2;k++){
		for(int i=1;i<=n;i++){
			
			for(int j=0;j<G[i].size();j++){
				
				if(d[S][i]!=INF){
					rd=r[G[i][j]];
					to=rd[1];
					if((S>>(rd[2]-1)) & 1) cost=rd[3];
					else cost=rd[4]; 
					d[S|(1<<(to-1))][to]=min(d[S|(1<<(to-1))][to],d[S][i]+cost);
					}				
				}
			}}
	}
	

}

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) G[i].clear();
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d%d",&r[i][0],&r[i][1],&r[i][2],&r[i][3],&r[i][4]);
		if(r[i][2]==1) r[i][4]=r[i][3];
		G[r[i][0]].push_back(i);		
		}
	
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			d[i][j]=INF;}
		}
	d[0][1]=0;
	dp();
	int ans=d[0][n];
	for(int i=1;i<(1<<n);i++) {
		ans=min(ans,d[i][n]);	}
	if(ans!=INF)
	printf("%d\n",ans);
	else printf("impossible\n");

	return 0;}
