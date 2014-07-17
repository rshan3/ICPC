#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n1,n2;
char c1[105];
char c2[105];
int d[105][105];


void dp(){

	for(int i=1;i<=n1;i++){

		for(int j=1;j<=n2;j++){

			if(c1[i-1]==c2[j-1]) d[i][j]=1+d[i-1][j-1];
			else{
				d[i][j]=max(d[i-1][j],d[i][j-1]);
	}
}
	}

}


int main(){
	freopen("in.txt","r",stdin);
	int cnt=0;
	while(true){

		cin.getline(c1,sizeof(c1));
		if(strlen(c1)!=0&&c1[0]=='#') break;
		cin.getline(c2,sizeof(c2));
		n1=strlen(c1);
		n2=strlen(c2);
		cnt++;
		dp();
		printf("Case #%d: you can visit at most %d cities.\n",cnt,d[n1][n2]);
		
}		

	return 0;}
