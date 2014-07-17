#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define INF 2147483646
int m[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int dis[8][8];
bool visit[8][8];
class mypair{
	public:
	int r,c;

	mypair(int i,int j){r=i;c=j;}
};

int solve(int si,int sj,int di,int dj){
	
	queue<mypair> q;
	q.push(mypair(si,sj));	
	while(!q.empty()){
		mypair tmp=q.front();
		q.pop();
		visit[si][sj]=true;
		int ti=tmp.r;int tj=tmp.c;
		if(ti==di&&tj==dj) return dis[ti][tj];	

	for(int i=0;i<8;i++){
		
		if(ti+m[i][0]<8 && ti+m[i][0]>=0 && tj+m[i][1]<8 && tj+m[i][1] >=0 && !visit[ti+m[i][0]][tj+m[i][1]])
		{       
			q.push(mypair(ti+m[i][0],tj+m[i][1]));
			dis[ti+m[i][0]][tj+m[i][1]]=dis[ti][tj]+1;
				}

		}
	}
	

	}


int main(){
	freopen("in.txt","r",stdin);
	char s[3];char d[3];
	while(cin >> s){
		getchar();
		cin >> d;
		getchar();
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				visit[i][j]=false;
				dis[i][j]=0;
				}
		}
		int ans=solve(s[1]-'1',s[0]-'a',d[1]-'1',d[0]-'a');
		printf("To get from %s to %s takes %d knight moves.\n",s,d,ans);	
		}


}
