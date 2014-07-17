#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
char s1[10005];
char s2[105];
int n1,n2;

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
	
} d[10005][105];


void dp(){

	for(int i=0;i<=n1;i++) d[i][0]=1;
	
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			if(i<j) d[i][j]=0;
			else{
				if(s1[i-1]!=s2[j-1]) {d[i][j]=d[i-1][j];}
				else{
					d[i][j]=(d[i-1][j]+d[i-1][j-1]);
					}
				}
		}
	}

}

int main(){

	freopen("in.txt","r",stdin);
	int ks;
	cin >> ks;
	while(ks--){
		cin >> s1;
		cin >> s2;
		n1=strlen(s1);
		n2=strlen(s2);
		dp();
		for(int i=d[n1][n2].dn-1;i>=0;i--) cout << d[n1][n2].a[i];
		cout << endl;
		}

}
