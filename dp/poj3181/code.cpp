#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct bign{

	int a[105];int dn;

	bign(){
		memset(a,0,sizeof(a));dn=1;
		}

	bign(int x){
		
		int i=0;
		memset(a,0,sizeof(a));
		while(x){
			a[i++]=x%10;
			x/=10;
		}
		dn=max(i,1);
	}

	bign operator +(const bign & other) {

		bign r=0;
		int sumi;
		int t=max(dn,other.dn);int carry=0;
		for(int i=0;i<=t;i++){
			sumi=a[i]+other.a[i]+carry;
			r.a[i]=sumi%10;
			carry=sumi/10;
			}
		if(r.a[t]>0) r.dn=t+1;
		else r.dn=t;	
		return r;	
	}
	
	void operator =(const bign & other){
			memcpy(a,other.a,sizeof(a));dn=other.dn;		
		}
		
	void operator =(int x){
		int i=0;
		memset(a,0,sizeof(a));
		while(x){
			a[i++]=x%10;
			x/=10;
		}
		dn=max(i,1);
	}
	
} d[1005];

int n,m;

void dp(){
	d[0]=1;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){

			d[j]=d[j-i]+d[j];
		}

	}

}


int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	
	dp();
	for(int i=d[n].dn-1;i>=0;i--)
	printf("%d",d[n].a[i]);
	printf("\n");
	return 0;}
