#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int m,n,t;
int d[4][10010];
int c[3];

void dp(){
	d[2][0]=0;d[1][0]=0;d[3][0]=0;
	for(int i=2;i>=1;i--){

		for(int j=0;j<=t;j++){

			d[i][j]=d[i+1][j];
			if(j>=c[i] && d[i][j-c[i]]!=-1) {d[i][j]=max(d[i][j-c[i]]+1,d[i][j]);}
			
}
	}

}





int main(){
	freopen("in.txt","r",stdin);
	while(cin >> m >> n >> t){
		
		c[1]=m;c[2]=n;
		for(int i=0;i<4;i++) memset(d,-1,sizeof(d));		
		dp();
		int tt=t;
		while(d[1][tt]==-1){tt--;}

		cout << d[1][tt];
		if(tt<t) cout << ' ' << t-tt;
		cout << endl;
			
	}

	return 0;}
