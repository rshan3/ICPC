#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int r,w;
char G[26][26];
int si,sj;
int vis[26][26][5][4];
int tc[26][26][5][4];
int move[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct myt{
	int i;
	int j;
	int col;
	int dir;
	myt(int a,int b,int c,int d){i=a;j=b;col=c;dir=d;}


};

void init(){
	
	for(int i=0;i<r;i++) cin >> G[i];
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			for(int k=0;k<5;k++)
				for(int l=0;l<4;l++)
					vis[i][j][k][l]=0;
		

	}

void findS(){
	for(int i=0;i<r;i++){
		for(int j=0;j<w;j++){
			if(G[i][j]=='S') {si=i;sj=j;return;}
		}
		}

	}

int bfs(){
		queue<myt> q;
		q.push(myt(si,sj,0,0));
		tc[si][sj][0][0]=0;
		while(!q.empty()){
			myt tmp=q.front();
			q.pop();
			vis[tmp.i][tmp.j][tmp.col][tmp.dir]=1;
			if(G[tmp.i][tmp.j]=='T'&&tmp.col==0) return tc[tmp.i][tmp.j][tmp.col][tmp.dir];
			if(vis[tmp.i][tmp.j][tmp.col][(tmp.dir+1)%4]==0) 
			{	q.push(myt(tmp.i,tmp.j,tmp.col,(tmp.dir+1)%4));
				tc[tmp.i][tmp.j][tmp.col][(tmp.dir+1)%4]=tc[tmp.i][tmp.j][tmp.col][tmp.dir]+1;

								}
			if(vis[tmp.i][tmp.j][tmp.col][(tmp.dir+3)%4]==0) 
			{	q.push(myt(tmp.i,tmp.j,tmp.col,(tmp.dir+3)%4));
				tc[tmp.i][tmp.j][tmp.col][(tmp.dir+3)%4]=tc[tmp.i][tmp.j][tmp.col][tmp.dir]+1;

								}
			int ni=tmp.i+move[tmp.dir][0];
			int nj=tmp.j+move[tmp.dir][1];

			if(ni>=0&&ni<r&&nj>=0&&nj<w&&vis[ni][nj][(tmp.col+1)%5][tmp.dir]==0&&G[ni][nj]!='#'){
				q.push(myt(ni,nj,(tmp.col+1)%5,tmp.dir));
				tc[ni][nj][(tmp.col+1)%5][tmp.dir]=tc[tmp.i][tmp.j][tmp.col][tmp.dir]+1;

					}
		
			}
		return -1;
	

		}

int main(){
	freopen("in.txt","r",stdin);
	int cnt=0;
	while(cin >> r >> w){
		if(r==0) break;		
		getchar();
		init();
		findS();		

		int ans=bfs();
		if(cnt++>0) cout << endl;
		cout << "Case #" << cnt <<endl;
		if(ans==-1) {cout << "destination not reachable" << endl;}

		else {printf("minimum time = %d sec\n",ans);}}

return 0;}
