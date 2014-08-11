#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 20000000
using namespace std;
int G[205][205];
int prev[205];
int vis[205];
int n,m,ans,aug;
bool flag;

int Augment(){
	queue<int> que;
	memset(prev,0,sizeof(prev));
	memset(vis,0,sizeof(vis));
	flag=false;
	
	que.push(1);
	vis[1]=1;
	
	while(!que.empty() && !flag){
		int v=que.front();
		que.pop();
		
		for(int i=1;i<=n;i++){
			if(G[v][i] && !vis[i]){
				prev[i]=v;vis[i]=1;
				if(i!=n){
					que.push(i);}
				else {flag=true;break;}
		}
		
	}}

	if(!flag) return 0;
		
	int ret=INF;int t=n;
	while(prev[t]){
		ret=min(ret,G[prev[t]][t]);
		t=prev[t];
	}
	t=n;
	while(prev[t]){
		G[prev[t]][t]-=ret;
		G[t][prev[t]]+=ret;	
		t=prev[t];
	}
	
	return ret;
	
}
	
	



void solve(){

	ans=0;aug=0;
	while(aug=Augment()){
		ans+=aug;
	}

}

int main(){
	freopen("in.txt","r",stdin);
	int a,b,c;
	while(scanf("%d%d",&m,&n)==2){
		memset(G,0,sizeof(G));
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			G[a][b]+=c;}

		solve();
		printf("%d\n",ans);		
	}

	
	return 0;}
