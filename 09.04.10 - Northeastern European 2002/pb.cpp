#include<stdio.h>
#include<math.h>
#define PI 3.14159265359
double a,b,x,y,z;
double phi;
double l;
int swap(double& x,double& y)
{
	double t;
	t=x;
	x=y;
	y=t;
	return 0;
}
int main()
{
	scanf("%lf%lf%lf%lf%lf",&x,&y,&z,&a,&b);
	if (x>y) swap(x,y);
	if (y>z) swap(y,z);
	if (x>y) swap(x,y);
	l=sqrt(x*x+y*y);
	phi=acos(x/l);
	if ((PI<=asin(a/l)+acos(b/l) && phi+acos(b/l)>=0 && PI/2+phi<=asin(a/l)) || (acos(b/l)+asin(a/l)>=2*phi && phi-acos(b/l)<=PI/2 && asin(a/l)+phi>=0))
		printf("YES\n");
	else printf("NO\n");
	return 0;
}
