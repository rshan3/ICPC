#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char name[100];
int r,c;
int G[105][105];
int d[105][105];
int beingcheck[105][105];
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool check(int x,int y){
	if(x<0||y<0||x>=r||y>=c) return false;
	
	return !beingcheck[x][y];

}

int dp(int i,int j){
		

		if(d[i][j]>0) return d[i][j];

		d[i][j]=1;
		beingcheck[i][j]=1;

		for(int k=0;k<4;k++){
			if(check(i+dir[k][0],j+dir[k][1])&& G[i+dir[k][0]][j+dir[k][1]] < G[i][j]){
				d[i][j]=max(d[i][j],dp(i+dir[k][0],j+dir[k][1])+1);
	}	
			}
		beingcheck[i][j]=0;
		return d[i][j];

}


int main(){
	
	freopen("in.txt","r",stdin);
	int ks;cin >> ks;
	while(ks--){
		getchar();
		cin >> name >> r >> c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin >> G[i][j];

		for(int i=0;i<105;i++) memset(d[i],0,sizeof(d[i]));
		int rte=0;
		for(int i=0;i<r;i++){

			for(int j=0;j<c;j++) rte=max(rte,dp(i,j));}
		printf("%s: %d\n",name,rte);
		
	}

	return 0;}
