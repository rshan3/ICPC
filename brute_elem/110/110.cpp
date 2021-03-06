#include <iostream>
#include <cstdio>
using namespace std;
int n;
int result[10];



void dfs(int cur){
	if(cur==n){
		for(int i=0;i<2*cur;i++) cout << ' ';
		cout << "writeln(";
		for(int i=0;i<n-1;i++) cout << char('a'+result[i]) << ',';
		cout << char('a'+result[n-1]) << ')' << endl;
	}
	else{	int tmp[10];
		for(int i=0;i<cur;i++) tmp[i]=result[i];
		
		for(int i=0;i<2*cur;i++) cout << ' ';
		printf("if %c < %c then\n",'a'+result[cur-1],'a'+cur);
		result[cur]=cur;
		dfs(cur+1);
		for(int i=0;i<cur;i++) result[i]=tmp[i];

		for(int i=cur-2;i>=0;i--){
		for(int k=0;k<2*cur;k++) cout << ' ';
		printf("else if %c < %c then\n",'a'+result[i],'a'+cur);
			for(int j=cur;j>i;j--){
				result[j]=result[j-1];}
			result[i+1]=cur;
		dfs(cur+1);
		for(int i=0;i<cur;i++) result[i]=tmp[i];
		}	

		for(int i=0;i<2*cur;i++) cout << ' ';
		cout << "else" << endl;
		for(int i=cur;i>0;i--) result[i]=result[i-1];
		result[0]=cur;
		dfs(cur+1);
		for(int i=0;i<cur;i++) result[i]=tmp[i];
	}


}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int ks;
	cin >> ks;
	while(ks--){
		cin >> n;
		result[0]=0;
		cout << "program sort(input,output);\nvar" << endl;
		for(int i=0;i<n-1;i++) cout << (char)('a'+i) << ',';
		cout << char('a'+n-1) <<" : integer;\nbegin\n  readln(";
		for(int i=0;i<n-1;i++) cout << (char)('a'+i) << ',';
		cout << char('a'+n-1) << ");\n";

		dfs(1);
		cout <<"end."<< endl;
		if(ks) cout << endl;
	}

	return 0;}
