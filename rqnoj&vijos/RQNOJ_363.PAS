program rqnoj_363;
var
cho:array[0..1001] of longint;
s,m,a,i,j,b,n,o,p,q,r:longint;
buf:array[1..10000] of byte;

procedure f(h:longint);
var
i:longint;
begin
i:=h;
while (cho[i]=0) and (i>=p) do
        dec(i);
if cho[i]>0 then begin inc(o);dec(cho[i]); end;
end;

procedure l(h:longint);
var
i,j:longint;
begin
j:=h;
if h>q then j:=q;
i:=p;
while (cho[i]=0) and (i<=j) do
        inc(i);
if (cho[i]>0)and(i<=j) then begin inc(o);dec(cho[i]); end;
if cho[i]=0 then p:=i;
end;

begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

fillchar(cho,sizeof(cho),0);
o:=0;
read(s);
p:=maxlongint;
q:=-maxlongint;
for i:=1 to s do
begin
        read(a);
        if a>q then q:=a;
        if a<p then p:=a;
        inc(cho[a]);
end;
read(n);
for i:=1 to n do
begin
        read(a,b);
        if b=1 then f(a) else l(a);
end;
read(n);
if o>=n then writeln(o) else writeln('Alice is the most beautiful girl.');
end.