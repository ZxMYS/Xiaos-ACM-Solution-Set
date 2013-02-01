program rqnoj_72;
var
f:array[0..5000] of longint;
a:array[1..100] of longint;
i,j,k,n,m:longint;
buf:array[1..4069] of byte;
function max(a,b:longint):longint;
begin
if a>b then exit(a) else exit(b);
end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

read(n);
k:=0;
for i:=1 to n do
        begin
        read(a[i]);
        inc(k,a[i]);
        end;
m:=k shr 1;
for i:=1 to n do
for j:=m downto a[i] do
        f[j]:=max(f[j],f[j-a[i]]+a[i]);

writeln(k - (f[m] shl 1));
end.