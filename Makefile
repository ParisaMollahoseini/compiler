default:
	cls
	flex -l tokens.l
	bison -dv code.y 
	gcc -o code code.tab.c lex.yy.c
	code.exe
