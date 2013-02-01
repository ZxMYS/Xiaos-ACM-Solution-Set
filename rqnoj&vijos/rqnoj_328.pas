program cannon;

const
  maxm=100;
  maxn=10;
  pow:array [0..10] of longint=(1,3,9,27,81,243,729,2187,6561,19683,59049);
  {3的次幂}
  maxtotal=1000000;


type
  statetype=array [1..maxn] of longint; {状态类型}

var
  a:array [1..maxm,1..maxn] of boolean; {地图}
  c,c1:array [0..maxtotal] of longint; {最优值}
  t:array [1..maxn] of boolean; {搜索堆栈}
  state,state1:statetype;
  m,n,i,j,total,s,ans:longint;
  ch:char;
  buf:array[1..10000] of byte;

  procedure numtoarr(k:longint; var a:statetype);
{将一个十进制的数转化为三进制的数}
  var
    j:longint;
  begin
    for j:=1 to n do
      a[j]:=(k div pow[j-1]) mod 3;
  end;

  procedure arrtonum(a:statetype; var k:longint);
  {将一个三进制的数转化为一个十进制的数}
  var
    j:longint;
  begin
    k:=0;
    for j:=1 to n do
      inc(k,a[j]*pow[j-1]);
  end;

  procedure search(top,now:longint);
  {对每一层的炮兵的放法进行搜索}
  var
    j,j1,temp:longint;
  begin
    if top>n then
    begin
      for j:=1 to n do
        if t[j]
          then state1[j]:=2
          else if state[j]=0
                 then state1[j]:=0
                 else state1[j]:=state[j]-1;
      arrtonum(state1,j1);
      temp:=c[i]+now;
      if temp>c1[j1] then c1[j1]:=temp;
      exit;
    end;
    t[top]:=false; search(top+1,now);
    if a[s,top] and (state[top]=0) then
    begin
      t[top]:=true;
      if top+1<=n then t[top+1]:=false;
      if top+2<=n then t[top+2]:=false;
      search(top+3,now+1);
    end;
  end;

begin
  assign(input,'f:\in.txt');
  reset(input);
  settextbuf(input,buf);
  readln(m,n);

  for i:=1 to m do
  begin
    for j:=1 to n do
    begin
      read(ch);
      if ch='H' then a[i,j]:=false else a[i,j]:=true;
    end;
    readln;
  end;
  total:=pow[n]-1;
  for j:=1 to total do c[j]:=-1; c[0]:=0; {初始条件}
  for s:=1 to m do
  begin
    {按行记忆化搜索}
    for i:=0 to total do c1[i]:=-1;
    for i:=0 to total do
      if c[i]<>-1 then
begin
  {状态可达}
        numtoarr(i,state);
        search(1,0);
      end;
    c:=c1;
  end;

  ans:=0;
  for j:=0 to total do
    if c[j]>ans then ans:=c[j]; {最优值}
  write(ans,chr(10));
end.