flex psdhd.l
bison -dy psdhd.y
gcc lex.yy.c y.tab.c -o psdhd.exe -Wall
