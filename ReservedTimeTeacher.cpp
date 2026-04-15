#include <iostream>
#include <vector>
#include "ReservedTimeTeacher.h"
using namespace std;

// constructor no argument to set header pointer by NULL
ReservedTimeTeacher::ReservedTimeTeacher()
{
    // initialize to zero
    for(int i=0; i<5; i++)
        totaltime[i]=0;

    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;

}
/*  @function to reserve time, we use 24 hours system in day
    @input Day , Start time and End time
    @output function return true  if the time reserved or false
     if the time not reserved
*/
bool ReservedTimeTeacher::ReserveTime(int D, int S, int E, vector<int> available_Day)
{
     // if the total time in this day = 6 return false and not reserve the time
    if(totaltime[D] > 10)
        return false;
    // if the old time in this day plus the new time will become greater than 6 hours return false
    // and not reserve the time
    else if(totaltime[D] + E-S > 10 )
        return false;


    int flag = 0;
    int n = available_Day.size();

    for(int i=0; i<n; i++)
    {
        if(D == available_Day[i] ) // if this day (D) is available for teacher
        {                          // make a break and continue the program
            flag = 0;
            break;
        }
        else
                                //else put flag = 1
        {
            flag = 1;
        }
    }
    if(flag == 1) // if the flag =  1 mean this day not available for teacher and return false
        return false;


    if(E <= S)
        return false;


    // make a new node
    Node* temp = new Node;
    temp->day = D;
    temp->start_time = S;
    temp->end_time = E;

    // if the linked list is empty
    if(header->next == trailer)
    {
        header->next = temp;
        temp->prev = header;
        temp->next = trailer;
        trailer->prev = temp;
        totaltime[D] = E - S;
        return true;
    }
    else
    {
        // if the linked list is not empty
        Node* current = new Node;
        current = header->next;

        // check if the new time is not repeated in the list
        while(current != trailer)
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
                delete temp;
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
        /*if(totaltime[D]+E-S>6)
        {
            cout<<totaltime[D]<<endl;
            delete temp;
            return false;
        }*/
        header->next->prev = temp;
        temp->next = header->next;
        temp->prev = header;
        header->next = temp;
        totaltime[D]+= E - S;

        return true;
    }
}
/*
    @function to check this time is reserved or not
    @input Day , Start time and End time
    @output function return true if the time reserved before that
        or return false if this time not reserved
*/
bool ReservedTimeTeacher::IsTimeReserved(int D, int S, int E )
{
   Node* current = header->next;

    while(current != trailer)
    {
        if(D == current->day && S == current->start_time && E == current->end_time ) //1
        {
            return true;
        }

        else if(D == current->day && S == current->start_time) // 2
        {
            return true;
        }

        else if(D == current->day &&  E == current->end_time ) // 3
        {
            return true;
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
            current = current->next;
    }

   return false;
}
/*
        @function to delete time
        @input Day , Start time and End time
        @output function return true if the time is reserved
          before and delete or return false if the time not reserved
          before and not delete
*/
bool ReservedTimeTeacher::DeleteTime(int D, int S, int E )
{
    Node* current ;//= new Node;
    current = header->next;
    while(current != trailer)
    {
        if(D == current->day && S == current->start_time && E == current->end_time )
        {
            Node* temp1 = current->next;
            Node* temp2 = current->prev;
            temp2->next = temp1;
            temp1->prev = temp2;
            totaltime[D] -= E - S;
            delete current;
            return true;
        }

        current = current->next;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/*
       @ function to return total time to the teacher
       @ no input
       @ return total time
*/
int ReservedTimeTeacher::TotalTimeInDay(int D)
{
    if(D < 7 && D >= 0)
      return totaltime[D];
    else // out of the range
        return 0;
}

// display the list of time
void ReservedTimeTeacher::dispaly()
{
    Node* temp= header->next;
    while(temp!= trailer)
    {
        cout<<temp->day<<" "<<temp->start_time<<"  "<<temp->end_time<<endl;
        temp = temp->next;
    }
}

