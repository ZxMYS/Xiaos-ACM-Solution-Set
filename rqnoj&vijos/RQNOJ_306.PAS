program destroy;
  type
    node=array[0..150] of
           record
             l,p:integer;
           end;
    gtype=array[0..150,0..150] of
            record
              c,f,z:longint;
            end;
    atype=array[1..9000] of integer;

  var
    lt:node;
    g:gtype;
    goal:atype;
    n,m,s,t,r,total:longint;

  procedure init;
    var
      i,j,x,y:integer;
    begin
      fillchar(g,sizeof(g),0);
      fillchar(lt,sizeof(lt),0);
      readln(n,m,s,t);
      for i:=1 to m do
        begin
          readln(x,y,g[x,y].c);
          g[y,x].c:=g[x,y].c;
          g[x,y].z:=i;
          g[y,x].z:=i;
        end;
    end;

  function find:integer;
    var
      i:integer;
    begin
      i:=1;
      while (i<=n) and not((lt[i].l<>0) and (lt[i].p=0)) do i:=i+1;
      if i>n then find:=0
             else find:=i;
    end;

  function ford(var a:integer):boolean;
    var
      i,w,x,j:integer;
    begin
      ford:=true;
      fillchar(lt,sizeof(lt),0);
      lt[s].l:=s;
      repeat
        i:=find;
        if i=0 then exit;
        for j:=1 to n do
          if (lt[j].l=0) and ((g[i,j].c<>0) or (g[j,i].c<>0)) then
             begin
               if (g[j,i].f>0) then lt[j].l:=-i;
               if (g[i,j].f<g[i,j].c) then lt[j].l:=i;
             end;
        lt[i].p:=1;
      until (lt[t].l<>0);
      w:=t;
      a:=32767;
      repeat
        j:=w;
        w:=abs(lt[j].l);
        if lt[j].l>0 then x:=g[w,j].c-g[w,j].f;
        if lt[j].l<0 then x:=g[j,w].f;
        if x<a then a:=x;
      until w=s;
      ford:=false;
    end;

  procedure change(a:integer);
    var
      w,j:integer;
    begin
      w:=t;
      repeat
        j:=w; w:=abs(lt[j].l);
        if lt[j].l>0 then g[w,j].f:=g[w,j].f+a;
        if lt[j].l<0 then g[j,w].f:=g[j,w].f-a;
      until w=s;
    end;

  procedure process;
    var
      del,i:integer;
      success:boolean;
    begin
      repeat
        success:=ford(del);
        if success=false then change(del);
      until success;
    end;

  function ford2(s,t:integer):boolean;
    var
      i,w,x,j:integer;
    begin
      ford2:=true;
      fillchar(lt,sizeof(lt),0);
      lt[s].l:=s;
      repeat
        i:=find;
        if i=0 then exit;
        for j:=1 to n do
          if (lt[j].l=0) and ((g[i,j].c<>0) or (g[j,i].c<>0)) then
             begin
               if (g[j,i].f>0) then lt[j].l:=-i;
               if (g[i,j].f<g[i,j].c) then lt[j].l:=i;
             end;
        lt[i].p:=1;
      until (lt[t].l<>0);
      ford2:=false;
    end;

  procedure main;
    var
      max2,i,j,k:longint;
    begin
      total:=0;
      for i:=1 to n do
        for j:=1 to n do
          begin
            if (g[i,j].f=g[i,j].c) and (g[i,j].c>0) then
              begin
                dec(g[i,j].c); dec(g[i,j].f);
                if ford2(i,j) then
                   begin
                     total:=total+1;
                     goal[total]:=g[i,j].z;
                   end;
                inc(g[i,j].c); inc(g[i,j].f);
              end;
          end;

    end;

  procedure qsort(var a:atype;s,t:integer);
    var
      i,j,x:integer;
    begin
      i:=s; j:=t; x:=a[s];
      while i<j do
        begin
          while (x<a[j]) and (j>i) do j:=j-1;
          if j>i then
             begin
               a[i]:=a[j];
               i:=i+1;
             end;
          while (x>a[i]) and (i<j) do i:=i+1;
          if i<j then
            begin
              a[j]:=a[i];
              j:=j-1;
            end;
        end;
        a[i]:=x;
        if s<(i-1) then qsort(a,s,i-1);
        if (j+1)<t then qsort(a,j+1,t);
      end;

  begin
    assign(input,'destroy.in'); reset(input);
    assign(output,'destroy.out'); rewrite(output);
    init;
    process;
    main;
    writeln(total);
    qsort(goal,1,total);
    for r:=1 to total do writeln(goal[r]);
    close(input);
    close(output);
  end.
