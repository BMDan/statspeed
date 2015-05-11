CC=gcc
CFLAGS=
statspeed: statspeed.c
	$(CC) $(CFLAGS) -o statspeed $^
