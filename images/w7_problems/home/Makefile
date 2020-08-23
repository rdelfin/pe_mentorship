CC = gcc

all: my_daemon daemonize minishell
.PHONY: all

my_daemon: my_daemon.c
	${CC} my_daemon.c -o my_daemon

daemonize: daemonize.c
	${CC} daemonize.c -o daemonize

minishell: minishell.c
	${CC} minishell.c -o minishell

clean:
	rm my_daemon daemonize minishell
