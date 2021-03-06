#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;
int n;
int a[7];
int mini;
int cnt;

void swap(int i){
	int t=a[i];a[i]=a[i+1];a[i+1]=t;

}

void dfs(int cur){
		int ok=1;
		for(int i=0;i<n-1;i++) {if(a[i]>a[i+1]) {ok=0;break;}}

		if(!ok){
			int tmp[7];
			memcpy(tmp,a,sizeof(a));
			for(int i=0;i<n-1;i++){
				if(a[i]>a[i+1]) {swap(i);dfs(cur+1);
						memcpy(a,tmp,sizeof(a));				
						}
		}
		}
		else{
			if(cur==0) cnt=0;
			else if(cur<mini) {mini=cur;cnt=1;}
			else if(cur==mini) cnt++;	
		}
}


int main(){
	freopen("in.txt","r",stdin);
		int ks=0;
	while(cin >> n && n){
		ks++;
		for(int i=0;i<n;i++){
			cin >> a[i];
			}

		mini=n*(n-1)/2;cnt=0;
		dfs(0);
		printf("There are %d swap maps for input data set %d.\n",cnt,ks);
		
		}
	return 0;}
