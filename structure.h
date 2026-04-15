#ifndef STRUCTURE_H_
#define STRUCTURE_H_

#include <iostream>
#include <vector>
#include <string>
#include "ReservedTimeTeacher.h"
#include "ReservedRoom.h"
#include <bits/stdc++.h>
using namespace std;
//global vector to calc number of hours per day
struct Professor {
    string name;
    vector<int> availableDays;
    ReservedTimeTeacher Time;
};

struct Assistant {
    string name;
    vector<int> availableDays;
    ReservedTimeTeacher Time;
    int flag=0;
};

struct Course {
    string name;
    int year; //1 , 2, 3 ,4 ,5
    int lectureHoursPerWeek; // 2 or 3
    int classHoursPerWeek; // 2 or 3
    bool specificPlaceRequired; //true or false
    int requiredPlace;  //if
    int numLecturesPerWeek;  // only one class per course
    int prof;
    int assis;
    int done=0;
};

struct Room {
    string name;
    ReservedRoom Time;//will be modified later
};

struct ScheduleSlot {  // 1 hour per slot
    int day;
    int startHour;  //must entered in the order of inputs because of endHour depends on start hour
    int endHour=startHour+1;
    string course;
    string professor;
    string room;
    int teacher;
};

struct College {
    int numYears;
    vector<vector<Course>> courses; //each row represent year courses
    vector<Professor> professors;
    vector<Assistant> assistants;
    vector<Room> rooms;
    vector<vector<ScheduleSlot>> schedule; //the whole table
    int startTime;  //8Am for example
    int maxStudyHoursPerDay;  //the importance of this not to fill only two days and let the others empty
    int sportsDay;
    int sportsStartHour;
    int sportsEndHour=sportsStartHour+2;
    vector<int> workingDays={0,1,2,3,4};  // sunday =0                  thursday =4
    vector<int> HoursDay={0,0,0,0,0};
    ReservedTimeTeacher Time[5];
    int hours;
};
#endif
