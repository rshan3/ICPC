#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int num[101][17];
int fnum[101][17];
int c[20];
bool flag;
int k,n,p;
void check();

void init(){
	
	cin >> p;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<p;j++){
			cin >> num[i][j];}
			}
	}

void per(int cur){
		if(cur==k+1) {check();}
		
		else{
			if(!flag){
					for(int i=c[cur-1]+1;i<p&&!flag;i++){
						c[cur]=i;						
						per(cur+1);
								}
				}
			
			}		
	
	}

bool thesame(int a[],int b[]){
		for(int i=0;i<p;i++){
			if(a[i]!=b[i]) return false;
			}
	return true;
	}

void check(){
		
		for(int i=0;i<n;i++){

			for(int j=0;j<p;j++){
				fnum[i][j]=num[i][j];
				}
				}
		
		for(int i=0;i<n;i++){
			for(int j=1;j<=k;j++){
			fnum[i][c[j]]=0;
			}}

		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(thesame(fnum[i],fnum[j])) {flag=false;return;}
				}
			}
		flag=true;		
}

int main(){
		freopen("in.txt","r",stdin);
		int test;
		cin >> test;
		while(test--){
			k=0;
			init();
			int ex=1;
			while(ex<n){ex*=2;k++;}
			for(k=p-k;k>0;k--){
				memset(c,0,sizeof(c));
				c[0]=-1;
				flag=false;
				per(1);
				if(flag) break;
				}
			cout << p-k << endl;			
					}


	}
