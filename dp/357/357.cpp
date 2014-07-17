#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int coin[5]={1,5,10,25,50};
int n;
long long d[30005];

void dp(){
		d[0]=1;
		for(int i=0;i<5;i++){

			for(int j=coin[i];j<30005;j++){

				d[j]+=d[j-coin[i]];
}
	
}}

int main(){
	dp();
	while(cin >> n){
	if(d[n]>1)
	printf("There are %lld ways to produce %d cents change.\n",d[n],n); 
	else{
	printf("There is only 1 way to produce %d cents change.\n",n); 
}
}
	return 0;}
