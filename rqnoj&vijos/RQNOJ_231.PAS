program rqnoj_231;
label 0;
const
max=1000000;
var
k,x,n:longint;
i,j,h,a1,a2,a3:integer;
a:array[1..max] of integer;
begin
read(n,k);
for i := 1 to n do
read(a[i]);

for h:= 1 to n do
begin
for i:= 1 to n-h do
begin
a1:=0;
a2:=0;
a3:=0;
  for j := 1 to i do
  begin
    if a[j]=1 then inc(a1);
    if a[j]=2 then inc(a2);
    if a[j]=3 then inc(a3);
  end;
if (a1>=k) and (a2>=k) and (a3>=k) then
begin
write(h,' ',i);
goto 0;
end;
end;
end;
0:
end.
