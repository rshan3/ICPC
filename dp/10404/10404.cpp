#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int c[10];
int d[1000009];


void dp(){

	d[0]=0;
	for(int i=1;i<=n;i++){	
		d[i]=0;

		for(int j=0;j<m;j++){

			if(i>=c[j]) {if(d[i-c[j]]==0) {d[i]=1;break;}}
			}
	}	

}

int main(){
	freopen("in.txt","r",stdin);
	while(cin >> n >> m){
		for(int i=0;i<m;i++) cin >> c[i];
		dp();
		if(d[n]) cout << "Stan wins" << endl;
		else cout << "Ollie wins" << endl;

	}

	return 0;}
