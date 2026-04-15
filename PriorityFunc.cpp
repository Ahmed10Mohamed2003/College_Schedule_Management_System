#include "PriorityFunc.h"

void Priorit_Teacher(College & college ,int Teacher_Type)
{
if(Teacher_Type==Prof)
{
    int i=0;
    int n=college.professors.size();
   int pri_prof[n];
    int last[n];
   for(int i=0;i<n;i++)
    {
        pri_prof[i]=0;
        last[i]=i;
    }

   for(int i=0;i<college.numYears;i++)
   {
      int courses=6;
      for(int j=0;j<courses;j++)
      {
          pri_prof[college.courses[i][j].prof]+=(college.courses[i][j].lectureHoursPerWeek*college.courses[i][j].numLecturesPerWeek);
      }
   }

    //sorting decreasing order

    for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (pri_prof[j] < pri_prof[j + 1]) { // Sort in descending order
            // Swap in `pri_ass`
            int temp = pri_prof[j];
            pri_prof[j] = pri_prof[j + 1];
            pri_prof[j + 1] = temp;

            // Swap corresponding indices in `last`
            int tempIndex = last[j];
            last[j] = last[j + 1];
            last[j + 1] = tempIndex;
        }
    }
}
    //cout<<endl<<pri_ass[0]<<endl;
    //cout<<endl<<last[0]<<endl;

for(int k=0;k<n;k++)
    {
        for( i;i<college.numYears;i++)
        {
          int courses=college.courses[0].size();
          int x=0;
          for(int j=0;j<courses;j++)
           {
              if(college.courses[i][j].prof==last[k])
                {
                    swap(college.courses[i][j],college.courses[i][x]);
                    x++;
                }

           }
        }
    }
}
else
{
    int i=0;
   int n=college.assistants.size();
   int pri_ass[n];
    int last[n];
   for(int i=0;i<n;i++)
    {
        pri_ass[i]=0;
        last[i]=i;
    }

   for(int i=0;i<college.numYears;i++)
   {
      int courses=6;
      for(int j=0;j<courses;j++)
      {
          pri_ass[college.courses[i][j].assis]+=college.courses[i][j].classHoursPerWeek;
      }
   }

    //sorting decreasing order

    for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (pri_ass[j] < pri_ass[j + 1]) { // Sort in descending order
            // Swap in `pri_ass`
            int temp = pri_ass[j];
            pri_ass[j] = pri_ass[j + 1];
            pri_ass[j + 1] = temp;

            // Swap corresponding indices in `last`
            int tempIndex = last[j];
            last[j] = last[j + 1];
            last[j + 1] = tempIndex;
        }
    }
}
    //cout<<endl<<pri_ass[0]<<endl;
    //cout<<endl<<last[0]<<endl;

for(int k=0;k<n;k++)
    {
        for(i;i<college.numYears;i++)
        {
          int courses=college.courses[0].size();
          int x=0;
          for(int j=0;j<courses;j++)
           {
              if(college.courses[i][j].assis==last[k])
                {
                    swap(college.courses[i][j],college.courses[i][x]);
                    x++;
                }

           }
        }
    }

}
}
