#include<cstdio>
#include<cmath>
const double pi=acos(-1.0);
struct point
{
	double x,y;
}A1,B1,C1,A2,B2,C2;
bool ans;
void print()
{
	if (!ans)printf("YES\n");
	else
	{
		printf("NO\n");
		printf("%.10lf %.10lf\n",A2.x,A2.y);
		printf("%.10lf %.10lf\n",B2.x,B2.y);
		printf("%.10lf %.10lf\n",C2.x,C2.y);
	}
}
inline double sqr(double X)
{
	return X*X;
}
inline double dotdet(double X1,double Y1,double X2,double Y2)
{
	return X1*X2+Y1*Y2;
}
inline double dis(double X1,double Y1,double X2,double Y2)
{
	return sqrt(sqr(X1-X2)+sqr(Y1-Y2));
}
void solve()
{
	ans=false;
	double AB,BC,AC,cosalpha,sinalpha,delta,a,b,c,x1,x2,AC_,tmp;
	AB=dis(A1.x,A1.y,B1.x,B1.y);
	AC=dis(A1.x,A1.y,C1.x,C1.y);
	BC=dis(B1.x,B1.y,C1.x,C1.y);
	tmp=dotdet(B1.x-A1.x,B1.y-A1.y,C1.x-A1.x,C1.y-A1.y);
	cosalpha=tmp;
	cosalpha/=AB;
	cosalpha/=AC;
	sinalpha=sqrt(1-sqr(cosalpha));

	b=-2*tmp/AC;
	c=sqr(AB)-sqr(BC);
	delta=sqr(b)-4*c;
	if (delta>0)
	{
		x1=(-b+sqrt(delta))/2;
		x2=(-b-sqrt(delta))/2;
		if (x1>0&&x2>0)
		{
			if (fabs(x1-AC)<1e-6)AC_=x2;
			else AC_=x1;
			A2.x=0;A2.y=0;
			B2.x=AB;B2.y=0;
			C2.x=cosalpha*AC_;C2.y=sinalpha*AC_;
			ans=true;
		}
	}
}
void init()
{
	scanf("%lf%lf%lf%lf%lf%lf",&A1.x,&A1.y,&B1.x,&B1.y,&C1.x,&C1.y);
}
int main()
{
	init();
	solve();
	print();
	return 0;
}
