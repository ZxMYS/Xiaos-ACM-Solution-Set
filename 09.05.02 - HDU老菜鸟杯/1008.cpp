#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
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
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas;
char tmp,tmp2;
string str,str4;
inline char chintochar(int ch1,int ch2){
    switch(ch1){
        case 2:
                switch(ch2){
                    case 1:return 'A';
                    case 2:return 'B';
                    case 3:return 'C';
                }
        case 3:
                switch(ch2){
                    case 1:return 'D';
                    case 2:return 'E';
                    case 3:return 'F';
                }
        case 4:
                switch(ch2){
                    case 1:return 'G';
                    case 2:return 'H';
                    case 3:return 'I';
                }
        case 5:
                switch(ch2){
                    case 1:return 'J';
                    case 2:return 'K';
                    case 3:return 'L';
                }
        case 6:
                switch(ch2){
                    case 1:return 'M';
                    case 2:return 'N';
                    case 3:return 'O';
                }
        case 7:
                switch(ch2){
                    case 1:return 'P';
                    case 2:return 'Q';
                    case 3:return 'R';
                    case 4:return 'S';
                }
        case 8:
                switch(ch2){
                    case 1:return 'T';
                    case 2:return 'U';
                    case 3:return 'V';
                }
        case 9:
                switch(ch2){
                    case 1:return 'W';
                    case 2:return 'X';
                    case 3:return 'Y';
                    case 4:return 'Z';
                }
    }
}

inline void chintoqwer(){
    int i,j;
    string str2="QWERTYUIOPASDFGHJKLZXCVBNMABCDEFGHIJKLMNOPQRSTUVWXYZ";
    LOOPB(i,0,str.length()){
        LOOPB(j,0,26){
            if(str[i]==str2[j])break;
        }
        str[i]=str2[j+26];
    }
}

inline void solve(){
    chintoqwer();
    string str3="";
    j=n=str.length()>>1;
    if(str.length()&1){
        n+=1;
        j+=1;
    }
    k=0;
    LOOPB(i,0,str.length()){
        if(i&1)
            str3+=str[j++];
        else
            str3+=str[k++];
    }
    reverse(str3.begin(),str3.end());
    cout<<str3<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(cin>>str4){
    int i;
    str="";
    for(i=0;i<str4.length();i+=2){
        tmp=str4[i];
        tmp2=str4[i+1];
        s=tmp-'0';
        t=tmp2-'0';
        str+=chintochar(s,t);
    }
    solve();
}
}
