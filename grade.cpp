// source files for grade functions
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using namespace std;

double grade(double midterm, double final, double homework){
  return 0.2*midterm + 0.4*final + 0.4*homework;
}

double grade(double midterm, double final, const vector<double>& hw){
  if (hw.size() == 0)
    throw domain_error("Student has submitted no homework grades");
  return grade(midterm, final, median(hw));
}

double grade(const Student_info& s){
  return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s){
  return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> fail;
  vector<Student_info>::size_type i = 0;
  // store students with failing grade in fail
  while (i != students.size()) {
    if (fgrade(students[i])) {
      // add student to vector of fails
      fail.push_back(students[i]);
      // remove student record from vector
      students.erase(students.begin() + i);
    } else
      ++i;
  }
      return fail;
}