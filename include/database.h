namespace Core {

class Database
{
    private:
        void connect();
        void disconnect();
        void Database();
    public:
        void getInstance(); //devuelve la conexion.. donde hago todo.
}

} //namespace Core
