program rqnoj_334;
type
e=^node;
node=record
        next:e;
        na:string;
        val:longint;
end;
const
prime=218357;
var
x,y,b,z,a,n,m,c,i,j,k:longint;
str,str2:string;
hashset:array[1..100000] of longint;
nameset:array[1..100000] of string;
p:e;
h:array[1..prime] of e;
function hash(st:string):longint;
var
qq,q:longint;
begin
qq:=0;
for q:=1 to length(st) do
        qq:=ord(st[q]) + (qq shl 6) + (qq shl 16) - qq;
exit(qq and $7FFFFFFF);
end;
begin
assign(input,'f:\in.txt');
reset(input);

readln(n,m);
for i:=1 to n do
begin
        readln(str);
        x:=hash(str);
        x:=x mod prime + 1;
        hashset[i]:=x;
        nameset[i]:=str;
        if h[x]=nil then
        begin
                new(h[x]);
                h[x]^.na:=str;
                h[x]^.next:=nil;
                h[x]^.val:=0;
        end
        else
        begin
                p:=h[x];
                while (p^.next<>nil)and(p^.na<>str) do
                begin
                p:=p^.next;
                end;
                if p^.na<>str then begin
                new(p^.next);
                p:=p^.next;
                p^.na:=str;
                p^.next:=nil;
                p^.val:=0;
                end;
        end;
end;

for i:=1 to m do
begin
        readln(str);
        readln(a);
        x:=hash(str);
        x:=x mod prime + 1;
        p:=h[x];
        if h[x]^.next<>nil then
        begin
                while p^.na<>str do
                begin
                p:=p^.next;
                end;
                p^.val:=p^.val+a;
        end
        else
        begin
                p^.val:=p^.val+a;
        end;
end;
b:=-maxlongint;
for i:=1 to n do
begin
        x:=hashset[i];
        str:=nameset[i];
        p:=h[x];
        if p^.next<>nil then
        begin
                while p^.na<>str do
                begin
                p:=p^.next;
                end;
        end;
        if (p^.val>b)or((p^.val=b)and(p^.na<str2)) then
        begin
                b:=p^.val;
                str2:=p^.na;
        end;
end;
writeln(str2);
end.