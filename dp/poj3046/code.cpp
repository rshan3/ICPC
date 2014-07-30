#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int d[100005];
int n,a,b,all,sum;
int num[1005];

void dp(){
	int k;
	for(int i=1;i<=n;i++){
		for(int j=b;j>0;j--){
			k=1;
			while(j-k>=0 && k<=num[i]){
				d[j]=(d[j]+d[j-k])%1000000;
				k++;
		}
		
		}
	

	}

}


int main(){
	freopen("in.txt","r",stdin);
	int t;
	scanf("%d%d%d%d",&n,&all,&a,&b);

	for(int i=0;i<all;i++){
		scanf("%d",&t);
		num[t]++;
	}
	
	d[0]=1;
	dp();
	sum=0;	
	for(int i=a;i<=b;i++){
		sum=(sum+d[i])%1000000;
		}
	printf("%d\n",sum);


	return 0;}
