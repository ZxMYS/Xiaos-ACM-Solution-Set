program rqnoj_195;
const
xc:array[1..4] of integer=(1,0,-1,0);
yc:array[1..4] of integer=(0,1,0,-1);
var
ga:array[0..2001,0..2001] of boolean;
i,j,k,t,j,m,n,x1,y1,x2,y2,min:longint;
procedure DFS(x,y,time);
var
i:longint;
begin

if time>=min then exit;
if (x=x2)and(y=y2)and(time<min) then
begin
        min:=time;
        end;
end;
for i:= 1 to 4 do
if ga[x+xc[i],y+yc[i]] then begin
        ga[x+xc[i],y+yc[i]]:=false;
        DFS(x+xc[i],y+yc[i],time+1);
        ga[x+xc[i],y+yc[i]]:=true;
        end;

end;
begin
assign(input,'f:\input.txt');
reset(input);
read(n,m)
for i:=1 to n do
for j:=1 to m do
        begin
        read(k);
        if k=0 then ga[i,j]:=true;
        end;
read(x1,y1,x2,y2);
min:=maxlongint;
search(x1,y1,0);
if min<>maxlongint then
write(min);
else
write('No Answer!');

end.