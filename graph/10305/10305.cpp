#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int G[101][101];
int vis[101];
int ind[101];
int outd[101];
int n,m,t;
int topo[101];

void init(){
	t=n;
	int a,b;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		G[a][b]=1;
		ind[b]++;
		outd[a]++;
		}

	}

void dfs(int i){

		vis[i]=1;
		for(int j=1;j<=n;j++){
			if(G[i][j]==1&&vis[j]==0){
				dfs(j);	}
		}

	topo[--t]=i;
	}

int main(){
	freopen("in.txt","r",stdin);
	while(cin >> n >> m){
		if(n==0&&m==0) break;
		memset(vis,0,sizeof(vis));
		memset(ind,0,sizeof(ind));
		memset(outd,0,sizeof(outd));
		for(int i=0;i<101;i++)
			for(int j=0;j<101;j++){
				G[i][j]=0;}		
		init();
		for(int i=1;i<=n;i++){
			if(ind[i]==0&&vis[i]==0)		
			dfs(i);}
		for(int i=0;i<n-1;i++){cout << topo[i] << ' ';}
		cout << topo[n-1] << endl;
		}

return 0;}
