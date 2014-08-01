#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define INF 2147483647
using namespace std;
int d[2005][2005];
int a[2005],b[2005];
int n;

void dp(){
	
	for(int i=1;i<=n;i++){
		d[i][0]=INF;
		for(int j=1;j<=n;j++){
			d[i][j]=min(d[i-1][j]+abs(b[j]-a[i]),d[i][j-1]);
			}
	}
	
}

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {scanf("%d",a+i);b[i]=a[i];}
	sort(b+1,b+1+n);

	dp();
	printf("%d\n",d[n][n]);
	return 0;}
