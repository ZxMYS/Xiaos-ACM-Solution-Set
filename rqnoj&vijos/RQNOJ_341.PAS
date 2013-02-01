program rqnoj_341;
type
line=^li;
li=record
        value,tar:longint;
        next:line;
        end;
var
ga:array[1..30000] of line;
bt,bt2:line;
i,j,k,a,b,c,d,n,m:longint;
f:array[1..30000] of boolean;
dis:array[1..30000] of longint;
q:array[1..300000] of longint;
buf:array[1..10000] of byte;
function min(x,y:longint):longint;
begin
if x>y then exit(y) else exit(x);
end;

begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

read(n,m);
fillchar(ga,sizeof(ga),0);
for i:=1 to n do
begin
new(ga[i]);
ga[i]^.next:=nil;
ga[i]^.tar:=0;
dis[i]:=maxint;
f[i]:=false;
end;

for i:=1 to m do
        begin
        read(a,b,c);
        new(bt);
        bt^.tar:=a;
        bt^.value:=c;
        bt^.next:=ga[b];
        ga[b]:=bt;
        new(bt);
        bt^.tar:=b;
        bt^.value:=c;
        bt^.next:=ga[a];
        ga[a]:=bt;
        end;
a:=1;
b:=1;
c:=1;
q[1]:=1;
f[1]:=true;
dis[1]:=0;
while c>0 do
begin
    k:=q[a];
    f[k]:=false;
    a:=(a+1) mod 300000;
    dec(c);
    bt:=ga[k];
    while (bt^.tar<>0)do
    begin
        if dis[bt^.tar]>dis[k]+bt^.value then begin
                dis[bt^.tar]:=dis[k]+bt^.value;
                if not(f[bt^.tar]) then begin
                f[bt^.tar]:=true;
                b:=(b+1) mod 300000;
                q[b]:=bt^.tar;
                inc(c);
                end;
        end;
        bt:=bt^.next;
    end;
end;
write(dis[n]);

end.
