# Make file

# Macros
NOME=jogo_cobrinha
#
CODIGO=src
CLASS=class
MAIN=main.cpp
# Definicõe da openCV
OPENCV=`pkg-config --cflags --libs opencv`
#
COMPILADOR=g++
OPCAO=

# Regras

all: prog
	clear
	./$(NOME)

prog: bib main
	@echo "\nlinkando todos os objeto gerando-> "$(NOME)"\n"
	$(COMPILADOR) $(OPCAO) *.o $(OPENCV) -o $(NOME)
	@echo "\n"

bib:
	@echo "\nGerando objeto das bibliotecas\n"
	$(COMPILADOR) $(OPCAO) -c $(CODIGO)/*.cpp -I$(CLASS) $(OPENCV)

main:
	@echo "\nGernado objeto "$(MAIN)"\n"
	$(COMPILADOR) $(OPCAO) -c $(MAIN) -I$(CLASS) $(OPENCV)

obj:
	@echo "\nGERANDO OBJETO "$(NOME)" "$(MAIN)" DA CLASSE "$(CODIGO)"\n"
	$(COMPILADOR) $(OPCAO) -c $(CODIGO) -I$(CLASS)

limpa:
	@echo "\nDeletando todos os objetos (.o)\n"
	-rm -f *.o
	-rm -f $(NOME)