#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define INF 1e9

using namespace std;
int m,n,s,t;
int d[20005],used[20005];
typedef pair<int,int> pii;



int main(){
		freopen("in.txt","r",stdin);
		int ks,a,b,c;
		cin >> ks;
		for(int ksi=1;ksi<=ks;ksi++){
			cin >> n >> m >> s >> t;
			
			vector<pii> G[n+1];
			for(int i=0;i<m;i++){cin >> a >> b >> c; G[a].push_back(make_pair(b,c));G[b].push_back(make_pair(a,c));}
		
			
			for(int i=0;i<=n;i++) {d[i]=INF;used[i]=0;}
	
			priority_queue<pii,vector<pii>,greater<pii> > que;
			que.push(make_pair(0,s));	
			d[s]=0;

			while(!que.empty()){
				int k=que.top().second;que.pop();
				if(used[k]==1) continue;
				used[k]=1;

			for(int i=0;i<G[k].size();i++)
			{	
			if(d[k]+G[k][i].second < d[G[k][i].first] ) {d[G[k][i].first]=d[k]+G[k][i].second;que.push(make_pair(d[G[k][i].first],G[k][i].first));}			
		}
			}



			if(d[t]!=INF) printf("Case #%d: %d\n",ksi,d[t]);
			else printf("Case #%d: unreachable\n",ksi);

		}
	


	return 0;}
