# ---------------- variables ----------------
NAME = uchat
SERVER_NAME = uchat_server
SERVER_DIR = server
CLIENT_DIR = client

# -- files and dirs --

# for sql 
LIBSQLITE_DIR = libraries/libs_raw/sqlite3
#########

# ----- commands -----

MAKE_M = make -sf Makefile -C

# ------------------ body -------------------

all:
	@$(MAKE_M) $(CLIENT_DIR) $@
	@$(MAKE_M) $(SERVER_DIR) $@
	

$(NAME):
	@$(MAKE_M) $(CLIENT_DIR)

$(SERVER_NAME):
	@$(MAKE_M) $(SERVER_DIR)

clean:
	@$(MAKE_M) $(CLIENT_DIR) $@
	@$(MAKE_M) $(SERVER_DIR) $@

uninstall:
	@$(MAKE_M) $(CLIENT_DIR) $@
	@$(MAKE_M) $(SERVER_DIR) $@

reinstall: uninstall all

.PHONY: all clean uninstall reinstall $(NAME) $(SERVER_NAME)

