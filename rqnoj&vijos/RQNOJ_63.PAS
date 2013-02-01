program rqnoj_63;
var
d:array[1..100000] of string;
e:array[1..100000] of longint;
hash:array[1..1000000] of boolean;
a,b,c:string;
fil:array[1..6,1..2] of string[20];
i,j,len,l1,l2,k,m,n,top,bot:longint;

function check(st:string):boolean;
var j,i,x:longint;
begin
x:=0;
i:=length(st);
if i>115 then exit(false);
for j:=2 to i-1 do
begin
x:=x+(trunc(ord(st[j])*j*j*j*j));
end;
x:=x mod 1000000;
if not(hash[x]) then
begin
hash[x]:=true;
exit(true);
end
else
exit(false);
{j:=top;
for i:=1 to len do
begin
     if st=d[j] then exit(false);
     j:=j mod 100000 + 1;
end;
exit(true);}
end;

begin
assign(input,'f:\in.txt');
reset(input);

fillchar(e,sizeof(e),0);
readln(c);
k:=pos(' ',c);
a:=copy(c,1,k-1);
b:=copy(c,k+1,length(c)-k);
top:=1;
bot:=1;
i:=1;
d[1]:=a;
repeat
readln(c);
if c='' then break;
k:=pos(' ',c);
fil[i,1]:=copy(c,1,k-1);
fil[i,2]:=copy(c,k+1,length(c)-k);
inc(i);
until eof(input);
m:=i-1;
len:=1;
while len>0 do
begin
c:=d[top];
if e[top]<=9 then
begin
for i:=1 to m do
begin
l2:=length(fil[i,1]);
l1:=length(c);
        for j:=1 to l1-l2+1 do
                begin
                if copy(c,j,l2)=fil[i,1] then
                begin
                   delete(c,j,l2);
                   insert(fil[i,2],c,j);
                   if check(c) then
                   begin
                   bot:=bot mod 100000 + 1;
                   d[bot]:=c;
                   e[bot]:=e[top]+1;
                   if c=b then
                        begin
                        write(e[bot]);
                        halt;
                        end;
                   inc(len);
                   end;
                   c:=d[top];
                end;
                end;

end;
end;
e[top]:=0;
top:=top mod 100000 + 1;
dec(len);
end;
write('NO ANSWER!');
end.