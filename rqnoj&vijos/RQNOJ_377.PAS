program rqnoj_377;
const
d=10000;
type
hugenum=array[0..10000] of longint;
var
a,b:hugenum;
i,j,k,n,e:longint;
st,s:ansistring;
buf:array[1..4096] of byte;

operator * (fa1,fa2:hugenum)r:hugenum;
var
i,j,x,y,z,k:longint;
begin
fillchar(r,sizeof(r),0);
for i:=1 to fa1[0] do
        for j:=1 to fa2[0] do
                begin
                        x:=fa1[i]*fa2[j];
                        y:=x div d;
                        z:=x mod d;
                        k:=i+j-1;
                        inc(r[k],z);
                        inc(r[k+1],(r[k] div d) + y);
                        r[k]:=r[k] mod d;
                end;
x:=fa1[0]+fa2[0];
if r[x]=0 then r[0]:=x-1 else r[0]:=x;
end;

begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
readln(n);
readln(s);
a[0]:=0;
k:=n mod 4;
e:=n div 4;
if k<>0 then begin
st:=copy(s,1,k);
val(st,a[e + 1],j);
s:=copy(s,k+1,length(s)-k);
a[0]:=1;
end;
for i:=1 to e do
begin
        st:=copy(s,1,4);
        val(st,a[e + 1 - i],j);
        s:=copy(s,5,length(s)-4);
end;
inc(a[0],e);
readln(s);
b[0]:=0;
k:=n mod 4;
e:=n div 4;
if k<>0 then begin
st:=copy(s,1,k);
val(st,b[e + 1],j);
s:=copy(s,k+1,length(s)-k);
b[0]:=1;
end;
for i:=1 to e do
begin
        st:=copy(s,1,4);
        val(st,b[e + 1 - i],j);
        s:=copy(s,5,length(s)-4);
end;

inc(b[0],e);
a:=a*b;

write(a[a[0]]);
dec(a[0]);
for i:=a[0] downto 1 do
begin
n:=d div 10;
for j:=trunc(ln(n) / ln(10))+1 downto 1 do
begin
        write(a[i] div n);
        a[i]:=a[i] mod n;
        n:=n div 10;
end;
end;
writeln;
end.