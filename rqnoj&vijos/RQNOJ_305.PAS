program rqnoj_305;
var
a:array[1..2500,1..2] of qword;
ans:qword;
i,j,k,b,c,d,x,y,z,n:longint;
begin
assign(input,'f:\in.txt');
reset(input);

read(n);
for i:=1 to n do
begin
        read(a[i,1]);
        a[i,2]:=0;
        for j:=1 to i-1 do
                if a[j,1]>a[i,1] then inc(a[i,2]);
end;
ans:=0;
for i:=1 to n do
        for j:=1 to i-1 do
                if a[j,1]>a[i,1] then inc(ans,a[j,2]);
write(ans);
end.