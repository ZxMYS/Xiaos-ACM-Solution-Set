#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t=0,l,tt,ttt;
char tmp,word[2000][500],word2[2000][500],tmp2[500];
bool duan1[2000],duan[2000],flag;
string out;
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
    out="";
while(scanf("%c",&tmp)!=EOF){

    ttt=0;l=0;
    memset(duan,0,sizeof(duan));
    memset(duan1,0,sizeof(duan1));
    while(tmp!='.'){
        tt=0;
        while(tmp!=' '&&tmp!='.'){
            word[ttt][tt]=tmp;
            word2[ttt][tt++]=tmp<'a'?(tmp-'A'+'a'):tmp;
            scanf("%c",&tmp);
        }
        word[ttt][tt]=word2[ttt][tt]='\0';
        if((!(strcmp(word2[ttt],"can")))||(!(strcmp(word2[ttt],"may")))||(!(strcmp(word2[ttt],"must")))||(!(strcmp(word2[ttt],"should"))))
            {duan[ttt+1]=true;l++;}
        else if ((!(strcmp(word2[ttt],"is")))||(!(strcmp(word2[ttt],"are"))))
            {duan1[ttt+1]=true;l++;}
        ttt++;
        if(tmp!='.')scanf("%c",&tmp);
    }
    scanf("%c",&tmp);
    while(l--){
        t++;
        flag=false;
    LOOPB(i,0,ttt){
            if(i!=0)out+=" ";
            if((flag)||((!duan1[i])&&(!duan[i]))){
                out+=word[i];
            }
            else if(duan[i]) {out+="not";duan[i]=false;flag=true;
                out+=" ";
                out+=word[i];
            }
            else if(duan1[i]) {out+="no";duan1[i]=false;flag=true;
                if(strcmp(word2[i],"a")&&strcmp(word2[i],"the")&&strcmp(word2[i],"an")){
                    out+=" ";
                    out+=word[i];
                }
            }
        }
        if(duan[ttt]&&!flag) {out+=" not";duan[ttt]=false;}
        if(duan1[ttt]&&!flag){out+=" no";duan1[ttt]=false;}
        
        //out[out.length()]='';
        out+=".\n";
    }
}
    cout<<t<<endl;
    cout<<out;
}
