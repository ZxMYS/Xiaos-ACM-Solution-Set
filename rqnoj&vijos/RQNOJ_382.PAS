program rqnoj_382;
var
i,j,m:longint;
a,b:ansistring;
r,p:array[1..100000]of longint;
buf:array[1..4096] of byte;
begin
settextbuf(input,buf);
readln(b);
readln(a);
m:=0;
P[1]:=0;
j:=0;
for i:=2 to length(b) do
begin
   while (j>0) and (B[j+1]<>B[i]) do j:=P[j];
   if B[j+1]=B[i] then j:=j+1;
   P[i]:=j;
end;
j:=0;
for i:=1 to length(a) do
begin
   while (j>0) and (B[j+1]<>A[i]) do j:=P[j];
   if B[j+1]=A[i] then j:=j+1;
   if j=length(b) then
   begin
        inc(m);
        r[m]:=i-length(b)+1;
      j:=P[j];
   end;
end;
writeln(m);
for i:=1 to m do
        writeln(r[i]);
end.
