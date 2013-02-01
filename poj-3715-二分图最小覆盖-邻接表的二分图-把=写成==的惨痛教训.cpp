/*
���������һ���ֵ�����С����С�㸲�ǡ�����ͼ��С�㸲�ǵ������ƥ��
�������Ҷ�֪����������ôʹ���ֵ�����С�أ�

����ʹ�����·�����
1�������ƥ��
2�������ƥ�������
     ��0��ʼö��
         ȥ�����
         ����С���Ǳ�С��˵���õ��������С�����У������
         ����                     �ָ���㣨����������㣬��ô������С������û�䣬��
         ��һ�������������Դ�ʱ���������

��Ϊ�Ǵ�0��ʼ�ģ������������ܵõ��ֵ�����С

�����ǣ������ö�ٵ�ʱ�򣬻�ʹ��hungary��ʹ���ڽӾ����Ӷ�O(N^4
)�������׳�ʱ����һ��ƥ����800~900ms������һ�߾�TLE�����ڽӱ���
��O(N^2*M)��ʱ����300~400ms��1000ms��ʱ����Ȼ����ΪO(N^2*M)���㷨
׼���ģ������������ǣ��ڵڶ��׶�ö��ʱ������õ��ǲ���ƥ���еĵ㣬
��ô����ֱ������������϶��������������õ�ƥ���ˣ�ɾ�����󣬵���
�����ܴ���ƥ���Ӧ���ǵ��ҵ�һ������·����С���ǲ��䣨����ط��ǹ�
�������������Ǿ͵õ����ڽӱ�ʵ�ֵ�O(N*M)���㷨��
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
            s[n]=ga[n][i];    //NOTICE~��¼ƥ���
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
