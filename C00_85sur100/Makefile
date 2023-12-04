CC = cc
CFLAGS = -Wall -Wextra -Werror
QUOICOU_SRC_DIR = Quoicoulinette_by_cviegas

# Liste des fichiers sources
SRCS = ./ex00/ft_putchar.c $(QUOICOU_SRC_DIR)/Quoicoulinette_c00_00.c \
       ./ex01/ft_print_alphabet.c $(QUOICOU_SRC_DIR)/Quoicoulinette_c00_01.c \
       ./ex02/ft_print_reverse_alphabet.c $(QUOICOU_SRC_DIR)/Quoicoulinette_c00_02.c \
       ./ex03/ft_print_numbers.c $(QUOICOU_SRC_DIR)/Quoicoulinette_c00_03.c \
       ./ex04/ft_is_negative.c $(QUOICOU_SRC_DIR)/Quoicoulinette_c00_04.c \
       ./ex05/ft_print_comb.c $(QUOICOU_SRC_DIR)/Quoicoulinette_c00_05.c \
       ./ex06/ft_print_comb2.c $(QUOICOU_SRC_DIR)/Quoicoulinette_c00_06.c \
       $(QUOICOU_SRC_DIR)/Quoicoulinette_c00_main.c

# Nom de l'exécutable
TARGET = Quoicoulinette_c00

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

re: clean all

#squidgame:
