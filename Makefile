DEPURA=1
PATHC=src/
PATHU=utils/

compilador: lex.yy.c y.tab.c compilador.o $(PATHC)compilador.h utils.o
	gcc lex.yy.c compilador.tab.c utils.o compilador.o -o compilador -ll -ly -lc

lex.yy.c: $(PATHC)compilador.l $(PATHC)compilador.h
	flex $(PATHC)compilador.l

y.tab.c: $(PATHC)compilador.y $(PATHC)compilador.h
	bison $(PATHC)compilador.y -d -v

compilador.o : $(PATHC)compilador.h $(PATHC)compiladorF.c
	gcc -c $(PATHC)compiladorF.c -o compilador.o

utils.o: $(PATHU)utils.c $(PATHU)utils.h
	gcc -c $(PATHU)utils.c -o utils.o

clean : 
	@echo "Removendo executaveis...."
	@rm -f compilador 
	@echo "Removendo objetos...."
	@rm -f *.o *~ *.bak
	@echo "Removendo lixo...."
	@rm -f core 
	@rm -f compilador.tab.* lex.yy.c 
