program rqnoj_194;
type
graphy=record
        c,f:longint;
        end;
const
len=200000;
var
ga:array[1..200,1..200] of graphy;
pre:array[1..200] of graphy;
line:array[1..200000,1..2] of longint;
q:array[1..200000] of integer;
f:array[1..200] of boolean;
top,bot,l,i,j,k,m,n,x,y,s,t:longint;
function min(x,y:longint):longint;
begin
        if x>y then exit(y) else exit(x);
end;
begin
assign(input,'f:\in.txt');
reset(input);

fillchar(ga,sizeof(ga),0);
read(m,n);
s:=1;
t:=n;
for i:=1 to m do
begin
        read(x,y,ga[x,y].f);
end;


repeat
        fillchar(pre,sizeof(pre),0);
        fillchar(f,sizeof(f),0);
        top:=0;
        bot:=0;
        l:=0;
        l:=0;
        f[s]:=true;
        pre[s].c:=0;
        pre[s].f:=maxlongint;
        bot:=(bot+1) mod len;
        top:=(top+1) mod len;
        inc(l);
        q[bot]:=s;

        while (l>0) and not(f[t]) do
                begin
                x:=q[top];
                top:=(top+1) mod len;
                dec(l);
                        for i:=1 to n do
                                if not(f[i]) and (ga[x,i].c<ga[x,i].f) then
                                        begin
                                        bot:=(bot+1) mod len;
                                        inc(l);
                                        q[bot]:=i;
                                        f[i]:=true;
                                        pre[i].c:=x;
                                        pre[i].f:=min(ga[x,i].f-ga[x,i].c,pre[x].f);
                                        end;
                end;
if f[t] then
        begin
                y:=t;
                x:=pre[y].c;
                while y<>s do
                begin
                ga[x,y].c:=ga[x,y].c+pre[t].f;
                ga[y,x].c:=-ga[x,y].c;
                y:=x;
                x:=pre[y].c;
                end;
        end;
until not(f[t]);
y:=0;
for i:=1 to n do
        inc(y,ga[i,n].c);
write(y);

end.
