#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 50000
using namespace std;
int ans,n;
int d[40001];
int a[40001];
void dp(){
	for(int i=1;i<=n;i++) d[i]=INF;

	for(int i=1;i<=n;i++){
		*lower_bound(d+1,d+1+n,a[i]) = a[i];
	}

}

int main(){
	freopen("in.txt","r",stdin);
	int ks;
	scanf("%d",&ks);
	while(ks--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
			scanf("%d",a+i);
		
		dp();
		printf("%d\n",lower_bound(d+1,d+1+n,INF)-d-1);


	}


	return 0;}
