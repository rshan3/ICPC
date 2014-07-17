    #include<iostream>  
    #include<cstdio>  
    #include<string>  
    #include<cstring>  
    using namespace std;  
      
    struct Statement  
    {  
        char speaker,object,nature;//说话者、陈述对象、对象的性质  
        bool whether;//是否  
    };  
      
    Statement s[60];  
    int res[5][4];//保存枚举的结果  
      
    void input(int num)  
    {  
        string str1,str2;  
        getline(cin,str1);  
        for(int i=0;i<str1.length();i++)//把陈述的所有空格去掉  
            if(str1[i]!=' ') str2+=str1[i];  
        s[num].speaker=str2[0];  
        if(str2[3]=='t')   
        {  
            s[num].object='t';//陈述对象是时间  
            if(str2[7]=='o')  
            {  
                s[num].whether=false;  
                s[num].nature=str2[9];  
            }  
            else  
            {  
                s[num].whether=true;  
                s[num].nature=str2[6];  
            }  
        }  
        else  
        {  
            if(str2[2]=='I')  
                s[num].object=s[num].speaker;  
            else  
                s[num].object=str2[2];  
            if(str2[5]=='n')  
            {  
                s[num].whether=false;  
                s[num].nature=str2[8];  
            }  
            else  
            {  
                s[num].whether=true;  
                s[num].nature=str2[5];  
            }  
        }  
    }  
    bool judge(int _fact,int t,bool whether,char statement)//判断陈述的性质与事实是否相符  
    {  
        char fact;  
        if(_fact==1) fact='d';  
        else if(_fact==2) fact='e';  
        else fact='h';  
        if(statement=='l'&&whether)  
        {  
            if(fact=='e'||fact=='h'&&t==2)//如果指证对方说谎，那么对方必须是恶魔或者晚上的人类才陈述正确  
                return 1;  
            else  
                return 0;  
        }  
        if(statement=='l'&&!whether)//如果澄清对方没有说谎，那么对方必须是牧师或者白天的人类才陈述正确  
        {  
            if(fact=='d'||fact=='h'&&t==1)  
                return 1;  
            else  
                return 0;  
        }  
        if((statement==fact)==whether)//同为真或同为假时陈述正确  
            return 1;  
        else  
            return 0;  
    }     
    bool islegal(int num,int A,int B,int C,int D,int E,int t)  
    {  
        bool stateistrue;//记录陈述是否正确  
        if(s[num].object=='t')//如果陈述的是时间  
        {  
            char time;  
            if(t==1) time='d';  
            else time='n';  
            if((s[num].nature==time)==(s[num].whether))//同为真或同为假时陈述正确  
                stateistrue=1;  
            else   
                stateistrue=0;  
        }  
        else  
        {  
            switch(s[num].object)  
            {  
                case'A':stateistrue=judge(A,t,s[num].whether,s[num].nature);break;  
                case'B':stateistrue=judge(B,t,s[num].whether,s[num].nature);break;  
                case'C':stateistrue=judge(C,t,s[num].whether,s[num].nature);break;  
                case'D':stateistrue=judge(D,t,s[num].whether,s[num].nature);break;  
                case'E':stateistrue=judge(E,t,s[num].whether,s[num].nature);break;  
            }  
        }  
        if(stateistrue)//判断完陈述是否正确还需要结和说话人的身份去确认陈述是否合法  
        {  
            switch(s[num].speaker)  
            {  
                case'A':if(A==1||A==3&&t==1) return 1;else return 0;  
                case'B':if(B==1||B==3&&t==1) return 1;else return 0;  
                case'C':if(C==1||C==3&&t==1) return 1;else return 0;  
                case'D':if(D==1||D==3&&t==1) return 1;else return 0;  
                case'E':if(E==1||E==3&&t==1) return 1;else return 0;  
            }  
        }  
        else  
        {  
            switch(s[num].speaker)  
            {  
                case'A':if(A==2||A==3&&t==2) return 1;else return 0;  
                case'B':if(B==2||B==3&&t==2) return 1;else return 0;  
                case'C':if(C==2||C==3&&t==2) return 1;else return 0;  
                case'D':if(D==2||D==3&&t==2) return 1;else return 0;  
                case'E':if(E==2||E==3&&t==2) return 1;else return 0;  
            }  
        }  
    }  
    int main()  
    {  freopen("in.txt","r",stdin);
        int i,j,n,cases=0;  
        while(cin>>n&&n)  
        {  
            getchar();  
            cases++;  
            cout<<"Conversation #"<<cases<<endl;  
            for(i=0;i<n;i++)  
            {  
                input(i);//输入第i个陈述  
            }  
            memset(res,0,sizeof(res));  
            int day=0,night=0;  
            for(int A=1;A<=3;A++)//1、2、3分别代表divine,evil,human   
                for(int B=1;B<=3;B++)  
                    for(int C=1;C<=3;C++)  
                        for(int D=1;D<=3;D++)  
                            for(int E=1;E<=3;E++)  
                                for(int t=1;t<=2;t++)//1表示白天，2表示夜晚  
                                {  
                                    int ok=1;  
                                    for(i=0;i<n;i++)  
                                        if(islegal(i,A,B,C,D,E,t)){}//判断该陈述是否合法  
                                        else  
                                        {  
                                            ok=0;  
                                            break;  
                                        }  
                                    if(ok)  
                                    {  
                                            res[0][A]=1;  
                                            res[1][B]=1;  
                                            res[2][C]=1;  
                                            res[3][D]=1;  
                                            res[4][E]=1;  
                                            if(t==1) day=1;  
                                            else night=1;  
                                    }  
                                }  
            int impossible=0,nodeducible=1;  
            for(i=0;i<5;i++)  
            {  
                int cnt=0,index;  
                for(j=1;j<=3;j++)  
                    if(res[i][j])  
                    {  
                        cnt++;  
                        index=j;  
                    }  
                if(cnt==0)  
                {  
                    impossible=1;  
                    break;  
                }  
                else if(cnt==1)  
                {  
                    char person=i+'A';  
                    if(index==1)  
                        cout<<person<<" is divine."<<endl;  
                    else if(index==2)  
                        cout<<person<<" is evil."<<endl;  
                    else  
                        cout<<person<<" is human."<<endl;  
                    nodeducible=0;  
                }  
            }  
            if(!day&&!night) impossible=1;  
            else if(day&&!night)   
            {  
                cout<<"It is day."<<endl;  
                nodeducible=0;  
            }  
            else if(night&&!day)  
            {  
                cout<<"It is night."<<endl;  
                nodeducible=0;  
            }  
            if(impossible) cout<<"This is impossible."<<endl;  
            else if(nodeducible) cout<<"No facts are deducible."<<endl;  
            putchar('\n');  
        }  
        return 0;  
    }  


