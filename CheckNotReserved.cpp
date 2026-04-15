

#include "CheckNotReserved.h"
using namespace std;

void checkUnreservedCourses(const College& college) {
    for (int year = 0; year < college.courses.size(); ++year) {
        for (int i = 0; i < college.courses[year].size(); ++i) {
            Course course = college.courses[year][i];
            if (course.done == 0) {
                cout << "Error: Course \"" << course.name
                     << "\" for year " << (year + 1)
                     << " is not scheduled." << endl;

                if (course.assis >= 0 && course.assis < college.assistants.size()) {
                    cout << "Assigned Assistant: \""
                         << college.assistants[course.assis].name << "\"" << endl;
                } else {
                    cout << "Assigned Assistant: Unknown or invalid index." << endl;
                }
            }
        }
    }
}

