/*
	Boring MST
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define DIS(i,j) sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))
using namespace std;
int x[505];
int y[505];
int ds[505];
int n,m,s;

struct edge{

	int a,b;double w;
	bool operator < (const edge & other) const{
			return w<other.w;
		}
}edges[200000];

int find(int i){
	if(i==ds[i]) return i;
	return ds[i]=find(ds[i]);

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

		cin >> s >> n;
		
		for(int i=1;i<=n;i++) {cin >> x[i] >> y[i];ds[i]=i;}
		
		m=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				edges[m].a=i;edges[m].b=j;
				edges[m].w=DIS(i,j);		
				m++;		
				}	
			}
		sort(edges,edges+m);
		int cnt=0;
		for(int i=0;i<m;i++){
			edge e=edges[i];
			if(find(e.a)!=find(e.b)){
					unite(e.a,e.b);
					cnt++;
					if(cnt==n-s) {printf("%.2f\n",e.w);break;}
				}
			}
		
}

	return 0;}
