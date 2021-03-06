#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 1001
using namespace std;
int r,c;


int G[MAXN][MAXN];
int sol[MAXN][MAXN];
int isNum[MAXN][MAXN];
string sa[MAXN][MAXN];

void init(){
	char read[2000];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> read;
			if(read[0]=='='){sa[i][j]=read;isNum[i][j]=0;}
			else {G[i][j]=atoi(read);isNum[i][j]=1;}			
			}
		
		}
	
	}

int dfs(int i,int j){
			if(isNum[i][j]==1){sol[i][j]=G[i][j];return sol[i][j];}
			else{	int col=0;int row=0;
				int cal=0;string s=sa[i][j];int a=1;
		
				while(a<s.length()){
				for(;s[a]!='+'&&a<s.length();a++){
					if(isalpha(s[a])){
							col=col*26+(s[a]-'A'+1);			}
					else if(isdigit(s[a])){
							row=row*10+(s[a]-'0');	}			
					}
				cal+=dfs(row-1,col-1);
				col=0;row=0;
				a++;
					}
				sol[i][j]=cal;
				return cal;

			}
		
	}

int main(){	freopen("in.txt","r",stdin);
		int test;
		cin >> test;
	while(test--){
		cin >> c >> r;
		init();
		for(int i=0;i<r;i++){
		   for(int j=0;j<c;j++){
			dfs(i,j);}}

		for(int i=0;i<r;i++){
			for(int j=0;j<c-1;j++){
				cout << sol[i][j] << ' ';}
			cout << sol[i][c-1] << endl;			
		}
		
		}

	return 0;}
