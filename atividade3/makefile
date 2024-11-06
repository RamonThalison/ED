# Nome do programa
PROG = programa

# Compilador
CC = gcc

# Alvo padrão
all: $(PROG)

# Como construir o programa
$(PROG): main.c
	$(CC) $(CFLAGS) main.c -o $(PROG)

# Limpeza dos arquivos gerados
clean:
	rm -f $(PROG)

