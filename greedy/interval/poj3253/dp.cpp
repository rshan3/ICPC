#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
long long c[20005];
int n;

int main(){
	freopen("in.txt","r",stdin);
	
	while(cin >> n){
		long long t;
		for(int i=0;i<n;i++){
			cin >> c[i];
			}
		sort(c,c+n);
	
	
	long long cost=0;int cnt=0;int hd=0;
	while(cnt<n-1){

		cost+=(c[hd]+c[hd+1]);
		t=c[hd+1]+c[hd];
		int i;
		for(i=hd+2;i<n;i++){
			if(c[i]<t) c[i-1]=c[i];
			else break;
			}
		c[i-1]=t;	
		hd++;cnt++;
		}
		cout << cost << endl;		
}
	return 0;}
