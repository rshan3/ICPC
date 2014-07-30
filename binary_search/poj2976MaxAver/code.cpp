#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n,k;
long long a[1005],b[1005],t[1005];

bool cmp(const long long a,const long long b){

	return a>b;
}

bool C(int x){
	for(int i=0;i<n;i++) t[i]=a[i]*1000-b[i]*x;

	sort(t,t+n,cmp);
	long long sum=0;
	for(int i=0;i<n-k;i++) sum+=t[i];
	
	return sum>=0;

}

int main(){
	freopen("drop.txt","r",stdin);
	freopen("a.txt","w",stdout);
	while(scanf("%d%d",&n,&k)==2){
		if(n==0 && k==0) break;
		for(int i=0;i<n;i++){scanf("%lld",a+i);}
		for(int i=0;i<n;i++){scanf("%lld",b+i);}

		int lo=0;int hi=1000;int mid,last;
		while(lo<=hi){
			mid=(lo+hi)>>1;
			if(C(mid)) {last=mid;lo=mid+1;}
			else hi=mid-1;
		
		}
		
		if((last%10) >=5) printf("%d\n",last/10+1);
		else printf("%d\n",last/10);
}


	return 0;}
