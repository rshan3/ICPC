    #include <iostream>  
    #include <cstring>  
    #include <cstdlib>  
    #include <cstdio>  
    #include <cmath>  
    using namespace std;  
    int n, m, num, _max, cal[8];  
    struct point  
    {  
        int start, des, ticket;  
    } po[24];  
    int judge(int cur)  
    {  
        int end = po[cur].des;  
        for(int i = po[cur].start; i < end; i++)  
        {  
            cal[i] += po[cur].ticket;  
            if(cal[i] > n)  
                return 0;  
        }  
        return 1;  
    }  
    void DFS(int cur, int sum)  
    {  
        if(cur == num)  
        {  
            if(_max < sum)  
                _max = sum;  
            return ;  
        }  
        int save[8];  
        DFS(cur + 1, sum);  
        memcpy(save, cal, sizeof(save));  
        if(judge(cur))  
            DFS(cur + 1, sum + po[cur].ticket * (po[cur].des - po[cur].start));  
        memcpy(cal, save, sizeof(save));  
    }  
    int main()  
    {  
    #ifdef test  
        freopen("sample.txt", "r", stdin);  
    #endif  
        while(scanf("%d%d%d", &n, &m, &num))  
        {  
            if(!n && !m && !num)  
                break;  
            for(int i = 0; i < num; i++)  
                scanf("%d%d%d", &po[i].start, &po[i].des, &po[i].ticket);  
            _max = 0;  
            DFS(0, 0);  
            printf("%d\n", _max);  
        }  
        return 0;  
    }  
