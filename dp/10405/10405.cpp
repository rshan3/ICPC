#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s1[1002];
char s2[1002];
int dp[1002][1002];
int l1,l2;

void search(){
	memset(dp[0],0,sizeof(dp[0]));
	for(int i=0;i<1002;i++){dp[i][0]=0;}

	for(int i=1;i<=l1;i++){
		for(int j=0;j<=l2;j++){
			if(s1[i-1]==s2[j-1]){dp[i][j]=dp[i-1][j-1]+1;}
			else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);	}
	}
	}

}


int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin.getline(s1,sizeof(s1)) && cin.getline(s2,sizeof(s2)) ){
		l1=strlen(s1);
		l2=strlen(s2);
		search();
		cout << dp[l1][l2] << endl;		
		}
	
	return 0;}
