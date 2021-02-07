default:
	cls
	flex -l tokens.l
	bison  code.y -v
	gcc -o code code.tab.c lex.yy.c
	code.exe
