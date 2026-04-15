#include "ReadinputFromFile.h"

#include <fstream>
#include <sstream>

#include "ReadinputFromFile.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void readInputFromFile(College& college, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;

    // Helper lambda to skip comments and empty lines
    auto skipCommentsAndEmptyLines = [&]() -> bool {
        while (getline(inputFile, line)) {
            line.erase(0, line.find_first_not_of(" \t")); // Trim leading spaces
            if (!line.empty() && line[0] != '#') {
                return true;
            }
        }
        return false;
    };

    // Read basic college information
    if (!skipCommentsAndEmptyLines()) {
        cout << "Error: Missing college details!" << endl;
        return;
    }
    stringstream(line) >> college.numYears;

    if (!skipCommentsAndEmptyLines()) {
        cout << "Error: Missing start time and max study hours!" << endl;
        return;
    }
    stringstream(line) >> college.startTime >> college.maxStudyHoursPerDay;

    if (!skipCommentsAndEmptyLines()) {
        cout << "Error: Missing sports day and start hour!" << endl;
        return;
    }
    stringstream(line) >> college.sportsDay >> college.sportsStartHour;
    college.sportsEndHour = college.sportsStartHour + 2;

    // Read professors
    if (!skipCommentsAndEmptyLines()) {
        cout << "Error: Missing number of professors!" << endl;
        return;
    }
    int numProfessors;
    stringstream(line) >> numProfessors;
    college.professors.resize(numProfessors);

    for (int i = 0; i < numProfessors; ++i) {
        if (!skipCommentsAndEmptyLines()) {
            cout << "Error: Missing professor data for professor " << i + 1 << "!" << endl;
            return;
        }
        stringstream ss(line);
        ss >> college.professors[i].name;
        int daysAvailable;
        for (int j = 0; j < 5; ++j) {
            ss >> daysAvailable;
            if (daysAvailable) {
                college.professors[i].availableDays.push_back(j);
            }
        }
    }
    cout << "Successfully read professors.\n";

    // Read assistants
    if (!skipCommentsAndEmptyLines()) {
        cout << "Error: Missing number of assistants!" << endl;
        return;
    }
    int numAssistants;
    stringstream(line) >> numAssistants;
    college.assistants.resize(numAssistants);

    for (int i = 0; i < numAssistants; ++i) {
        if (!skipCommentsAndEmptyLines()) {
            cout << "Error: Missing assistant data for assistant " << i + 1 << "!" << endl;
            return;
        }
        stringstream ss(line);
        ss >> college.assistants[i].name;
        int daysAvailable;
        for (int j = 0; j < 5; ++j) {
            ss >> daysAvailable;
            if (daysAvailable) {
                college.assistants[i].availableDays.push_back(j);
            }
        }
    }
    cout << "Successfully read assistants.\n";

    // Read courses
    if (!skipCommentsAndEmptyLines()) {
            cout << "Error: Missing number of courses for year "  << "!" << endl;
            return;
        }
    int numCourses;
    stringstream(line) >> numCourses;
    college.courses.resize(college.numYears,vector<Course>(numCourses));
    for (int year = 0; year < college.numYears; ++year) {

        for (int i = 0; i < numCourses; ++i) {
            if (!skipCommentsAndEmptyLines()) {
                cout << "Error: Missing course data for year " << year + 1 << ", course " << i + 1 << "!" << endl;
                return;
            }
            stringstream ss(line);
            Course& course = college.courses[year][i];
            ss >> course.name >> course.year >> course.lectureHoursPerWeek
               >> course.classHoursPerWeek >> course.specificPlaceRequired
               >> course.requiredPlace
               >> course.prof >> course.assis;
        }
    }
    cout << "Successfully read courses.\n";

    // Read rooms
    if (!skipCommentsAndEmptyLines()) {
        cout << "Error: Missing number of rooms!" << endl;
        return;
    }
    int numRooms;
    stringstream(line) >> numRooms;
    college.rooms.resize(numRooms);

    for (int i = 0; i < numRooms; ++i) {
        if (!skipCommentsAndEmptyLines()) {
            cout << "Error: Missing room data for room " << i + 1 << "!" << endl;
            return;
        }
        stringstream ss(line);
        ss >> college.rooms[i].name;
    }
    cout << "Successfully read rooms.\n";

    college.schedule.resize(college.numYears,vector<ScheduleSlot>(20));
    for(int i=0;i<college.numYears;i++)
    {
       college.Time[i].ReserveTime(college.sportsDay,college.sportsStartHour-college.startTime,college.sportsEndHour-college.startTime,college.workingDays); //for sports hours
    }
    college.workingDays={0,1,2,3,4};


    inputFile.close();
    cout << "Input successfully read from " << filename << endl;
}
