#include<iostream>
#include<vector>

using namespace std;

struct dot
{
       dot(int _x = 0,int _y = 0)
       {
              x = _x;
              y = _y;
       }
       int x;
       int y;
};

bool operator < (dot a,dot b)
{
         return (a.x < b.x || (a.x == b.x && a.y < b.y) );
}

bool operator == (dot a,dot b)
{
     return (a.x == b.x && a.y == b.y);
}

vector<dot> a;
int n,w,h;

int main()
{
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);

    cin >> n >> w >> h;
    for (int i = 1;i<=n;i++)
    {
        int x,y;
        cin >> x >> y;
        a.push_back(dot(x,y));
    }
    a.push_back(dot(0,0));
    a.push_back(dot(w,0));
    a.push_back(dot(0,h));
    a.push_back(dot(w,h));
    sort(a.begin(),a.end());
    unique(a.begin(),a.end());
    n = a.size();

    /*/
    cout << n << endl;
    for (int i = 0;i!=n;i++)
    cout << a[i].x << " " << a[i].y << endl;
    /*/

    int answer = 0;
    int answerx,answery;

    for (int i = 0;i!=n;i++)
    for (int j = 0;j!=n;j++)
    if (a[i].x < a[j].x && a[i].y > a[j].y )
    {
        int left = 0;
        int right = min(w - a[i].x,h - a[j].y);
        while (left != right)
        {
              //x : a[i].x , a[i].x + mid
              //y : a[j].y ,a[j].y + mid
              int mid = (left + right + 1) / 2;
              bool ok = 1;
              for (int k = 0;k!=n;k++)
              if (a[i].x < a[k].x && a[k].x < a[i].x + mid)
              if (a[j].y < a[k].y && a[k].y < a[j].y + mid)
              {
                 ok = 0;
                 break;
              }
              if (ok) left = mid;
              else right = mid - 1;
        }
        if (left > answer)
        {
                 answer= left;
                 answerx = a[i].x;
                 answery = a[j].y;
        }
    }

    cout << answerx << " " << answery << " " << answer << endl;

    return 0;
}
