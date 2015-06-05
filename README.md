Server HTTP with Rest Api Integration
=============

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

0. @type Request
0. httpGetConnection
0. httpReadRequest
0. httpProcessRequest
0 .@type Response
0. httpOutput
0. httpSetResponse
0. httpSetCOntentType
0. httpAddHeader
0. httpSendHeaders
0. httpUrlEncode
0. httpRequestMethod (HEAD,POST,PUT,DELETE,GET)
0. @type ErrorHandler
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
