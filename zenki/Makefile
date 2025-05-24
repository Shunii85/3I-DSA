# zenki/Makefile

SRCDIR := .
FINISHED := $(SRCDIR)/finished

# .cpp → 実行ファイル名変換（拡張子除去）
BIN_SRCS := $(SRCDIR)/*.cpp
BIN_FINISHED := $(FINISHED)/*.cpp

BINS := $(basename $(wildcard $(BIN_SRCS))) \
        $(basename $(wildcard $(BIN_FINISHED)))
.PHONY: clean
clean:
	rm -f $(BINS) a.out
