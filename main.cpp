#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;




int main() {

// Repository of possible characters
        
    vector<char> upcase = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    vector<char> lowcase = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    vector<char> nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    vector<char> characters = {'~', '`', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', 
    '=', '+', '[', ']', '{', '}', '\\', '/', '<', '>', ',', '.', '/', '?'};

// Ask how many characters they want

    cout << "How many characters do you want your password to be?" << endl;

// User Enters, saves to integer x
    int x;
    cin >> x;

// Ask what type of characters the use wants or needs


    cout << "What type of characters do you want included?" << 
    "The options include: upercase, lowercase, numbers, and misc" << 
    "Type your desired characters, one at a time, pressing enter after each one" << 
    "When finsihed, type: end-of-file" << endl;

// take in users inputs
    string word;
    vector<string> desiredchar;

    while (cin >> word) {
            if (word == "end-of-file") {
            break;
        }
        desiredchar.push_back(word);
    }

    cout << "thanks. please provide a ranom number, it will make this process more secure" << endl;

    int rndnum;
    cin >> rndnum;

    cout << "okay, thanks! now I can make you're password" << endl;

// Password generation

    int j;
    vector<vector<char> > userscharacters;
    vector<string>::iterator iter1 = desiredchar.begin();

    for (iter1; iter1 != desiredchar.end(); iter1++) {
        if (*iter1 == "upercase") {
            userscharacters.push_back(upcase);
        } else if (*iter1 ==  "lowercase"  ) {
            userscharacters.push_back(lowcase);
        } else if (*iter1 ==   "numbers"  ) {
            userscharacters.push_back(nums);
        }else if (*iter1 ==  "misc" ) {
            userscharacters.push_back(characters);
        } else {
            cout << "Please enter a propper type" << endl;
        }

    }

    int sizeofN = userscharacters.size();
    
    srand(time(0));

    string password;
    for (int k = 0; k != x; k++) {
        int process = rand()%sizeofN;
        int proces2 = rand()%userscharacters[process].size();
        password.push_back(userscharacters[process][proces2]);
    }

    cout << "Your password is: " << password << endl;

    return 0;
}