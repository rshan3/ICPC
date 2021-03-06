
#include <iostream>
#include <cstdio>
#define MAXN 100005
using namespace std;
typedef long long ll;
int n,q;
ll ans,d;
struct node{
	int l,r;
	ll sum,inc;
}tree[3*MAXN];

void buildtree(int cur,int a,int b){
		
		tree[cur].l=a;tree[cur].r=b;
		tree[cur].sum=0;tree[cur].inc=0;
	
		if(a==b) {return;}
		else {
			int mid=(a+b)>>1;
			buildtree(cur*2,a,mid);
			buildtree(cur*2+1,mid+1,b);
		}
}


void add(int cur,int a,int b,ll d){
		if(tree[cur].l==a && tree[cur].r==b){
			tree[cur].inc+=d;
			return;	}
	
		tree[cur].sum+=d*(b-a+1);
		int mid=(tree[cur].l+tree[cur].r)>>1;
		if(b<=mid){
			add(cur*2,a,b,d);
			}
		else if(a>mid){
			add(cur*2+1,a,b,d);
			}
		else {
			add(cur*2,a,mid,d);
			add(cur*2+1,mid+1,b,d);

		}
		
}

void query(int cur,int a,int b){
		if(tree[cur].l==a && tree[cur].r==b){
			ans+=(tree[cur].sum+tree[cur].inc*(b-a+1));
			return;
		} 
		
		
		int mid=(tree[cur].l+tree[cur].r)>>1;
		ans+=(tree[cur].inc*(b-a+1));
		
		
		
		if(b<=mid){
			query(cur*2,a,b);
		}
		else if(a>mid){
			query(cur*2+1,a,b);	
		}
		else {
			query(cur*2,a,mid);
			query(cur*2+1,mid+1,b);
	}

}

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&q)==2){

		buildtree(1,1,n);
		ll t,d;int a,b;char ty;
		for(int i=1;i<=n;i++) {scanf("%lld",&t); 
		add(1,i,i,t);}
				
		for(int i=0;i<q;i++){
			getchar();
			scanf("%c",&ty);
			if(ty=='C'){
				scanf("%d",&a);
				scanf("%d",&b);
				scanf("%lld",&d);
				add(1,a,b,d);	}
			else{
				scanf("%d",&a);
				scanf("%d",&b);
				ans=0;
				query(1,a,b);
				printf("%lld\n",ans);
					}
						}
		
		}
	
	
	return 0;}
