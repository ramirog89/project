namespace Core {

class Database
{
    private:
		// {@see: http://stackoverflow.com/questions/1008019/c-singleton-design-pattern/1008289#1008289}
		// {@see: http://stackoverflow.com/questions/270947/can-any-one-provide-me-a-sample-of-singleton-in-c/271104#271104}
		// {@see: http://www.yolinux.com/TUTORIALS/C++Singleton.html}
		// 2 formas diferentes de hacer singleton..
		//static Database* instance; // singleton instance
		
        void _connect(); // podria retronar el cnx
        void _disconnect(); // podria retornar true o false..
		
		// Singleton features
        Database(); // Constructor privado
		// C++11 igualar a delete = delete (borra los metodos)
		Database(Database const&); // Copiar constructor es privado = delete
		void operator=(Database const&); // asignar operador es privado = delete
		
    public:
        //static Database* getInstance(); // singleton access
		static Database& getInstance()
		{
			stati	c Database INSTANCE;
			return INSTANCE;
		}
		
		pqxx::result query(std::string);
		//std::vector<json::value> fetchResult();
}

} //namespace Core
