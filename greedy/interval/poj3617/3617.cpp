#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
char old[2005];
char ans[2005];


int main(){
	
	freopen("in.txt","r",stdin);
	while(cin >> n){

		getchar();
		for(int i=0;i<n;i++) {cin >> old[i]; getchar();}
	
		int a=0;int b=n-1;int cnt=0;
		while(a<=b){
			if(old[a]<old[b])
			ans[cnt++]=old[a++];
			else if(old[a]>old[b])
			ans[cnt++]=old[b--];
			else{	int i=0;bool left;
				for(;(a+i)<=(b-i);i++){
					if(old[a+i]<old[b-i]) {left=true;break;}
					else if(old[a+i]>old[b-i]) {left=false;break;}				
					}
				if(left) ans[cnt++]=old[a++];
				else ans[cnt++]=old[b--];
				}
			}
		for(int i=0;i<n;i++) {cout << ans[i]; if((i+1)%80==0) cout << endl;}
		if(n%80) cout << endl;
	}

	return 0;}
