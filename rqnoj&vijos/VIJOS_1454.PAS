program vijos_1454;
var
x,y,a,z,i,j,k,m,n:longint;
na:array[1..3000] of ansistring;
st:ansistring;
ch:char;
buf:array[1..10000] of byte;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
readln(n);
x:=1;
for i:=1 to n do
begin
st:='';
repeat
read(ch);
if ('a'<=ch)and(ch<='z') then
st:=ch+st
until eoln;
if pos('jszxoier',st)>0 then begin
na[x]:=st;
inc(x);
end;
readln;
end;
dec(x);
y:=0;
k:=1;
for i:=1 to x do
begin
a:=0;
for j:=1 to length(na[i])-2 do
begin
        case na[i][j] of
        'r':begin inc(a,5); if na[i][j+1]='p' then inc(a,20); end;
        'p':inc(a,5);
        'c':if (na[i][j+1]='o') and (na[i][j+2]='w') then begin inc(a,5);na[i]:=na[i]+' '; end;
        end;
end;
inc(j);
        case na[i][j] of
        'r':begin inc(a,5); if na[i][j+1]='p' then inc(a,20); end;
        'p':inc(a,5);
        end;
inc(j);
        case na[i][j] of
        'r':inc(a,5);
        'p':inc(a,5);
        end;
if (a>y)or((a=y) and (length(na[k])>length(na[i]))) then
begin
        y:=a;
        k:=i;
end;
end;
st:='';
for j:=length(na[k]) downto 1 do
if na[k][j]<>' ' then st:=st+na[k][j];
writeln(st);
writeln(y);
end.
