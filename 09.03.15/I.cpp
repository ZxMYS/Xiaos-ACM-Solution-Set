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
#define MaxN 1000
#define MaxLen 20
struct str
{
       void read()
       {
            len = 0;
            char ch;
            scanf("%c",&ch);
            while (ch != '\n')
            {
                  a[++len] = ch;
                  scanf("%c",&ch);
            }
       }

       void maxi(int i,int j,int x,int fi,int fj)
       {
            if (f[i][j] < x)
            {
                        f[i][j] = x;
                        fr[i][j][0] = fi;
                        fr[i][j][1] = fj;
            }
       }

       void update(int x1,int x2)
       {
            if (x1 == 0 || x2 == 0) return;
            if (fr[x1][x2][0] < x1 && fr[x1][x2][1] < x2)
            {
                              update(x1-1,x2 - 1);
                              x[++n1] = x1;
                              y[++n2] = x2;
            }
            else if (fr[x1][x2][0] < x1) update(x1 - 1,x2);
            else update(x1,x2 - 1);
       }

       void LCS(str &b)
       {
            memset(f,0,sizeof(f));
            memset(fr,0,sizeof(fr));
            for (int i = 1;i<=len;i++)
            for (int j = 1;j<=b.len;j++)
            {
                f[i][j] = 0;
                if (a[i] != b.a[j])
                {
                         maxi(i,j,f[i-1][j],i-1,j);
                         maxi(i,j,f[i][j-1],i,j-1);
                }
                else maxi(i,j,f[i-1][j-1] + 1,i - 1,j - 1);
            }
            n1 = 0,n2 = 0;
            update(len,b.len);
       }

       int len;
       char a[MaxN];
       int f[MaxLen][MaxLen];
       int fr[MaxLen][MaxLen][2];
       int x[MaxLen];int n1;
       int y[MaxLen];int n2;
} st[100],tmpp;
char tmp[100],tmp2[100];
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,MLEN;
bool flag,flag2;
bool chk(char a[],char p[]){
    //printf("CHECKING.....%s in %s\n",p,a);
    bool flag=0;
    int len=strlen(p),lena=strlen(a),i=0,j=0;
    if((!a[0]&&!p[0])||((!a[0])&&p[0]=='*'&&len==1)||(!strcmp(a,p)))return true;
    else if (!a[0]) return false;
    while(p[i]){
        if(!(a[j])&&i==len-1&&p[i]=='*')return true;
        else if(!a[j]) return false;
        if(p[i]=='*'){
            i++;
            if(i==len)return true;
            while(j<lena&&p[i]!=a[j])j++;
            while(j<lena){
                j++;i++;
                flag=flag||chk(a+j-1,p+i-1);
                i--;
                while(j<lena&&p[i]!=a[j])j++;
            }
            return flag;
            if(j==lena)return false;
        }else if(p[i]=='?'){
                i++;
                j++;
                if(j==lena&&i==len)return true;
                else if(j==lena&&i==len-1&&p[i]=='*') return true;
                else if(j==lena)return false;
        }else if(p[i]==a[j]){i++;j++;}
        else return false;
    }
    if((a[j])&&p[len-1]=='*')return true;
    return false;
}

bool try1(char a[]){
int i;
LOOPB(i,0,n)
    if(!chk(st[i].a+1,a))return false;
return true;
}
bool try2(char a[]){
int i;
LOOPB(i,n,m+n)
    if(chk(st[i].a+1,a))return false;
return true;
}

char* str_rep(char *str, const char *strSearch, const char *strReplace)
{
char *pTemp = str;
int iStrSearlen, iStrReplen, iTemp;

if (str == NULL || strSearch == NULL || strReplace == NULL)
{
return NULL;
}

iStrSearlen = strlen(strSearch);
iStrReplen = strlen(strReplace);
iTemp = iStrSearlen - iStrReplen;

if( iStrSearlen == 0 ) //如果查找字符串的长度为0(调用strstr()函数前必须考虑的)，直接返回
{
return str;
}

while(pTemp = strstr(pTemp, strSearch)) //匹配到字符串，进行替换。
{
const char *p = strReplace;
if(iTemp < 0)
{
int i = strlen(str);
while (i >= pTemp-str+iStrSearlen) //i >= pTemp-str+iStrlen
{
str[i-iTemp] = str[i]; //整体向后移动-iTemp位(包括最后的'\0')，注意iTemp<0
i--;
}
while(*p != '\0') //替换字符串
{
*pTemp++ = *p++;
}
}
else
{
while(*p != '\0')
{
*pTemp++ = *p++;
}

if(iTemp > 0) //如果匹配字符比替换字符长，则整体左移iTemp位
{
strcpy(pTemp, pTemp+iTemp);
}
}
return str;
}
return str;
}

//用strncpy(substr, str+begin, len);就是substr了
char* str_sub(char *substr, const char *str, size_t begin, size_t len)
{
strncpy(substr, str+begin, len);
substr[len] = '\0';

return substr;
}

void check(char ch[],int v,int step){
//printf("T %s\n",ch);

if(try1(ch)&&try2(ch))goto L3;

if(step<tmpp.len){
//printf("!!!\n");
check(ch,v+2,step+1);
char wok[200];
LOOPB(j,0,st[0].x[step]-st[0].x[step-1]-1)
    wok[j]='?';
wok[j]='\0';
str_rep(ch+v,"*",wok);
if(try1(ch))
    check(ch,v+st[0].x[step]-st[0].x[step-1],step+1);
}

if(!try2(ch)||!try1(ch))return;
L3:
    printf("%s\n",ch);
exit(0);
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
/*printf("%d\n",chk("aaaaa","*a*a*a*")?1:0);
printf("%d\n",chk("aabaa","*a*a*a*")?1:0);
printf("%d\n",chk("aaaaa","aaa")?1:0);
printf("%d\n",chk("aaaaa","aaa*")?1:0);
printf("%d\n",chk("aaaaa","*aaa")?1:0);
system("pause");*/
scanf("%d%d\n",&n,&m);
st[0].read();
MLEN=st[0].len;

flag=true;
LOOPB(i,1,n){
    st[i].read();
    if(flag&&MLEN!=st[i].len)flag=false;
    MLEN=MIN(st[i].len,MLEN);
}
l=n;
LOOPB(i,0,m){
    st[l].read();
    //printf("%d\n",chk(st[l].a+1,tmp)?1:0);
    l++;
}
l=-1;
LOOP(i,1,MLEN){
flag2=true;
LOOPB(j,1,n){
    if(st[0].a[i]!=st[j].a[i]){flag2=false;break;}
}
if(flag2){
    tmp[i]=st[0].a[i];
    l=i;
}
else
    tmp[i]='?';
}
if(flag)
tmp[MLEN+1]='\0';
else{
tmp[l+1]='*';
tmp[l+2]='\0';
}
if(l!=-1){
    //printf("TRY  %s\n",tmp+1);
    LOOPB(j,n,m+n)
        if(chk(st[j].a+1,tmp+1)){
            if(flag){printf("OOPS\n");exit(0);}
            else goto L1;
    }
    printf("%s\n",tmp+1);
    exit(0);
}
L1:
strcpy(tmp,st[0].a+1);
LOOPB(i,1,n){
    st[0].LCS(st[i]);
    LOOP(k,1,st[0].n1){
        st[0].a[k]=st[0].a[st[0].x[k]];
    }
    st[0].a[k]='\0';
    //printf("%s\n",st[0].a+1);
}
strcpy(tmp2,st[0].a+1);
strcpy(st[0].a+1,tmp);
a=strlen(tmp2);
tmp[0]='*';
l=1;
LOOPB(i,0,a){
        tmp[l++]=tmp2[i];
        tmp[l++]='*';
    }

tmp[l]='\0';
    LOOPB(j,n,m+n)
        if(chk(st[j].a+1,tmp)){
            goto L2;
    }
    printf("%s\n",tmp);
    exit(0);
L2:
    //printf("%s\n",tmp);
    strcpy(tmpp.a+1,tmp2);
    tmpp.len=strlen(tmp2);
    st[0].LCS(tmpp);
    //for (int i = 1;i<=st[0].n1;i++) cout << st[0].x[i] << " ";
    check(tmp,2,1);
    check(tmp+1,2,1);
    tmp[strlen(tmp)-1]='\0';
    check(tmp,2,1);
    check(tmp+1,2,1);
    printf("OOPS\n");
}
