#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        if(s.length() > 1){
            int first = 0, last = s.length()-1;
            while(last > first){
                char c = s.at(last);
                s.at(last--) = s.at(first);
                s.at(first++) = c;
            }
        }
        return s;
    }
};
int main(){
	cout << "-- Testing -- " << endl;
    string inputString = "Testing string";
    Solution mysolution;
	string reverse = mysolution.reverseString(inputString);
	
    cout << "Final output: "<< endl;
    cout << inputString << "  =>  " << reverse << endl << endl;
	return 0;
}
