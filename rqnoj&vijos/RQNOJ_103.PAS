program rqnoj_103;
var
f:array[-10000..10000] of longint;
i,j,k,n,v:longint;
c,w:array[1..5000] of longint;
function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;

begin
assign(input,'f:\in.txt');
reset(input);
for i:=-10000 to 10000 do
 f[i]:=-maxlongint;

f[v]:=0;
read(n,v);
for i:=1 to n do
        read(w[i],c[i]);
for i:=1 to n do
        for j:= 0 to v do
               if j>=w[i] then f[j]:=max(f[j],f[j-w[i]]+c[i]);
write(f[v]);
end.