CC = gcc

all: cleanup kill_ign stop_ign
.PHONY: all

cleanup: cleanup.c
	${CC} cleanup.c -o cleanup

kill_ign: kill_ign.c
	${CC} kill_ign.c -o kill_ign

stop_ign: stop_ign.c
	${CC} stop_ign.c -o stop_ign

clean:
	rm cleanup kill_ign stop_ign
