#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 1000000
using namespace std;
queue<int> que;
int G[235][235];
int a[235][235];
int K,C,M,T;
int prev[235],vis[235];

void floyd(){
	int n=K+C;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
}

int Augment(){
	int ret=INF;int t;bool flag;
	while(!que.empty()) que.pop();
	memset(vis,0,sizeof(vis));
	memset(prev,-1,sizeof(prev));
	flag=false;
	
	que.push(0);vis[0]=1;
	while(!que.empty() && !flag){
		int v=que.front();
		que.pop();
		for(int i=0;i<=K+C+1;i++){
			if(a[v][i]>0 && !vis[i]){
				prev[i]=v;vis[i]=1;
				que.push(i);
				if(i==T) {flag=true;break;}				
				}
		}
	}

	if(!flag) return 0;
	t=T;
	while(prev[t]!=-1){
		ret=min(ret,a[prev[t]][t]);
		t=prev[t];
		}
	t=T;
	while(prev[t]!=-1){
		a[prev[t]][t]-=ret;
		a[t][prev[t]]+=ret;
		t=prev[t];
		}
	return ret;


}

bool Check(int p){
	int ans,aug;
	memset(a,0,sizeof(a));
	for(int i=1;i<=K;i++) a[i][T]=M;
	for(int i=K+1;i<=K+C;i++) a[0][i]=1;

	for(int i=K+1;i<=K+C;i++){
		for(int j=1;j<=K;j++)
		if(G[i][j]<=p) {a[i][j]=1;}
		}

	ans=0;aug=0;
	while(aug=Augment()){
		ans+=aug;
	}
	
	return ans==C;
	
	

}

void solve(){
	
	
		int lo=0;int hi=40001;int mid,last;
		while(lo<=hi){

			mid=(lo+hi)>>1;
			if(Check(mid)){last=mid;hi=mid-1;}
			else lo=mid+1;	
	}

		printf("%d",last);
	}


int main(){
	int tmp;
	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&K,&C,&M);
	for(int i=0;i<235;i++) fill(G[i],G[i]+234,INF);
	T=K+C+1;	

	for(int i=1;i<=K+C;i++){
		for(int j=1;j<=K+C;j++){			
			scanf("%d",&tmp);
			if(i==j) G[i][j]=0;
			else {
				if(tmp!=0) G[i][j]=tmp;}
			
		}
		}
	floyd();
	solve();
	
	}
