#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int c[22];
int s,n;
int d[23][100000];
int wor[23][100000];


void dp(){
		memset(d[n+1],0,sizeof(d[n+1]));
		
		for(int i=n;i>=1;i--){

			for(int j=0;j<=s;j++){
				wor[i][j]=0;
				if(j>=c[i]){
					if(d[i+1][j-c[i]]+c[i]>=d[i+1][j]) {d[i][j]=d[i+1][j-c[i]]+c[i];wor[i][j]=1;} 
						else {d[i][j]=d[i+1][j];wor[i][j]=2;}
				}
				else {d[i][j]=d[i+1][j];wor[i][j]=2;}
		}
			}
}


int main(){
		freopen("in.txt","r",stdin);
	while(cin >> s >> n){

			for(int i=1;i<=n;i++){
				cin >> c[i];
				}
		
		dp();
		int k=1;int ss=s;
		while(k<=n){
			if(wor[k][ss]==1) {cout << c[k] << ' ';ss-=c[k];}
			k++;			
			}
		
		cout << "sum:" << d[1][s] << endl;
		}
	return 0;}
