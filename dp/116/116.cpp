#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 1<<30

using namespace std;
int m,n,mini;
int G[11][101];
int route[101];
long long d[11][101];
int prev[11][101];


void check(int i,int j){
		if(i-1<1) {if(d[m][j-1]+G[i][j]==d[i][j]){
						prev[i][j]=min(m,prev[i][j]);
						}
				else if(d[m][j-1]+G[i][j]<d[i][j]){d[i][j]=d[m][j-1]+G[i][j];prev[i][j]=m;}
}
		else {if(d[i-1][j-1]+G[i][j]==d[i][j]){
						
						prev[i][j]=min(i-1,prev[i][j]);
						}
					else if(d[i-1][j-1]+G[i][j]<d[i][j]){d[i][j]=d[i-1][j-1]+G[i][j];prev[i][j]=i-1;}
		}
				
								
				
				if(d[i][j-1]+G[i][j]==d[i][j]){
						prev[i][j]=min(i,prev[i][j]);
						}
				else if(d[i][j-1]+G[i][j]<d[i][j]){
						d[i][j]=d[i][j-1]+G[i][j];
						prev[i][j]=i;
						}

				if(i+1>m) {if(d[1][j-1]+G[i][j]<=d[i][j]){
						d[i][j]=d[1][j-1]+G[i][j];
						prev[i][j]=1;
					
					}}
				else	{if(d[i+1][j-1]+G[i][j]==d[i][j]){
						
						prev[i][j]=min(i+1,prev[i][j]);
									}
					else if(d[i+1][j-1]+G[i][j]<d[i][j]){
						d[i][j]=d[i+1][j-1]+G[i][j];
						prev[i][j]=i+1;
									}	
}
}

void dp(){
	
		for(int j=1;j<=n;j++){
			for(int i=1;i<=m;i++){
				d[i][j]=INF;prev[i][j]=INF;
				check(i,j);
				
			
				
	}
			
	}
		 mini=1;
		for(int i=1;i<=m;i++){if(d[i][n]<d[mini][n]) mini=i;}
		
}




int main(){
		freopen("in.txt","r",stdin);
		while(cin >> m >> n){

			for(int i=1;i<=m;i++){
				for(int j=n;j>=1;j--){
				cin >> G[i][j];
		}
		}
	
			memset(route,0,sizeof(route));
			dp();
			int t=mini;
			for(int i=0;i<n-1;i++){
				cout << t << ' ';
				t=prev[t][n-i];
	}
			cout << t << endl;
			
			
			cout << d[mini][n] << endl;
}
	
	return 0;}
