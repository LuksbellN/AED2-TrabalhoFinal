# Variáveis
CC = gcc          # Compilador
CFLAGS = -Wall    # Opções de compilação
TARGET = main     # Nome do executável

# Diretórios
SRCDIR = .
AUXDIR = auxiliares
DATADIR = estruturas_dados
SEACRHDIR = buscas

# Arquivos fonte
SRC = $(SRCDIR)/main.c $(wildcard $(AUXDIR)/*.c) $(wildcard $(DATADIR)/*.c) $(wildcard $(SEACRHDIR)/*.c)

# Regras
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
