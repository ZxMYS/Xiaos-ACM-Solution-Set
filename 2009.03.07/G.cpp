#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<sstream>
#include<assert.h>
#include<list>
#include<iostream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,b,m,n,t,l,tt,f[2][10000],top=0;
string s[10000];
bool flag;
char c;
vector<int> wox;
vector<int> s(int a){
    if(wox)
}

int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif

	top=-1;
	flag=0;
	while (scanf("%c",&c)>-1)
	{
		while (c==' ' || c==10)
			if (scanf("%c",&c)==-1)
			{
				break;
				flag=1;
			}
		top++;
		if (flag==1) break;
		s[top]="";
		if (c==EOF) break;
		while (c!=' ' && c!=EOF && c!=10 &&c!='\n')
		{
			s[top]+=c;
			if (c==',' || c=='.' || c=='!' || c=='?')
				break;
			if (scanf("%c",&c)==-1)
			{
				break;
				flag=1;
			}
		}
		if (flag==1) break;
		if (s[top]=="," || s[top]=="." || s[top]=="!" || s[top]=="?")
		{
			top--;
			s[top]+=s[top+1];
		}
	}

LOOP(i,0,top)
    cout<<s[i]<<endl;
tt=1<<29;
printf("%d\n",s(0));
a=0;
/*LOOPB(i,1,top)
    f[0][i]=f[1][i]=1<<28;
f[0][0]=f[1][0]=0;
f[0][1]=f[1][1]=s[0].length();
LOOPB(i,1,top){
    cout<<s[i]<<" "<<s[i].length()<<endl;
    b=(a+1)&1;
    LOOP(j,1,i+1){
        if(j==1)f[b][j]=f[a][j]+1+s[i].length();else
        f[b][j]=MIN(MAX(f[a][j-1],s[i].length()),f[a][j]+1+s[i].length());
        printf("%d %d\n",f[b][j],j);
    }
    a=b;
}


top--;
LOOP(i,1,top)
    if(tt>(f[a][i]+2)*(i+2)){
        tt=(f[a][i]+2)*(i+2);
        printf("‡å%d\n",i);
        assert(tt>0);
    }*/
//printf("%d\n",tt);
return 0;
}
