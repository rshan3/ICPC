#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MAXN 20005
#define MAXX 262144
using namespace std;
typedef long long ll;

ll c[MAXX+1],q[MAXX+1];
ll ans,num_below,num_above,sum_below,sum_above;
int n;


void add1(int x,int d){

	while(x<=MAXX){
		c[x]+=d;
		x+=(x&-x);
	}
}

ll sum1(int x){
	ll ret=0;
	while(x>0){
	ret+=c[x];
	x-=(x&-x);
	}
	return ret;
}


void add2(int x,int d){

	while(x<=MAXX){
		q[x]+=d;
		x+=(x&-x);
	}
}

ll sum2(int x){
	ll ret=0;
	while(x>0){
	ret+=q[x];
	x-=(x&-x);
	}
	return ret;
}
struct cow{
	int v,x;

	bool operator < (const cow & other) const {
		return v<other.v;
		}
}cows[MAXN];

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	memset(q,0,sizeof(q));
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++) scanf("%d%d",&cows[i].v,&cows[i].x);
	sort(cows+1,cows+1+n);

	ans=0;
	for(int i=1;i<=n;i++){
		num_below=sum1(cows[i].x);
		num_above=i-1-num_below;
		sum_below=sum2(cows[i].x);
		sum_above=sum2(MAXX)-sum_below;
		ans+=(num_below*cows[i].x-sum_below)*cows[i].v;
		ans+=(sum_above-num_above*cows[i].x)*cows[i].v;		
		add1(cows[i].x,1);
		add2(cows[i].x,cows[i].x);
		
		
	}
	printf("%lld",ans);
	

	
	return 0;}
