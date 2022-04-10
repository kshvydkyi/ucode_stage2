# ---------------- variables ----------------
CLIENT := uchat

# -- files and dirs --

# for libmx
LIBMXD := libmx/libmx.a
LIB_DIR := libs
LIB_INC_DIR := $(LIB_DIR)/include
###########

# for sql
SQL_FILES := ../libraries/libs/libsqlite3.a
#########

# for ssl
SSL_FILES := ../libraries/openssl/lib/libssl.a
SSL_FILESC := ../libraries/openssl/lib/libcrypto.a
#########

SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj

INC_FILES := $(wildcard $(INC_DIR)/*.h)
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))

# ----- commands -----
RM := rm -rdf
MKDIR := mkdir -p

CC := clang

CFLAGS := -rdynamic `pkg-config --cflags --libs gtk+-3.0`\
          -std=c11  -Wno-error -Wall -Werror -Wextra -Wpedantic\
           -Wno-unused-command-line-argument -Wno-unused-variable \
          -Wno-unused-function -Wno-unused-parameter -g

# ------------------ body -------------------
	
all: $(CLIENT) $(WFLAGS)

$(CLIENT): $(OBJ_FILES)
	@$(CC) $(CFLAGS)  $(OBJ_FILES) $(LIBMXD) $(SSL_FILES) $(SSL_FILESC) $(SQL_FILES) -o $@

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@$(CC) $(CFLAGS) -c $< -I $(INC_DIR) -I $(LIB_INC_DIR) -o $@\

clean:
	@$(RM) $(OBJ_DIR)

uninstall: clean
	@$(RM) $(CLIENT) $(LIB_DIR)

reinstall: uninstall all

.PHONY: all uninstall clean reinstall

