program rqnoj_324;
var
f:array[0..10000,0..1000,0..1000,0..1000,0..1000] of longint;
i,k,j,a,b,c,d,e,n,m:longint;
v:array[1..5] of longint;
cc:array[1..200,1..5] of longint;
w:array[1..200] of longint;
function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;

begin
assign(input,'f:\in.txt');
reset(input);
read(n,m);
fillchar(f,sizeof(f),0);

for i:=1 to m do
begin
       read(v[i]);
end;
for i:=1 to n do
begin
read(w[i]);
        for j:=1 to m do
        begin
        read(cc[i,j]);
        end;
        for j:=m+1 to 5 do
        cc[i,j]:=0;
end;
for i:=1 to n do
begin
        for a:=v[1] downto cc[i,1] do
        begin
                for b:= v[2] downto cc[i,2] do
                begin
                         for c:= v[3] downto cc[i,3] do
                         begin
                                 for d:= v[4] downto cc[i,4] do
                                 begin
                                         for e:= v[5] downto cc[i,5] do
                begin
                writeln(a,' ',b,' ',c, ' ',d,' ',e);
                writeln(a-cc[i,1],' ',b-cc[i,2],' ',c-cc[i,3],' ',d-cc[i,4],' ',e-cc[i,5]);
                f[a,b,c,d,e]:=max(f[a,b,c,d,e],f[a-cc[i,1],b-cc[i,2],c-cc[i,3],d-cc[i,4],e-cc[i,5]] + w[i]);
                writeln(a,' ',b,' ',c, ' ',d,' ',e, ' ',f[a,b,c,d,e]);
                end;
                end;
                end;
                end;
        end;
end;
write(f[v[1],v[2],v[3],v[4],v[5]]);
end.