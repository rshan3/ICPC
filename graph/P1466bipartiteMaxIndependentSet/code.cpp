#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
int n,ans;
int sex[505],vis[505],match[505];
int G[505][505];


int aug(int k){

	for(int i=0;i<n;i++){
		if(G[k][i] && !vis[i]){
			vis[i]=1;
			if(match[i]==-1 || aug(match[i])){
				match[i]=k;
				return 1;
				}
		
			}
		
		}
	return 0;
}


int main(){
	freopen("in.txt","r",stdin);
	int t,st,num;;
	while(~scanf("%d",&n)){
			memset(G,0,sizeof(G));
			memset(match,-1,sizeof(match));
			//memset(sex,0,sizeof(sex));

			for(int i=0;i<n;i++){
				scanf("%d: (%d)",&st,&num); 
				
				for(int j=0;j<num;j++) {
					scanf("%d",&t);
					G[st][t]=1;
				}
				}
		
			ans=0;
			for(int i=0;i<n;i++){
							
					memset(vis,0,sizeof(vis));
					if(aug(i)) ans++;					
					}
				
				
			
			printf("%d\n",n-ans/2);}
	
	

	return 0;}
