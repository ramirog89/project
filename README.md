RPC Server HTTP with Rest Api Integration
=============

***RPC:*** https://technet.microsoft.com/en-us/library/cc787851%28v=ws.10%29.aspx


Esta libreria abre un puerto para comunicarse via HTTP protocolo y resuelve
la petición con un frontcontroller


RestFULL API Support for:

0. ***HEAD***
0. ***POST***
0. ***PUT***
0. ***DELETE***
0. ***GET***

Lista de métodos HTTP soportados por el API HTTP Handler:

0. ***200 OK***
0. ***302 Redirect***
0. ***403 Forbidden***
0. ***404 Not Found***
0. ***405 Method Not Allowed***
0. ***500 Server internal error***
0. ***501 Not Implemented***

COMMUNICATION VIA JSON STANDARD STRUCTURE
------

Estructura de Enlaces Permanentes(Uri Permanent Structure) para la interpretación de recursos:

```
dominio.org/recurso/verbodelrecurso(accion)/param1/param2/param3
dominio.org/recurso/verbodelrecurso(accion)/param1/value1/param2/value2/param3/value3
```

Referencias
------

http://www.hughes.com.au/products/libhttpd/libhttpd.pdf

Leer las instancias de la clase HTTP para tratar al protocolo:

0. ***@type Request***
	0. httpGetConnection
	0. httpReadRequest
	0. httpProcessRequest
0. ***@type Response***
	0. httpOutput
	0. httpSetResponse
	0. httpSetCOntentType
	0. httpAddHeader
	0. httpSendHeaders
	0. httpUrlEncode
	0. httpRequestMethod (HEAD,POST,PUT,DELETE,GET)
0. ***@type ErrorHandler***
	0. httpSetErrorFunction (ClientError [400-417]|ServerError [500-505])

------------
Para compilar la base de datos:

```
g++ -g -Wall -O0 src/database.cpp -I/usr/local/include/ -lpqxx -lpq -o data
```

-----------------------------------------------------

REST API
-----------

http://www.restapitutorial.com/lessons/restquicktips.html

```
/users
/users/:id
/users/:id/marks
/users/:id/marks/:id
/users/:id/notifications
/users/:id/notifications/:id
/users/:id/messages
/users/:id/events
/users/:id/events/:id
/users/:id/events/:id/participants

/marks
/marks/:id

/notifications
/notifications/:id

/events
/events/:id
/events/:id/participants
```


Respuesta
------

Para los requests Compuestos como por ejemplo Users
Se va a retornar como resultado de un metodo que devuelva algo,
Se va a tener en cuenta primero... si vinieron argumentos, el 1er argumentos
sera el id del recurso pedido, todo lo demás será tratado como par de 
llave y valor (entity=>value) y esto, simplemente modificara la query.
Si pido el recurso Usuario, siempre va a traer el usuario, todo lo demás
será tratado como Left join, o como inner join, o se hara una query en partiuclar con los ids
anteriores y se pusheara al array del resultado.
ejemplo:


```
Servicio : ***/users/:id/marks***

Array {
  UserObject : User =>
  {
	Array MarksObject => {
		{		
			MarkObject => { id : 1}
		},
		{
			MarkObject => { id : 2}
		}
	}
  }
}
```


-----------------------------------------

EXTRAS
---------

***Reflection***
-----
Es la capacidad de obtener la informacion de un objeto en tiempo de ejecucion.
Ver su tipo, sus metodos de invocacion, sus campos, esto es requerido cuando se quiere
implementar codigo generico el cual pueda trabajar con tipos no conocidos de los objetos
en el momento que se instancian.
0. Hay muchas tareas en las que la refleccion puede ser usada: 
	0. - Invocar metodos remotos
	0. - Serializacion
	0. - Dump de un objeto
	0. - Interfaz de una base de datos
Como funciona? : Dado un objeto, se pregunta su tipo,
Como resultado, obtenemos un "descriptor de clase" que provee la informacino acerca de sus metodos y campos.

Ver: http://www.garret.ru/cppreflection/docs/reflect.html

***C++ no permite "Reflection"***
-----
Esto significa que no puedo hacer : 
```
controller->(*this->_getAction())
```
asi como si nada.. vamos a tener que implementarlo
http://stackoverflow.com/questions/10668363/how-to-pass-method-name-in-variable

***Instancia Dinamica de Objetcos @C++***
-----
Solución a este problema:
Implementación de ***Prototype Pattern*** y ***Factory Pattern***

Ver: 

0. http://www.cs.sjsu.edu/~pearce/modules/lectures/oop/types/reflection/prototype.htm
0. http://stackoverflow.com/questions/4189682/calling-an-external-function-from-a-class-method
0. http://karthikpresumes.blogspot.com/2011/10/prototype-pattern-in-c-dynamic.html
0. http://www.cs.sjsu.edu/~pearce/modules/lectures/oop/types/reflection/prototype.htm

-----------------------------------------

***MultiThread vs MultiTask***
---------

0. Referencias
	0. http://yoda.arachsys.com/csharp/threads/whentouse.shtml
	0. http://www.cpp-home.com/tutorials/128_1.htm
	0. Imagen MultiHttpThreadFlow : https://images.duckduckgo.com/iu/?u=http%3A%2F%2Fwww3.nd.edu%2F~dthain%2Fcourses%2Fcse30341%2Fspring2009%2Fproject4%2Fmulti.gif&f=1
	0. http://www.cpp-home.com/tutorials/128_1.htm
	0. http://research.cs.wisc.edu/shore/1.0/ssmvas/node5.html
	0. https://images.duckduckgo.com/iu/?u=http%3A%2F%2Frandu.org%2Ftutorials%2Fthreads%2Fimages%2Fprocess.png&f=1
0. Diferencias entre MultiHilo y MultiProceso
	0. http://www.differencebetween.net/miscellaneous/difference-between-thread-and-process/
	0. http://www.programmerinterview.com/index.php/operating-systems/thread-vs-process/
	0. http://stackoverflow.com/questions/200469/what-is-the-difference-between-a-process-and-a-thread
0. FlowDiagram MultiThread WebServer
	0. http://stackoverflow.com/questions/12850059/multithreaded-web-server-flow-diagram
	0. ServerC++ ejemplo MultiHilo: http://www.cplusplus.com/forum/unices/116977/
0. Ejemplos de servidores:
	0. http://www.codeproject.com/Articles/7785/Single-Server-With-Multiple-Clients-a-Simple-C-Imp
	0. http://www.rohitab.com/discuss/topic/26991-cc-how-to-code-a-multi-client-server-in-c-using-threads/
 
C++ Multitask usa Fork para crear un proceso por Request
C++ Uso de thread para crear un hilo por Request..


Muchadata: http://www.bogotobogo.com/cplusplus/sockets_server_client.php
 
RPC Server Followed by: http://www.linuxhowtos.org/C_C++/socket.htm

