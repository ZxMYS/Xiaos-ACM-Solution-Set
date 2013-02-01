#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define VI vector<int>
#define eps 1e-9
const double pi = acos(-1.0);

template <class T> T sqr(T x){return x * x;}

using namespace std;

double f(double a,double b,double A,double B,double sita)
{
       sita = fmod(sita,pi);
       if (sita < 0) sita += pi;
       if (sita > pi/2) sita = pi - sita;

       if (fabs(sita - pi/2) < eps) return B;

       if (sita > atan(B/A)) return B/sin(sita);
       else return A/cos(sita);
}

bool check(double a,double b,double A,double B)
{
     if (min(a,b) - eps <= min(A,B))
     if (max(a,b) - eps <= max(A,B))
     return 1;
     if (sqr(a) + sqr(b) + eps >= sqr(A) + sqr(B)) return 0;

     double l = atan(B/A),r = pi / 2;
     while (fabs(r - l) > eps)
     {
           double m = (l + r)/2;
           if (f(a,b,A,B,m) < sqrt(sqr(a) + sqr(b))) r = m;
           else l = m;
     }

     double sita = (l + r)/2;
     double delta = atan(a/b) * 2;

     if (f(a,b,A,B,sita + delta) >= sqrt(sqr(a) + sqr(b))) return 1;
     if (f(a,b,A,B,sita - delta) >= sqrt(sqr(a) + sqr(b))) return 1;
     if (f(a,b,A,B,sita +(pi - delta)) >= sqrt(sqr(a) + sqr(b))) return 1;
     if (f(a,b,A,B,sita -(pi - delta)) >= sqrt(sqr(a) + sqr(b))) return 1;

     return 0;
}

int main()
{
    double a,b,c,d,e;
    while(cin >> a >> b >> c >> d >> e)
    {
        if (check(a,b,d,e)) cout << "YES";
        else if (check(a,c,d,e)) cout << "YES";
        else if (check(b,c,d,e)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
