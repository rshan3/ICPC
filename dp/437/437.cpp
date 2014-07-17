#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int b[200][3];
int d[200];
int n;
int t[3];
int G[200][200];


int dfs(int cur){

		if(d[cur]>0) return d[cur];

		d[cur]=b[cur][2];

		for(int i=0;i<n;i++) {
			if(G[cur][i]){
				d[cur]=max(d[cur],b[cur][2]+dfs(i));
			}
		}	
	return d[cur];

}

int main(){
		freopen("in.txt","r",stdin);

	int cnt=0;
	while(cin >> n && n){
		int num=0;
		for(int i=0;i<n;i++){

			for(int j=0;j<3;j++) cin >> t[j];
			
			sort(t,t+3);	
				do{
			memcpy(b[num],t,sizeof(t));
			num++;
			}while(next_permutation(t,t+3));
		
				}


		n=num;int tallest=0;memset(d,0,sizeof(d));for(int i=0;i<200;i++) memset(G[i],0,sizeof(G[i]));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(G[j][i]==0){if(b[i][0]>b[j][0] && b[i][1] > b[j][1]) G[i][j]=1;}
			}
			}
		
		for(int i=0;i<n;i++) {

			tallest=max(tallest,dfs(i));
			} 

		printf("Case %d: maximum height = %d\n",++cnt,tallest);
}	

	return 0;
}
