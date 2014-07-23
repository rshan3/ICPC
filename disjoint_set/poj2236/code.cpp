#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define dis(i,t) (x[i]-x[t])*(x[i]-x[t])+(y[i]-y[t])*(y[i]-y[t])
using namespace std;
int n,d;
int pa[1005];

int x[1005],y[1005];
char s[20];


int find(int a){
	if(pa[a]==a) return a;
	return pa[a]=find(pa[a]); 
	
}

void unite(int a,int b){
	int ra=find(a);
	int rb=find(b);
	
	pa[ra]=rb;
}

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&d)==2){
		memset(pa,-1,sizeof(pa));
				
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x[i],&y[i]);
			}
		getchar();
		int t,a,b;
		while(cin.getline(s,sizeof(s))){
			if(s[0]=='O'){
					
					sscanf(s+1,"%d",&t);
					pa[t]=t;
					for(int i=1;i<=n;i++){
							if(i!=t&&pa[i]!=-1){
								if(dis(i,t)<=d*d && find(i)!=find(t)) {unite(i,t);}	}
										}
					
						}

			else{
					sscanf(s+1,"%d%d",&a,&b);
					if(pa[a]!=-1 && pa[b]!=-1 && find(a)==find(b)) printf("SUCCESS\n"); 
					else printf("FAIL\n");						
						}
			}
		}
	
	return 0;}
