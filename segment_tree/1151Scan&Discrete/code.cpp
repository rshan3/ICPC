#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <set>
#define INF 0x7FFFFFFF
#define EPS 1e-9
using namespace std;

int dir;double cover,area;

struct Line{
	double xa,xb;double y;
	int type;
	bool operator < (const Line & other) const {
		return y<other.y; 

		}
}line[300];

double X[300];

struct node{

	int l,r;
	int level;
	double leng;
}tree[1500];

void buildtree(int cur, int a, int b){
	tree[cur].l=a;tree[cur].r=b;	
	tree[cur].leng=0;tree[cur].level=0;
	if(a==b){
			
			return;
		}
	int mid=(a+b)>>1;
	buildtree(cur<<1,a,mid);
	buildtree(cur<<1|1,mid+1,b);

}

void update(int cur,int a,int b){
	if(tree[cur].l==a && tree[cur].r==b){
			tree[cur].level+=dir;
			if(tree[cur].level>0) tree[cur].leng=X[b]-X[a-1];
			else{
				if(a==b) tree[cur].leng=0;
				else tree[cur].leng=tree[cur<<1].leng+tree[cur<<1|1].leng;
				}
			
			return;		}
	
	int mid=(tree[cur].r+tree[cur].l)>>1;
	
	if(b<=mid){update(cur<<1,a,b);}
	else if(a>mid) {update(cur<<1|1,a,b);}
	else{
			update(cur<<1,a,mid);
			update(cur<<1|1,mid+1,b);
	}


	if(tree[cur].level==0){
		tree[cur].leng=tree[cur<<1].leng+tree[cur<<1|1].leng;
		}	

}

int main(){
	freopen("in.txt","r",stdin);
	int n,ks;ks=0;
	while(scanf("%d",&n)==1){
		if(n==0) break;
		ks++;
		int cnt=0;double x1,x2,y1,y2;
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			line[cnt].y=y1;line[cnt].xa=x1;line[cnt].xb=x2;X[cnt]=x1;line[cnt].type=1;cnt++;
			line[cnt].y=y2;line[cnt].xa=x1;line[cnt].xb=x2;X[cnt]=x2;line[cnt].type=-1;cnt++;
			

		}
			
	
		int a,b;
		sort(X,X+cnt);
		int num=unique(X,X+cnt)-X;
		buildtree(1,1,num-1);
		cover=0;area=0;

		sort(line,line+cnt);
		a=lower_bound(X,X+num,line[0].xa)-X+1;
		b=lower_bound(X,X+num,line[0].xb)-X;
		dir=line[0].type;		
		update(1,a,b);
		cover=tree[1].leng;
		
		for(int i=1;i<cnt;i++){
			area+=(line[i].y-line[i-1].y)*(cover);
		
			a=lower_bound(X,X+num,line[i].xa)-X+1;
			b=lower_bound(X,X+num,line[i].xb)-X;
			dir=line[i].type;

			update(1,a,b);
			cover=tree[1].leng;
	}
		printf("Test case #%d\n",ks);
		printf("Total explored area: %.2lf\n\n",area);
	}

	return 0;}
