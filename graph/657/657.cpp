#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int w,h;
char G[55][55];
bool vis[55][55];

int dice[1000];


void cd(int i,int j){
	G[i][j]='*';
	if(i-1>=0&&G[i-1][j]=='X'){cd(i-1,j);}
	if(j+1<w&&G[i][j+1]=='X'){cd(i,j+1);}
	if(i+1<h&&G[i+1][j]=='X') cd(i+1,j);
	if(j-1>=0&&G[i][j-1]=='X') cd(i,j-1);		
	
		
	}

void dfs(int i,int j,int com){

		vis[i][j]=true;
		if(G[i][j]=='X'){
			cd(i,j);
			dice[com]++;
			}
	
		if(i-1>=0){
			if(!vis[i-1][j]){
				
			
				if(G[i-1][j]=='*'||G[i-1][j]=='X'){

					dfs(i-1,j,com);
					}	
				}

			}
		if(j+1<w){

				if(!vis[i][j+1]){
				
			
				 if(G[i][j+1]=='*'||G[i][j+1]=='X'){

					dfs(i,j+1,com);
					}	
				}
		

				}
		if(i+1<h){

				if(!vis[i+1][j]){
				
				 if(G[i+1][j]=='*'||G[i+1][j]=='X'){

					dfs(i+1,j,com);
					}	
				}				
			}
		if(j-1>=0){	
				if(!vis[i][j-1]){
					if(G[i][j-1]=='*'||G[i][j-1]=='X'){

					dfs(i,j-1,com);
					}	
				}}
		}

int main(){

	freopen("in.txt","r",stdin);
	int cnt=0;
	while(cin >> w >> h){

		if(w==0&&h==0) break;

		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				
				cin >> G[i][j]; 
				
				vis[i][j]=false;	}
	
		}

		int com=0;dice[0]=0;
	for(int i=0;i<h;i++){

		for(int j=0;j<w;j++){

			if(!vis[i][j]&&(G[i][j]=='*'||G[i][j]=='X')){
				dfs(i,j,com);
				com++;
				dice[com]=0;
				}
			}
		}
		sort(dice,dice+com);
		cnt++;
		cout << "Throw " << cnt << endl;
		for(int i=0;i<com-1;i++){
		cout << dice[i];
		cout << " ";
				}
		cout << dice[com-1] << endl;
		cout << endl;
	
		}

return 0;}
