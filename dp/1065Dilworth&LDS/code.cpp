#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[5005];
int ans,n;
struct stick{
	int l,w;
	bool operator < (const stick & other) const{
		return l<other.l;
		}
}s[5005];

void dp(){

	for(int i=n;i>0;i--){
		d[i]=1;
		for(int j=n;j>i;j--){
			if(s[i].w>s[j].w) {d[i]=max(d[i],d[j]+1);ans=max(ans,d[i]);}
			}
	}
}

int main(){
	freopen("in.txt","r",stdin);
	int ks;	
	scanf("%d",&ks);
	while(ks--){

	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s[i].l,&s[i].w);
		}

	sort(s+1,s+1+n);
	ans=1;
	dp();
	printf("%d\n",ans);
	}


	return 0;}
