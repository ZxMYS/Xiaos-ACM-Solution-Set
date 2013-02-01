program rqnoj_377;
const
digit=100000000;
ze=ord('0');
type
hugenum=array[0..5000] of qword;
var
a,b,c:hugenum;
i,j,k,n:longint;
ch:char;
begin
readln(n);
for i:=1 to n do
        begin
        read(ch);
        a[(n-i) div 8 + 1]:=a[(n-i) div 8 + 1]*10 + ord(ch) - ze;
        end;
readln;
for i:=1 to n do
        begin
        read(ch);
        b[(n-i) div 8 + 1]:=b[(n-i) div 8 + 1]*10 + ord(ch) - ze;
        end;
n:=(n-1) div 8 + 1;
for i:=1 to n do
for j:=1 to n do
        inc(c[i+j-1],a[i]*b[j]);
n:=(n shl 1) - 1;
for i:=1 to n do
        begin
                inc(c[i+1],c[i] div digit);
                c[i]:=c[i] mod digit;
        end;
inc(n);
while c[n]=0 do dec(n);
write(c[n]);
dec(n);
for i:=1 to n do
 begin
        k:=digit div 10;
        while k>1 do
        begin
                if c[i]<k then write(0);
                k:=k div 10;
        end;
        write(c[i]);
 end;
 end.