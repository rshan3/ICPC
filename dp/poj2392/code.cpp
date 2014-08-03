#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int MaxH,n;
int d[400005];
struct block{
	int a,c,h;
	bool operator < (const block & other) const {
		return a<other.a;}
}bs[405];

void dp(){
	
	for(int i=n;i>0;i--){
		for(int j=0;j<=MaxH;j++){for(int k=1;k<=bs[i].c && (j+bs[i].h*k) <=bs[i].a;k++){d[j]=max(d[j],bs[i].h*k+d[j+bs[i].h*k]);} }		
	}
	
}



int main(){

	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	MaxH=0;
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&bs[i].h,&bs[i].a,&bs[i].c);
		MaxH+=bs[i].c*bs[i].h;
		}
	
	sort(bs+1,bs+1+n);
	dp();
	printf("%d\n",d[0]);
	

	return 0;}
