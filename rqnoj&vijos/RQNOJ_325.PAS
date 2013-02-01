program rqnoj_325;
var
s,f:array[1..1000] of longint;
d:array[1..500000,1..2] of longint;
i,j,k,a,b,c,m,n:longint;
min:qword;
procedure swap(x,y:longint);
var
t:longint;
begin
t:=x;
x:=y;
y:=t;
end;
procedure qsort(lx,rx:longint);
var
i,j,x:longint;
begin
i:=lx;j:=rx;x:=d[(i+j) shr 1,1];
repeat
        while (d[i,1]<x)and(i<rx) do
                inc(i);
        while (d[j,1]>x)and(j>lx) do
                dec(j);
        if i<=j then
        begin
                swap(d[i,1],d[j,1]);
                swap(d[i,2],d[j,2]);
                swap(d[i,3],d[j,3]);
                inc(i);
                dec(j);
        end;
until i>=j;
if j>lx then qsort(lx,j);
if i<rx then qsort(i,rx);
end;
begin

read(n,m);
for i:=1 to m do
        read(s[i]);
for i:=1 to m do
        read(f[i]);
for i:=1 to n do
begin
        read(d[i,1],d[i,2],k);
end;
read(a);
qsort(1,n);
i:=1;
while a<=d[i,1] do
        inc(i);
n:=i-1;
for i:=1 to n do
       if (s[d[i,2]]>0) then
        begin
             dec(s[d[i,2]]);
        end;

min:=maxlongint shl 1;
for i:=1 to m do
        if (s[i]>0) and (f[i]<min) then
        min:=f[i];

if min=maxlongint shl 1 then
write(0)
else
write(min);



end.