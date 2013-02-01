/*
题意就是求一个字典序最小的最小点覆盖。二分图最小点覆盖等于最大匹配
，这个大家都知道，但是怎么使得字典序最小呢？

我们使用以下方法：
1：求最大匹配
2：在最大匹配基础上
     从0开始枚举
         去掉这点
         若最小覆盖变小，说明该点必须在最小覆盖中，打出来
         否则                     恢复这点（如果打出了这点，那么由于最小覆盖数没变，最
         后一定会多输出，所以此时不能输出）

因为是从0开始的，所以这样就能得到字典序最小

问题是，如果在枚举的时候，还使用hungary，使用邻接矩阵复杂度O(N^4
)，很容易超时（从一边匹配是800~900ms，从另一边就TLE），邻接表还可
以O(N^2*M)，时间在300~400ms。1000ms的时限显然不是为O(N^2*M)的算法
准备的，我们这样考虑，在第二阶段枚举时，如果该点是不在匹配中的点，
那么可以直接跳过，这个肯定不会输出；如果该点匹配了，删掉他后，当且
仅当能从他匹配对应的那点找到一条增广路，最小覆盖不变（这个地方是关
键）。这样我们就得到了邻接表实现的O(N*M)的算法。
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
int i,j,k,a,m,n,s[201],t,l[201],tt,group[201];
vector<int> ga[201];
bool chk[201],ava[201];
bool find(int n){
chk[n]=true;
int i,j=ga[n].size();
LOOPB(i,0,j){
    if(!chk[ga[n][i]]&&ava[ga[n][i]]){
        chk[ga[n][i]]=true;
        if(l[ga[n][i]]==-1||find(l[ga[n][i]])){
            l[ga[n][i]]=n;
            s[n]=ga[n][i];    //NOTICE~记录匹配点
            return true;
        }
    }
}
return false;
}

bool dfs1(int n){
chk[n]=true;
int i,j=ga[n].size();
LOOPB(i,0,j){
    if(!chk[ga[n][i]]&&ava[ga[n][i]]){
        chk[ga[n][i]]=true;
        if(l[ga[n][i]]==-1||dfs1(l[ga[n][i]]))
            return true;
        }
    }
return false;
}

bool dfs2(int n){
chk[n]=true;
int i,j=ga[n].size();
LOOPB(i,0,j){
    if(!chk[ga[n][i]]&&ava[ga[n][i]]){
        chk[ga[n][i]]=true;
        if(s[ga[n][i]]==-1||dfs2(s[ga[n][i]]))
            return true;
        }
    }
return false;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&tt);
while(tt--){
    t=0;
    scanf("%d%d",&n,&m);
    LOOPB(i,0,n){
        scanf("%d",&group[i]);
        ga[i].clear();
        chk[i]=false;
        ava[i]=true;
        l[i]=-1;
        s[i]=-1;
    }
    LOOPB(i,0,m){
        scanf("%d%d",&a,&k);
        if(group[a]==group[k])continue;
        ga[a].push_back(k);
        ga[k].push_back(a);
    }
    LOOPB(i,0,n){
        if(group[i]){
            LOOPB(j,0,n)
                chk[j]=false;
            if(find(i))t++;
        }
    }
    printf("%d",t);
    LOOPB(i,0,n){
        if(!t)break;
        if(l[i]==-1&&s[i]==-1)continue;
        LOOPB(j,0,n)
            chk[j]=false;
        if(l[i]!=-1){
            ava[i]=false;
            if(!dfs1(l[i])){
                t--;
                s[l[i]]=-1;
                printf(" %d",i);
            }else
                ava[i]=true;
        }
        else if(s[i]!=-1){
            ava[i]=false;
            if(!dfs2(s[i])){
                t--;
                l[s[i]]=-1;
                printf(" %d",i);
            }else
                ava[i]=true;
        }
    }
putchar('\n');
}
}
