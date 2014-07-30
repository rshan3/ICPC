#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int u[100005];
int d[100005];
int p[100005];
int v[100005];
int m,n,cnt;

void dp(){

	memset(d,0,sizeof(int)*(m+5));
	d[0]=1;
	
	for(int i=1;i<=n;i++){
		memset(u,0,(m+5)*sizeof(int));
		for(int j=v[i];j<=m;j++){
			if(d[j-v[i]]==1 && d[j]==0 && u[j-v[i]]<p[i]){
				d[j]=1;cnt++;
				u[j]=u[j-v[i]]+1;
		}
			
			
		}
	}

}


int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&m)==2){

		if(n==0 && m==0) break;
		for(int i=1;i<=n;i++) scanf("%d",v+i);
		for(int i=1;i<=n;i++) scanf("%d",p+i);
	
		cnt=0;
		dp(); 
			
		printf("%d\n",cnt);
}


	return 0;}
