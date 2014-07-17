#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#define INF 2147483647
using namespace std;
int l;
int n;
int m[51][51];
int seg[51];
int cut[51];

void dp(){
	for(int dis=1;dis<=n;dis++){
		for(int i=1;i+dis<=n;i++){
			m[i][i+dis]=INF;int a=0;
			for(int ii=i;ii<=i+dis;ii++) a+=seg[ii];
			for(int k=i;k<i+dis;k++){
				if(m[i][k]+m[k+1][i+dis]+a<m[i][i+dis]) m[i][i+dis]=m[i][k]+m[k+1][i+dis]+a;
		}
}
	}

}

int main(){
	freopen("in.txt","r",stdin);
	while(cin >> l && l){
		cin >> n;
		
		for(int i=1;i<=n;i++)
		{cin >> cut[i];}
		for(int i=1;i<=n;i++){seg[i]=cut[i]-cut[i-1];}
		seg[n+1]=l-cut[n];
		n=n+1;
	
		dp();
		printf("The minimum cutting is %d.\n",m[1][n]);
		
	}
	
	return 0;}
