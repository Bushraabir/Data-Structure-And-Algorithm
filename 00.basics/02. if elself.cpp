// Problem:
/* 
Given marks of a student, print on the screen:

    Grade A if marks >= 90
    Grade B if marks >= 70
    Grade C if marks >= 50
    Grade D if marks >= 35
    Fail, otherwise.
*/


#include <iostream>
using namespace std;

class Solution {
public:
    void studentGrade(int marks) {
        if (marks >= 90)
            cout << "Grade A";
        else if (marks >= 70)
            cout << "Grade B";
        else if (marks >= 50)
            cout << "Grade C";
        else if (marks >= 35)
            cout << "Grade D";
        else
            cout << "Fail";
    }
};

int main() {
    Solution obj;
    int marks;

    cout << "Enter student's marks: ";
    cin >> marks;

    obj.studentGrade(marks);

    return 0;
}
