program eeeeeee;
var
n,m,i:longint;
a1,a2,b1,b2:real;
a,b:array [1..18511] of longint;
begin
readln(n,m);
a1:=0;
b1:=0;
for i:= 1 to n do
 begin
 read(a[i]);
 a1:=a1+(a[i]/n);
 end;
for i:= 1 to m do
 begin
 read(b[i]);
 b1:=b1+(b[i]/m);
 end;
for i:= 1 to n do a2:=a2+sqr(a[i]-a1)/n;
for i:= 1 to m do b2:=b2+sqr(b[i]-b1)/m;
if (n>m) and (a1>b1) and (a2<b2) then write('can')
else write('can''t');
end.
