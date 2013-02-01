program fjdshjfdfkasffasdl;
var
i,n,s:longint;
a:array[1..200000]of longint;
procedure qsort(l,r:longint);
var
i,j:longint;
t,x:qword;
begin
i:=l;j:=r;x:=a[(l+r) div 2];
repeat
while (a[i]<x) do i:=i+1;
while (x<a[j]) do j:=j-1;
if i<=j then
begin
t:=a[i];
a[i]:=a[j];
a[j]:=t;
i:=i+1;j:=j-1;
end;
until i>=j;
if l<j then qsort(l,j);
if r>i then qsort(i,r);
end;
begin
read(n);
for i:=1 to n do
read(a[i]);
qsort(1,n);
s:=1;
write(a[1],' ');
for i:=2 to n do if a[i]=a[i-1] then s:=s+1 else begin writeln(s);s:=1;write(a[i],' ');end;
writeln(s);
end.