#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,midx;
int d[1001];
int prev[1001];
int ans[1001];
struct elephant{
	int w;int s;int idx;
	

}ele[1001];

int cmp(const elephant & a,const elephant & b) {

	return a.w<b.w;
}

void dp(){

		for(int i=1;i<=n;i++){
			d[i]=1;
			for(int j=1;j<i;j++){

				if(ele[i].s<ele[j].s&&ele[i].w>ele[j].w){
					if(d[j]+1>d[i]){
					d[i]=d[j]+1;
					prev[i]=j;
					}
		}
}
		if(d[i]>d[midx]) {midx=i;}
}}

int main(){
		freopen("in.txt","r",stdin);
		int a,b;n=0;
		
	while(cin >> a >> b){
		n++;
		ele[n].w=a;
		ele[n].s=b;
		ele[n].idx=n;
}
	sort(ele+1,ele+n+1,cmp);
	midx=0;
	dp();
	int t=midx;
		int cnt=0;
	while(t){
		cnt++;
		ans[cnt]=ele[t].idx;t=prev[t];
	}

	cout << cnt << endl;
	for(int i=cnt;i>=1;i--) cout << ans[i] << endl;

		
	return 0;}
