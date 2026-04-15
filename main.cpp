#include <iostream>
#include <vector>
#include <string>
#include "ReservedTimeTeacher.h"
#include "ReservedRoom.h"
#include "structure.h"
#include "PlaceClasses.h"
#include "PriorityFunc.h"
#include "OutputInExcel.h"
#include <bits/stdc++.h>
#include "CheckNotReserved.h"
#include "ReadInputFromFile.h"
#include "PlaceCources.h"
#include "ConflictRooms.h"
#include "CheckConflictTeacher.h"
#include "Test1.h"
#include "Test2.h"
#include "Test3.h"
#include "Test4.h"
#include "Test5.h"

#define Prof 1
#define Assis 0
using namespace std;

void outputClassSchedule(const College& college,int y) {
    cout << "Class Schedule (Only Classes):\n";

    // Loop through the schedule and print details for class slots
    for (const auto& slot : college.schedule[y]) {
        if (slot.teacher==1) {  // Only print the slots for classes
            cout << "Day " << slot.day << ", "
                      << "Course: " << slot.course << ", "
                      << "Class by: " << slot.professor << ", "<<"Room: "<<slot.room<<","
                      << "Time: " << slot.startHour << " - " << slot.endHour << "\n";
        }
    }
}

int main() {
    College college;
    //Test2(college);

   readInputFromFile(college,"testavilable2_3.txt");

   Priorit_Teacher(college,Prof);
   for(int i = 0; i<college.numYears; i++)
   {
        PlaceLecture(college,i);

   }


   Priorit_Teacher(college,Assis);


   for(int i = 0; i<college.numYears; i++)
   {
       placeClasses(college, i);

   }


   for(int i = 0; i<college.numYears; i++)
   {
       cout<<"\n\n   year number "<<i+1<<"\n\n";
       outputClassSchedule(college,i);
   }





    checkRoomConflicts(college.schedule);
     cout<<"\n\n\n\n\n";

    checkTeacherConflicts(college.schedule);
    cout<<"\n\n\n\n\n";

    checkUnreservedCourses(college);
    cout<<"\n\n\n\n\n";

    saveScheduleToCSV(college,"scheudle.csv");

    return 0;
}
