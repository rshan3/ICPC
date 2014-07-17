#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;


char s1[103][35];
char s2[103][35];
int n1,n2;
int d[104][104];
int tran[102][102];

int ans[105];

void dp(){
		d[n1+1][n2+1]=0;d[n1+1][n2]=0;d[n1][n2+1]=0;
		for(int i=n1;i>=1;i--){

			for(int j=n2;j>=1;j--){
					
				if(strcmp(s1[i],s2[j])==0){d[i][j]=1+d[i+1][j+1];tran[i][j]=1;}
				else{

					if(d[i+1][j]>d[i][j+1]){d[i][j]=d[i+1][j];tran[i][j]=2;}
					else { d[i][j]=d[i][j+1];tran[i][j]=3;}
				}
}
	
}
	

}


int main(){
	freopen("in.txt","r",stdin);
	while(cin >> s1[0]){
		if(s1[0][0]=='#') {n1=0;n2=0;
		while(true){
		cin >> s2[++n2];
		if(s2[n2][0]=='#') break;
		}
		continue;}
		strcpy(s1[1],s1[0]);
		n1=1;
		while(true)	
		{	
		cin >> s1[++n1];
		if(s1[n1][0]=='#') break;
		
		}
		n1--;
		n2=0;
		while(true){
		cin >> s2[++n2];
		if(s2[n2][0]=='#') break;
		}
		n2--;
	for(int i=0;i<104;i++)
	memset(d[i],0,sizeof(d[i]));
	dp();
	int a=1;int b=1;
	int cnt=0;
	while(a<=n1&&b<=n2){
		if(tran[a][b]==1) {ans[cnt++]=a;a++;b++;}
		else if(tran[a][b]==2) {a++;}
		else {b++;}
	}
	if(cnt>0){
	for(int i=0;i<cnt-1;i++) {cout << s1[ans[i]] << ' ';}
	cout << s1[ans[cnt-1]] << endl;}
		}
	return 0;

}
