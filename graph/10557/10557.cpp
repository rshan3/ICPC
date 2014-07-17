#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
int n;
int preE[105];
int roomE[105];
vector<int> G[105];
int visit[105];
int cv[105];



void dfsC(int u){
	
	
	cv[u]=1;
	for(int i=0;i<G[u].size();i++){

		if(cv[G[u][i]]==0){

			dfsC(G[u][i]);
			}

		}
	


}

bool bfs(){
		
		queue<int> q;
		q.push(0);
		preE[0]=100;
		while(!q.empty()){
			int tmp=q.front();
			q.pop();
			visit[tmp]=1;
			int afterE=preE[tmp]+roomE[tmp];
			if(afterE<=0) continue;
		
			for(int i=0;i<G[tmp].size();i++){
				if(G[tmp][i]==n-1) {return true;}
		
				if(visit[G[tmp][i]]==0) {
							preE[G[tmp][i]]=afterE;
							q.push(G[tmp][i]);
								}
				else{
						if(afterE > preE[G[tmp][i]]){
							memset(cv,0,sizeof(cv));
							dfsC(G[tmp][i]);
							if(cv[n-1]==1)
							return true;}
								}

					}
			
			
				}
		return false;
		

		}







int main(){
	freopen("in.txt","r",stdin);
	while(cin >> n){

		if(n==-1) break;

		memset(preE,0,sizeof(preE));
		memset(roomE,0,sizeof(roomE));
		memset(visit,0,sizeof(visit));
		memset(cv,0,sizeof(cv));
		for(int i=0;i<105;i++){G[i].clear();}
	
		for(int i=0;i<n;i++){
			cin >> roomE[i];
			int nn;
			cin >> nn;
			while(nn--){
				int t;
				cin >> t;
				G[i].push_back(t-1);
					}
			
				}
		
		bool ans=bfs();
		if(ans) cout << "winnable" << endl;
		else cout << "hopeless" << endl;
			}

	return 0;}
