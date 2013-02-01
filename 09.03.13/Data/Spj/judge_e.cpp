#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>
using namespace std;

double eps=1e-2;
char* pattern[]={"%lf"};
char a[100];
char b[100];

bool check(FILE *out,FILE *ans)
{
	while (true)
	{
		for (int i=0;i<sizeof(pattern)/sizeof(char*);i++)
		{
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			int x=fscanf(out,pattern[i],a);
			int y=fscanf(ans,pattern[i],b);
			if (x!=y) return false;
			if (x==EOF) return true;
			if (!strcmp(pattern[i],"%lf"))
			{
				if (fabs(*(double*)a-*(double*)b)>eps) return false;
			}
			else if (!strcmp(pattern[i],"%d"))
			{
				int A,B;
				sscanf(a,"%d",&A);
				sscanf(b,"%d",&B);
				if (A!=B) return false;
			}
			else
			{
				if (strcmp(a,b)) return false;
			}
		}
	}
}

int main(int argc,char* argv[])
{
	FILE* out=fopen(argv[2],"r");
	FILE* ans=fopen(argv[3],"r");
	FILE* result=fopen(argv[4],"w");
	bool correct=check(out,ans);
	fprintf(result,"<?xml version=\"1.0\"?>");
	if (correct)
		fprintf(result,"<result   outcome=\"%s\"   security=\"%s\">   string2  </result>","accepted",argv[4]);
	else
		fprintf(result,"<result   outcome=\"%s\"   security=\"%s\">   string2  </result>","rejected",argv[4]);
	fclose(out);
	fclose(ans);
	fclose(result);
	return 0;
}

