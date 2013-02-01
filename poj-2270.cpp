/*
这题用这种做法太低效了……
POJ 700ms+，直接垫底；
但是标程也只快一点点而已。
到底他们都怎么做的啊？？
*/
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
int i,j,k,a,m,n,s,t,l,ga[512][512];
string str;

string build(int top,int left,int size){
    string a;
    if(size==1){
        a=ga[top][left];
        return a;
    }
    string b,c,d,ret;
    size>>=1;
    a=build(top,left,size);
    b=build(top,left+size,size);
    c=build(top+size,left,size);
    d=build(top+size,left+size,size);
    if(a[0]==b[0]&&a[0]==c[0]&&a[0]==d[0]&&a[0]!='Q')return a;
    else {
        ret='Q';
        a+=b;
        a+=c;
        a+=d;
        ret+=a;
        return ret;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("#define quadtree_width %d\n",&n);
m=n/8;
scanf("#define quadtree_height %d\n");
scanf("static char quadtree_bits[] = {\n");
LOOPB(i,0,n)
    LOOPB(j,0,m){
        scanf("%x",&a);
        t=1;
        LOOPB(k,0,8){
            if(a&t)ga[i][j*8+k]='B';
            else ga[i][j*8+k]='W';
            t<<=1;
        }
        scanf("%c");
    }

/*LOOPB(i,0,n){
    LOOPB(j,0,n)
        putchar(ga[i][j]);
    putchar('\n');
}*/
str=build(0,0,n);
printf("%d\n",n);
cout<<str<<endl;
}
