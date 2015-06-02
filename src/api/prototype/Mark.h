#ifndef API_CONTROLLER_MARK_H
#define API_CONTROLLER_MARK_H

using namespace Core;

class Mark : public Core::Controller
{
    public:
        int post();
        int put();
        int delete();
        int get();
        int head();
}

#endif