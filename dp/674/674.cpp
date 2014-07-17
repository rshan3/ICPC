#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[7500];
int n;

void dp(){

		for(int i=1;i<=n;i++){
		
			if(d[i]==0){
			for(int j=i-1;j>=0;j--){
				d[i]=max(d[i],d[
			}
	}
			
	}

}


int main(){
	memset(d,0,sizeof(d));
	while(cin >> n){
				
		dp();
	}
	
	return 0;}
