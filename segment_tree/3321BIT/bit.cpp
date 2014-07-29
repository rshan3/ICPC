#include <iostream>
#include <cstdio>
using namespace std;
int Left[100005];
int Right[100005];
int G[100005][100];
int leng[100005];
int c[200005];
int app[100005];
int n,k,m,cnt,inc;
char op;

void dfs(int cur){

	Left[cur]=++cnt;
	for(int i=0;i<leng[cur];i++){
		dfs(G[cur][i]);
		}
	Right[cur]=cnt;
}

int sum(int p){

	int ret=0;
	while(p>0){
		ret+=c[p];
		p-=(p&-p);
	}
	return ret;
}

void add(int p,int d){

	while(p<=n){
		c[p]+=d;
		p+=(p&-p);
	}
}

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	int a,b;
	for(int i=0;i<n-1;i++){

		scanf("%d%d",&a,&b);
		G[a][leng[a]++]=b;		
	}
	cnt=0;
	dfs(1);
	for(int i=1;i<=n;i++){
		add(Left[i],1);
		app[i]=1;
		}	

	scanf("%d",&m);
	getchar();
	for(int i=0;i<m;i++){
		scanf("%c",&op);
		scanf("%d",&k);getchar();
		if(op=='C'){
			if(app[Left[k]]==1) inc=-1;
			else inc=1;
			app[Left[k]]=1-app[Left[k]];
			add(Left[k],inc);
				}
		else {
			int diff=sum(Right[k])-sum(Left[k]-1);
			printf("%d\n",diff);
			}
			
		}



	return 0;}
