# C flags:
#CFLAGS_OPTIMIZATION = -g
CFLAGS_OPTIMIZATION = -O3
CFLAGS_VERSION = -std=c11
CFLAGS_WARNINGS = -Wall -Wextra -Wno-unused-parameter -Wno-unused-but-set-parameter
CFLAGS_DEFINES = -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -D_POSIX_SOURCE=1 -D_DEFAULT_SOURCE=1 -D_GNU_SOURCE=1
CFLAGS = $(CFLAGS_OPTIMIZATION) $(CFLAGS_VERSION) $(CFLAGS_WARNINGS) $(CFLAGS_DEFINES)

LIBS = -lm

CC = gcc
RM = rm -f

all: clean
	$(CC) -o binaryLoadBalance binaryLoadBalance.c $(LIBS) $(CFLAGS)

clean:
	-$(RM) binaryLoadBalance
