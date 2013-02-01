#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define PI 3.1415926535898
int i,j,k,m=0,n;
double d,ga[200][200];
char ch;
typedef struct {double x,y;} point;
typedef struct {int sx,sy,ex,ey;vector<int> p;} line;
typedef struct {int x,y,r;vector<int> p;} circle;
point p;
line l;
circle c;
vector<line> lines;
vector<circle> circles;
vector<point> points,tmp,tmp2;
const double INF=1<<29;

vector<point> LxL(line l1,line l2){
    tmp.clear();
    double d=(l2.ey-l2.sy)*(l1.ex-l1.sx)-(l2.ex-l2.sx)*(l1.ey-l1.sy);
    if(d==0)return tmp;
    double a=((l2.ex-l2.sx)*(l1.sy-l2.sy)-(l2.ey-l2.sy)*(l1.sx-l2.sx))/(double)d;
    double b=((l1.ex-l1.sx)*(l1.sy-l2.sy)-(l1.ey-l1.sy)*(l1.sx-l2.sx))/(double)d;
    if(a<0||a>1||b<0||b>1)return tmp;
    p.x=l1.sx+a*(l1.ex-l1.sx);
    p.y=l1.sy+a*(l1.ey-l1.sy);
    tmp.push_back(p);
    return tmp;
}
vector<point> LxC(line l,circle c){
    tmp.clear();
    int dx=l.ex - l.sx;
    int dy=l.ey - l.sy;
    int A=dx * dx + dy * dy;
    int B=2 * ( dx * ( l.sx - c.x ) + dy * ( l.sy - c.y ) );
    int C=( l.sx - c.x ) * ( l.sx - c.x ) + ( l.sy - c.y ) * ( l.sy - c.y ) - c.r * c.r;
    int D=B * B - 4 * A * C;
    if ( D <= 0 ) return tmp;
    double t=( -B + sqrt((double) D ) ) / ( 2 * A );
    if ( t >= 0 && t <= 1 ){
        p.x=l.sx + t * dx;
        p.y=l.sy + t * dy;
        tmp.push_back(p);
    }
    t=( -B - sqrt((double) D ) ) / ( 2 * A );
    if ( t >= 0 && t <= 1 ){
        p.x=l.sx + t * dx;
        p.y=l.sy + t * dy;
        tmp.push_back(p);
    }
    return tmp;
}
vector<point> CxC(circle c1,circle c2){
    tmp.clear();
    int dx=c2.x - c1.x;
    int dy=c2.y - c1.y;
    double d=sqrt((double) dx * dx + dy * dy );
    if ( d > c1.r + c2.r || d < abs( c1.r - c2.r ) ) return tmp;
    double a=( c1.r * c1.r  - c2.r * c2.r  + d * d ) / ( 2 * d );
    double x=c1.x + dx * a / d;
    double y=c1.y + dy * a / d;
    double h=sqrt((double) c1.r * c1.r - a * a );
    double rx=-dy * h / d;
    double ry=dx * h / d;
    p.x=x + rx;
    p.y=y + ry;
    tmp.push_back(p);
    p.x=x - rx;
    p.y=y - ry;
    tmp.push_back(p);
    return tmp;
}

double LDis(point p,point q) {
    return sqrt((double)(p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}
double CDis(circle c,point p,point q){
    double theta = fabs(atan2( p.y - c.y, p.x - c.x ) - atan2( q.y - c.y, q.x - c.x ));
    return c.r * MIN( theta, 2 * PI - theta );
}

int main()
{
while(1){
    scanf("%c\n",&ch);
    if(ch=='*')break;

    printf("Case %d: ",++m);

    LOOPB(i,0,200)
    LOOPB(j,0,200)
        ga[i][j]=INF;
    lines.clear();
    circles.clear();
    points.clear();

    do{
        if(ch=='L'){
            scanf("%d%d%d%d\n",&l.sx,&l.sy,&l.ex,&l.ey);
            l.p.clear();
            p.x=l.sx;p.y=l.sy;
            l.p.push_back(points.size());
            points.push_back(p);
            p.x=l.ex;p.y=l.ey;
            l.p.push_back(points.size());
            points.push_back(p);
            lines.push_back(l);
        }else{
            scanf("%d%d%d\n",&c.x,&c.y,&c.r);
            circles.push_back(c);
        }
        scanf("%c\n",&ch);
    }while(ch!='*');

    LOOPB(i,0,lines.size())
    LOOPB(j,i+1,lines.size()){
        tmp2=LxL(lines[i],lines[j]);
        LOOPB(k,0,tmp2.size()){
            lines[i].p.push_back(points.size());
            lines[j].p.push_back(points.size());
            points.push_back(tmp2[k]);
        }
    }
    LOOPB(i,0,lines.size())
    LOOPB(j,0,circles.size()){
        tmp2=LxC(lines[i],circles[j]);
        LOOPB(k,0,tmp2.size()){
            lines[i].p.push_back(points.size());
            circles[j].p.push_back(points.size());
            points.push_back(tmp2[k]);
        }
    }
    LOOPB(i,0,circles.size())
    LOOPB(j,i+1,circles.size()){
        tmp2=CxC(circles[i],circles[j]);
        LOOPB(k,0,tmp2.size()){
            circles[i].p.push_back(points.size());
            circles[j].p.push_back(points.size());
            points.push_back(tmp2[k]);
        }
    }

    LOOPB(i,0,lines.size())
    LOOPB(j,0,lines[i].p.size())
    LOOPB(k,j+1,lines[i].p.size()){
        ga[lines[i].p[k]][lines[i].p[j]]=ga[lines[i].p[j]][lines[i].p[k]]=LDis(points[lines[i].p[j]],points[lines[i].p[k]]);
    }
    LOOPB(i,0,circles.size())
    LOOPB(j,0,circles[i].p.size())
    LOOPB(k,j+1,circles[i].p.size()){
        if(j!=k){
        d=CDis(circles[i],points[circles[i].p[j]],points[circles[i].p[k]]);
        ga[circles[i].p[k]][circles[i].p[j]]=ga[circles[i].p[j]][circles[i].p[k]]=MIN(ga[circles[i].p[j]][circles[i].p[k]],d);
        }
    }

    LOOPB(k,0,points.size())
    LOOPB(i,0,points.size()){
    if(i==k)continue;
    LOOPB(j,0,points.size()){
        if(i==j||j==k||ga[i][k]==INF||ga[k][j]==INF)continue;
        ga[i][j]=MIN(ga[i][j],ga[i][k]+ga[k][j]);
    }
    }

    d=-INF;
    LOOPB(i,0,points.size())
    LOOPB(j,0,points.size()){
        if(i==j)continue;
        if(ga[i][j]!=INF)d=MAX(d,ga[i][j]);
    }

    printf("%.1lf",d);
    printf("\n");
}
}
