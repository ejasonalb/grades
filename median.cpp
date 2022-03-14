// source file for the median function
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "median.h"

using namespace std;

double median(vector<double> vec){

    //store size of input vector
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();

    if (size == 0)
      throw domain_error("median of an empty vector");

    //sort data
    sort(vec.begin(), vec.end());

    //compute median
    vec_sz mid = size/2;
    double median;

    median = size % 2 ? (vec[mid] + vec[mid-1])/2
                        : vec[mid];

    return median;

}
