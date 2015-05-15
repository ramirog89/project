namespace Core;

class Front
{
    private _http;

    private _controller;

    private _action;

    public function front(
        Http http
    )
    {
        this->_http = request;

        this->_init(http->getRequest());
    }
    
    private function _init()
    {
        //@TODO: exploto al request
        controller = request.controller;
        action     = request.action;
    }

    public function execute()
    {
        /**
         * @TODO: podria ser un resource object
         * que incluye el archivo controller
         * pregunta por su metodo action..
         * lo ejecuta
         */
        return exec(
            new {getController()},
            {getAction},
            args
        );
    }

    public function setController(){}
    
    public function setAction(){}

    public function getController(){}

    public function getAction(){}

}
