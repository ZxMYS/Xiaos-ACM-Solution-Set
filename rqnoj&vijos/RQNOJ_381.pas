program rqnoj_381;
var
w,m1,v:array[1..10000] of longint;
b,f:array[1..100] of longint;
i,j,k,n,m,ti,a,temp:longint;
buf:array[1..4096] of byte;
function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
fillchar(f,sizeof(f),0);
read(n,m,ti,a);
if ti>=a-1 then ti:=a-1;
a:=0;
for i:=1 to n do
        for j:=1 to m do
        begin
                inc(a);
                read(v[a]);
                w[a]:=((i+j) shl 1);
        end;
a:=0;
for i:=1 to n do
        for j:=1 to m do
        begin

                inc(a);
                read(m1[a]);
        end;
for i:=1 to a do
        for j:=ti downto w[i] do
        begin
                for k:=w[i] to 100 do b[i]:=0;
                temp:=f[j-w[i]]+v[i];
                if (temp>f[j]) and (b[j]<m1[i]) then
                begin
                f[j]:=temp;
                b[j]:=b[j-v[i]]+1;
                end;
        end;

writeln(f[ti]);
end.