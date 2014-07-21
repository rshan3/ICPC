/*
	Floyd Marshall algorithm may work, and it takes O(n^3) time.
	However, all the edge's weight is 1, so bfs may apply and this algorithm runs O(n^2).
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 2147483647
using namespace std;
int G[303][303];
int d[303][303];
int vis[303];
int a[302];
int n,m;
int tmin;

void search(int i){
	memset(vis,0,sizeof(vis));
	queue<int> que;
	que.push(i);
	
	int deg=0;		d[i][i]=0;vis[i]=1;
	while(!que.empty()){
		int k=que.front();
		
		que.pop();
		for(int j=1;j<=n;j++){
			if(G[k][j] && vis[j]==0){
				if(d[j][i]==0){
					d[j][i]=d[k][i]+1;
					d[i][j]=d[j][i];
						}
				else {d[i][j]=d[j][i];}
				deg+=d[i][j];
				que.push(j);
				vis[j]=1;
				}
			}
		
		}
	if(deg<tmin) tmin=deg;

}


int main(){
	freopen("in.txt","r",stdin);

	while(cin >> n >> m){
		for(int i=0;i<n;i++) memset(d[i],0,sizeof(d[i]));
		for(int i=0;i<n;i++) memset(G[i],0,sizeof(d[i]));
		for(int i=0;i<m;i++){
			int num;
			cin >> num;
			for(int j=0;j<num;j++){
				cin >> a[j];
					}
			for(int j=0;j<num;j++){
				for(int k=j+1;k<num;k++){
					G[a[j]][a[k]]=1;G[a[k]][a[j]]=1;
					}	}
			}
		tmin=INF;
	
		for(int i=1;i<=n;i++)		
		search(i);

		printf("%d\n",(int)(100*(double(tmin)/(n-1))) );

	}


	return 0;}
