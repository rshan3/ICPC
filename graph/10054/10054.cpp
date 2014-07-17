#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int G[51][51];
int deg[51];
int vis[51][51];
int n,tt;
int cnt;
int aa[2500];
int num[51];
void init(){
	
	cin >> n;int a,b;
	for(int i=0;i<n;i++){
		cin >> a;
		cin >> b;
		deg[a]++;deg[b]++;
		G[a][b]++;
		G[b][a]++;	
		}

	}

void dfs(int i){
		
		num[i]=1;
		for(int j=0;j<51;j++){
			if(G[i][j]!=0 && vis[i][j]<G[i][j])
			{vis[i][j]++;vis[j][i]++;dfs(j);
			aa[cnt++]=j;
			aa[cnt++]=i;}
			}
		
}

bool check(){	
		
		for(int i=0;i<51;i++){	
			if(deg[i]%2==1) return false;
			
		}
	int si;
	for(si=0;si<51;si++) {if(deg[si]!=0) break;}
	
	dfs(si);
	for(int i=0;i<51;i++) {if(num[i]==0&&deg[i]>0) return false;}
	return true;
	}


int main(){
	freopen("in.txt","r",stdin);
	int testcase;tt=1;
	cin >> testcase;
	while(testcase--){
		memset(num,0,sizeof(num));
		memset(aa,0,sizeof(aa));
		memset(deg,0,sizeof(deg));
		for(int i=0;i<51;i++) {
		 	for(int j=0;j<51;j++){
			G[i][j]=0;vis[i][j]=0;}}
		cnt=0;
		init();
		bool ans=check();
		printf("Case #%d\n",tt++);
		if(ans){
		for(int i=cnt-1;i>0;i-=2){
			cout << aa[i];
			cout << " " << aa[i-1] << endl;
		}	}
		else cout << "some beads may be lost\n";
		if(testcase) cout << endl;
		}


	return 0;}
