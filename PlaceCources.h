#ifndef _PLACE_CURCES_H_
#define _PLACE_CURCES_H_
#include "structure.h"


void PlaceLecture(College& college,int year)
{
    //1

    // function to check if the prof is available in this day
    bool checkprof(const Professor* prof, const int day);

    // function to check the time is available in schedule slot or no
    bool checkscheduleslot(const int startTime, int time, int d, std::vector<ScheduleSlot>& v);

    // function to reserve in schedule slot
    void reserveScheduleSlot(int startTime, int endTime, int d, string nameOfRoom, string nameprof, string namecorse, int profindex, std::vector<ScheduleSlot>& v,College &co );
    // function to reserve the room and return the name of this room
    string reserveRoom(int day, int startTime, int endTime, College& R);


    // vector to indicate to number of the lecture in every day
    vector<int> Lectperday(5,0);


    // number of the courses in the year
    int Numcourses = college.courses[year].size();


    // flage to the last day take lecture
    int lastDaySetLectue = 0;

    // loop on the courses
    for(int  indexTocourse= 0; indexTocourse<Numcourses; indexTocourse++)
    {
        //2


        if(lastDaySetLectue >= 5)
        {
            lastDaySetLectue = 0;

        }


        // the time of course
        int timeToCourse = college.courses[year][indexTocourse].lectureHoursPerWeek;
        string nameofcorse = college.courses[year][indexTocourse].name;

        // index of the prof in the vector courses that teach this course
        int indexprof = college.courses[year][indexTocourse].prof;


        // pointer to prof that teach this course
        Professor* prof = &(college.professors[indexprof]);

        // loop over the days
        for(int j = lastDaySetLectue; j<5; j++)
        {
            //3

            if(Lectperday[j] >= 2)
                continue;


            int startTime = 0; //

            // check if the prof is available in this day
            bool available = checkprof(prof, j);

            if(available == 0)
            {
                //4
                // the prof is not available in this time

                continue;
            } //4
            else
            {
                //5

                // the teacher is available in this day

                // check if the number of the lecture in this day not more than 2 lecure
                // if the number of the lecture in this day more than or equal 2 go to next day

                //check if the time available in schedule slot or no
                bool availableInschedule = college.Time[year].IsTimeReserved(j, startTime, startTime+timeToCourse);

                if(availableInschedule == 0 )
                {
                    //6
                    // this time is available in schedule slot

                    //check if this time is available for the prof and the total time in the day not reach the max time
                    if(prof->Time.IsTimeReserved(j,startTime,startTime+timeToCourse) == 0 )
                    {
                        //7
                        // this time is available for prof

                        // we will reserve this time for the prof
                        prof->Time.ReserveTime(j, startTime, startTime+timeToCourse, prof->availableDays);

                        string room = reserveRoom(j, startTime, startTime+timeToCourse, college);
                        // reserve this time in schedule slot
                        reserveScheduleSlot(startTime, startTime+timeToCourse, j, room, prof->name, nameofcorse, indexprof, college.schedule[year] ,college);

                        // reserve this time in for this year
                        college.Time[year].ReserveTime(j,startTime, startTime+timeToCourse,college.workingDays);

                        // we will add the lecture in this day
                        Lectperday[j] += 1;
                        //Hours day + Lecture hours
                        college.HoursDay[j]+=timeToCourse;

                        college.courses[year][indexTocourse].done = 1;

                        lastDaySetLectue = j + 1;




                        break;


                    }//7
                    else
                    { //cout<<"DONE\n";

                        int flag = 0;
                        for(int i = startTime; i<5; i++)
                        {
                            availableInschedule = college.Time[year].IsTimeReserved(j, i, i+timeToCourse);
                            if(availableInschedule == 0)
                            {
                                if(prof->Time.IsTimeReserved(j,i,i+timeToCourse) == 0)
                                {
                                    // we will reserve this time for the prof
                                    prof->Time.ReserveTime(j, i, i+timeToCourse, prof->availableDays);

                                    string room = reserveRoom(j, i, i+timeToCourse, college);
                                    // reserve this time in schedule slot
                                    reserveScheduleSlot(i, i+timeToCourse, j, room, prof->name, nameofcorse, indexprof, college.schedule[year],college );

                                    // reserve this time in for this year
                                    college.Time[year].ReserveTime(j,i, i+timeToCourse,college.workingDays);

                                    // we will add the lecture in this day
                                    Lectperday[j] += 1;

                                    college.HoursDay[j]+=timeToCourse;

                                    college.courses[year][indexTocourse].done = 1;

                                    lastDaySetLectue = j + 1;
                                    flag = 1;
                                    break;

                                }
                            }
                        }


                        if(flag == 1)
                            break;


                   }//8



                }//6
                else
                {
                    //12

                    int flag = 0;

                    // this time is not available in schedule slot

                    for(int i = startTime  ; i < 5; i++ )
                    {
                        availableInschedule = college.Time[year].IsTimeReserved(j, i, i+timeToCourse);

                        if(availableInschedule == 0)
                        {
                            //check if this time is available for the prof and the total time in the day not reach the max time
                            if(prof->Time.IsTimeReserved(j,i,i+timeToCourse) ==0)
                            {

                                // we will reserve this time for the prof
                                prof->Time.ReserveTime(j, i, i+timeToCourse, prof->availableDays);

                                string room = reserveRoom(j, i, i+timeToCourse, college);
                                // reserve this time in schedule slot
                                reserveScheduleSlot(i, i+timeToCourse, j, room, prof->name, nameofcorse, indexprof, college.schedule[year],college );

                                college.Time[year].ReserveTime(j,i, i+timeToCourse,college.workingDays);
                                // we will add the lecture in this day
                                Lectperday[j] += 1;

                                college.HoursDay[j]+=timeToCourse;
                                flag = 1;
                                lastDaySetLectue = j + 1;
                                college.courses[year][indexTocourse].done = 1;


                                break;

                            }
                            else
                            {
                                break;

                            }
                        }
                        else
                        {
                            continue;

                        }

                    }

                    if(flag == 1)
                        break;


                }//12

            } //5
        }//3



        if(college.courses[year][indexTocourse].done==0)
        {
            indexTocourse--;
            lastDaySetLectue=0;
        }
        if(indexTocourse==college.courses[year].size()-1&&college.courses[year][indexTocourse].done==1)
        {
            for(int i=0;i<5;i++)
               college.HoursDay[i]=0;
        }



    } //2


} //1




////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
// function to check if the prof is available in this day
bool checkprof(const Professor* prof, const int day)
{

    int n = prof->availableDays.size();
    for(int i=0; i<n; i++)
    {
        if(day == prof->availableDays[i])
            return true;
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// function to reserve in schedule slot
void reserveScheduleSlot(int startTime, int endTime, int d, string nameOfRoom, string nameprof, string namecorse, int profindex, std::vector<ScheduleSlot>& v,College &co )
{
    for(int i = startTime; i != endTime; i++)
    {

        ScheduleSlot slot;
        slot.course = namecorse;
        slot.day = d;
        slot.startHour = i+co.startTime;
        slot.endHour=slot.startHour+1;
        slot.professor = nameprof;
        slot.teacher = 1;
        slot.room = nameOfRoom;


        v.push_back(slot);
        //cout<<"2\n";
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
string reserveRoom(int day, int startTime, int endTime, College& R)
{

    int n = R.rooms.size();
    for(int i =0; i<n; i++)
    {

        if(R.rooms[i].Time.is_room_available(day, startTime, endTime) == 0)
        {
            R.rooms[i].Time.reserve_room(day, startTime, endTime);
            return R.rooms[i].name;
        }
    }
}

#endif // _PLACE_CURCES_H_
