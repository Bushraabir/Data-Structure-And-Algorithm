// Problem:
/*
Given the integer day denoting the day number, print on the screen which day of the week it is. Week starts from Monday and for values greater than 7 or less than 1, print Invalid.

Ensure only the 1st letter of the answer is capitalised.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void whichWeekDay(int day) {
        string week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        if (day >= 1 && day <= 7)
            cout << week[day - 1];
        else
            cout << "Invalid";
    }
};

int main() {
    Solution obj;
    int day;

    cout << "Enter day number: ";
    cin >> day;

    obj.whichWeekDay(day);

    return 0;
}
