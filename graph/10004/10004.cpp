#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n;
vector<int> G[200];
int vc[200];


void init(){
	memset(vc,0,sizeof(vc));
	for(int i=0;i<200;i++) G[i].clear();
	int e;	
	cin >> e;
	while(e--){

		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);

			}

	}

bool bfs(){

	queue<int> q;
	q.push(0);
	vc[0]=1;
	while(!q.empty()){

		int t=q.front();
		q.pop();
		for(int i=0;i<G[t].size();i++){
			if(vc[G[t][i]]==0) {vc[G[t][i]]=-vc[t];q.push(G[t][i]);}
			else if(vc[G[t][i]]==vc[t]) return false;
			}

		}
	return true;

	}


int main(){
	freopen("in.txt","r",stdin);

	while(cin >> n){
		if(n==0) break;
		init();
		if(bfs())
			cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
		

		}



	return 0;}
