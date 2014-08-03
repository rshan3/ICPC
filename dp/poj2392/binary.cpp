#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int MaxH,n,cnt;
int d[400005];
struct block{
	int a,h;
	bool operator < (const block & other) const {
		return a<other.a;}
}bs[403<<2];

void dp(){
	
	for(int i=cnt;i>0;i--){
		for(int j=0;j<=MaxH;j++){
				if(j+bs[i].h<=bs[i].a){
				d[j]=max(d[j],bs[i].h+d[j+bs[i].h]);
				}
	}
	
}
}


int main(){

	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	MaxH=0;cnt=1;int aa,hh,cc;
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&hh,&aa,&cc);
		MaxH+=cc*hh;
		
		for(int j=1;j<=cc;j<<=1){
			bs[cnt].h=j*hh;
			bs[cnt++].a=aa;
			cc-=j;
			}
		if(cc>0){
			bs[cnt].h+=cc*hh;
			bs[cnt++].a=aa;}
		}
	
	sort(bs+1,bs+1+cnt);
	dp();
	printf("%d\n",d[0]);
	

	return 0;}
