#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;
int r,c;
int G[102][102];
int d[102][102];
char s[200];

int Unumber;
void dp(){
		d[0][1]=1;
		for(int i=1;i<=r;i++){
			d[i][0]=0;
			for(int j=1;j<=c;j++){
			d[i][j]=0;
			if(G[i][j-1]==0) d[i][j]+=d[i][j-1];
			if(G[i-1][j]==0) d[i][j]+=d[i-1][j];	
		}
		}
}

int main(){
	freopen("in.txt","r",stdin);
	int ks;
	
	cin >> ks;
	while(ks--){
		
		cin >> r >> c;
		getchar();
		for(int i=1;i<=r;i++){
			int j;
			memset(G[i],0,sizeof(G[i]));
			
			cin.getline(s,sizeof(s));
			stringstream strm(s);
			strm >> j;

			while(strm >> j) {G[i][j]=1;}
			}

		dp();
		cout << d[r][c] << endl;
		if(ks) cout << endl;
	}


	return 0;}
