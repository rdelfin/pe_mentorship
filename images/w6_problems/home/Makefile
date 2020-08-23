CC = gcc

all: my_daemon
.PHONY: all

my_daemon: my_daemon.c
	${CC} my_daemon.c -o my_daemon

signal_reader: signal_reader.c
	${CC} signal_reader.c -o signal_reader

clean:
	rm my_daemon signal_reader
