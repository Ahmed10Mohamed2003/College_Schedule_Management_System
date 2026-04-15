#ifndef CONFLICTROOMS_
#define CONFLICTROOMS_


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "structure.h"
using namespace std;
void checkRoomConflicts(const vector<vector<ScheduleSlot>>& schedule) {
    bool conflictFound = false;

    // Iterate over all years
    for (size_t year1 = 0; year1 < schedule.size(); ++year1) {
        for (size_t i = 0; i < schedule[year1].size(); ++i) {
            const ScheduleSlot& slot1 = schedule[year1][i];

            // Skip empty slots or slots where the teacher flag is not set
            if (slot1.teacher != 1) continue;

            // Compare with all other slots in the same year and other years
            for (size_t year2 = year1; year2 < schedule.size(); ++year2) {
                size_t jStart = (year1 == year2) ? i + 1 : 0; // Avoid duplicate comparisons within the same year
                for (size_t j = jStart; j < schedule[year2].size(); ++j) {
                    const ScheduleSlot& slot2 = schedule[year2][j];

                    // Skip empty slots or slots where the teacher flag is not set
                    if (slot2.teacher != 1) continue;

                    // Check if the same room is reserved at overlapping times
                    if (slot1.room == slot2.room && slot1.day == slot2.day) {
                        // Check for time overlap
                        if ((slot1.startHour < slot2.endHour && slot1.endHour > slot2.startHour)) {
                            cout << "Conflict detected: "
                                      << "Year " << year1 + 1 << ", Course: " << slot1.course
                                      << " overlaps with Year " << year2 + 1 << ", Course: " << slot2.course
                                      << " in Room: " << slot1.room << " on Day: " << slot1.day
                                      << " at times " << slot1.startHour << "-" << slot1.endHour
                                      << " and " << slot2.startHour << "-" << slot2.endHour << ".\n";
                            conflictFound = true;
                        }
                    }
                }
            }
        }
    }

    if (!conflictFound) {
        cout << "No room conflicts detected in the schedule.\n";
    }
}



#endif // CONFLICTROOMS_

