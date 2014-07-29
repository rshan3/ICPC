#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int used[20210];
int org[20210];
int a[20210];
int hash[10000109];
int sum,n;

struct node{
	int l,r;int c;
}tree[150030];



void buildtree(int cur,int a,int b){
	tree[cur].l=a;
	tree[cur].r=b;
	tree[cur].c=0;
	if(a==b) return;
	
	buildtree(cur*2,a,(a+b)>>1);
	buildtree(cur*2+1,((a+b)>>1) +1,b);

}

void insert(int cur,int a,int b,int k){

		if(tree[cur].c!=0) {return;}
			
		if(tree[cur].l==a && tree[cur].r==b) {
			tree[cur].c=k;
			if(used[k]==0) {sum++;used[k]=1;} 
			return;}
	
		int mid=(tree[cur].l+tree[cur].r)>>1;
		
		if(b<=mid) {
			insert(cur*2,a,b,k);
			}
		else if(a>mid){
			insert(cur*2+1,a,b,k);
			}
		else {
			insert(cur*2,a,mid,k);
			insert(cur*2+1,mid+1,b,k);
			}

		if(tree[cur*2].c!=0 && tree[cur*2+1].c!=0) {tree[cur].c=-1;}

}

int main(){
	freopen("in.txt","r",stdin);
	int ks;
	scanf("%d",&ks);
	while(ks--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",org+i);
			a[i]=org[i];
		}

		sort(a+1,a+1+2*n);
		
		int rank=1;
		hash[a[1]]=rank;
		for(int i=2;i<=2*n;i++){
			if(a[i]>a[i-1]) {
				rank+=(a[i]-a[i-1])>1?2:1;
				hash[a[i]]=rank;}
			else {hash[a[i]]=rank;}
		}

		buildtree(1,1,rank);
		sum=0;
		for(int i=2*n-1;i>0;i-=2){
			used[i]=0;
			insert(1,hash[org[i]],hash[org[i+1]],i);
			}
		printf("%d\n",sum);
	}

}
