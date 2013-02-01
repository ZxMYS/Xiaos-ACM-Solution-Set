program rqnoj_255;
var
s,s2:array[1..10000] of longint;
m,a,n,i,j,x,y:longint;
procedure qsort(lx,rx:longint);
var
i,j,t,x:longint;
begin
i:=lx;j:=rx;t:=s[(i+j) div 2];
repeat
        while(s[j]>t)and(j>lx) do
        dec(j);
        while(s[i]<t)and(i<rx) do
        inc(i);
        if i<= j then
        begin
        x:=s[i];
        s[i]:=s[j];
        s[j]:=x;
        x:=s2[i];
        s2[i]:=s2[j];
        s2[j]:=x;
        inc(i);dec(j);
        end;
until i>=j;
if j>lx then qsort(lx,j);
if i<rx then qsort(i,rx);
end;
procedure qsort2(lx,rx:longint);
var
i,j,t,x:longint;
begin
i:=lx;j:=rx;t:=s2[(i+j) div 2];
repeat
        while(s2[j]>t)and(j>lx) do
        dec(j);
        while(s2[i]<t)and(i<rx) do
        inc(i);
        if i<= j then
        begin
        x:=s2[i];
        s2[i]:=s2[j];
        s2[j]:=x;
        inc(i);dec(j);
        end;
until i>=j;
if j>lx then qsort2(lx,j);
if i<rx then qsort2(i,rx);
end;
begin
readln(n);
for i:=1 to n do
        begin read(s[i]);
        s2[i]:=i; end;
qsort(1,n);
i:=1;

repeat
while s[i]<>s[i+1] do
inc(i);
a:=i+1;
while s[a]=s[a+1] do
inc(a);
qsort2(i,a);
i:=a+1;
until (i>=n)or(a>=n);

for i:=1to n-1 do
begin
write(s2[i],' ');
inc(x,s[i]);
inc(y,x);
end;
writeln(s2[n]);
write(y/n:trunc(ln(y/n)/ln(10))+3:2);
end.

