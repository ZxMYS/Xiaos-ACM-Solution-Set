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
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
int i,j,k,m,n,t,l,tt,cas;
const int radius=6378;
typedef struct {double x,y,z;} node;
map<string,node> _map;
map<string,node>::iterator a,b,c;
double lon,lat,x,y,z,an;
node tmp;
string s,s1,s2;
inline double deg2rad(const double& deg){
    return deg*M_PI/180.0;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
cout.setf(ios::fixed);
cout.precision(0);
while(cin>>s&&s[0]!='#'){
    cin>>lat>>lon;
    tmp.x=cos(deg2rad(lat))*cos(deg2rad(lon));
    tmp.y=cos(deg2rad(lat))*sin(deg2rad(lon));
    tmp.z=sin(deg2rad(lat));
    _map.insert(make_pair(s,tmp));
}
while(cin>>s&&s[0]!='#'){
    cin>>s1>>s2;
    a=_map.find(s);
    if(a==_map.end())
        goto L1;
    b=_map.find(s1);
    if(b==_map.end())
        goto L1;
    c=_map.find(s2);
    if(c==_map.end())
        goto L1;
    x=a->second.x-b->second.x;
    y=a->second.y-b->second.y;
    z=a->second.z-b->second.z;
    if(!x&&!y&&!z){
        cout<<s2<<" is 0 km off "<<s<<'/'<<s1<<" equidistance."<<endl;
        continue;
    }
    an=acos((x*c->second.x+y*c->second.y+z*c->second.z)/sqrt(x*x+y*y+z*z));
    cout<<s2<<" is "<<fabs((M_PI/2-an)*radius)<<" km off "<<s<<'/'<<s1<<" equidistance."<<endl;
    continue;
    L1:
        cout<<s2<<" is ? km off "<<s<<'/'<<s1<<" equidistance."<<endl;
}
}
