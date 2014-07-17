#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1<<30
using namespace std;
int n1,n2;
int t1[101];int t2[101];
int d[102][102];

void dp(){
	for(int i=1;i<=n1;i++){

		for(int j=1;j<=n2;j++){

			if(t1[i-1]==t2[j-1]) {d[i][j]=1+d[i-1][j-1];}
			else{d[i][j]=max(d[i-1][j],d[i][j-1]);}
	}
}

}

int main(){	freopen("in.txt","r",stdin);	
		int cnt=0;
		while(cin >> n1 >> n2){
			cnt++;
			if(n1==0 && n2==0) break;
			for(int i=0;i<n1;i++)
				cin >> t1[i];
			for(int i=0;i<n2;i++)
				cin >> t2[i];
			
			
				dp();
			printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",cnt,d[n1][n2]);
	}
		
	return 0;}
