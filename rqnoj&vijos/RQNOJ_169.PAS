program rqnoj_169;
var
a:array[1..10000] of longint;
c:array[1..10] of longint;
i,j,k,n:longint;
function min(x,y:longint):longint;
begin
if x<y then exit(x) else exit(y);
end;
begin
assign(input,'f:\in.txt');
reset(input);
for i:=1 to 10 do
read(c[i]);
read(n);
a[1]:=c[1];
for i:=2 to 10 do
        for j:=1 to i do
         begin
         c[i]:=min(c[i],c[i-j]+c[j]);
         a[i]:=c[i];
         end;
for i:=11 to n do
begin
a[i]:=a[i-1]+a[1];
for j:=2 to 10 do
begin
a[i]:=min(a[i],a[i-j]+a[j]);
end;
end;
write(a[n]);
end.
