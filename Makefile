all: eggshell findegg

eggshell:
	gcc -o eggshell eggshell.c

findegg:
	gcc -o findegg findegg.c

.PHONY: eggshell findegg
