#ifndef TEST3_
#define TEST3_

#include <iostream>
#include <vector>
#include <string>
#include "ReservedTimeTeacher.h"
#include "ReservedRoom.h"
#include "structure.h"
#include <bits/stdc++.h>

void Test3(College& college)
{

    college.assistants.resize(10);
    college.assistants[0].availableDays={0,1,2,3};
    college.assistants[1].availableDays={1,2,3,4};
    college.assistants[2].availableDays={1,2,3,4};
    college.assistants[3].availableDays={0,2,3,4};
    college.assistants[4].availableDays={1,2,3,4};
    college.assistants[5].availableDays={0,1,2,3};
    college.assistants[6].availableDays={0,1,3,4};
    college.assistants[7].availableDays={1,2,3,4};
    college.assistants[8].availableDays={0,2,3,4};
    college.assistants[9].availableDays={0,1,2,4};
    college.assistants[0].name="Ahmed";
    college.assistants[1].name="MOhamed";
    college.assistants[2].name="Mahmoud";
    college.assistants[3].name="osama";
    college.assistants[4].name="said";
    college.assistants[5].name="Ali";
    college.assistants[6].name="Abdo";
    college.assistants[7].name="shady";
    college.assistants[8].name="omar";
    college.assistants[9].name="Amr";
    //courses data
    college.courses.resize(5,vector<Course>(6));
    college.courses[0][0].year=0;
    college.courses[0][1].year=0;
    college.courses[0][2].year=0;
    college.courses[0][3].year=0;
    college.courses[0][4].year=0;
    college.courses[0][5].year=0;
    college.courses[0][0].classHoursPerWeek=2;
    college.courses[0][1].classHoursPerWeek=2;
    college.courses[0][2].classHoursPerWeek=3;
    college.courses[0][3].classHoursPerWeek=2;
    college.courses[0][4].classHoursPerWeek=2;
    college.courses[0][5].classHoursPerWeek=2;
    college.courses[0][0].specificPlaceRequired=false;
    college.courses[0][1].specificPlaceRequired=false;
    college.courses[0][2].specificPlaceRequired=true;
    college.courses[0][3].specificPlaceRequired=false;
    college.courses[0][4].specificPlaceRequired=false;
    college.courses[0][5].specificPlaceRequired=false;
    college.courses[0][2].requiredPlace=5;
    college.courses[0][0].prof=0;
    college.courses[0][1].prof=1;
    college.courses[0][2].prof=2;
    college.courses[0][3].prof=3;
    college.courses[0][4].prof=4;
    college.courses[0][5].prof=5;
    college.courses[0][0].assis=0;
    college.courses[0][1].assis=1;
    college.courses[0][2].assis=2;
    college.courses[0][3].assis=3;
    college.courses[0][4].assis=4;
    college.courses[0][5].assis=5;

    college.courses[0][0].name="course1";
    college.courses[0][1].name="course2";
    college.courses[0][2].name="course3";
    college.courses[0][3].name="course4";
    college.courses[0][4].name="course5";
    college.courses[0][5].name="course6";

    college.courses[1][0].year=1;
    college.courses[1][1].year=1;
    college.courses[1][2].year=1;
    college.courses[1][3].year=1;
    college.courses[1][4].year=1;
    college.courses[1][5].year=1;
    college.courses[1][0].classHoursPerWeek=2;
    college.courses[1][1].classHoursPerWeek=2;
    college.courses[1][2].classHoursPerWeek=3;
    college.courses[1][3].classHoursPerWeek=2;
    college.courses[1][4].classHoursPerWeek=2;
    college.courses[1][5].classHoursPerWeek=2;
    college.courses[1][0].specificPlaceRequired=false;
    college.courses[1][1].specificPlaceRequired=false;
    college.courses[1][2].specificPlaceRequired=true;
    college.courses[1][3].specificPlaceRequired=false;
    college.courses[1][4].specificPlaceRequired=false;
    college.courses[1][5].specificPlaceRequired=false;
    college.courses[1][2].requiredPlace=5;
    college.courses[1][0].prof=0;
    college.courses[1][1].prof=1;
    college.courses[1][2].prof=2;
    college.courses[1][3].prof=3;
    college.courses[1][4].prof=4;
    college.courses[1][5].prof=5;
    college.courses[1][0].assis=6;
    college.courses[1][1].assis=7;
    college.courses[1][2].assis=8;
    college.courses[1][3].assis=9;
    college.courses[1][4].assis=0;
    college.courses[1][5].assis=1;
    college.courses[1][0].name="course1";
    college.courses[1][1].name="course2";
    college.courses[1][2].name="course3";
    college.courses[1][3].name="course4";
    college.courses[1][4].name="course5";
    college.courses[1][5].name="course6";

    college.courses[2][0].year=2;
    college.courses[2][1].year=2;
    college.courses[2][2].year=2;
    college.courses[2][3].year=2;
    college.courses[2][4].year=2;
    college.courses[2][5].year=2;
    college.courses[2][0].classHoursPerWeek=2;
    college.courses[2][1].classHoursPerWeek=2;
    college.courses[2][2].classHoursPerWeek=3;
    college.courses[2][3].classHoursPerWeek=2;
    college.courses[2][4].classHoursPerWeek=2;
    college.courses[2][5].classHoursPerWeek=2;
    college.courses[2][0].specificPlaceRequired=false;
    college.courses[2][1].specificPlaceRequired=false;
    college.courses[2][2].specificPlaceRequired=true;
    college.courses[2][3].specificPlaceRequired=false;
    college.courses[2][4].specificPlaceRequired=false;
    college.courses[2][5].specificPlaceRequired=false;
    college.courses[2][2].requiredPlace=5;
    college.courses[2][0].prof=0;
    college.courses[2][1].prof=1;
    college.courses[2][2].prof=2;
    college.courses[2][3].prof=3;
    college.courses[2][4].prof=4;
    college.courses[2][5].prof=5;
    college.courses[2][0].assis=2;
    college.courses[2][1].assis=3;
    college.courses[2][2].assis=4;
    college.courses[2][3].assis=5;
    college.courses[2][4].assis=6;
    college.courses[2][5].assis=7;
    college.courses[2][0].name="course1";
    college.courses[2][1].name="course2";
    college.courses[2][2].name="course3";
    college.courses[2][3].name="course4";
    college.courses[2][4].name="course5";
    college.courses[2][5].name="course6";

    college.courses[3][0].year=3;
    college.courses[3][1].year=3;
    college.courses[3][2].year=3;
    college.courses[3][3].year=3;
    college.courses[3][4].year=3;
    college.courses[3][5].year=3;
    college.courses[3][0].classHoursPerWeek=2;
    college.courses[3][1].classHoursPerWeek=3;
    college.courses[3][2].classHoursPerWeek=2;
    college.courses[3][3].classHoursPerWeek=2;
    college.courses[3][4].classHoursPerWeek=2;
    college.courses[3][5].classHoursPerWeek=3;
    college.courses[3][0].specificPlaceRequired=false;
    college.courses[3][1].specificPlaceRequired=false;
    college.courses[3][2].specificPlaceRequired=true;
    college.courses[3][3].specificPlaceRequired=false;
    college.courses[3][4].specificPlaceRequired=false;
    college.courses[3][5].specificPlaceRequired=false;
    college.courses[3][2].requiredPlace=5;
    college.courses[3][0].prof=0;
    college.courses[3][1].prof=1;
    college.courses[3][2].prof=2;
    college.courses[3][3].prof=3;
    college.courses[3][4].prof=4;
    college.courses[3][5].prof=5;
    college.courses[3][0].assis=8;
    college.courses[3][1].assis=9;
    college.courses[3][2].assis=0;
    college.courses[3][3].assis=1;
    college.courses[3][4].assis=2;
    college.courses[3][5].assis=3;
    college.courses[3][0].name="course1";
    college.courses[3][1].name="course2";
    college.courses[3][2].name="course3";
    college.courses[3][3].name="course4";
    college.courses[3][4].name="course5";
    college.courses[3][5].name="course6";

    college.courses[4][0].year=4;
    college.courses[4][1].year=4;
    college.courses[4][2].year=4;
    college.courses[4][3].year=4;
    college.courses[4][4].year=4;
    college.courses[4][5].year=4;
    college.courses[4][0].classHoursPerWeek=2;
    college.courses[4][1].classHoursPerWeek=2;
    college.courses[4][2].classHoursPerWeek=2;
    college.courses[4][3].classHoursPerWeek=2;
    college.courses[4][4].classHoursPerWeek=2;
    college.courses[4][5].classHoursPerWeek=3;
    college.courses[4][0].specificPlaceRequired=false;
    college.courses[4][1].specificPlaceRequired=false;
    college.courses[4][2].specificPlaceRequired=true;
    college.courses[4][3].specificPlaceRequired=false;
    college.courses[4][4].specificPlaceRequired=false;
    college.courses[4][5].specificPlaceRequired=false;
    college.courses[4][2].requiredPlace=5;
    college.courses[4][0].prof=0;
    college.courses[4][1].prof=1;
    college.courses[4][2].prof=2;
    college.courses[4][3].prof=3;
    college.courses[4][4].prof=4;
    college.courses[4][5].prof=5;
    college.courses[4][0].assis=4;
    college.courses[4][1].assis=5;
    college.courses[4][2].assis=6;
    college.courses[4][3].assis=7;
    college.courses[4][4].assis=2;
    college.courses[4][5].assis=3;
    college.courses[4][0].name="course1";
    college.courses[4][1].name="course2";
    college.courses[4][2].name="course3";
    college.courses[4][3].name="course4";
    college.courses[4][4].name="course5";
    college.courses[4][5].name="course6";
    //Rooms data
    college.rooms.resize(10);
    college.rooms[0].name="A0";
    college.rooms[1].name="A1";
    college.rooms[2].name="A2";
    college.rooms[3].name="A3";
    college.rooms[4].name="A4";
    college.rooms[5].name="A5";
    college.rooms[6].name="A6";
    college.rooms[7].name="A7";
    college.rooms[8].name="A8";
    college.rooms[9].name="A9";
    college.workingDays={0,1,2,3,4};
    //other data
    college.maxStudyHoursPerDay=10;
    college.numYears=5;
    college.sportsDay=3;
	college.sportsStartHour=14;
    college.sportsEndHour=16;
    college.startTime=8;
    college.Time[0].ReserveTime(3,6,8,college.workingDays); //for sports hours
    college.Time[1].ReserveTime(3,6,8,college.workingDays); //for sports hours
    college.Time[2].ReserveTime(3,6,8,college.workingDays);//for sports hours
    college.Time[3].ReserveTime(3,6,8,college.workingDays); //for sports hours
    college.Time[4].ReserveTime(3,6,8,college.workingDays);//for sports hours
    //cout<<college.Time[0].ReserveTime(3,4,6,college.workingDays)<<endl;
    //cout<<college.Time[0].ReserveTime(3,4,6,college.workingDays);
   college.schedule.resize(5,vector<ScheduleSlot>(20));


     //college.assistants[1].Time.ReserveTime(1,12,14,college.assistants[1].availableDays);
     college.Time[0].ReserveTime(0,0,4,college.workingDays);
     college.Time[0].ReserveTime(1,0,4,college.workingDays);
     college.Time[0].ReserveTime(2,0,4,college.workingDays);
     college.Time[0].ReserveTime(3,0,4,college.workingDays);
     college.Time[0].ReserveTime(4,0,4,college.workingDays);
     /*college.Time[0].ReserveTime(0,7,12,college.workingDays);
     college.Time[0].ReserveTime(1,7,12,college.workingDays);
     college.Time[0].ReserveTime(2,7,12,college.workingDays);
     college.Time[0].ReserveTime(3,7,12,college.workingDays);
     college.Time[0].ReserveTime(4,7,12,college.workingDays);*/

     college.Time[1].ReserveTime(0,0,2,college.workingDays);
     college.Time[1].ReserveTime(1,0,4,college.workingDays);
     college.Time[1].ReserveTime(2,2,4,college.workingDays);
     college.Time[1].ReserveTime(3,0,2,college.workingDays);
     college.Time[1].ReserveTime(4,2,4,college.workingDays);

     college.Time[2].ReserveTime(0,0,2,college.workingDays);
     college.Time[2].ReserveTime(1,0,4,college.workingDays);
     college.Time[2].ReserveTime(2,2,4,college.workingDays);
     college.Time[2].ReserveTime(3,0,2,college.workingDays);
     college.Time[2].ReserveTime(4,2,4,college.workingDays);

     college.Time[3].ReserveTime(0,0,2,college.workingDays);
     college.Time[3].ReserveTime(1,0,4,college.workingDays);
     college.Time[3].ReserveTime(2,2,4,college.workingDays);
     college.Time[3].ReserveTime(3,0,2,college.workingDays);
     college.Time[3].ReserveTime(4,2,4,college.workingDays);

     college.Time[4].ReserveTime(0,0,2,college.workingDays);
     college.Time[4].ReserveTime(1,0,4,college.workingDays);
     college.Time[4].ReserveTime(2,2,4,college.workingDays);
     college.Time[4].ReserveTime(3,0,2,college.workingDays);
     college.Time[4].ReserveTime(4,2,4,college.workingDays);


}

#endif // TEST3_
