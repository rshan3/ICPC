#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int h,k;
int v[10];
int ans[1000];
int result[10];
int maxs;

void compute(int cur,int sum,int remain){
	if(cur==k||remain==0){ans[sum]=1;}
	else{
		for(int i=0;i<=remain;i++){
			compute(cur+1,sum+i*v[cur],remain-i);
			}
		
	}
	
}

void dfs(int cur){
	if(cur==k) {    memset(ans,0,sizeof(ans));
			compute(0,0,h);
			int i;
			for(i=0;i<1000;i++){
				if(ans[i]==0) break;}
			if(i>maxs) {maxs=i-1;memcpy(result,v,sizeof(v));}
		}
	
	else{
		if(cur==0) {v[cur]=1;dfs(cur+1);}
		else {for(int i=v[cur-1]+1;i<=v[cur-1]*h+1;i++){
			v[cur]=i;
			dfs(cur+1);
		}}
	}
}


int main(){
	freopen("in.txt","r",stdin);
	while(cin >> h >> k){
		if(h==0&&k==0) break;
		
		memset(result,0,sizeof(result));
		maxs=0;
		dfs(0);
		for(int i=0;i<k;i++){
			printf("%3d",result[i]);}
		printf(" ->%3d\n",maxs);
	}
	return 0;}
