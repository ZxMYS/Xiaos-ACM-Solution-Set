program rqnoj_350;
var
a:array[1..10000] of longint;
b:array[1..10000] of ^longint;
i,j,l,r,p,n,m:longint;
buf:array[1..10000] of byte;
procedure qs(po,lx,rx:longint);
var
l,r,x,m,i:longint;
t:^longint;
c:array[1..10000] of ^longint;
begin
writeln('...',lx,' ',rx);
l:=lx;r:=rx;
m:=(lx+rx) shr 1
x:=b[m]^;
if po>=m then begin
        for i:=l to r do
                if b[i]
end;
end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

read(n,m);
for i:=1 to n do
        read(a[i]);
for i:=1 to m do
        begin
                read(l,r,p);
                for j:=l to r do
                begin
                        b[j]:=@a[j];
                end;
                qs(p,l,r);
                for j:=l to r do
                        write(b[j]^,' ');
                writeln;
                write(b[l+p-1]^);
        end;
end.
