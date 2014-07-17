    #include <cstdio>  
    #include <cstring>  
      
    using namespace std;  
      
    const int maxn = 50 + 10;  
    const int maxm = (1000 << 1) + 10;  
      
    int T, N, head[maxn], nxt[maxm], v[maxm], d[maxn], ecnt, kase;      //d[i]表示颜色i的度数  
    int fa[maxn];       //并查集用  
    bool vis[maxm];     //dfs用  
    bool color[maxn];       //color[i]标记颜色i是否出现过  
      
    int Find(int x){  
        return x == fa[x] ? x : (fa[x] = Find(fa[x]));  
    }  
      
    void Union(int x, int y){  
        int newx = Find(x);  
        int newy = Find(y);  
        if(newx != newy) fa[newy] = newx;  
    }  
      
    void init(){  
        memset(head, -1, sizeof(head));  
        memset(vis, 0, sizeof(vis));  
        memset(color, 0, sizeof(color));  
        memset(d, 0, sizeof(d));  
        for(int i = 1; i <= 50; i++) fa[i] = i;  
        ecnt = 0;  
    }  
      
    void addEdge(int uu, int vv){  
        v[ecnt] = vv;  
        nxt[ecnt] = head[uu];  
        head[uu] = ecnt;  
        ecnt++;  
    }  
      
    void dfs(int x){  
        for(int e = head[x]; e != -1; e = nxt[e]) if(!vis[e]){  
    //        printf("%d %d\n", x, v[e]);       //不能在这里输出！！！求解。。。  
            vis[e] = vis[e^1] = 1;  
            dfs(v[e]);  
            printf("%d %d\n", v[e], x);  
        }  
    }  
      
    void read(){  
        scanf("%d", &N);  
        int uu, vv;  
        for(int i = 0; i < N; i++){  
            scanf("%d%d", &uu, &vv);  
            addEdge(uu, vv);  
            addEdge(vv, uu);  
            d[uu]++;  
            d[vv]++;  
            color[uu] = color[vv] = 1;  
            Union(uu, vv);  
        }  
    }  
      
    void solve(){  
        printf("Case #%d\n", kase++);  
        bool ok = 1;  
        for(int i = 1; i <= 50; i++) if(d[i]&1){        //判是否能成欧拉回路  
            ok = 0;  
            break;  
        }  
        if(ok){     //判是否只有一个连通分量  
            int sum = 0;  
            for(int i = 1; i <= 50; i++) if(color[i] && fa[i] == i) sum++;  
            if(sum > 1) ok = 0;  
        }  
        if(ok) for(int i = 1; i <= 50; i++) dfs(i);     //这里不能单单1个dfs(1),也许珠子根本就没有1这种颜色  
        else puts("some beads may be lost");  
        if(T) puts("");  
    }  
      
    int main()  
    {  freopen("in.txt","r",stdin);
        kase = 1;  
        scanf("%d", &T);  
        while(T--){  
            init();  
            read();  
            solve();  
        }  
        return 0;  
    }  
