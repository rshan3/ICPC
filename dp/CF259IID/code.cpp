#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int n,all,maxi;
int a[101],ans[101];
int d[1<<17][101];
int prev[1<<17][101],out[1<<17][101];


int factor(int k){
	int ret=0;
	if(k==1) return ret;
	
	for(int i=0;prime[i]<=k;i++){
		if(k%prime[i]==0){
			ret|=1<<i;
			}}
	return ret;
}



void dp(){
	int limit=2*maxi-1;int fac;int idx;
	for(idx=0;idx<17;idx++) if(prime[idx]>=limit) break;
	all=(1<<(idx+1))-1;
	d[0][0]=0;

	for(int S=0;S<=all;S++){
			
			for(int i=1;i<=n;i++){
				d[S][i]=d[S][i-1]+abs(1-a[i]);prev[S][i]=S;out[S][i]=1;
				for(int j=1;j<=limit;j++){
					fac=factor(j);
					if((S|fac)==S) {
						if(d[S^fac][i-1]+abs(j-a[i])<d[S][i]) {
							d[S][i]=d[S^fac][i-1]+abs(j-a[i]);prev[S][i]=S^fac;out[S][i]=j;}
						
					}		
			}

	}
	
}
	int t,S,i;	
	t=n;S=all;i=0;
	while(t){
		
		ans[t]=out[S][t];
		
		S=prev[S][t];
		t--;
			}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
}


int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		{scanf("%d",a+i);maxi=max(maxi,a[i]);}
	dp();
	//printf("%d\n",d[all][n]);
		return 0;
}
