#include <iostream> //for cout, cin, endl
#include <cmath>    //for pow -- the only one you're allowed to use from this lib
#include <iomanip>  //for setprecision, setw -- the only ones you're allowed to use from this lib
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST USE THESE (do not remove):
void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int* array, int size);
double stddev(int* array, int size);


bool isInteger(const string& input) {
    if (input.empty() || (!isdigit(input[0] && input[0] != '-')){
        return false; //Not a valid integer 
    }
    for (char c : input) {
        if (!isdigit(c) && c != '-') {
            return false:
		    }
    }
    return true;
	}
int main() {
    // Sets the printing of floating-point numbers
    // to show only 2 places after the decimal point
	cout << fixed << showpoint;
	cout << setprecision(2);
	
	int size;
	string input; 
	
	cout << "Enter number of grades: ";
	while (true){
		getline(cin, input);
		if (isInteger(input)){
			size = atoi(input.c_str());
			if (size > 0){
				break;
			}
		}
		cout << "Error!\n";
	}
	int* grades = new int[size]; //Dynamically allocate an array for grades 
	cout << "Enter grades (each on a new line)" << endl; //Prompt user for grades input
	for (int i = 0; i < size; i++) {
		while (true) {
			getline (cin, input);
			if (isInteger(input)) {
				grades[i] = atoi(input.c_str());
				break;
			}
			cout << "Error!\n";
		}
	}
// Output statistics 
	cout << "Here are some statistics:"<<endl;
	cout << "Average: " << average(grades, size) <<endl;
	cout <<"Median: " <<median(grades, size) << endl;
	cout<< "StdDev: " << stddev(grades, size) << endl;
// Deallocate the dynamically allocated array 
	delete[] grades;
	return 0; //End of the program 
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
// Function to calculate the average of an array 
double average(int *array, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++){
		sum += array[i]; // Sum of all grades 
	}return sum / size; //Return average of array 
}
//Function to calculate the median of an array 
double median (int* array, int size) {
	bubbleSort(array, size); //Sort the array first 
	if (size % 2 != 0) {
		// If odd, return the middle element 
		return array[size /2];
	}
	else {
		//If even, return the average of the two middle elements 
		return (array[(size - 1) / 2] + array[size / 2]) / 2.0;
	}
}
//Function to calculate the standard deviation of an array
double stddev (int* array, int size){
	double mean = average(array, size); //Calculate mean 
	double sum_squares = 0;
	for (int i = 0; i < size; i++) {
		//Sum the squares of the differences from the mean 
		sum_squares += pow(array[i] - mean, 2);
	}
	// Return the square root of the variance 
	return pow(sum_squares / (size - 1), 0.5);
}
