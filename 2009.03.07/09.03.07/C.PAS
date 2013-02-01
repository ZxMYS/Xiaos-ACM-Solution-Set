var a:string[8];
b:array[1..8]of byte;i,j:integer;k:boolean;
f,f1:text;
begin
assign(f,'input.txt');
reset(f);
read(f,a);
k:=true;
for i:=1 to 8 do b[i]:=1;
for i:=1 to 8 do
for j:=i+1 to 8 do
if (a[i]<>'0')and (a[i]=a[j]) then begin inc(b[i]);a[j]:='0';b[j]:=0 end;

j:=1;
for i:=1 to 8 do
 if b[i]<>0then  begin b[j]:=b[i];inc(j);end;
for j:=j to 8 do b[j]:=0;
for i:=1 to 8 do if b[i]>4 then k:=false;
if b[1]=8 then k:=false;
if (b[2]<>0) and (b[3]=0) then if b[1]<>b[2] then k:=false;
if (b[3]<>0) and (b[4]=0) then  if (b[1]+b[2])>4 then k:=false;
close(f);
assign(f1,'output.txt');
append(f1);
if k then write(f1,'1') else write(f1,'0');
close(f1);
end.