/*
 Coin problem,
 find the recurrence relationship,
 coin frow little to large,
  a[i]+=a[i-coin].
 just use mod,not big number
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MOD 1000000000
using namespace std;

int n;
int d[1000005];

void dp(){
	d[0]=1;
	for(int i=1;i<=1000005;i*=2){
		for(int j=i;j<=1000005;j++){
			d[j]=(d[j-i]+d[j])%MOD;
			}
		}
	
}


int main(){
	dp();
	while(cin >> n){

		cout << d[n] << endl; 
	}
	
	return 0;
}
