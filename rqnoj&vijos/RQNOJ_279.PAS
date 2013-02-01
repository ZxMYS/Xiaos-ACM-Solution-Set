program rqnoj_279;
var
f:array[0..100] of longint;
v,w:array[1..20] of longint;
n,i,j:longint;
function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;
begin
assign(input,'f:\in.txt');
reset(input);

read(n);
fillchar(f,sizeof(f),0);
for i:=1 to n do
        read(v[i]);
for i:=1 to n do
        read(w[i]);
for i:=1 to n do
for j:=99 downto v[i]+1 do
        f[j]:=max(f[j],f[j-v[i]]+w[i]);
write(f[99]);
end.
