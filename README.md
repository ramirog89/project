# project
http handler api core 


RestFULL API
Support for
HEAD POST PUT DELETE GET 

Lista de status necesarios minimos para soportar ésta api y ser claro con el servidor
STATUS 200 302 403 404 405 500 501 HANDLERS SUPPORTED
200 OK
302 Redirect
403 Forbidden
404 Not Found
405 Method Not Allowed
500 Server internal error
501 Not Implemented

COMMUNICATION VIA JSON STANDARD STRUCTURE

Estructura de Enlaces permanentes para la interpretacion de recursos:
dominio.org/recurso/verbodelrecurso(accion)/param1/param2/param3
dominio.org/recurso/verbodelrecurso(accion)/param1/value1/param2/value2/param3/value3

A quien le pido? recurso
Que le pido?  verbo del recurso (accion)
Le tengo que pasar estos parametros para que procese.. podes recibirlos? Parametros



Entonces mi API funcinoaria asi como en etapas.

El cliente hace una peticion a un dominio donde tengo el puerto http (80) redireccionado al socket abierto que tengo en mi computadora (puedo ponerlo en cualquiera si quiero tambien) y recibir el mensaje HTTP request, parsearlo, interpretarlo y generar un proceso sobre la peticion, donde interpreto un recurso, una accion del recurso y parametros de ser necesarios para generar una solicitud en caso de no estar en la cache, sobre la base de datos que va a contener los datos requeridos por el cliente.
 Una vez generada la solicitud y los datos esten en memoria, se ordenaran con un orden estandard en un formato estandard (HTTP response) con el contenido de la respuesta generada en formato JSON para que el cliente pueda interpretar una respuesta coherente de acuerdo el protocolo de comunicación elegido (HTTP).

Referencias
{@link: http://www.hughes.com.au/products/libhttpd/libhttpd.pdf}
Leer las instancias de la clase HTTP para tratar al protocolo
@type Request
httpGetConnection
httpReadRequest
httpProcessRequest
@type Response
httpOutput
httpSetResponse
httpSetCOntentType
httpAddHeader
httpSendHeaders
httpUrlEncode
httpRequestMethod (HEAD,POST,PUT,DELETE,GET)
@type ErrorHandler
httpSetErrorFunction (ClientError [400-417]|ServerError [500-505])

Para compilar la base de datos:
g++ -g -Wall -O0 src/database.cpp -I/usr/local/include/ -lpqxx -lpq -o data

-----------------------------------------------------

* REST API * | {@link: http://www.restapitutorial.com/lessons/restquicktips.html}
------------
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



Para los requests Compuestos como por ejemplo Users
Se va a retornar como resultado de un metodo que devuelva algo,
Se va a tener en cuenta primero... si vinieron argumentos, el 1er argumentos
sera el id del recurso pedido, todo lo demás será tratado como par de 
llave y valor (entity=>value) y esto, simplemente modificara la query.
Si pido el recurso Usuario, siempre va a traer el usuario, todo lo demás
será tratado como Left join, o como inner join, o se hara una query en partiuclar con los ids
anteriores y se pusheara al array del resultado.
ejemplo


/users/:id/marks

Traera como resultado algo del tipo:

{

  UserObject : User =>
  
  {
  
	//atributos del usuario
	
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




