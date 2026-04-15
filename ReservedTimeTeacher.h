#ifndef RESERVED_TIME_TEACHER_H_
#define RESERVED_TIME_TEACHER_H_
using namespace std;
#include<vector>
struct  Node
{
    int day; // day from 0=satarsday to 6=friday
    int start_time;
    int end_time;
    Node* next;
    Node* prev;
};
class ReservedTimeTeacher
{
private:
    int totaltime[5]; // to store the total time in every day
    Node* header;
    Node* trailer;
public:
    // constructor no argument to set header pointer by NULL
    ReservedTimeTeacher();
    /*
         @function to reserve time
         @input Day , Start time and End time
         @output function return true  if the time reserved or false
           if the time not reserved
    */
    bool ReserveTime(int D, int S, int E, vector<int>available_Day );
    /*
        @function to check this time is reserved or not
        @input Day, Start time, End time and availableDays
        @output function return true if the time reserved before that
           or return false if this time not reserved
    */
    bool IsTimeReserved(int D, int S, int E );
    /*
        @function to delete time
        @input Day , Start time and End time
        @output function return true if the time is reserved
          before and delete or return false if the time not reserved
          before and not delete
    */
    bool DeleteTime(int D, int S, int E );
////////////////////////////////////////////////////////////////////////
    /*
       @ function to return total time in day to the teacher
       @ input take a day
       @ return total time in this day
    */
    int TotalTimeInDay(int D);
    // display list of time
    void dispaly();

};
#endif // RESERVED_TIME_TEACHER_H_
