# DSA Practice Problems in C++

This repository contains my personal solutions to various Data Structures & Algorithms (DSA) problems. Each file holds only the solution code without a detailed problem description—this is purely for my own practice and reference.

## Overview

I'm following along with a [YouTube playlist](https://www.youtube.com/playlist?list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt) that guides through multiple DSA problems. The repository reflects the practices and learnings from that series.

## Repository Structure

- **Problem Files:** Each problem is contained in a single file, with the file name typically indicating the problem.
- **Language:** All solutions are implemented in C++.

## Example Code

Below is an example code snippet demonstrating nested loops in C++:

```cpp
#include<iostream>
using namespace std;

int main(){
    for(int i = 0; i <= 3; i++){
        for(int j = 1; j < 5; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
How to Compile and Run
You can compile any of the C++ files using a C++ compiler like g++. For example:

bash
Copy
Edit
g++ filename.cpp -o output
Then, run the executable:

bash
Copy
Edit
./output
Notes
Personal Practice: This repository is solely for my personal practice and learning.

Contributions: Contributions and suggestions for improvements are welcome.
Happy coding ! :D