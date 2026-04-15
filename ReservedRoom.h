#ifndef _RESERVED_ROOM_H_
#define _RESERVED_ROOM_H_

struct Noderoom
{
    int day;
    int start_time;
    int end_time;
    Noderoom* next;
};

class ReservedRoom
{
private:
    Noderoom* header;
public:
    ReservedRoom();
    bool reserve_room(int D, int S, int E);
    bool is_room_available(int D, int S, int E);
    bool delete_time(int D, int S, int E);
    void display();

};
#endif // _RESERVED_ROOM_H_
