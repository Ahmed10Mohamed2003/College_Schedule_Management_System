#include"PlaceClasses.h"
void placeClasses(College& college,int year) {
    // Algorithm to place classes after lectures
    //int c=college.courses[year].size();
    //cout<<" c = "<<5<<endl;
    int total_hours=0;

    //loop to calc total hours of sections along the week

    for(int sec=0;sec<college.courses[year].size();sec++) //loop of courses
    {
        int Space=0;
        for(int Day=0;Day<5;Day++)//loop of Days
        {
            int flag=0; //if(course reserved dont complete the loops (slot&Day)
        if(college.maxStudyHoursPerDay>(college.HoursDay[Day]+college.courses[year][sec].classHoursPerWeek))
            {
            for(int slot=0;slot<8;slot++) //loop of slots
            {

               vector<int>Avilable=college.assistants[college.courses[year][sec].assis].availableDays;

                bool Done=college.assistants[college.courses[year][sec].assis].Time.IsTimeReserved(Day,slot,slot+college.courses[year][sec].classHoursPerWeek);
                if(Done&&college.assistants[college.courses[year][sec].assis].availableDays.size()!=1&&Space==0)
                {
                    break;
                }
                if( !Done )
                {

                    if(college.courses[year][sec].specificPlaceRequired)
                    {

                        bool R_empty=college.rooms[college.courses[year][sec].requiredPlace].Time.is_room_available(Day,slot,slot+college.courses[year][sec].classHoursPerWeek);
                        bool Year_Av=college.Time[year].IsTimeReserved(Day,slot,slot+college.courses[year][sec].classHoursPerWeek);

                        if(!R_empty&&!Year_Av)
                        {
                            college.rooms[college.courses[year][sec].requiredPlace].Time.reserve_room(Day,slot,slot+college.courses[year][sec].classHoursPerWeek);
                            college.Time[year].ReserveTime(Day,slot,slot+college.courses[year][sec].classHoursPerWeek,college.workingDays);
                            college.assistants[college.courses[year][sec].assis].Time.ReserveTime(Day,slot,slot+college.courses[year][sec].classHoursPerWeek,college.assistants[college.courses[year][sec].assis].availableDays);
                            //college.rooms[college.courses[year][sec].requiredPlace].Time.display();

                            college.HoursDay[Day]+=college.courses[year][sec].classHoursPerWeek;
                            for(int j=slot;j<slot+college.courses[year][sec].classHoursPerWeek;j++)
                            {
                                ScheduleSlot s1;
                                s1.course=college.courses[year][sec].name;
                                college.courses[year][sec].done=1;
                                s1.day=Day;
                                s1.startHour=j+college.startTime;
                                s1.endHour=s1.startHour+1;
                                s1.professor=college.assistants[college.courses[year][sec].assis].name;
                                s1.teacher=1;
                                s1.room=college.rooms[(college.courses[year][sec]).requiredPlace].name;
                                college.schedule[year].resize(college.schedule[year].size()+1);
                                college.schedule[year].push_back(s1);

                            }

                            flag=1;
                            break;
                        }
                        else
                        {
                            if(!R_empty&&Space==0)
                            {
                                break;
                            }
                           // college.assistants[college.courses[year][sec].assis].Time.DeleteTime(Day,slot,slot+college.courses[year][sec].classHoursPerWeek);
                           // college.rooms[college.courses[year][sec].requiredPlace].Time.delete_time(Day,slot,slot+college.courses[year][sec].classHoursPerWeek);
                            /*if(college.courses[year][sec].classHoursPerWeek==2)//not to advance by one hour to let 2hours to another coming section
                               slot++;*/
                        }



                    }
                    else
                    {

                        int NUM_ROOMS=college.rooms.size();

                        for(int Room=0;Room<NUM_ROOMS;Room++)
                        {


                           bool R_empty=college.rooms[Room].Time.is_room_available(Day,slot,slot+college.courses[year][sec].classHoursPerWeek);
                           bool Year_Av=college.Time[year].IsTimeReserved(Day,slot,slot+college.courses[year][sec].classHoursPerWeek);
                           if(!R_empty&&!Year_Av)
                           {
                               if(year==1&&sec==2)
                                {college.assistants[7].Time.dispaly();cout<<"before\n";}
                               college.rooms[Room].Time.reserve_room(Day,slot,slot+college.courses[year][sec].classHoursPerWeek);
                                college.assistants[college.courses[year][sec].assis].Time.ReserveTime(Day,slot,slot+college.courses[year][sec].classHoursPerWeek,college.assistants[college.courses[year][sec].assis].availableDays);
                                college.Time[year].ReserveTime(Day,slot,slot+college.courses[year][sec].classHoursPerWeek,college.workingDays);
                                    if(year==1&&sec==2)
                               {
                                   college.assistants[7].Time.dispaly();
                                   cout<<"after\n";

                               }

                              college.HoursDay[Day]+=college.courses[year][sec].classHoursPerWeek;
                              for(int j=slot;j<slot+college.courses[year][sec].classHoursPerWeek;j++)
                              {
                                ScheduleSlot s1;
                                s1.course=college.courses[year][sec].name;
                                college.courses[year][sec].done=1;
                                s1.day=Day;
                                s1.startHour=j+college.startTime;
                                s1.endHour=s1.startHour+1;
                                s1.professor=college.assistants[college.courses[year][sec].assis].name;
                                s1.teacher=1;
                                s1.room=college.rooms[Room].name;
                                college.schedule[year].resize(college.schedule[year].size()+1);
                                college.schedule[year].push_back(s1);

                              }
                              flag=1;
                               break;
                           }
                           else
                           {
                               if(!R_empty&&Space==0)
                            {
                                break;
                            }
                              //college.assistants[college.courses[year][sec].assis].Time.DeleteTime(Day,slot,slot+college.courses[year][sec].classHoursPerWeek);
                             // college.rooms[Room].Time.delete_time(Day,slot,slot+college.courses[year][sec].classHoursPerWeek);
                           }
                        }
                        if(flag)
                        break;

                    }

                }
                else
                {
                    /*if(college.courses[year][sec].classHoursPerWeek==2)//not to advance by one hour to let 2hours to another coming section
                    slot++;            */                           //and can be minimized in minimize function as we can
                }
            }
            if(flag)
            {
                break;
            }

        }
        if(Day==4&&flag!=1)
        {
            Space=1;
            Day=-1;
        }

        }
        if(sec==college.courses[year].size()-1&&college.courses[year][sec].done)
        {
            for(int i=0;i<5;i++)
               college.HoursDay[i]=0;
        }
    }

}
