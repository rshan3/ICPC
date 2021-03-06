#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int w,h;
int G[160][160];
vector<int> s;
void init(){
		char c;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
			c=getchar();
			if(c=='\\'){
				G[2*i][2*j]=0;
				G[2*i+1][2*j+1]=0;
				G[2*i+1][2*j]=1;
				G[2*i][2*j+1]=1;
				}
			else if(c=='/'){
				G[2*i][2*j]=2;
				G[2*i+1][2*j+1]=2;
				G[2*i+1][2*j]=0;
				G[2*i][2*j+1]=0;
				}	
			}
			getchar();

			}

	}

int dfs(int i,int j){
		int re=0;
		int tmp=G[i][j];re++;
		G[i][j]=0;
		if(i-1>=0&&G[i-1][j]!=0) re+=dfs(i-1,j);
		if(i+1<2*h&&G[i+1][j]!=0) re+=dfs(i+1,j);
		if(j+1<2*w&&G[i][j+1]!=0) re+=dfs(i,j+1);
		if(j-1>=0&&G[i][j-1]!=0) re+=dfs(i,j-1);

		if(tmp==1){
			if(i+1<2*h&&j+1<2*w&&G[i+1][j+1]!=0) re+=dfs(i+1,j+1);
			if(i-1>=0&&j-1>=0&&G[i-1][j-1]!=0) re+=dfs(i-1,j-1);
			}
		if(tmp==2){
			if(i+1<2*h&&j-1>=0&&G[i+1][j-1]!=0) re+=dfs(i+1,j-1);
			if(i-1>=0&&j+1<2*w&&G[i-1][j+1]!=0) re+=dfs(i-1,j+1);
			}
		return re;
	}

void bound(){
		for(int i=0;i<2*w;i++){
			if(G[0][i]!=0) dfs(0,i);
			}
		for(int i=0;i<2*w;i++){
			if(G[2*h-1][i]!=0) dfs(2*h-1,i);
			}
		for(int i=0;i<2*h;i++){
			if(G[i][0]!=0) dfs(i,0);
			}
		for(int i=0;i<2*h;i++){
			if(G[i][2*w-1]!=0) dfs(i,2*w-1);
			}

		}

void solve(int cnt){
	for(int i=0;i<2*h;i++){
		for(int j=0;j<2*w;j++){
			
			if(G[i][j]!=0) s.push_back(dfs(i,j));
			}
		}
	if(s.empty()) {cout << "Maze #" << cnt << ":\n";
			cout << "There are no cycles.\n\n";}
	else{	int max=0;	
		for(int i=0;i<s.size();i++){
			if(s[i]>s[max]) max=i;	}
		printf("Maze #%d:\n",cnt);
		int a=s.size();
		int b=s[max];
		printf("%d Cycles; the longest has length %d.\n\n",a,b); 
			}
	}


int main(){
	freopen("in.txt","r",stdin);
	int cnt=0;
	while(cin >> w >> h){

		if(w==0) break;
		getchar();
		cnt++;
		s.clear();
		init();
		bound();
		solve(cnt);
		
		}



}
