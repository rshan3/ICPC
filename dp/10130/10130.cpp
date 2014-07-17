#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,person;
int objw[1003];
int objv[1003];
int s[103];
int tot;
int d[1003][32];

void dp(){

	memset(d[n+1],0,sizeof(d[n+1]));
	for(int i=n;i>=1;i--){

		for(int j=0;j<=32;j++){
			if(j>=objw[i])
			d[i][j]=max(d[i+1][j],d[i+1][j-objw[i]]+objv[i]);
			else 
                        d[i][j]=d[i+1][j];
			}	
	}
}


int main(){
		freopen("in.txt","r",stdin);

	int ks;
	cin >> ks;
	while(ks--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> objv[i] >> objw[i]; }
		cin >> person;
		for(int i=1;i<=person;i++){
	
			cin >> s[i];}

		tot=0;
		dp();
		for(int i=1;i<=person;i++){tot+=d[1][s[i]];}
		cout << tot << endl;

}
	return 0;
	

}
