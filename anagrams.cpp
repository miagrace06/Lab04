#include <iostream> //For input/out operations 
#include <string> //For string data type 
#include <cctype> //For character manipulation functions 
using namespace std;

//Function to check if two words are anagrams
// Takes two strings as input and retuns true if they are anagrams, false if they are not
bool checkAnagram(string word1, string word2){
	int count[26] = {0}; //Array to store character counts, size 26 for each letter of alphabet 

	// Process first string 
	//Increment counter for each letter found 
	for (char &c : word1){
		if (isalpha(c)) {  // Check if character is a letter 
			count [tolower(c) - 'a']++;  // Convert to lowercase and increment count 
			// subtracting 'a' converts character to 0-25 index 
		}
	}
	//Process second string 
	//Decrement counter for each letter found 
	for (char &c : word2){
		if (isalpha(c)) { // Check if character is a letter 
			count[tolower(c) - 'a'] --; //Convert to lowercase and decrement count
		}
	}
	// Check if all counters are zero
	// If any counter is not zero, strings are not anagrams 
	for (int i = 0; i < 26; i++){
		if (count[i] != 0){
			return false;
		}
	}
	return true;
	//If we reach here, all counters were zero, so strings are anagrams 
}

int main()
{
	//Get input from user 
	string text1, text2;
	cout << "Enter first string:\n ";
	getline(cin, text1); // Using getline to read entire line including spaces 
	cout << "Enter second string:\n";
	getline(cin, text2);

	// Check if strings are anagrams and output result
	if (checkAnagram(text1, text2)){
		cout << "The strings are anagrams." << endl;
	}else{
		cout << "The strings are not anagrams." << endl;
	}
	return 0;
}
