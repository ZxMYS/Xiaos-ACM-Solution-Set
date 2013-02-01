program rqnoj_226;
var
ch:char;
f:array[0..200] of boolean;
n:array[-1..200] of longint;
i,j,k,a,s,t,m,b,c,x,y:longint;
buf:array[1..4096] of byte;
begin
assign(input,'f:\in.txt');
reset(input);

settextbuf(input,buf);
readln(m);
for i:=0 to m do
        f[i]:=true;
for i:=1 to m do
        begin
                n[i]:=i+1;
                f[i]:=false;
                read(ch);
                if ch='j' then
                begin
                read(ch);
                if (ch='m')and not(eoln) then
                begin
                read(ch);
                if (ch='p')and not(eoln) then
                begin
                read(ch);
                if (ch=' ')and not(eoln) then
                read(n[i]);
                end;
                end;
                end;
                readln;
        end;
if n[m]=m+1 then n[m]:=-1 else begin write(0);halt; end;
a:=0;
i:=1;
while (i<>-1) and not(f[i]) do
begin
f[i]:=true;
inc(a);
i:=n[i];
end;
if i=-1 then write(a) else write(0);
end.