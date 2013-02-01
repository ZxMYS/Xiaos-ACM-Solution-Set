var
  a,b:array[1..100]of integer;
  m,n,i:0..100;luckybaby:boolean;
procedure qsort(l,r:integer);
  var i,j,mid,temp:integer;
begin
    i:=l;j:=r;mid:=b[(l+r)div 2];
    repeat
      while b[i]<mid do inc(i);
      while b[j]>mid do dec(j);
      if i<=j then begin
        temp:=b[i];
        b[i]:=b[j];
        b[j]:=temp;
        inc(i);dec(j);
        end;
    until i>j;
    if l<j then qsort(l,j);
    if i<r then qsort(i,r);
  end;
begin
while not eof do begin
  read(n);for i:=1 to n do read(a[i]);
  m:=0;
  for i:=1 to n do begin
    luckybaby:=true;
    for n:=1 to i do if b[n]=a[i] then luckybaby:=false;
    if luckybaby then begin
      inc(m);b[m]:=a[i];
      end;
    end;
  writeln(m);
  qsort(1,m);
  for n:=1 to m-1 do write(b[n],' ');
  writeln(b[m]);
  end;
end.