#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<list>
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

void getNext(char pat[], int next[])
{
   int j = 0;
   int k = -1;
   next[0] = -1;
   while (pat[j])
   {
      if ( k == -1 || pat[j] == pat[k])
      {
         j++;
         k++;
         next[j] = k;
      }
      else
      {
         k = next[k];
      }
   }
}

int index_KMP(char str[], char pat[])
{
     int i = 0;
     int j = 0;
     int next[255];
     getNext(pat, next);
     while (str[i])
     {
        if (pat[j] == '\0')
        {
           return (i - j);
        }
        if (str[i] == pat[j])
        {
           i++;
           j++;
           continue;
        }
        i += next[j+1]+1;
     }
     if (pat[j] == '\0')
     {
           return (i - j);
     }
     return -1;
}

int CountStr(char* str,char* strTarget)
{
    int t=-1,count=0;;
    while(*str)
    {
        t=index_KMP(str, strTarget);
        if(t!=-1)
        {
            count++;
            str+=t+1;
        }else break;
    }
    return count;
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d",&n,&m);
while(n!=0){

scanf("%d%d",&n,&m);
}
}
