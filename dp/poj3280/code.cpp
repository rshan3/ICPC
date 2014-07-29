#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
int n,m;
int d[2005][2005];
char s[2005];
int add[26];


void dp(){

	int i,j;i=1;j=0;
	for(j=1;j<m;j++){
		for(int i=1;i+j<=m;i++){
			if(s[i]!=s[i+j])			
			d[i][i+j]=min(d[i][i+j-1]+add[s[i+j]-'a'], d[i+1][i+j]+add[s[i]-'a']);
			else {
			d[i][i+j]=d[i+1][i+j-1];
			}	
	}	}
}

int main(){
	freopen("in.txt","r",stdin);
	int a,b;char alpha;
	scanf("%d%d",&n,&m);
	
	scanf("%s",s+1);
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c%d%d",&alpha,&a,&b);
		add[alpha-'a']=a<b?a:b;
		
	}

	dp();
	
	printf("%d\n",d[1][m]);
	

	return 0;}
