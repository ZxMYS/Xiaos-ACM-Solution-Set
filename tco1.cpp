#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct aaa{int a,b;} aa[60];
int i,cc[60];
bool less(const struct aaa &a, const struct aaa &b)
{
        return a.a > b.a;
}
class SortingWithPermutation{
public:
vector <int> getPermutation(vector <int> a){
vector <int> b;
b.clear();
for(i=0;i<a.size();i++){
        aa[i].a=a[i];
        aa[i].b=i;
        printf("%d\n",aa[i].a);
}


stable_sort( aa,aa+a.size(),less);

for(i=0;i<a.size();i++){
        printf("%d\n",aa[i].a);
}
for(i=0;i<a.size();i++){
cc[aa[i].b]=i;
}
for(i=0;i<a.size();i++){
        b.push_back(cc[i]);
}
return b;
}

};
