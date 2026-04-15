#include "ReservedRoom.h"
#include <iostream>
using namespace std;

// constructor no arg
ReservedRoom::ReservedRoom():header(NULL)
{
}
///////////////////////////////////////////////////////////////////////
/*
    @function to reserve room
    @function input  a day , start time and end time
    @function return true if the room is reserved or return false if the room not reserved

*/
bool ReservedRoom::reserve_room(int D, int S, int E)
{
    Noderoom* temp = new Noderoom;
    temp->day = D;
    temp->start_time = S;
    temp->end_time = E;

    if(header == NULL)
    {
        temp->next = header;
        header = temp;
        return true;
    }
    else
    {
        Noderoom* current = header;
        while(current != NULL)
        {
            if(D == current->day && S == current->start_time && E == current->end_time ) //1
            {
                delete temp;
                return false;
            }

            else if(D == current->day && S == current->start_time) // 2
            {
                delete temp;
                return false;
            }

            else if(D == current->day &&  E == current->end_time ) // 3
            {
                delete temp;
                return false;
            }
            else if(D == current->day &&  (E > current->start_time && E < current->end_time)) // 4
            {

                return false;
            }
            else if(D == current->day &&  (S > current->start_time && S < current->end_time)) // 5
            {
                delete temp;
                return false;
            }
            else if(D == current->day &&  (S < current->start_time && E > current->end_time)) // 6
            {
                delete temp;
                return false;
            }

            else if(D == current->day &&  (S > current->start_time && E < current->end_time)) // 7
            {
                delete temp;
                return false;
            }

            else
                current = current->next;


        }

        if(current == NULL)
        {
            temp->next = header;
            header = temp;
            return true;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////
/*
    @ function to check is a room available in this time
    @ function take day, start time and end time
    @ function return true if the room is reserved before or return false if not reserved


*/
bool ReservedRoom::is_room_available(int D, int S, int E)
{
    if(header == NULL)
    {
        return false;

    }
    else
    {
       Noderoom* current = header;
        while(current != NULL)
        {
            if(current->day == D && current->start_time == S && current->end_time == E) // 1
            {
                return true ;
            }
            else if(current->day == D && current->start_time == S) // 2
            {
                return true ;
            }
            else if(current->day == D && current->end_time == E) // 3
            {
                return true ;
            }
            else if(D == current->day &&  (E > current->start_time && E < current->end_time)) // 4
            {
                return true;
            }
            else if(D == current->day &&  (S > current->start_time && S < current->end_time)) // 5
            {
                return true;
            }
            else if(D == current->day &&  (S < current->start_time && E > current->end_time)) // 6
            {
                return true;
            }

            else if(D == current->day &&  (S > current->start_time && E < current->end_time)) // 7
            {
                return true;
            }

            else
            {
                current = current->next;
            }
        }

        return false;

    }

}
////////////////////////////////////////////////////////////////////////////
/*
    @function to delete the reserved room
    @function take day, start time and time
    @function return true if the time is deleted or return false if the time is not deleted

*/
bool ReservedRoom::delete_time(int d, int s, int e)
{
    if(header == NULL)
    {
        return false;
    }

    if(header->day == d && header->start_time == s && header->end_time == e )
    {
        Noderoom* t = header;
        header = header->next;
        delete t;
        return true;
    }

    Noderoom* temp1 =  header;
    Noderoom* temp2 = header->next;
    while(temp2 != NULL)
    {
        if(temp2->day == d && temp2->start_time == s && temp2->end_time == e )
        {
            temp1->next = temp2->next;
            delete temp2;
            return true;
        }
        else
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
    return false;
}
//////////////////////////////////////////////////////////////////////////////////

void ReservedRoom::display()
{
    Noderoom* t=header;
    while(t != NULL)
    {
        cout<<t->day<<"  "<<t->start_time<<"  "<<t->end_time<<endl;
        t =t->next;
    }

}
///////////////////////////////////////////////////////
