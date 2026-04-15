#ifndef CHECKCONFLICTTEACHER_
#define CHECKCONFLICTTEACHER_


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "structure.h"

using namespace std;
void checkTeacherConflicts(const vector<vector<ScheduleSlot>>& schedule) {
    bool conflictFound = false;

    // Iterate over all years
    for (size_t year1 = 0; year1 < schedule.size(); ++year1) {
        for (size_t i = 0; i < schedule[year1].size(); ++i) {
            const ScheduleSlot& slot1 = schedule[year1][i];

            // Skip empty or unused slots (teacher flag not set)
            if (slot1.teacher != 1) continue;

            // Compare with all other slots in the same year and other years
            for (size_t year2 = year1; year2 < schedule.size(); ++year2) {
                size_t jStart = (year1 == year2) ? i + 1 : 0; // Avoid duplicate comparisons within the same year
                for (size_t j = jStart; j < schedule[year2].size(); ++j) {
                    const ScheduleSlot& slot2 = schedule[year2][j];

                    // Skip empty or unused slots (teacher flag not set)
                    if (slot2.teacher != 1) continue;

                    // Check for conflicts with professors
                    if (!slot1.professor.empty() && slot1.professor == slot2.professor && slot1.day == slot2.day) {
                        // Check for overlapping times
                        if (slot1.startHour < slot2.endHour && slot1.endHour > slot2.startHour) {
                            cout << "Professor Conflict detected:\n"
                                      << "Year " << year1 + 1 << ", Course: " << slot1.course
                                      << " overlaps with Year " << year2 + 1 << ", Course: " << slot2.course
                                      << " for Professor: " << slot1.professor << " on Day: " << slot1.day
                                      << " at times " << slot1.startHour << "-" << slot1.endHour
                                      << " and " << slot2.startHour << "-" << slot2.endHour << ".\n";
                            conflictFound = true;
                        }
                    }

                    // Check for conflicts with assistants
                    if (!slot1.room.empty() && slot1.room == slot2.room && slot1.day == slot2.day) {
                        if (slot1.startHour < slot2.endHour && slot1.endHour > slot2.startHour) {
                            cout << "Assistant Conflict detected:\n"
                                      << "Year " << year1 + 1 << ", Course: " << slot1.course
                                      << " overlaps with Year " << year2 + 1 << ", Course: " << slot2.course
                                      << " for Room: " << slot1.room << " on Day: " << slot1.day
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
        std::cout << "No conflicts found for Professors or Assistants in the schedule.\n";
    }
}











#endif // CHECKCONFLICTTEACHER_
