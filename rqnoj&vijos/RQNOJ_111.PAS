program rqnoj_111;
type
hugenum=array[0..5000] of byte;
sc=record
        s:hugenum;
        n:string;
end;
var
buf:array[1..4096] of byte;
ss:array[1..5000] of sc;
i,j,k,a,b,c,n:longint;
ch:char;

function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;

operator > (fa1,fa2:hugenum)r:boolean;
var
k,i:longint;
begin

k:=max(fa1[0],fa2[0]);
for i:=1 to k do
        if fa1[i]>fa2[i] then exit(true) else if fa1[i]<fa2[i] then exit(false);
exit(false);
end;

operator = (fa1,fa2:hugenum)r:boolean;
var
k,i:longint;
begin
k:=max(fa1[0],fa2[0]);
for i:=k downto 1 do
        if fa1[i]<>fa2[i] then exit(false);
exit(true);
end;

procedure qsort(lx,rx:longint);
var
l,r:longint;
t,x:sc;

begin
l:=lx;r:=rx;
t:=ss[(lx+rx) shr 1];
repeat
        while (l<rx)and((ss[l].s>t.s)or((ss[l].s=t.s)and(t.n>ss[l].n))) do
                inc(l);
        while (lx<r)and((t.s>ss[r].s)or((ss[r].s=t.s)and(ss[r].n>t.n))) do
                dec(r);
        if l<=r then begin
                x:=ss[l];
                ss[l]:=ss[r];
                ss[r]:=x;
                inc(l);dec(r);
                end;
until l>=r;
if l<rx then qsort(l,rx);
if lx<r then qsort(lx,r);
end;

begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
//fillchar(ss,sizeof(ss),0);
readln(n);
for i:=1 to n do
        begin
                readln(ss[i].n);
                c:=0;
                repeat
                        read(ch);
                        val(ch,a,b);
                        inc(c);
                        ss[i].s[c]:=a;
                until eoln;
                ss[i].s[0]:=c;
                readln;
        end;

qsort(1,n);
for i:=1 to n do
        writeln(ss[i].n);
end.
