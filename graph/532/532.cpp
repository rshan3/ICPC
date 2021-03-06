#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
char G[31][31][31];
int dis[31][31][31];
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int l,r,c;
int sl,sr,sc;



struct mytuple{

		int i;
		int j;
		int k;
		mytuple(int x,int y,int z){i=x;j=y;k=z;}

		};

queue<mytuple> q;
void init(){
	
	for(int i=0;i<l;i++){

		for(int j=0;j<r;j++){

		cin >> G[i][j];
		
			}
		
		}

	}

int bfs(){
		
		q.push(mytuple(sl,sr,sc));
		dis[sl][sr][sc]=0;
		while(!q.empty()){

			mytuple t=q.front();
			q.pop();
			if(G[t.i][t.j][t.k]=='E') return dis[t.i][t.j][t.k];
 			G[t.i][t.j][t.k]='#';
			
			for(int d=0;d<6;d++){
				int lev=t.i+dir[d][0];
				int row=t.j+dir[d][1];
				int col=t.k+dir[d][2];
				if(lev>=0&&lev<l&&row>=0&&row<r&&col>=0&&col<c&&G[lev][row][col]!='#'){

					q.push(mytuple(lev,row,col));
					dis[lev][row][col]=dis[t.i][t.j][t.k]+1;
					}
			
				}			

		}
	
	return -1;

		}

void findStart(){
		for(int i=0;i<l;i++){
			for(int j=0;j<r;j++){
				for(int k=0;k<c;k++){
					if(G[i][j][k]=='S') {sl=i;sr=j;sc=k; return;}					
					}}
			}

}

int main(){
	freopen("in.txt","r",stdin);

	while(cin >> l >> r >> c){

		if(l==0) break;
		getchar();
		init();
		findStart();
		
		int ans=bfs();	
		if(ans==-1) cout << "Trapped!" << endl;
		else {printf("Escaped in %d minute(s).\n",ans);}
			}


	return 0;}

