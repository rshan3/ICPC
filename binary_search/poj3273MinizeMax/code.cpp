#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100005
#define INF 21474783647
using namespace std;
int n,m;
int up,low,mid,ans;
int x[MAXN];

int judge(int money){
	int i,j;int sum;int cnt=0;
	i=0;
	while(i<n){
		sum=0;
		for(j=i;j<n;j++) {
			if(sum+x[j]<=money) {sum+=x[j];}
			else break;
			
			}
		cnt++;
		i=j;
	}
	return cnt<=m;
}

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&m)==2){
		up=0;low=0;
		for(int i=0;i<n;i++) {scanf("%d",&x[i]);up+=x[i];low=max(low,x[i]);}

		while(low<=up){

			mid=(up+low)/2;
			
			if(judge(mid)) {up=mid-1;ans=mid;}
			else {low=mid+1;}
		}
		
		cout << ans << endl;
		}


	return 0;}
