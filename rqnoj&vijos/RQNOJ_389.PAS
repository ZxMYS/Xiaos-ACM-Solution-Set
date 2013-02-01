program rqnoj_389;
const
big=1 shl 30;
var
i,j,k,a,b,c,m,n:longint;
buf:array[1..4096] of byte;
f:array[1..250,1..250] of boolean;
ga:array[1..250,0..250,0..1] of longint;
function dfs(now,tar,nc:longint):longint;
var
i,j,k:longint;
begin
        //writeln(now,' ',tar);
        if nc>a then exit(big);
        if now=tar then exit(nc);
        k:=big;
        for i:=1 to ga[now,0,0] do
                if (not(f[now,ga[now,i,0]])) then
                begin
                        f[now,ga[now,i,0]]:=true;
                        f[ga[now,i,0],now]:=true;
                        k:=dfs(ga[now,i,0],tar,nc+ga[now,i,1]);
                        if k<a then a:=k;
                        f[now,ga[now,i,0]]:=false;
                        f[ga[now,i,0],now]:=false;
                end;
        exit(k);
end;

begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
read(n,m);
for i:=1 to m do
begin
read(a,b,c);
inc(ga[a,0,0]);
ga[a,ga[a,0,0],0]:=b;
ga[a,ga[a,0,0],1]:=c;
inc(ga[b,0,0]);
ga[b,ga[b,0,0],0]:=a;
ga[b,ga[b,0,0],1]:=c;
end;
for i:=1 to n do
        f[i,i]:=true;
a:=big;
for i:=1 to n do
begin
        fillchar(f,sizeof(f),0);
        for j:=1 to ga[i,0,0] do
        begin
        f[i,ga[i,j,0]]:=true;
        f[ga[i,j,0],i]:=true;
        b:=dfs(ga[i,j,0],i,ga[i,j,1]);
        if b<a then a:=b;
        f[i,ga[i,j,0]]:=false;
        f[ga[i,j,0],i]:=false;
        end;
end;
if a<>big then
        writeln(a) else writeln('He will never come back.');
end.