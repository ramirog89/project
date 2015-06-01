#include "../include/controller.h"

using namespace Core;

class User : public Core::Controller
{
    public:
        int post();
        int put();
        int delete();
        int get();
        int head();
}
