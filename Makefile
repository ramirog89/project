CC = g++
#CFLAGS = -Wall -Wextra -g -O0
CFLAGS = -Wall -g -O0
LDFLAGS = -lm 

#DEP = $(OBJ:%.o=%.d)

# El -c dice.. Solo compila... no linkees.. porque cuando linkea, no encuentra main en esta clase
# {@see: http://www.linuxquestions.org/questions/programming-9/c-compiling-single-class-without-a-main-358189/#post1825895}
myprogram : src/main.cpp request.o response.o handler.o front.o server.o
	${CC} ${CFLAGS} src/main.cpp -o bin/myprogram ${LDFLAGS} build/request.o build/response.o
# El build/request.o y build/response.o se ponen aca para que se linkeen los objetos y se puedan usar las funciones necesarias

server.o : src/server.cpp
	${CC} ${CFLAGS} -c src/server.cpp -o build/server.o

request.o : src/request.cpp
	${CC} ${CFLAGS} -c src/request.cpp -o build/request.o 

response.o : src/response.cpp
	${CC} ${CFLAGS} -c src/response.cpp -o build/response.o

handler.o : src/handler.cpp 
	${CC} ${CFLAGS} -c src/handler.cpp -o build/handler.o 

front.o : src/front.cpp include/front.h 
	${CC} ${CFLAGS} -c src/front.cpp -o build/front.o 
