/*
	Simple Kruscal MST
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define DIS(i,j) sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))
using namespace std;
int ds[101];
double x[101];
double y[101];
int n,m;double ans;
struct edge{

	int a,b;double w;

	bool operator < (const edge & other) const {
		return w<other.w;
			}
}edges[10101];


int find(int a){
	if(a==ds[a]) return a;
	return ds[a]=find(ds[a]);

}


void unite(int a,int b){

	int ra=find(a);
	int rb=find(b);
	ds[ra]=rb;
}



int main(){
	freopen("in.txt","r",stdin);
	int ks;
	cin >> ks;
	while(ks--){

		cin >> n;
		for(int i=0;i<n;i++) {cin >> x[i] >> y[i];ds[i]=i;}
		
		m=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				edges[m].a=i;edges[m].b=j;
				edges[m].w=DIS(i,j);
				m++;			
				}
			}


		sort(edges,edges+m);
		ans=0;
		
		for(int i=0;i<m;i++){
			edge e=edges[i];
			if(find(e.a)!=find(e.b)){
				unite(e.a,e.b);
				ans+=e.w;
				}
				
			}
		
		printf("%.2f\n",ans);
		if(ks) cout << endl;		
				
	}

}
