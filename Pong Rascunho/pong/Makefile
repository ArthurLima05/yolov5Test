# Variáveis de compilação
CC = gcc
CFLAGS = -Wall -Iinclude

# Diretórios de origem e destino
SRC_DIR = src
BIN_DIR = bin

# Lista de arquivos fonte
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)
TARGET = $(BIN_DIR)/pong

# Regras de compilação
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_FILES) $(TARGET) $(BIN_DIR)

# Regras de uso
.PHONY: all clean
