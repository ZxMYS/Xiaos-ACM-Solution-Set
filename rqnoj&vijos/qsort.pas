program qsort;
const
n=10;
var
s:array[1..n] of integer;
x:integer;
procedure qsort(lx,rx:integer);
var
i,j,t,z:integer;
begin
i:=lx;j:=rx;t:=s[i];
repeat
    while (s[j]>t) do
        j:=j-1;
    while (s[i]<t) do
        i:=i+1;

    if i<=j then
        begin
            z:=s[i];
            s[i]:=s[j];
            s[j]:=z;
            i:=i+1;
            j:=j-1;
        end;
until i>=j;
if lx<j then qsort(lx,j);
if i<rx then qsort(i,rx);
end;
begin
for x:=1 to n do
        read(s[x]);
qsort(1,n);
for x:= 1 to n do
        write(s[x],' ');
end.
