#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 100000
using namespace std;
int d[22][22];
int G[22][22];

void floyd(){
	
	for(int k=1;k<=20;k++)
		for(int i=1;i<=20;i++)
			for(int j=1;j<=20;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

}


int main(){

	freopen("in.txt","r",stdin);
	int num,cnt,t;cnt=0;
	while(cin >> num){
		cnt++;
		

		for(int i=0;i<21;i++){
			memset(G[i],0,sizeof(G[i]));
			for(int j=0;j<21;j++)
			{if(i!=j) d[i][j]=INF;
			 else d[i][j]=0;}
				
}
		for(int i=0;i<num;i++) {cin >> t;G[1][t]=1;G[t][1]=1;d[1][t]=1;d[t][1]=1;}
		for(int i=2;i<=19;i++) {
			cin >> num;
			for(int j=0;j<num;j++){
				cin >> t;G[i][t]=1;G[t][i]=1;d[i][t]=1;d[t][i]=1;}

	}
		
		floyd();
		int k,a,b;
		cin >> k;
		cout << "Test Set #" << cnt <<endl;
		for(int i=0;i<k;i++){
			cin >> a >> b;
			printf("%2d to %2d: %d\n",a,b,d[a][b]);
			
			}
		cout << endl;
	}
	


}
