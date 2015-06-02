#ifndef API_CONTROLLER_NOTIFICATION_H
#define API_CONTROLLER_NOTIFICATION_H

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

#endif