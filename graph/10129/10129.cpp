#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int n;
int alph[26];
int G[26][26];
int ind[26];
int outd[26];
int vis[26];
void init(){
		cin >> n;
		getchar();
		for(int i=0;i<n;i++){
		string s;
		cin >> s;
		int a=s[0]-'a';
		int b=s[s.length()-1]-'a';
		outd[a]++;
		ind[b]++;
		alph[a]=1;
		alph[b]=1;
		G[a][b]=1;
}
	}

bool bfs(){
	int i;
	for(i=0;i<26;i++) if(alph[i]==1) break;
	queue<int> q;
	q.push(i);
		
	while(!q.empty()){
		int t=q.front();
		q.pop();
		vis[t]=1;
		for(int i=0;i<26;i++){
			if(G[t][i]==1&&vis[i]==0){q.push(i);}
			}
		}
	for(int i=0;i<26;i++) {if(vis[i]!=alph[i]) return false;}
	return true;

	}

bool check(){
		int a,b,diff; a=0;b=0;
		for(int i=0;i<26;i++){

			diff=ind[i]-outd[i];
			if(diff>1) return false;
			if(diff<-1) return false;
			if(diff==1){a++;if(a>1) return false;}
			if(diff==-1) {b++;if(b>1) return false;}
			}
		
		return a==b && bfs();
		

	}


int main(){
	freopen("in.txt","r",stdin);
	int testcase;
	cin >> testcase;
	while(testcase--){
		memset(alph,0,sizeof(alph));
		memset(vis,0,sizeof(vis));
		memset(ind,0,sizeof(ind));
		memset(outd,0,sizeof(outd));
		for(int i=0;i<26;i++){for(int j=0;j<26;j++) G[i][j]=0;}

		init();
		if(check()) cout << "Ordering is possible.\n";
		else cout << "The door cannot be opened.\n";
			}

	return 0;}
