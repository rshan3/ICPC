#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int r,c;
int G[101][101];
bool vis[101][101];
void dfs(int i,int j);
int main(){
	
	freopen("in.txt","r",stdin);
	
	while(cin >> r >> c){
		if(r==0) break;
	

	      for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
		{
			char c;
			cin >> c;
			if(c=='*') G[i][j]=0;
			else if(c=='@') G[i][j]=1;
			}

		}
	
	      for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			vis[i][j]=false;

		int com=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){

			if(!vis[i][j]&&G[i][j]==1){
				dfs(i,j);
				com++;
			}
		}}
	
		cout << com << endl;	
	
	
	}
	


return 0;}



void dfs(int i,int j){
	vis[i][j]=true;

	if(i-1>=0) {if(!vis[i-1][j]&&G[i-1][j]==1) dfs(i-1,j);}
	if(i-1>=0&&j+1<c){if(!vis[i-1][j+1]&&G[i-1][j+1]==1) dfs(i-1,j+1);}
	if(j+1<c){if(!vis[i][j+1]&&G[i][j+1]==1) dfs(i,j+1);}
	if(j+1<c&&i+1<r){if(!vis[i+1][j+1]&&G[i+1][j+1]==1) dfs(i+1,j+1);}
	if(i+1<r){if(!vis[i+1][j]&&G[i+1][j]==1) dfs(i+1,j);}
	if(i+1<r&&j-1>=0){if(!vis[i+1][j-1]&&G[i+1][j-1]==1) dfs(i+1,j-1);}
	if(j-1>=0){if(!vis[i][j-1]&&G[i][j-1]==1) dfs(i,j-1);}
	if(i-1>=0&&j-1>=0){if(!vis[i-1][j-1]&&G[i-1][j-1]==1) dfs(i-1,j-1);}
	

	}
