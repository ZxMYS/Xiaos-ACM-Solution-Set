program rqnoj_68;
const
digit=100000;
type
hugenum=array[0..100] of qword;
var
ga:array[0..9,0..9] of boolean;
f:array[0..9] of longint;
ans,number:hugenum;
ch:char;
i,j,k,a:longint;
buf:array[1..4096] of byte;
operator * (fa1:longint;fa2:hugenum)r:hugenum;
var
i,k:longint;
begin
k:=0;
for i:=1 to 100 do
begin
fa2[i]:=fa2[i]*fa1+k;
k:=fa2[i] div digit;
fa2[i]:=fa2[i] mod digit;
end;
k:=100;
while (fa2[k]=0)and(k>1) do dec(k);
fa2[0]:=k;
exit(fa2);
end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
fillchar(ga,sizeof(ga),0);
fillchar(f,sizeof(f),0);
read(ch);
k:=0;
while ch<>' ' do
begin
inc(k);
val(ch,number[k],a);
read(ch);
end;
number[0]:=k;
read(k);
for a:=1 to k do
begin
        read(i,j);
        ga[i,j]:=true;
end;
for a:=0 to 9 do
        ga[a,a]:=true;

for a:=0 to 9 do
for i:=0 to 9 do
for j:=0 to 9 do
        ga[i,j]:=ga[i,j] or (ga[i,a] and ga[a,j]);
for i:=0 to 9 do
for j:=0 to 9 do
        inc(f[i],ord(ga[i,j]));
fillchar(ans,sizeof(ans),0);
ans[0]:=1;
ans[1]:=1;
for i:=1 to number[0] do
        ans:=f[number[i]]*ans;
write(ans[ans[0]]);
dec(ans[0]);
for i:=ans[0] downto 1 do
begin
        j:=digit div 10;
        while j>1 do
        begin
                if ans[i] div j=0 then write(0) else break;
                j:=j div 10;
        end;
write(ans[i]);
end;
end.