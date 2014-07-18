#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,w;
int d[1005][35];
int t[1005];

void dp(){

	for(int i=n;i>=1;i--){
		for(int j=0;j<=w;j++){
			if(  (((w-j)&1) && t[i]==2) || (((w-j)%2==0) && t[i]==1 ) ){
			  if(j>=1) d[i][j]=max(d[i+1][j]+1,d[i+1][j-1]);
				else d[i][j]=d[i+1][j]+1;}
			else{
			  if(j>=1)	d[i][j]=max(d[i+1][j],d[i+1][j-1]+1);
			else d[i][j]=d[i+1][j];
				}	
		}
	}

}


int main(){
	freopen("in.txt","r",stdin);

	while(cin >> n >> w){

		for(int i=1;i<=n;i++){
			cin >> t[i];
			}

		dp();
		cout << d[1][w] << endl;
	}

return 0;}
