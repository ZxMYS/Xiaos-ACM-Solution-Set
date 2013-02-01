program rqnoj_138;
var
ga:array[1..100,1..100] of longint;
i,j,k,a,m,n:longint;
begin
assign(input,'f:\in.txt');
reset(input);

read(n,m);
for i:=1 to n do
        for j:=1 to m do
        begin
                read(a);
                if a=1 then begin
                for k:=1 to m do inc(ga[i,k]);
                for k:=1 to n do inc(ga[k,j]);
                end;
        end;
k:=0;
for i:=1 to n do
for j:=1 to m do
        if ga[i,j]>k then k:=ga[i,j];
writeln(k);
end.