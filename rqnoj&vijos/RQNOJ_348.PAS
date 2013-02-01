program rqnoj_348;
type
ti=^node;
node=record
        l,r:^ti;
        op:boolean;
        str:char;
        num:integer;
        end;
oper=record
        level:integer;
        ch:char;
        end;
var
p,p1,p2,root:ti;
ch:char;
levels:array['*'..'^'] of longint;
ops:array[1..10000] of oper;
ns:array[1..20000] of integer;
b,c,i,j,k,k2,a,s,t,x,y,z:longint;
buf:array[1..10000] of byte;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

levels['+']:=1;levels['-']:=1;levels['*']:=2;levels['/']:=2;levels['^']:=3;
k:=0;
k2:=0;
{root:=build;}
read(ch);
new(p);
repeat
val(ch,b,c);
if c=0 then begin inc(k); ns[k]:=b; end else
begin
if ch='(' then begin inc(k2);ops[k2].ch:=ch;ops[k2].level:=100; end else
if ch<>')' then begin
     if levels[ch]>ops[k2].level then
        inc(k2);
        ops[k2].ch:=ch;
        ops[k2].level:=levels[ch];
        end
     else
        //out..............
        new(p2);
        p2^.op:=false;
        p2^.l:=nil;
        p2^.r:=nil;
        p2^.num:=ns[k];
        p^.l:=p2;
        dec(k);
        new(p2);
        p2^.op:=false;
        p2^.l:=nil;
        p2^.r:=nil;
        p2^.num:=ns[k];
        p^.r:=p2;
        dec(k);
        p^.op:=true;
        p^.str:=ch;
        new(p3);
        p3^.l:=p;
        p:=p3;
        //result in
        ops[k2].ch:=ch;
        ops[k2].level:=levels[ch];
end
else
begin
        //( out...
        repeat
        dec(k2);
        dec(k,2);
        //result in...
        inc(k);
        until ops[k2].ch='(';
        dec(k2);
end;
until eof(input);
end.