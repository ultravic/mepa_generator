$DEPURA=1

compilador: lex.yy.c y.tab.c compilador.o compilador.h stack.o
	gcc lex.yy.c compilador.tab.c stack.o compilador.o -o compilador -ll -ly -lc

lex.yy.c: compilador.l compilador.h
	flex compilador.l

y.tab.c: compilador.y compilador.h
	bison compilador.y -d -v

compilador.o : compilador.h compiladorF.c
	gcc -c compiladorF.c -o compilador.o

stack.o: stack.c stack.h
	gcc -c stack.c -o stack.o

clean : 
	@echo "Removendo executaveis...."
	@rm -f compilador 
	@echo "Removendo objetos...."
	@rm -f *.o *~ *.bak
	@echo "Removendo lixo...."
	@rm -f core 
	@rm -f compilador.tab.* lex.yy.c 
