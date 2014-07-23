/*
	Kindergarden MST...

*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define DIS(i,j) sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))
using namespace std;
int n,m,k;
double cost;
int x[800];
int y[800];
int ds[800];

struct edge{
	int a,b;double w;

	bool operator < (const edge & other) const{
			return w<other.w;
			}

}edges[300000];

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
	while(cin >> n){
		int a,b;

		for(int i=1;i<=n;i++) {cin >> x[i] >> y[i];ds[i]=i;}

		cin >> k;
		for(int i=0;i<k;i++) {cin >> a >> b;unite(a,b);}

		m=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				edges[m].a=i;edges[m].b=j;
				edges[m].w=DIS(i,j);
				m++;
				}
			}

		
		sort(edges,edges+m);
		cost=0;
		for(int i=0;i<m;i++){
			edge e=edges[i];
			if(find(e.a)!=find(e.b)){
				unite(e.a,e.b);
				cost+=e.w;					
				}
			}

		printf("%.2f\n",cost);


		}



	return 0;}
