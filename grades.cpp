/* Computing student grades example from "Accelerated C++" 
   by Andrew Koenig and Barbara E. Moo */

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

struct Student_info {
  string name;
  double midterm, final;
  vector<double> homework;
}; // note the semicolon--it's required

bool compare(const Student_info& x, const Student_info& y){
  return x.name < y.name;
}

double median(vector<double> vec){

  //store size of homework vector
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();

    if (size == 0){
      cout << "You must enter your grades."
	"Please try again." << endl;
      return 1;
    }

    //sort homework scores
    sort(vec.begin(), vec.end());

    //compute median score
    vec_sz mid = size/2;
    double median;

    median = size % 2 ? (vec[mid] + vec[mid-1])/2
                        : vec[mid];

    return median;

}
  
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

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw){

  if (in) {
    // get rid of previous contents
    hw.clear();
    // read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);

    // clear the stream so that input will work for the next student
    in.clear();
      
  }
  return in;
}

istream& read(istream& is, Student_info& s){
  //read and store the student's name and midterm and final exam grades
  is >> s.name >> s.midterm >> s.final;

  read_hw(is, s.homework);
  return is;
}

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
