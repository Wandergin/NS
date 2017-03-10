#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int lookupaddr(char *hostname)
{
    int status;
    struct addrinfo hints; 
    struct addrinfo *ai0, *ai;
    char ipstr[INET6_ADDRSTRLEN];
    memset(&hints, 0, sizeof(hints));
    hints.ai_family    = PF_UNSPEC;
    hints.ai_socktype  = SOCK_STREAM;
    if ((status = getaddrinfo(hostname, "http", &hints, &ai0)) != 0) {
        printf("Unable to look up IP address: %s", gai_strerror(status));
        return 2;
    }
    printf("%d\n", status);
    printf("IP addresses for %s:\n\n", hostname);
    // Try to connect to each address in turn
    for (ai = ai0; ai != NULL; ai = ai->ai_next) {
        void *addr;
        char *ipv;
        if (ai->ai_family == AF_INET) { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)ai->ai_addr;
            addr = &(ipv4->sin_addr);
            ipv = "IPv4";
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)ai->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipv = "IPv6";
        }
        // Convert the IP to a string
        inet_ntop(ai->ai_family, addr, ipstr, sizeof ipstr);
        printf("%s : %s\n", ipv, ipstr);

    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ipaddress>\n", argv[0]);
        return 1;
    }

    lookupaddr(argv[1]);

}