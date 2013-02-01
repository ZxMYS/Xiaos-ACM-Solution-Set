program vijos_1480;
var
ns:array[1..275] of longint;
i,j,k,a,m,n:longint;
st:ansistring;
b,c:array[0..400] of longint;
e:array[0..65535] of boolean;
sqr:array[1..200,1..400,1..400] of char;
function min(x,y:LONGINT):longint;
begin
if x>y then exit(y) else exit(x);
end;
function find(num,now,nc:longint):longint;
var i:longint;
begin
find:=65535;
if nc>=a then exit(65535);
if e[now] then exit(65535);
e[now]:=true;
inc(b[0]);
for i:=n downto 1 do
begin
        if now+ns[i]<num then begin
        b[b[0]]:=ns[i];
        find:=min(find,find(num,now+ns[i],nc+1));
        end;
        if now+ns[i]=num then
        if a>nc+1 then begin
             c:=b;
             c[c[0]]:=ns[i];
             a:=nc+1;
        end;
end;
dec(b[0]);
exit(a);
end;

begin
{assign(input,'f:\in.txt');
reset(input);  }
a:=200;
b[0]:=0;
{readln(st); }
readln(n);
for i:=1 to 275 do
begin
        ns[i]:=i*i;
        if ns[i]>={length(st)}n then break;
end;
n:=i;
a:=find({length(st)}n,0,0);

for i:=1 to c[0] do
        write(c[i],' ');

a:=0;
{for k:=1 to c[0] do
        for i:=1 to trunc(sqrt(c[k])) do
                for j:=1 to trunc(sqrt(c[k])) do
                begin
                inc(a);
                sqr[k,i,j]:=st[a];
                end;

for k:=1 to c[0] do
        for i:=1 to trunc(sqrt(c[k])) do
                for j:=1 to trunc(sqrt(c[k])) do
                        write(sqr[k,j,i]);
               }
end.
