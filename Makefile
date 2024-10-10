# Variáveis
CC = gcc          # Compilador
CFLAGS = -Wall    # Opções de compilação
TARGET = main     # Nome do executável

# Diretórios
SRCDIR = .
DIR = src

# Arquivos fonte
SRC = $(SRCDIR)/main.c $(wildcard $(DIR)/*.c) 

# Regras
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
