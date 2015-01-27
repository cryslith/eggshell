all: eggshell findegg overflow

eggshell:
	gcc -o eggshell eggshell.c

findegg:
	gcc -o findegg findegg.c

overflow:
	gcc -o overflow overflow.c

.PHONY: eggshell findegg overflow
