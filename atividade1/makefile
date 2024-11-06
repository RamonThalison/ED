# Nome do executável
EXEC = programa

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Arquivos fonte
SRC = main.c lista_encadeada.c

# Arquivos objeto
OBJ = $(SRC:.c=.o)

# Regra principal (default) que compila o projeto
all: $(EXEC)

# Regra para gerar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objetos e do executável
clean:
	rm -f $(OBJ) $(EXEC)

# Limpeza completa (inclui arquivos de backup como *~)
cleanall: clean
	rm -f *~
