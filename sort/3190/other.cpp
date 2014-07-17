    #include <iostream>  
    #include <cstdio>  
    #include <queue>  
    #include <algorithm>  
      
    using namespace std;  
      
    struct cow  
    {  
        int st,ed;  
        int p;  
        bool operator<(const cow& rhs) const //重载  
        {  
            return ed>rhs.ed; //可取出右端点最小的。若改成'<'则取出右端点最大的。  
        }  
    }a[51111];  
      
    bool cmp(cow a,cow b)  
    {  
        return a.st<b.st;  
    }  
      
    int main()  
    {  
        int n,num[51111],sz=0;  
        scanf("%d",&n);  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%d%d",&a[i].st,&a[i].ed);  
            a[i].p=i;  
        }  
        sort(a+1,a+n+1,cmp);  
        priority_queue<cow>que;  
        num[a[1].p]=++sz;  
        que.push(a[1]);  
        for(int i=2;i<=n;i++)  
        {  
            cow temp=que.top();  
            if(temp.ed<a[i].st)  
            {  
                num[a[i].p]=num[temp.p];  
                que.pop();  
                que.push(a[i]);  
            }  
            else  
            {  
                num[a[i].p]=++sz;  
                que.push(a[i]);  
            }  
        }  
        printf("%d\n",sz);  
        for(int i=1;i<=n;i++)  
            printf("%d\n",num[i]);  
      
        return 0;  
    }  
