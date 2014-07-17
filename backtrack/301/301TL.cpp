#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int cap,sta,order,maxe;

int start[25];
int destination[25];
int person[25];
int onboard[25];
int check[25];

void search(int cur,int remain,int earn){
	
  if(cur==sta){if(earn>maxe) maxe=earn;}
  else{	for(int i=0;i<order;i++) {if(check[i]) onboard[i]=1;}
	for(int i=0;i<order;i++) {if(destination[i]==cur&&onboard[i]) {remain+=person[i];onboard[i]=0;}}
	

	for(int i=0;i<order;i++){
		if(start[i]==cur && (remain-person[i]>=0) && check[i]==0){
			check[i]=1;onboard[i]=1;
			search(cur,remain-person[i],earn+person[i]*(destination[i]-start[i]));
			check[i]=0;onboard[i]=0;}	
		}
	search(cur+1,remain,earn);	
}
}
int main(){
	freopen("in.txt","r",stdin);
	while(cin >> cap >> sta >> order){
		if(cap==0) break;
		memset(onboard,0,sizeof(onboard));
		memset(check,0,sizeof(check));
		for(int i=0;i<order;i++){
			cin >> start[i] >> destination[i] >> person[i];
			
			}
		maxe=0;
		search(0,cap,0);
		cout << maxe << endl;
		}
	return 0;}





