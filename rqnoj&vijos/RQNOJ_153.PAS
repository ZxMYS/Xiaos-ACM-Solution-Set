program rqnoj_153;
var
a,k:longint;
procedure s(m:longint);
var
i:longint;
begin
inc(k);
for i:=1 to m div 2 do
s(i);
end;
begin
read(a);
s(a);
write(k);
end.
