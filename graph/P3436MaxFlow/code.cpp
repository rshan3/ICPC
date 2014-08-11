#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 100000
#define F 0
#define Start 1
#define End 2
using namespace std;
int vis[105],prev[105];
int G[105][105],orig[105][105];
int bit[105][11];
int ll[3000][3];
int T,n,p;

int Augment(){
	queue<int> que;
	bool flag=false;
	int ret=INF;
	memset(vis,0,sizeof(vis));
	memset(prev,0,sizeof(prev));

	que.push(1);
	vis[1]=1;
	while(!que.empty() && !flag){
		int v=que.front();
		que.pop();
		
		for(int i=1;i<=T;i++){
			if(G[v][i] && !vis[i]){
			
				vis[i]=1;prev[i]=v;que.push(i);
				if(i==T) {flag=true;break;}	
					}		
		}
		
		
	}

	if(!flag) return 0;
	int t=T;
	while(prev[t]){
		ret=min(ret,G[prev[t]][t]);
		t=prev[t];
	}	
	t=T;
	while(prev[t]){
		G[prev[t]][t]-=ret;
		G[t][prev[t]]+=ret;  			
		t=prev[t];
	}

	return ret;
}


void solve(){
	int ans,cnt,aug;
	ans=0;aug=0;cnt=0;
	memcpy(orig,G,sizeof(G));

	while(aug=Augment()){
		ans+=aug;
	}
	
	printf("%d ",ans);


	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(G[i<<1|1][j<<1]<orig[i<<1|1][j<<1]){
				ll[cnt][F]=orig[i<<1|1][j<<1]-G[i<<1|1][j<<1];
				ll[cnt][Start]=i;
				ll[cnt][End]=j;
				cnt++;
				}
			if(G[j<<1|1][i<<1]<orig[j<<1|1][i<<1]){
				ll[cnt][F]=orig[j<<1|1][i<<1]-G[j<<1|1][i<<1];
				ll[cnt][Start]=j;
				ll[cnt][End]=i;
				cnt++;
				}
	}
	}

	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%d %d %d\n",ll[i][Start],ll[i][End],ll[i][F]);
	}
	
}

bool check(int m,int f){

	for(int i=0;i<p;i++){
		if(bit[f][i]==2) continue;
		else {
			if(bit[f][i]!=bit[m][i]) return false;
			}
	}
	return true;
}

void init(){
		int v;

		T=(n<<1)+2;
		memset(G,0,sizeof(G));
		for(int i=2;i<T;i+=2){
			scanf("%d",&v);
			for(int j=0;j<p;j++) scanf("%d",&bit[i][j]);
			for(int j=0;j<p;j++) scanf("%d",&bit[i+1][j]);
			G[i][i+1]=v;

			int j;
			for(j=0;j<p;j++){if(bit[i][j]==1) break;} 
			if(j==p) G[1][i]=INF;
			
			for(j=0;j<p;j++) {if(bit[i+1][j]==0) break;}
			if(j==p) G[i+1][T]=INF;
		}
	
	
	for(int i=1;i*2<T;i++){
		
		for(int j=i+1;j*2<T;j++){
			if(check(j<<1|1,i<<1)) {G[j<<1|1][i<<1]=INF;}
			if(check(i<<1|1,j<<1)) {G[i<<1|1][j<<1]=INF;}
		}
	}


}
int main(){
		freopen("in.txt","r",stdin);
		while(scanf("%d%d",&p,&n)==2){
			init();
			solve();}


	return 0;}
