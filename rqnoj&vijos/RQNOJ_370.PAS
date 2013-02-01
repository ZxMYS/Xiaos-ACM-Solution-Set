program rqnoj_370;
var
n,m,i,j,k,a,b,c,tot:longint;
ga:array[1..100,1..100] of longint;
dis:array[1..100] of longint;
f:array[1..100] of boolean;
buf:array[1..10000] of byte;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

read(n,k);
for i:=1 to n do
begin
        f[i]:=false;
        for j:=1 to n do
                ga[i,j]:=maxint;
end;
tot:=0;
for i:=1 to k do
begin
        read(a,b,c);
        ga[a,b]:=c;
        ga[b,a]:=c;
        inc(tot,c);
end;
for i:=2 to n do
begin
        dis[i]:=ga[1,i];
end;
f[1]:=true;
for j:=1 to n-1 do
begin
a:=maxlongint;
        for i:=2 to n do
                if not(f[i])and(dis[i]<a) then begin
                a:=dis[i];
                c:=i;
                end;
dec(tot,a);
f[c]:=true;
        for i:=2 to n do
                if ga[c,i]<dis[i] then dis[i]:=ga[c,i];
end;
writeln(tot);
end.