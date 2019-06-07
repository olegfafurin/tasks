program ccl;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var n,m,u,v,i,j,c,t,v_x,start:integer;
    a: array [1..100000,1..3] of integer;
    d,path,p: array[1..250] of integer;
    mark,change: array[1..250] of Boolean;

begin
//    reset(input,'cycle.in');
//    rewrite(output,'cycle.out');
    read(n);
    c:=0;
    for i:=1 to n do mark[i]:=false;

    for i:=1 to n do
    begin
        for j:=1 to n do
        begin
            read(t);
            if t<>1000000000 then
            begin
                Inc(c);
                a[c,1]:=i;
                a[c,2]:=j;
                a[c,3]:=t;
            end;
        end;
    end;
  m:=c;

  for start:=1 to n do
  begin
   if not Mark[start] then
   begin
    for i:=1 to n do d[i]:=1000000000;
    d[start]:=0;

    for j:=1 to n-1 do
    begin
        for i:=1 to m do
        begin
           if (d[a[i,1]]+a[i,3]<d[a[i,2]]) and (d[a[i,1]]<>1000000000) then
           begin
              d[a[i,2]]:=d[a[i,1]]+a[i,3];
              p[a[i,2]]:=a[i,1];
           end;
        end;
    end;

    for i:=1 to n do change[i]:=false;
    for i:=1 to m do
    begin
        if (d[a[i,1]]+a[i,3]<d[a[i,2]]) and (d[a[i,1]]<>1000000000) then
        begin
          d[a[i,2]]:=d[a[i,1]]+a[i,3];
          p[a[i,2]]:=a[i,1];
          change[a[i,2]]:=true;
        end;
    end;
    v_x:=0;
    for i:=1 to n do if change[i] then v_x:=i;
    if v_x<>0 then
    begin
      Writeln('YES');
      for i:=1 to n do v_x:=p[v_x];

      path[1]:=v_x;
      v:=p[v_x];
      c:=1;
      while v<>v_x do
      begin
         Inc(c);
         path[c]:=v;
         v:=p[v];
      end;
      Writeln(c+1);
      write(v_x,' ');
      for i:=c downto 1 do write(path[i],' ');
      Exit;

    end;
   end;
  end;
  writeln('NO');
//Close(Output);
end.