program rqnoj_378;
type
st=record
        s:longint;
        n:string;
        end;
var
f:array[0..150] of longint;
top:array[1..10000] of string;
i,j,k,a,n:longint;
ch:char;
s:array[1..130000] of st;
buf:array[1..4096] of byte;

procedure qsort(lx,rx:longint);
var
l,r:longint;
t:string;
x:st;
begin
l:=lx;r:=rx;t:=s[(l+r) shr 1].n;
repeat
        while(s[l].n<t)and(l<rx) do
                inc(l);
        while(s[r].n>t)and(r>lx) do
                dec(r);
        if l<=r then begin
                x:=s[l];
                s[l]:=s[r];
                s[r]:=x;
                inc(l);
                dec(r);
        end;
until l>=r;
if l<rx then qsort(l,rx);
if r>lx then qsort(lx,r);
end;


begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

fillchar(f,sizeof(f),0);
k:=0;
readln(n);
for i:=1 to n do
begin
        s[i].n:='';
        read(ch);
        repeat
        s[i].n:=s[i].n+ch;
        read(ch);
        until ch=' ';
        readln(s[i].s);
        inc(f[s[i].s]);
end;
qsort(1,n);

for i:=1 to n do
        if s[i].s=150 then begin
        inc(k);
        top[k]:=s[i].n;
        end;

writeln('1~9 10~19 20~29 30~39 40~49 50~59 60~69 70~79 80~89 90~99 100~109 110~119 120~129 130~139 140~149');
for i:=1 to 14 do
begin
k:=0;
        for j:=i*10-10 to i*10-1 do
                inc(k,f[j]);
write(k,' ');
end;
k:=0;
        for j:=140 to 149 do
                inc(k,f[j]);
writeln(k);

for i:=1 to n do
        writeln(s[i].n,' ',s[i].s);

writeln(f[150]);
if f[150]>0 then
        for i:=1 to f[150] do
                writeln(top[i])
else
                writeln('No');
end.
