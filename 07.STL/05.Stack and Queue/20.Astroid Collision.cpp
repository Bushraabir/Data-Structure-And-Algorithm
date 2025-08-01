/*
 * Problem Statement: Asteroid Collisions
 *
 * You are given an array of integers where each element represents an asteroid.
 * - The absolute value indicates the size.
 * - The sign indicates direction:
 *      - Positive  => moving right
 *      - Negative  => moving left
 *
 * Task: Determine the final state of all asteroids after all possible collisions.
 *
 * Collision Rules:
 * - Only a right-moving asteroid (+ve) can collide with a left-moving one (-ve).
 * - Same-direction asteroids never collide.
 * - When two asteroids collide:
 *      - Smaller one is destroyed.
 *      - If same size, both are destroyed.
 *      - Larger one survives.
 *
 * Intuition:
 * - Use a list as a stack (`vector<int>`) to simulate the flow.
 * - A negative asteroid will interact with previous right-moving asteroids.
 * - This requires accessing the last pushed element repeatedly => LIFO behavior => use stack.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;  // acts as a stack

    for (int current : asteroids) {
        bool destroyed = false;

        // Handle collisions only when current is moving left (<0) and stack top is right (>0)
        while (!st.empty() && current < 0 && st.back() > 0) {
            if (abs(current) > st.back()) {
                st.pop_back();  // destroy the right-moving asteroid and keep checking
            } else if (abs(current) == st.back()) {
                st.pop_back();  // both are destroyed
                destroyed = true;
                break;
            } else {
                destroyed = true;  // current is destroyed
                break;
            }
        }

        if (!destroyed) {
            st.push_back(current);
        }
    }

    return st;  // final state of asteroids
}

int main() {
    vector<int> asteroids = {5, 10, -5};

    vector<int> result = asteroidCollision(asteroids);

    cout << "Final state: ";
    for (int a : result) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
