namespace Core {

class Database
{
    private:
        void _connect(); // podria retronar el cnx
        void _disconnect(); // podria retornar true o false..
		
		// Singleton features
        Database(); // Constructor privado
		// C++11 igualar a delete = delete (borra los metodos)
		Database(Database const&); // Copiar constructor es privado = delete
		void operator=(Database const&); // asignar operador es privado = delete
		
		pqxx::work _txn; // conexion creada por el PQXX/lib
    public:
		/**
		 * {@see: http://stackoverflow.com/questions/1008019/c-singleton-design-pattern/1008289#1008289}
		 * {@see: http://stackoverflow.com/questions/270947/can-any-one-provide-me-a-sample-of-singleton-in-c/271104#271104}
		 * {@see: http://www.yolinux.com/TUTORIALS/C++Singleton.html}
		 */
		static Database& getInstance()
		{
			static Database INSTANCE;
			return INSTANCE;
		}
		
		pqxx::result query(std::string);
}

} //namespace Core
