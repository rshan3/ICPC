#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
int k,dim;
int a[35][11];
int d[35];
int G[35][35];
int outer[35];

int dp(int i){
	if(d[i]>0) return d[i];

	for(int j=0;j<k;j++){
		if(G[i][j]){
			int poss=dp(j);
			if((poss+1)>d[i]) {d[i]=poss+1;outer[i]=j;}}
		}
	return d[i]; 

}

void judge(int in,int out){
	for(int i=0;i<dim;i++){
			if(a[in][i]>=a[out][i]){return;}
	}
	G[in][out]=1;
}

void init(){
	for(int i=0;i<k;i++){

		for(int j=0;j<k;j++){

			if(i!=j&&G[j][i]==0){
				judge(i,j);}
		}
	}

}

int main(){
		freopen("in.txt","r",stdin);
	while(cin >> k >> dim){
		for(int i=0;i<k;i++){

			for(int j=0;j<dim;j++){cin >> a[i][j];}	
	}


		for(int i=0;i<k;i++){sort(a[i],a[i]+dim);}
		for(int i=0;i<k;i++){memset(G[i],0,sizeof(G[i]));}		
		init();
		int t,tmax;tmax=0;int start;
		memset(d,0,sizeof(d));
		
		for(int i=0;i<k;i++)
		 {t=dp(i);if(t>tmax) {tmax=t;start=i;}}
		cout << tmax+1 << endl;
		for(int i=0;i<tmax;i++){
		cout << start+1 << ' ';
		start=outer[start];
			}
		cout << start+1 << endl;
		
	}	

	return 0;}
