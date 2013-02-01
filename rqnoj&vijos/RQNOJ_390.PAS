program rqnoj_390;
var
i,j,q,k,a,n,v:longint;
f:array[0..100,0..201] of longint;
vs:array[1..100] of longint;
buf:array[1..4096] of byte;
function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
read(n,v,k);
for i:=1 to n-1 do
        read(vs[i]);
for i:=1 to n do
        for j:=0 to 201 do
                f[i,j]:=-maxlongint;
f[n-1,v]:=v;
if abs(v-vs[n-1])>k then begin writeln('YI DING YAO JIAN CHI JI HUA SHENG YU');halt;end;
for i:=n-2 downto 1 do
        for j:=201 downto 1 do
                for q:=j+1 downto j-1 do
                if abs(q-vs[i])<=k then
                f[i,q]:=max(f[i+1,j]+q,f[i,q]);
for i:=201 downto 0 do
        if f[1,i]>0 then break;
if i>0 then writeln(f[1,i] / (n-1):0:2) else writeln('YI DING YAO JIAN CHI JI HUA SHENG YU');
end.