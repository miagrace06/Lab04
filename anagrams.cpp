#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Function to cehck if two words are anagrams
bool checkAnagram(string word1, string word2){
	int count[26] = {0};
	
	for (char &c : word1){
		if (isalpha(c)) {
			count [tolower(c) - 'a']++;
		}
	}
	for (char &c : word2){
		if (isalpha(c)) {
			count[tolower(c) - 'a'] --;
		}
	}
	for (int i = 0; i < 26; i++){
		if (count[i] != 0){
			return false;
		}
	}

	return true;
}

int main()
{
	string text1, text2;
	cout << "Enter first string: ";
	getline(cin, text1);
	cout << "Enter second string: ";
	getline(cin, text2);

	if (checkAnagram(text1, text2))
		cout << "The strings are anagrams." << endl;
	else
		cout << "The strings are not anagrams." << endl;
    
    return 0;
}

// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)
