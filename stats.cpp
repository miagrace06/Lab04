#include <iostream> // for cout, cin, endl
#include <cmath>    // for pow -- the only one you're allowed to use from this lib
#include <iomanip>  // for setprecision, setw -- the only ones you're allowed to use from this lib
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST USE THESE (do not remove):
void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int* array, int size);
double stddev(int* array, int size);

int main() {
    // Sets the printing of floating-point numbers
    // to show only 2 places after the decimal point
    cout << fixed << showpoint;
    cout << setprecision(2);

    int size; 
    do {
	    cout << "Enter number of grades: ";
	    cin >> size;
	    if (size <=0){
		    cout<< "Error!"<< endl;
		    exit(1);
	    }

    }while (size <=0);

    int* grades = new int[size];
    
    cout << "Enter grades (each on a new line:" << endl;
    for (int i = 0; i < size; i++) {
	    cin >> grades[i];
    }
    cout << "Here are some statistics:"<<endl;
    cout << "Average: " << average(grades, size) <<endl;
    cout <<"Median: " <<median(grades, size) << endl;
    cout<< "StdDev: " << stddev(grades, size) << endl;

    delete[] grades;
    return 0;
}

// This is bubbleSort - it is given for you to use.
// Pre-Condition:: It takes in a dynamic int array and its size
// Post-Condition: It sorts the array in ascending order of its values
void bubbleSort(int *array, int size) {
  int temp;
  for (int i = size-1; i >= 0; i--) {
    for (int j = 1; j <= i; j++) {
      if (array[j-1] > array[j]) {
        temp = array[j-1];
        array[j-1] = array[j];
        array[j] = temp;
      } // if
    } // for j
  } // for i
}

double average(int *array, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++){
		sum += array[i];
	}
	return sum / size;
}
double median (int* array, int size) {
	bubbleSort(array, size);
	if (size % 2 != 0) {
		return array[size /2];
	}
	else {
		return (array[(size - 1) / 2] + array[size / 2]) / 2.0;
	}
}
double stddev (int* array, int size){
	double mean = average(array, size);
	double sum_squares = 0;
	for (int i = 0; i < size; i++) {
		sum_squares += pow(array[i] - mean, 2);
	}
	return pow(sum_squares / (size - 1), 0.5);
}
// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)
