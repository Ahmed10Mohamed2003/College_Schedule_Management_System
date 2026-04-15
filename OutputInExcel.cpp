#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "structure.h"


// Function to save the schedule to a CSV file
void saveScheduleToCSV(const College& college, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write header row with tabs for better visual alignment in Excel or Sheets
    file << "Year\tDay\tStart Hour\tEnd Hour\tCourse\tProfessor\tRoom\tTeacher\n";

    // Write schedule data for each year
    for (int year = 0; year < college.numYears; ++year) {
        for (const auto& slot : college.schedule[year]) {
            file << year + 1 << "\t"  // Year (1-based)
                 << slot.day << "\t"    // Day (0=Sunday, 1=Monday, ..., 4=Thursday)
                 << slot.startHour << "\t" // Start Hour
                 << slot.endHour << "\t"   // End Hour
                 << slot.course << "\t"    // Course
                 << slot.professor << "\t" // Professor Name
                 << slot.room << "\t"      // Room Name
                 << slot.teacher << "\n"; // Teacher (1 for professor, 2 for assistant)
        }
    }

    file.close();
    std::cout << "Schedule saved to CSV file!" << std::endl;
}
