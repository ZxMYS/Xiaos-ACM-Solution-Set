program rqnoj_399;
var
n,a,b,x,y:longint;
s:array[1..10010] of longint;
f1:text;
procedure qsort(lx,rx:longint);
var
i,j,t,z:longint;
begin
i:=lx;j:=rx;t:=s[(i+j) div 2];
repeat
        while s[j]<t do
                dec(j);
        while s[i]>t do
                inc(i);
        if i<= j then
                begin
                        z:=s[i];
                        s[i]:=s[j];
                        s[j]:=z;
                        inc(i);
                        dec(j);
                end;
until i>=j;
if lx<j then qsort(lx,j);
if rx>i then qsort(i,rx);
end;

procedure insert(m:longint);
var
j,k,i:longint;
begin
j:=1;
while (m<s[j]) and (j<=n) do
        inc(j);
k:=m;
for i:= n downto j do
                s[i+1]:=s[i];
s[j]:=k;
end;

{procedure wa;
var
a1:longint;
begin
writeln('n',n,' a',a,' b',b);
for a1:=1 to n+2 do
write(s[a1]);
writeln;
end;}

begin
assign(f1,'f:\in.txt');
reset(f1);
a:=0;
read(f1,n);
for x:= 1 to n do
read(f1,s[x]);
qsort(1,n);
//wa;
y:=n-1;
for x:= 1 to y do
begin
b:=s[n]+s[n-1];
a:=a+b;
n:=n-2;
insert(b);
//wa;
inc(n);
//wa;
end;
write(a);
end.