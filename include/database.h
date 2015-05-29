namespace Core {

class Database
{
    private:
        Mysql cnx;
        connect();
        disconnect();
        Database();
    public:
        getInstance(); //devuelve la conexion.. donde hago todo.
}

} //namespace Core
