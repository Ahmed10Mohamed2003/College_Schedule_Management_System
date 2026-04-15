#ifndef OUTINEXCEL_
#define OUTINEXCEL_
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "structure.h"

using namespace std;

// Function to save the schedule to a CSV file with checks for missing data
void saveScheduleToCSV(const College& college, const string& filenameBase) {
    for (int year = 0; year < college.numYears; ++year) {
        ofstream file(filenameBase + "_Year" + to_string(year + 1) + ".csv");
        if (!file) {
            cout << "Error opening file for Year " << year + 1 << "!" << endl;
            continue;
        }

        // Write header row: days of the week (e.g., Monday, Tuesday, ...)
        file << "Day,8AM,9AM,10AM,11AM,12PM,1PM,2PM,3PM,4PM\n";

        // Write schedule data for each year
        for (int day = 0; day < 5; ++day) { // Iterate over days (0=Sunday to 4=Thursday)
            file << (day == 0 ? "Sunday" : day == 1 ? "Monday" : day == 2 ? "Tuesday" : day == 3 ? "Wednesday" : "Thursday");

            // Write slots for each hour of the day
            for (int hour = 8; hour <= 16; ++hour) {
                bool slotFound = false;

                for (vector<ScheduleSlot>::const_iterator it = college.schedule[year].begin(); it != college.schedule[year].end(); ++it) {
                    if (it->day == day && it->startHour == hour) {
                        file << "," << it->course
                             << " (" << it->professor
                             << ") "<<it->room;
                        slotFound = true;
                        break;
                    }
                }

                if (!slotFound) {
                    file << ", "; // Empty slot for that hour
                }
            }

            file << "\n";
        }

        file.close();
        cout << "Year " << year + 1 << " schedule saved to CSV file!" << endl;
    }
}

#endif
