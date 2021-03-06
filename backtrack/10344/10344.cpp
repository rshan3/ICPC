#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[5];
bool flag;

void dfs(int cur,int result){
	if(cur==4){flag=result==23;}
	else{ 
	 	dfs(cur+1,result+a[cur+1]);if(flag) return;
		dfs(cur+1,result*a[cur+1]);if(flag) return;
		dfs(cur+1,result-a[cur+1]);if(flag) return;
		}
}

int main(){
	freopen("in.txt","r",stdin);
	while(true){
		for(int i=0;i<5;i++) cin >> a[i];
		if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0) break;
		sort(a,a+5);flag=false;
		do{
			dfs(0,a[0]);
	
	}while(!flag&&next_permutation(a,a+5));		

	if(flag) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	}
	return 0;}
