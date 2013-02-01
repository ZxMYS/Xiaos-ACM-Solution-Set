#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
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
int i,j,k,A,p,m,n,B,s,t,tt,cas,l;
long long int wtf,ans,AA,BB;
int a[510],aa[510],amax=-oo,amaxi;
bool has[10101],flag;
typedef struct {long long int v;int r;} node;
vector<node> f;
node tmp;
inline bool cmp(const node& a,const node& b){
    return a.v<b.v;
}

inline bool eq(const node& a,const node& b){
    return a.v==b.v;
}

inline bool jiao(){
    AA=MAX(f[p].v,A);
    BB=MIN(f[p+1].v-1,B);
    if(AA>BB)return false;
    return true;
}

inline long long gcd(long long a,long long b){
    long long c;
    while(b){
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

inline int lcm(const long long& a,const long long b){
    long long tmp=gcd(a,b);
    if(tmp==0){
        flag=true;
        return -1;
    }
    return a*b/tmp;
}

inline long long LCM(){
    int i;
    long long ll=aa[0];
    LOOPB(i,1,n)
        ll=lcm(ll,aa[i]);
    return ll;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d%d%d",&n,&A,&B)!=EOF){
    memset(has,0,sizeof(has));
    f.clear();ans=0;i=0;
    LOOPB(j,0,n){
        scanf("%d",&a[i]);
        if(has[a[i]])continue;
        has[a[i]]=true;
        aa[i]=0;
        if(a[i]>amax){
            amax=a[i];
            amaxi=i;
        }
        wtf=a[i];
        tmp.r=i;
        while(wtf<=B){
            tmp.v=wtf;
            f.push_back(tmp);
            wtf*=a[i];
        }
        tmp.v=wtf;
        f.push_back(tmp);
        i++;
    }
    n=i;
    sort(f.begin(),f.end(),cmp);
    /*LOOPB(i,0,f.size())
        cout<<f[i].v<<' '<<f[i].r<<' ';
    cout<<endl;*/
    p=0;

    while(p!=f.size()){
        flag=false;
        while(!jiao()&&p!=f.size()){
            aa[f[p].r]++;
            p++;
        }
        if(p==f.size())break;
        aa[f[p].r]++;
        if(aa[amaxi]<=0)goto L1;
        l=LCM();
        if(flag||l==0)goto L1;
        /*cout<<"!"<<AA<<','<<BB<<' '<<l<<endl;
        LOOPB(i,0,n)
            cout<<aa[i]<<' ';
        cout<<endl;*/
        AA=AA+((AA%l)?l-AA%l:0);
        if(AA>BB)goto L1;
        ans+=((BB-AA)/l)+1;
        L1:
            p++;
    }
    cout<<ans<<endl;
}
}
