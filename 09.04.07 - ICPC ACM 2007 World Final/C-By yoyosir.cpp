#include<stdio.h>
#include<math.h>
double cl,cr,dl,dr,a,b,c,d,k,theta;
int n,i,alph,x1,x2,yy1,y2,t;
int main()
{
	scanf("%d%d",&n,&alph);
	t=0;
	while (n>0)
	{
		x1=yy1=0;
		cl=dl=0;
		cr=dr=180;
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&x2,&y2);
			if (x2==x1)
			{
				if (y2>yy1)
				{
					a=0;
					b=180;
					d=0;
					c=180;
				}
				else
				{
					a=180;
					b=0;
					c=0;
					d=180;
				}
			}
			else 
			{
				k=(y2-yy1)*1.0/(x2-x1);
				theta=atan(k)*180/3.14159265358979324;
				if (x2>x1)
				{
					a=0;
					b=90+theta;
					c=0;
					d=90-theta;
				}
				else
				{
					a=90+theta;
					b=180;
					c=90-theta;
					d=180;
				}
			}
			if (b<cr)
				cr=b;
			if (a>cl)
				cl=a;
			if (c>dl)
				dl=c;
			if (d<dr)
				dr=d;
			x1=x2;
			yy1=y2;
		}
		t++;
		if (alph==0) printf("Case %d: Acceptable as proposed\n",t);
		else if (cl>cr && dl>dr)	printf("Case %d: Unacceptable\n",t);
		else if (cl<=cr && dl>dr) printf("Case %d: Acceptable after clockwise rotation of %0.2lf degrees\n",t,cl);
		else if (cl>cr && dl<=dr) printf("Case %d: Acceptable after counterclockwise rotation of %0.2lf degrees\n",t,dl);
		else if (cl==0 && dl==0) printf("Case %d: Acceptable as proposed\n",t);
		else if (cl<=dl) printf("Case %d: Acceptable after clockwise rotation of %0.2lf degrees\n",t,cl);
		else printf("Case %d: Acceptable after counterclockwise rotation of %0.2lf degrees\n",t,dl);
		printf("\n");
		scanf("%d%d",&n,&alph);
	}
	return 0;
}
