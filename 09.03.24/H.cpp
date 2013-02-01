
#include<iostream>
#include<fstream>
using namespace std;
template <class Type>
class MinHeap
{
public:
MinHeap(Type a[], int n);
MinHeap(int ms);
~MinHeap();
bool Insert(const Type &x); //插入一个元素,如果空返回false，否则返回true
bool RemoveMin(Type &x); //删除最小的元素，如果空返回false，否则返回true
void MakeEmpty(); //使堆为空
bool IsEmpty();
bool IsFull();
int Size();
protected:
void FilterDown(const int start, const int endOfHeap); //自顶向下构造堆
void FilterUp(const int start); //自底向上构造堆
private:
Type *heap;
int maxSize;
const int defaultSize;
int currentSize;
};

template <class Type>
MinHeap<Type>::MinHeap(int ms):defaultSize(100000)
{
maxSize=ms>defaultSize ? ms : defaultSize;
heap=new Type[maxSize];
currentSize=0;
}

template <class Type>
MinHeap<Type>::MinHeap(Type a[], int n):defaultSize(100000)
{
maxSize=n>defaultSize ? n : defaultSize;
heap=new Type[maxSize];
currentSize=n;
for (int i=0; i<n; i++) heap[i]=a[i];
int curPos=(currentSize-2)/2;
while (curPos>=0)
{
   FilterDown(curPos, currentSize-1);
   curPos--;
}
}

template <class Type>
MinHeap<Type>::~MinHeap()
{
delete []heap;
}

template <class Type>
void MinHeap<Type>::FilterDown(const int start, const int endOfHeap)
{
int i=start, j=i*2+1;
Type temp=heap[i];
while (j<=endOfHeap)
{
   if (j<endOfHeap&&heap[j]>heap[j+1]) j++;
   if (temp<heap[j]) break;
   else
   {
    heap[i]=heap[j];
    i=j;
    j=2*i+1;
   }
}
heap[i]=temp;
}

template <class Type>
void MinHeap<Type>::FilterUp(const int start)
{
int i=start, j=(i-1)/2;
Type temp=heap[i];
while (i>0)
{
   if (temp>=heap[j]) break;
   else
   {
    heap[i]=heap[j];
    i=j;
    j=(i-1)/2;
   }
}
heap[i]=temp;
}

template <class Type>
bool MinHeap<Type>::RemoveMin(Type &x)
{
if (IsEmpty())
{
   cerr<<"Heap empty!"<<endl;
   return false;
}
x=heap[0];
heap[0]=heap[currentSize-1];
currentSize--;
FilterDown(0, currentSize-1);
return true;
}

template <class Type>
bool MinHeap<Type>::Insert(const Type &x)
{
if (IsFull())
{
   cerr<<"Heap Full!"<<endl;
        return false;
}
heap[currentSize]=x;
FilterUp(currentSize);
currentSize++;
return true;
}

template <class Type>
bool MinHeap<Type>::IsEmpty()
{
return currentSize==0;
}

template <class Type>
bool MinHeap<Type>::IsFull()
{
return currentSize==maxSize;
}

template <class Type>
void MinHeap<Type>::MakeEmpty()
{
currentSize=0;
}

template <class Type>
int MinHeap<Type>::Size()
{
return currentSize;
}


int *p;

//最小堆结点
class HeapNode
{
friend class VC;
public:
operator int()const{return cn;}
private:
   int i,cn,*x,*c;
};

class VC
{
friend int MinCover(int **,int [],int);
private:
void BBVC();
bool cover(HeapNode E);
void AddLiveNode(MinHeap<HeapNode>&H,HeapNode E,int cn,int i,bool ch);
int **a,n,*w,*bestx,bestn;
};

void VC::BBVC()
{
MinHeap<HeapNode>H(100000);
HeapNode E;
E.x=new int[n+1];
E.c=new int[n+1];
for(int j=1;j<=n;j++)
{
   E.x[j]=E.c[j]=0;
}

int i=1,cn=0;
while(true)
{
   if(i>n)
   {
    if(cover(E))
    {
     for(int j=1;j<=n;j++)
      bestx[j]=E.x[j];
     bestn=cn;
     break;
    }
   }
   else
   {
    if(!cover(E))
     AddLiveNode(H,E,cn,i,true);
    AddLiveNode(H,E,cn,i,false);
   }

   if(H.IsEmpty())break;
   H.RemoveMin(E);
   cn=E.cn;
   i=E.i+1;
}
}

//cover

bool VC::cover(HeapNode E)
{
for(int j=1;j<=n;j++)
{
   if(E.x[j]==0&&E.c[j]==0)
    return false;
}
return true;
}

void VC::AddLiveNode(MinHeap<HeapNode> &H,HeapNode E,int cn,int i,bool ch)
{
HeapNode N;
N.x=new int[n+1];
N.c=new int[n+1];
for(int j=1;j<=n;j++)
{
   N.x[j]=E.x[j];
   N.c[j]=E.c[j];
}
N.x[i]=ch?1:0;
if(ch)
{
   N.cn=cn+w[i];
   for(int j=1;j<=n;j++)
    if(a[i][j]>0)
     N.c[j]++;
}
else
{
   N.cn=cn;
}
N.i=i;
H.Insert(N);
}

int MinCover(int **a,int v[],int n)
{
VC Y;
Y.w=new int[n+1];
for(int j=1;j<=n;j++)
{
   Y.w[j]=v[j];
}
Y.a=a;
Y.n=n;
Y.bestx=v;
Y.BBVC();
return Y.bestn;
}

int main()
{
int u,v,tt;
int n,c;
ifstream infile("in.txt");
ofstream outfile("out");
infile>>tt;
while(tt--){
infile>>n>>c;
int **a;
a=new int *[n+1];
for(int k=0;k<=n;k++)
   a[k]=new int[n+1];
for(int i=0;i<=n;i++)
   for(int j=0;j<=n;j++)
    a[i][i]=0;
p=new int[n+1];
for(int i=1;i<=n;i++)
   infile>>p[i];
for(int i=1;i<=c;i++)
{
   infile>>u>>v;
   a[u][v]=1;
   a[v][u]=1;
}
cout<<MinCover(a,p,n)<<endl;
//for(i=1;i<=n;i++)
//   cout<<p[i]<<" ";
//cout<<endl;
}
return 0;
}
