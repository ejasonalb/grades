#include <iostream>
#include <iomanip>
#include <ios>
#include <string>

using namespace std;

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

    // the number of grades read so far
    int count = 0;
    double sum = 0;

    // a variable into which to read grades
    double x;

    // invariant
    while (cin >> x){
        ++count;
        sum += x;
    }

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2*midterm + 0.4*final + 0.4*sum/count
         << setprecision(prec) << endl;

    return 0;
}