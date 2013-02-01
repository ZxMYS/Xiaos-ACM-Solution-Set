program rqnoj_144;
var
s:array[1..1000] of string;
function bigger(a,b:string):boolean;
var
c,d:string[1];
begin
c:=copy(a,1,1);
d:=copy(b,1,1);
if c>d then exit(true)
else
  if (length(a)>1)and(length(b)>1) then
  exit(bigger(copy(a,2,length(a)-1),copy(b,2,length(b)-1)))
  else
  if (length(a)=1)and(length(b)<>1) then
  exit(false)
  else
  exit(false);
end;
procedure qsort(lx,rx:longint);
var
i,j:longint;
x,t:string;
begin
i:=lx;j:=rx;t:=s[((i+j) div 2)];
repeat
        while(bigger(t,s[j])) do
                j:=j-1;
        while(bigger(s[i],t)) do
                i:=i+1;
        if i<=j then
        begin
                x:=s[i];
                s[i]:=s[j];
                s[j]:=x;
                inc(i);inc(j);
        end
until i>=j;
if j>lx then qsort(lx,j);
if i<rx then qsort(i,rx);
end;
begin
s[1]:='aaaac';s[2]:='aaaaa';s[3]:='aa';s[4]:='a';s[5]:='bbbbb';
//qsort(1,2);
write(bigger(s[1],s[2]);
end.

