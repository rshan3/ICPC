#include <iostream>
#include <cstdio>
using namespace std;
int n;
char G[4][4];
int maxp;


bool ok(int i,int j){
	if(G[i][j]!='.') return false;

	for(int k=i;k<n;k++){if(G[k][j]=='X') break; else if(G[k][j]=='O') return false;}
	for(int k=i;k>=0;k--){if(G[k][j]=='X') break; else if(G[k][j]=='O') return false;}
	for(int k=j;k<n;k++){if(G[i][k]=='X') break; else if(G[i][k]=='O') return false;}	
	for(int k=j;k>=0;k--){if(G[i][k]=='X') break; else if(G[i][k]=='O') return false;}
	return true;
}



void dfs(int i,int j,int num){
	if(ok(i,j)){
		G[i][j]='O';
		maxp=num+1>maxp?num+1:maxp;
		for(int ii=0;ii<n;ii++){
			for(int jj=0;jj<n;jj++){
				
				dfs(ii,jj,num+1);}}
		G[i][j]='.';}	}


int main(){
	freopen("in.txt","r",stdin);
	while(cin >> n && n){
	getchar();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			{cin >> G[i][j];}
		getchar(); 
			}
	maxp=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			{
			dfs(i,j,0);
							}
		}
	cout << maxp << endl;
		}
	return 0;}
