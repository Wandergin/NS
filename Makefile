CC     = clang
CFLAGS = -W -Wall -Wextra -lpthread

dnslookup: dnslookup.c
	$(CC) $(CFLAGS) -o dnslookup dnslookup.c

clean:
	rm -f dnslookup

