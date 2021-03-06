#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n;
int x[10];
int y[10];
int vis[10];
int a[10];
int res[10];
double mini;

double dis(int i,int j){
		
	return 16+sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));

}

void calculate(){
	double sum=0;
	for(int i=0;i<n-1;i++){
		sum+=dis(a[i],a[i+1]); }
	if(sum<mini){
		mini=sum;
		for(int i=0;i<n;i++) res[i]=a[i];
			}
}


void dfs(int cur){
		if(n==cur){
		calculate();

	}

		else{
			for(int i=0;i<n;i++){
				if(!vis[i]){
					a[cur]=i;vis[i]=1;
					dfs(cur+1);
					vis[i]=0;
				}
				}


			}


}


int main(){
	freopen("in.txt","r",stdin);
	int cnt=0;
	while(cin >> n && n){
	cnt++;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
		cin >> x[i] >> y[i];}
	mini=5000;
		
	dfs(0);
	cout << "**********************************************************\n";
	cout << "Network #" << cnt << endl;
	for(int i=0;i<n-1;i++){
	printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",x[res[i]],y[res[i]],x[res[i+1]],y[res[i+1]],dis(res[i],res[i+1]));
	}	
	printf("Number of feet of cable required is %.2f.\n",mini);}
	return 0;}
