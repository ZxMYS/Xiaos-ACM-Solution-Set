program rqnoj_379;
const
prime=2069;
type
l=^line;
line=record
        f:longint;
        fn:string;
        fnext:longint;
        fnextn:string;
        next:l;
        n:string;
        end;
var
mm:array[0..2069] of l;
mm1,mm2,mm3:l;
buf:array[1..4096] of byte;
i,j,k,k2,a,m,n,p:longint;
ch:char;
st,st2:string;
function hash(st:string):longint;
var
h,i:longint;
begin
h:=0;
        for i:=1 to length(st) do
                h:=ord(st[i])+(h shl 16)+(h shl 6) -h;
hash:=h and $7FFFFFFF;
end;

function select(k:longint;st:string):l;
var
t:l;
begin
t:=mm[k];
//writeln('aaa',st);
        while((t^.n<>st)) do
        begin
                writeln('a',t^.n);
                t:=t^.next;
        end;
exit(t);
end;


procedure insert(k:longint;st:string);
var
i:longint;
newmm:l;
begin
if mm[k]^.f=0 then
with mm[k]^ do begin f:=k;n:=st;fn:=st;fnext:=0;next:=nil;  end
else
begin
new(newmm);
with newmm^ do
begin
next:=mm[k];
n:=st;
f:=k;
fn:=st;
fnext:=0;
end;
mm[k]:=newmm;
end;
end;

begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

readln(n,m,p);
for i:=1 to 2069 do
begin
new(mm[i]);
mm[i]^.n:='';mm[i]^.next:=nil;mm[i]^.f:=0;mm[i]^.fnext:=0;
end;
for i:=1 to n do
begin
        readln(st);
        k:=hash(st) mod prime;
        insert(k,st);
end;
for i:=1 to m do
begin
     read(ch);
     st:='';
     repeat
     st:=st+ch;
     read(ch);
     until ch=' ';
     readln(st2);
     k:=hash(st) mod prime;
     k2:=hash(st2) mod prime;

     mm1:=select(k,st);
     mm2:=select(k2,st2);
     if mm1^.fn<>mm2^.fn then begin
     if mm2^.fn<>mm2^.n then
     mm2:=select(mm2^.f,mm2^.fn);
     new(mm3);
     mm3^:=mm2^;

     if mm1^.fn<>mm1^.n then
     mm1:=select(mm1^.f,mm1^.fn);

     mm2^.f:=mm1^.f;
     mm2^.fn:=mm1^.fn;
     while mm2^.fnext<>0 do begin
     mm2:=select(mm2^.fnext,mm2^.fnextn);
     mm2^.f:=mm1^.f;
     mm2^.fn:=mm1^.fn;
     end;
     end;
     while mm1^.fnext<>0 do
     begin
        mm1:=select(mm1^.fnext,mm1^.fnextn);
     end;
     mm1^.fnext:=mm3^.f;
     mm1^.fnextn:=mm3^.fn;
end;

for i:=1 to p do
begin
     read(ch);
     st:='';
     repeat
     st:=st+ch;
     read(ch);
     until ch=' ';
     readln(st2);
     k:=hash(st) mod prime;
     k2:=hash(st2) mod prime;
     mm1:=select(k,st);
     mm2:=select(k2,st2);
     if mm1^.f<>mm2^.f then writeln('cc cry') else writeln('safe');
end;
end.
