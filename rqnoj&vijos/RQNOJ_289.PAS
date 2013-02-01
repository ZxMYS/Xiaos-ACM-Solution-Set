program rqnoj_289;
var
a,b,c:array[1..9,1..9] of boolean;
d:array[1..81] of integer;
i,j,k,e:longint;
procedure gg;
begin
write(0);
halt;
end;
begin
assign(input,'f:\in.txt');
reset(input);

for i:=1 to 81 do
        read(d[i]);

k:=1;
for i:=1 to 9 do
for j:=1 to 9 do
     begin
        if not(a[i,d[k]]) then a[i,d[k]]:=true else gg;
        inc(k);
     end;

k:=1;
for i:=1 to 9 do
for j:=1 to 9 do
        begin
        if not(b[j,d[k]]) then b[j,d[k]]:=true else gg;
        inc(k);
        end;

k:=1;
for i:=1 to 9 do
for j:=1 to 9 do
        begin
        e:= ((i+2) div 3)*3 - (2 - ((j + 2) div 3));
        if not(c[e,d[k]]) then c[e,d[k]]:=true else gg;
        inc(k);
        end;

write(1);
end.
