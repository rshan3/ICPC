#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005
using namespace std;
int Left[MAXN],Right[MAXN],arr[MAXN],cnt[MAXN];
int ans,last,num,n,q;

struct node{
	int l,r,maxi;
}tr[MAXN<<2];

void bldt(int cur,int a,int b){

	tr[cur].l=a;
	tr[cur].r=b;
	tr[cur].maxi=0;
	if(a==b) return;
	int mid=(tr[cur].l+tr[cur].r)>>1;
	bldt(cur<<1,a,mid);
	bldt(cur<<1|1,mid+1,b);
}

void insert(int cur,int a,int b,int k){
		tr[cur].maxi=max(k,tr[cur].maxi);
		if(a==tr[cur].l && b==tr[cur].r){
			return;
			}
		int mid=(tr[cur].l+tr[cur].r)>>1;
		if(b<=mid) insert(cur<<1,a,b,k);	
		else if(a>mid) insert(cur<<1|1,a,b,k);
		else {
			insert(cur<<1,a,mid,k);
			insert(cur<<1|1,mid+1,b,k);
			}

	}

int query(int cur,int a,int b){
		if(a==tr[cur].l && b==tr[cur].r){
			return tr[cur].maxi;
			}
		int mid=(tr[cur].r+tr[cur].l)>>1;
		if(b<=mid) return query(cur<<1,a,b);
		else if(a>mid) return query(cur<<1|1,a,b);
		else {
			return max(query(cur<<1,a,mid),query(cur<<1|1,mid+1,b));
		}
		
	}

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)){
		if(n==0) break;
		memset(cnt,0,(n+5)*sizeof(int));
		scanf("%d",&q);
		arr[0]=-100005;
		num=0;last=arr[0];
		for(int i=1;i<=n;i++) {
			scanf("%d",arr+i);
			if(arr[i]!=last){
				last=arr[i];
				arr[i]=++num;
				Right[arr[i-1]]=i-1;
				Left[arr[i]]=i;
				cnt[num]++;
				}
			else {	last=arr[i];
				arr[i]=num;
				cnt[num]++;}
		
			}
		Right[arr[n]]=n;
	
		bldt(1,1,num);
		for(int i=1;i<=num;i++) 
			insert(1,i,i,cnt[i]);
		int a,b,a1,b1;
		for(int i=0;i<q;i++){
			scanf("%d%d",&a,&b);
			if(arr[a]!=arr[b]){
				ans=max(Right[arr[a]]-a+1,b-Left[arr[b]]+1);
              			 a1=arr[a]+1;b1=arr[b]-1;
				if(a1<=b1)		
				ans=max(ans,query(1,a1,b1));}
			else ans=b-a+1;
			printf("%d\n",ans);		
			}
		
	
	}

	return 0;}
