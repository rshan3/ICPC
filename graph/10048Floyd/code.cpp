/* 
	Boring floyd...
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
int n,m,q;
int d[105][105];



void floyd(){

	for(int k=1;k<=n;k++){

		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
				}
		}

}


int main(){

	freopen("in.txt","r",stdin);
	int ks=0;int a,b,c;
	while(cin >> n >> m >> q){

		if(n==0 && m==0 && q==0) break;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				{if(i!=j) {d[i][j]=INF;}else {d[i][j]=0;}}

	
		for(int i=0;i<m;i++){
			cin >> a >> b >> c;
			d[a][b]=c;
			d[b][a]=c;
		}
	
		floyd();
		if(ks) cout << endl;
		cout << "Case #" << ++ks << endl;
		for(int i=0;i<q;i++){

			cin >> a >> b;
			if(d[a][b]==INF) cout << "no path\n";
			else printf("%d\n",(int)d[a][b]);
			}

}


	return 0;}
