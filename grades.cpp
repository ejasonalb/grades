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
    double x;
    vector<double> homework;

    // invariant
    while (cin >> x){
        homework.push_back(x);
    }
    
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << grade(midterm, final, median(homework))
         << setprecision(prec) << endl;

    return 0;
}
