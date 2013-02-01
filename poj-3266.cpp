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
int i,j,k,a,m,n,s,t,l,tt;
char tmp;
unsigned char ga[1024][1024];
void mkt(int left,int top,int size){
scanf("%c",&tmp);
switch(tmp){
    case 'W':
        LOOPB(i,top,top+size)
            LOOPB(j,left,left+size)
                ga[i][j>>3]&= ~(1<<(j&7));
        break;
    case 'B':
        LOOPB(i,top,top+size)
            LOOPB(j,left,left+size)
                ga[i][j>>3]|= 1<<(j&7);
        break;
    case 'Q':
        mkt(left,top,size>>1);
        mkt(left+(size>>1),top,size>>1);
        mkt(left,top+(size>>1),size>>1);
        mkt(left+(size>>1),top+(size>>1),size>>1);
}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    #endif
    scanf("%d\n",&n);
    printf("#define quadtree_width %d\n",n);
    printf("#define quadtree_height %d\n",n);
    printf("static char quadtree_bits[] = {\n");
    mkt(0,0,n);
    LOOPB(i,0,n){
        LOOPB(j,0,n>>3)
            printf("0x%02x,",ga[i][j]);
        printf("\n");
    }
    printf("};\n");
}
