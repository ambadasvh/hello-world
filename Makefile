CODE_DIR = test/src
BIN=msg

.PHONY: all

all:
	$(MAKE) -C $(CODE_DIR) all

clean:
	$(MAKE) -C $(CODE_DIR) clean

install: all
	cp $(CODE_DIR)/$(BIN) .

uninstall:
	rm -f $(BIN)
	$(MAKE) -C $(CODE_DIR) clean
