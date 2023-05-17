#include <iostream>
#include <string>

using namespace std;

// count all the specific char in the whole array of strings
int countAllSpecificChars(string sArr[], int arrLength, char specificChar) {
    int count = 0; //variable count wasnt initialized
    for (int i = 0; i < arrLength; i++)//"<="changed to "<"
        for (int j = 0; j < sArr[i].size(); j++)//"<="changed to "<"
            // if the jth char of the string is the specific char
            if (sArr[i][j] == specificChar)//"="changed to "=="
                count++;
    return count;
}

int main() {
    string sArr[4] = {
            "I am",
            "in",
            "ap",
            "class"
    };
    char findIt;
    cin >> findIt;
    cout << countAllSpecificChars(sArr, 4, findIt);
}