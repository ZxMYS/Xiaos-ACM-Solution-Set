program rqnoj_343;
type
fr=record
        first,last,next,length:longint;
        end;
var
ga:array[1..1000] of fr;
f:array[1..1000] of boolean;
a,b,c,n,m,i,j,k,x,y,z:longint;
begin
assign(input,'f:\in.txt');
reset(input);

read(n,m);
for x:=1 to n do
        begin
        f[x]:=true;
        ga[x].first:=x;
        ga[x].next:=0;
        ga[x].last:=x;
        ga[x].length:=1;
        end;
for x:=1 to m do
begin
        read(a,b);
        if ga[a].first<>ga[b].first then begin
        inc(ga[ga[a].first].length,ga[ga[b].first].length);
        ga[ga[a].last].next:=ga[b].first;
        c:=ga[a].first;
        while c<>ga[b].first do
                begin
                ga[c].last:=ga[b].last;
                c:=ga[c].next;
                end;
        c:=ga[b].first;
        while c<>0 do
                begin
                f[c]:=false;
                ga[c].first:=ga[a].first;
                c:=ga[c].next;
                end;

        f[a]:=true;
        end;
end;
a:=1;
for i:=1 to n do
        if f[i] and (ga[i].length>a) then a:=ga[i].length;
writeln(a);
end.