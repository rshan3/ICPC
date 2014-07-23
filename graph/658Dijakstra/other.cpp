#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int b[110][2],p[110][2],t[110];
char s1[25],s2[25];
int n,m;
const int INF=1000000000;
queue<int> q;
bool inq[1<<20];
int d[1<<20];
void Bellman_Ford(){
     int maxn=(1<<n)-1;
     while(!q.empty()) q.pop();
     for(int i=0;i<(1<<20);i++){d[i]=INF;inq[i]=false;}
     q.push(maxn);d[maxn]=0;
     while(!q.empty()){
        int x=q.front();q.pop();
        inq[x]=false;
        for(int i=0;i<m;i++){
            int v;
            int v1=x|b[i][0],v2=x&b[i][1];
            if(v1==x&&v2==x){
                v=x|p[i][0];
                v=v&p[i][1];
                if(d[v]>d[x]+t[i]){
                    d[v]=d[x]+t[i];
                    if(!inq[v]){
                       inq[v]=true;
                       q.push(v);
                    }
                }
            }
        }
     }
}
int main(){
	freopen("in.txt","r",stdin);
    int cnt=0;
    while(scanf("%d%d",&n,&m)==2){
        if(n==0&&m==0) break;
        memset(b,0,sizeof(b));
        memset(p,0,sizeof(p));
        for(int i=0;i<m;i++){
            scanf("%d%s%s",&t[i],s1,s2);
            for(int j=0,k=n-1;j<n;j++,k--){
                if(s1[j]=='+') b[i][0]|=(1<<k);
                if(s2[j]=='+') p[i][0]|=(1<<k);
                if(s1[j]!='-') b[i][1]|=(1<<k);
                if(s2[j]!='-') p[i][1]|=(1<<k);
            }
        }
        Bellman_Ford();
        printf("Product %d\n",++cnt);
        if(d[0]!=INF)
            printf("Fastest sequence takes %d seconds.\n\n",d[0]);
        else
            printf("Bugs cannot be fixed.\n\n");
    }
    return 0;
} 
