#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<queue>  
#include<fstream>  
using namespace std;  
#define INF 0x7fffffff  
int DP[15][1<<10];  
bool Inq[15][1<<10];  
struct Road  
{  
    int b,c,p,r;  
    Road()  
    {}  
    Road(int b,int c,int p,int r)  
    {  
        this->b=b,this->c=c,this->p=p,this->r=r;  
    }  
};  
vector<Road> Gra[15];  
int work(int n)  
{  
    queue<int> q1,q2;  
    int i,j,u,v,c,p,r,s;  
    memset(Inq,0,sizeof(Inq));  
    for(i=0;i<10;++i)  
        for(j=0;j<(1<<10);++j)  
            DP[i][j]=INF;  
    DP[0][1]=0,Inq[0][1]=true;  
    q1.push(0),q2.push(1);  
    while(!q1.empty())  
    {  
        u=q1.front();  
        q1.pop();  
        s=q2.front();  
        q2.pop();  
        Inq[u][s]=false;  
        for(i=0;i<Gra[u].size();++i)  
        {  
            v=Gra[u][i].b,c=Gra[u][i].c,p=Gra[u][i].p,r=Gra[u][i].r;  
            if(s&(1<<c))  
            {  
                if(DP[u][s]+p<DP[v][s|(1<<v)])  
                {  
                    DP[v][s|(1<<v)]=DP[u][s]+p;  
                    if(!Inq[v][s|(1<<v)])  
                    {  
                        q1.push(v);  
                        q2.push(s|(1<<v));  
                        Inq[v][s|(1<<v)]=true;  
                    }  
                }  
            }  
            else  
            {  
                if(DP[u][s]+r<DP[v][s|(1<<v)])  
                {  
                    DP[v][s|(1<<v)]=DP[u][s]+r;  
                    if(!Inq[v][s|(1<<v)])  
                    {  
                        q1.push(v);  
                        q2.push(s|(1<<v));  
                        Inq[v][s|(1<<v)]=true;  
                    }  
                }  
            }  
        }  
    }  
    int ans=INF;  
    for(i=0;i<(1<<n);++i)  
    {  
        if((i&1)&&(i&(1<<(n-1))))  
            ans=min(ans,DP[n-1][i]);  
    }  
    return ans;  
}  
int main()  
{  freopen("in.txt","r",stdin);
    int n,m,i,j,a,b,c,p,r,ans;  
    scanf("%d %d",&n,&m);  
    while(m--)  
    {  
        scanf("%d %d %d %d %d",&a,&b,&c,&p,&r);  
        a--,b--,c--;  
        Gra[a].push_back(Road(b,c,p,r));  
    }  
    ans=work(n);  
    if(ans==INF)  
        printf("impossible\n");  
    else  
        printf("%d\n",ans);  
    return 0;  
}  
