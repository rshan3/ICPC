#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int d[102][25001];
int n;int vol,sum;
int c[101];


void dp(){
	memset(d[n+1],0,sizeof(d[n+1]));
	for(int i=n;i>=1;i--){

		for(int j=0;j<=vol;j++){

			if(j>=c[i-1]){d[i][j]=max(d[i+1][j],d[i+1][j-c[i-1]] + c[i-1]);}
			else d[i][j]=d[i+1][j];
}
}

}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int ks;cin >> ks;
	while(ks--){
		cin >> n;
		sum=0;
		for(int i=0;i<n;i++) {cin >> c[i];sum+=c[i];}
		vol=sum/2;
		dp();
		
		cout << abs(sum-2*d[1][vol]) << endl;	
}

}
