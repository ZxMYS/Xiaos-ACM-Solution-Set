program rqnoj_392;
var
i,j,q,k:longint;
begin
read(i,j,k);
if i=1 then
        begin read(i);write(i);end;
if i=2 then
        begin read(i,j);write(i+j);end;
if i>=3 then
        begin read(i,j,q);write((i+j+q)*k); end;
end.