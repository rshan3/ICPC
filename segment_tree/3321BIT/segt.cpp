#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
int n,m,cnt;
int Left[100005];
int a[100005];
int sa[100005];
int Right[100005];

int G[100005][100];
struct node{
	int l,r;
	int sum,app;
	
}tree[400030];


void dfs(int cur){
	
	Left[cur]=++cnt;
	
	for(int i=0;G[cur][i]!=0;i++){
		dfs(G[cur][i]);
		
		
	}
	Right[cur]=cnt;

}

int query(int cur,int a,int b){
	if(a==tree[cur].l && b==tree[cur].r){
		return tree[cur].sum;
	}
	
	int mid=(tree[cur].l+tree[cur].r)>>1;	
	if(b<=mid) {return query(cur<<1,a,b);}
	else if(a>mid) {return query(cur<<1|1,a,b);}
	else {
		return query(cur<<1,a,mid)+query(cur<<1|1,mid+1,b);
		}
	
}
void buildtree(int cur,int a,int b){
	tree[cur].l=a;tree[cur].r=b;
	tree[cur].sum=0;tree[cur].app=0;
	
	if(a==b) return;
	int mid=(tree[cur].l+tree[cur].r)>>1;
	buildtree(cur<<1,a,mid);
	buildtree(cur<<1|1,mid+1,b);

}

void upd(int cur,int tl){
	if(tree[cur].l==tree[cur].r){ 
		tree[cur].sum+=(tree[cur].app==0)?1:-1;
		tree[cur].app=1-tree[cur].app;
		return ;}

	int mid=(tree[cur].l+tree[cur].r)>>1;
	
	if(tl<=mid) {upd(cur<<1,tl);}
	else if(tl>mid) {upd(cur<<1|1,tl);}
	else {
		upd(cur<<1,tl);
		}
	tree[cur].sum=tree[cur].app+tree[cur<<1].sum+tree[cur<<1|1].sum;
	}

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)==1){
		int a,b;
		for(int i=0;i<n-1;i++){

		scanf("%d%d",&a,&b);
		G[a][sa[a]++]=b;
	}
		cnt=0;
		dfs(1);

		buildtree(1,1,cnt);
		for(int i=1;i<=n;i++){
			upd(1,Left[i]);
			}
		int k;char op;
		scanf("%d",&m);getchar();
		for(int i=0;i<m;i++){
			scanf("%c",&op);
			scanf("%d",&k);getchar();
			if(op=='Q'){
				a=Left[k];
				b=Right[k];
				int ans=query(1,a,b);
				printf("%d\n",ans);
					}
			if(op=='C'){
				a=Left[k];
				upd(1,a);
				}	
		}

		
	
}

	return 0;}
