#include <string>

using namespace std;

string toUpper(const string& word) {
		string wordUpper = "";
		for (char x : word) {
			if (x >= 'a' and x <= 'z') {
				wordUpper += x - 32;
			} else  {
				wordUpper += x;
            }    
        }

        return wordUpper;
	}
