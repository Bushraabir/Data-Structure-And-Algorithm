# DSA Practice Problems in C++

This repository contains my personal solutions to various Data Structures and Algorithms (DSA) problems. Each file includes only the solution code without detailed problem descriptions, serving as a reference for my practice and learning.

## Overview

I'm following along with a [YouTube playlist](https://www.youtube.com/playlist?list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt) that guides through multiple DSA problems. This repository reflects the practices and learnings from that series.

## Repository Structure

- **Problem Files:** Each problem is contained in a single `.cpp` file, with the filename typically indicating the problem.
- **Language:** All solutions are implemented in C++.

## Example Code

Below is an example demonstrating nested loops in C++:

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i <= 3; i++) {
        for (int j = 1; j < 5; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
```

## How to Compile and Run

To compile and run any of the C++ files, ensure you have a C++ compiler like `g++` installed. For example:

```bash
g++ filename.cpp -o output
./output
```

Replace `filename.cpp` with the actual file name and `output` with your desired output executable name.

## Notes

- **Personal Practice:** This repository is solely for my personal practice and learning.
- **Contributions:** Contributions and suggestions for improvements are welcome.

Happy coding! :D
