#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
int n,m,maxp;
int G[26][26];


void dfs(int cur,int pat){
	
	if(pat>maxp) maxp=pat;
	for(int i=0;i<n;i++){
		if(G[cur][i]){
			G[cur][i]=0;G[i][cur]=0;
			dfs(i,pat+1);
			G[cur][i]=1;G[i][cur]=1;
		}}

}

int main(){
	freopen("in.txt","r",stdin);
	while(cin >> n >> m){
		if(n==0) break;
		int a,b;maxp=0;
		for(int i=0;i<26;i++) {memset(G[i],0,sizeof(G[i]));}
		for(int i=0;i<m;i++){
			cin >> a >> b;
			G[a][b]=1;
			G[b][a]=1; 
			}
		for(int i=0;i<n;i++){
			dfs(i,0);
		}
		cout << maxp << endl;
		}

	return 0;}
