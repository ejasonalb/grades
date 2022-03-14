/* Computing student grades example from "Accelerated C++" 
   by Andrew Koenig and Barbara E. Moo */

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Student_info.h"
#include "grade.h"

using namespace std;

int main(){

    vector<Student_info> students;
    Student_info record;

    string::size_type maxlen = 0;

    //read and store the records and find the length of the longest name
    while (read(cin, record)){
      maxlen = max(maxlen, record.name.size());
      students.push_back(record);
    }

    //alphabetize records
    sort(students.begin(), students.end(), compare);

    cout << endl;
    
    for (vector<Student_info>::size_type i = 0;
    
    i != students.size(); ++i){
      
      // write the name, padded to maxlen+1 characters
      cout << setw(maxlen+1) << students[i].name << setw(maxlen);

      //compute and write the grade
      try {
        double final_grade = grade(students[i]);
        streamsize prec = cout.precision();
        cout << setprecision(3) << final_grade
        << setprecision(prec);
        } catch (domain_error e) {
          cout << e.what();
          }
          
          cout << endl;
    
    }

    return 0;
}
