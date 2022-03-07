/* Computing student grades examples from  Accelerated C++ 
   by Andrew Koenig and Barbara E. Moo */

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>

using namespace std;

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

// read homework grades from an input stream into a vector<double>
istream& readhw(istream& in, vector<double>& hw){

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

int main(){
  
    // ask for student's name
    cout << "Please enter you name: ";
    string name;
    cin >> name;
    cout << "Hello, " + name + "!" << endl;

    // ask for the midterm and final grades
    cout << "Please enter you midterm and final grades: "; 
    double midterm, final;
    cin >> midterm >> final;

    // ask for homework grades
    cout << "Enter all of your homework grades, "
            "followed by end-of-file: ";

    // variable into which to read grades
    vector<double> homework;

    // read the homework grades
    readhw(cin, homework);

    // compute and print final grade, if possible
    try {
      double final_grade = grade(midterm, final, homework);
      streamsize prec = cout.precision();
      cout << "Your final grade is " << setprecision(3)
	   << final_grade << endl;
    }

    catch (domain_error) {

      cout << endl << "You must enter your grades. "
	" Please try again." << endl;
      return 1;
     }

    return 0;
}
