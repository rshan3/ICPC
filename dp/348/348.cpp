#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 1<<30
using namespace std;
int n;
int r[12];int c[12];
long long d[12][12];
long long possible;
int par[12][12];
int lp[12];
int rp[12];


void dp(){
	
	
	for(int dis=1;dis<n;dis++){

		for(int i=1;i+dis<=n;i++){
			d[i][i+dis]=INF;int idx=0;
			for(int k=i;k<i+dis;k++){
				possible=d[i][k]+d[k+1][i+dis]+r[i]*c[k]*c[i+dis];
				if(possible<d[i][i+dis]) {d[i][i+dis]=possible;idx=k;}
				}
			par[i][i+dis]=idx;
	}
}	
		
}

void parenthsis(int s,int e){
		if(e-s<2) return;

		int k = par[s][e];
		if(k>s){lp[s]++;rp[k]++;}
		if(k<e-1){lp[k+1]++;rp[e]++;}
		parenthsis(s,k);
		parenthsis(k+1,e);
}


int main(){
	freopen("in.txt","r",stdin);int cnt=0;
	while(cin >> n && n){
		cnt++;
		for(int i=0;i<n;i++){

			cin >> r[i+1] >> c[i+1];
			}

		for(int i=0;i<12;i++) {memset(d[i],0,sizeof(d[i]));memset(par[i],0,sizeof(par[i]));}
		memset(lp,0,sizeof(lp));memset(rp,0,sizeof(rp));	
		dp();
		parenthsis(1,n);
		printf("Case %d: ",cnt); 
		cout << '(';
		for(int i=1;i<=n;i++){
			while(lp[i]--) {cout << '(';}
			 cout << 'A' << i;
			while(rp[i]--) {cout << ')';}
			
			if(i!=n) cout << " x ";
			
			
		}
		cout << ')' << endl;
		}

	return 0;}
