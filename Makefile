CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lm

request.o : request.c request.h     
    ${CC} ${CFLAGS} -c request.c

response.o : response.c response.h     
    ${CC} ${CFLAGS} -c request.c

http.o : http.c http.h request.h response.h   
    ${CC} ${CFLAGS} -c http.c

server.o : server.c server.h http.h
    ${CC} ${CFLAGS} -c server.c

main.o : main.c server.o http.o request.o response.o

server : main.o server.o http.o request.o response.o
    ${CC} ${CFLAGS} main.o server.o http.o request.o response.o ${LDFLAGS} -o server
    
