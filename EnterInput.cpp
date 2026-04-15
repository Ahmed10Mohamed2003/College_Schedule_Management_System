/*#include <iostream>
#include <vector>
#include <string>
#include"EnterInput.h"

void getInputForCollege(College &college) {
    std::cout << "Enter number of years in college: ";
    std::cin >> college.numYears;

    std::cout << "Enter college start time (in hours, e.g., 8 for 8 AM): ";
    std::cin >> college.startTime;

    std::cout << "Enter maximum study hours per day: ";
    std::cin >> college.maxStudyHoursPerDay;

    std::cout << "Enter sports day (0=Monday, 1=Tuesday, etc.): ";
    std::cin >> college.sportsDay;

    std::cout << "Enter sports start hour: ";
    std::cin >> college.sportsStartHour;

    std::cout << "Enter sports end hour: ";
    std::cin >> college.sportsEndHour;

    int numWorkingDays;
    std::cout << "Enter number of working days: ";
    std::cin >> numWorkingDays;

    college.workingDays.resize(numWorkingDays);
    std::cout << "Enter the working days (0=Sunday, 1=Monday, etc.): ";
    for (int i = 0; i < numWorkingDays; ++i) {
        std::cin >> college.workingDays[i];
    }

    int numCourses;
    std::cout << "Enter number of courses: ";
    std::cin >> numCourses;
	college.courses[0].resize(numCourses);

    for (int i = 0; i < numCourses; ++i) {
        Course course;
        std::cout << "Enter course name: ";
        std::cin >> course.name;
        std::cout << "Enter year for the course: ";
        std::cin >> course.year;
        std::cout << "Enter lecture hours for the course: ";
        std::cin >> course.lectureHoursPerWeek;
        std::cout << "Enter class hours for the course: ";
        std::cin >> course.classHoursPerWeek;
		std::cout << "Enter professor of the course: ";
        std::cin >> course.prof;
		std::cout << "Enter Assistant of the course: ";
        std::cin >> course.assis;
        std::cout << "Does the course require a specific room? (1 for Yes, 0 for No): ";
        std::cin >> course.specificPlaceRequired;
        if (course.specificPlaceRequired) {
            std::cout << "Enter the specific room : ";
            std::cin >> course.requiredPlace;
        }
        std::cout << "Enter number of lectures per week: ";
        std::cin >> course.numLecturesPerWeek;

        //college.courses.push_back(course);
    }

    int numProfessors;
    std::cout << "Enter number of professors: ";
    std::cin >> numProfessors;
    college.professors.resize(numProfessors);
    for (int i = 0; i < numProfessors; ++i) {
        Professor prof;
        std::cout << "Enter professor's name: ";
        std::cin >> prof.name;

        int numAvailableDays;
        std::cout << "Enter number of available days for professor: ";
        std::cin >> numAvailableDays;

        prof.availableDays.resize(numAvailableDays);
        std::cout << "Enter available days: ";
        for (int j = 0; j < numAvailableDays; ++j) {
            std::cin >> prof.availableDays[j];
        }


        college.professors.push_back(prof);
    }

    int numAssistants;
    std::cout << "Enter number of assistants: ";
    std::cin >> numAssistants;
    college.assistants.resize(numAssistants);
    for (int i = 0; i < numAssistants; ++i) {
        Assistant assist;
        std::cout << "Enter assistant's name: ";
        std::cin >> assist.name;

        int numAvailableDays;
        std::cout << "Enter number of available days for Assistant: ";
        std::cin >> numAvailableDays;

        assist.availableDays.resize(numAvailableDays);
        std::cout << "Enter available days: ";
        for (int j = 0; j < numAvailableDays; ++j) {
            std::cin >> assist.availableDays[j];
        }

        college.assistants.push_back(assist);
    }

    int numRooms;
    std::cout << "Enter number of rooms: ";
    std::cin >> numRooms;
    college.rooms.resize(numRooms);
    for (int i = 0; i < numRooms; ++i) {
        Room room;
        std::cout << "Enter room name: ";
        std::cin >> room.name;
        college.rooms.push_back(room);
    }
}

*/
