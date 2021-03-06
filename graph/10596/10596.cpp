#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
int G[201][201];
int n,r,tmp;
int deg[201];
int vis[201];

void init(){
	int a,b;
	for(int i=0;i<r;i++){
		cin >> a >> b;
		G[a][b]=1;G[b][a]=1;
		deg[a]++;deg[b]++;
		
		tmp=a;
		}	

}

void dfs(int i){
			vis[i]=1;
		for(int j=0;j<n;j++){
			if(G[i][j]!=0&&vis[j]==0) 
			dfs(j);
		}		
	}

bool check(){
			for(int i=0;i<n;i++){if(deg[i]%2==1) return false;}
			dfs(tmp);
			for(int i=0;i<n;i++) {if(!vis[i]) return false;}
			return true;
	}

int main(){
		freopen("in.txt","r",stdin);
	while(cin >> n >> r){
		memset(deg,0,sizeof(deg));
		memset(vis,0,sizeof(vis));
		tmp=0;
		for(int i=0;i<201;i++){
			for(int j=0;j<201;j++)
			G[i][j]=0;}
		init();
		
		if(check()) cout << "Possible\n";
		else cout << "Not Possible\n"; 
		}

	return 0;}
