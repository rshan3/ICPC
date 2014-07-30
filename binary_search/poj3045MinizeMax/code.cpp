#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
long long sum;
int n;

struct cow{

	int w,s,a;
	bool operator < (const cow & other) const {
		return a<other.a;}
}cows[50005];

bool C(int k){
	int i;long long ts=k;
	for(i=0;i<n;i++){
		if(cows[i].a<=ts){ts+=cows[i].w;}
		else break;
	}
	return i==n;
		
}

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	
	for(int i=0;i<n;i++) {scanf("%d%d",&cows[i].w,&cows[i].s);sum+=cows[i].w;}
	for(int i=0;i<n;i++) {cows[i].a=sum-cows[i].w-cows[i].s;}
	sort(cows,cows+n);
	long long lo,hi,mid,last;
	lo=cows[0].a;hi=cows[n-1].a;
	
	while(lo<=hi){

		mid=(lo+hi)>>1;
	
		if(C(mid)){last=mid;hi=mid-1;}
		else lo=mid+1;
}
	printf("%lld\n",last);
	
	return 0;
}
