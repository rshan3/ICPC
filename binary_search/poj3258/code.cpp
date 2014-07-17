#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int l,m,n;
int x[50005];


bool C(int d){

	int cnt=0;int i,j;j=0;

	for(i=1;i<n+2;i++){if(x[i]-x[j]>=d) {cnt++;j=i;}}

	return cnt>=n+1-m;
}

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&l,&n,&m)!=EOF){
		x[0]=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",&x[i]);
		}
		x[n+1]=l;
		sort(x,x+n+2);

		int up=l;int low=0;int mid;int ans;
		while(low<=up){
			mid=(up+low)/2;
			if(C(mid)) {low=mid+1;ans=mid;}
			else up=mid-1;		
		
		}
		cout << ans << endl;
		
		}

	return 0;}
