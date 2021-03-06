/*
	Usually, we'd first tend to save the sum in the node, and update it.
	However, When some increasment is taken on some intervals, say i----j; for all the subtree below i---j, u 	need to update their sum, and it takes O(n) per operation, however, we wanna to be log n.
	The method is to use the way of stuck or delay. When some increasement is taken on certain interval i to   j, just record the increase value as a variable of the node, and leave its subtree unchanged.
	However,if the interval does not fit, u need to update its sum, cause it is during the O(lgn) process, u dont want the delay happen everywhere.
	When query is performed, you have to deal with the increasment(delay), update the current sum and pass down the increasment. U need to make sure the interval(1 or 2) has received its ancestors' increase. 

*/
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
		
		tree[cur].sum+=tree[cur].inc*(tree[cur].r-tree[cur].l+1);
		int mid=(tree[cur].l+tree[cur].r)>>1;
		add(cur*2,tree[cur].l,mid,tree[cur].inc);
		add(cur*2+1,mid+1,tree[cur].r,tree[cur].inc);

		tree[cur].inc=0;
		
		
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
