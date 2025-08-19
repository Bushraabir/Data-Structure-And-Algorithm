/*
 * Problem Statement: Word Ladder II - Optimized Approach Using BFS + Backtracking
 *
 * You are given a start word, a target word, and a list of unique words of equal length.
 * The goal is to transform the start word into the target word by changing exactly
 * one character at a time, such that each intermediate word exists in the word list.
 * Return all possible shortest transformation sequences.
 *
 * Optimized Approach:
 * - Step 1 (Forward BFS): Compute the minimum number of transformations (levels) to
 *   reach each word from the start word. Store each word's level in a map for fast lookup.
 * - Step 2 (Backward DFS): Backtrack from the target word to the start word following
 *   valid level transitions (level[current_word] - 1). Only paths that follow decreasing
 *   levels are explored, guaranteeing all shortest sequences without unnecessary branches.
 *
 * Key Observations:
 * - Separating BFS (level calculation) from DFS (path reconstruction) reduces memory
 *   usage and avoids copying sequences during BFS, preventing TLE.
 * - Backward DFS ensures exploration only along shortest paths.
 *
 * Time Complexity:
 * - BFS: O(N * WordLength * 26), where N = number of words in the list.
 * - DFS: O(Number_of_Shortest_Paths * Max_Path_Length * WordLength), highly input-dependent.
 *
 * Space Complexity:
 * - O(N * WordLength) for word set and level map.
 * - O(Number_of_Shortest_Paths * Max_Path_Length * WordLength) for storing sequences.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Forward BFS: Compute levels of all reachable words
// ---------------------------
unordered_map<string, int> bfsLevels(const string &beginWord, const string &endWord, unordered_set<string> &wordSet) {
    unordered_map<string, int> levelMap;
    queue<string> q;
    q.push(beginWord);
    levelMap[beginWord] = 0;

    while (!q.empty()) {
        string word = q.front(); q.pop();
        int currLevel = levelMap[word];
        wordSet.erase(word); // Prevent revisiting

        for (int i = 0; i < word.size(); i++) {
            char originalChar = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (wordSet.count(word)) {
                    levelMap[word] = currLevel + 1;
                    q.push(word);
                }
            }
            word[i] = originalChar;
        }
    }

    return levelMap;
}

// ---------------------------
// Backward DFS: Reconstruct all shortest paths
// ---------------------------
void dfsBacktrack(const string &currentWord, const string &beginWord,
                  unordered_map<string, int> &levelMap,
                  unordered_set<string> &wordSet,
                  vector<string> &sequence, vector<vector<string>> &ans) {
    sequence.push_back(currentWord);

    if (currentWord == beginWord) {
        vector<string> path(sequence.rbegin(), sequence.rend()); // reverse
        ans.push_back(path);
    } else {
        for (int i = 0; i < currentWord.size(); i++) {
            string tempWord = currentWord;
            char originalChar = tempWord[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                tempWord[i] = ch;
                if (levelMap.count(tempWord) && levelMap[tempWord] == levelMap[currentWord] - 1) {
                    dfsBacktrack(tempWord, beginWord, levelMap, wordSet, sequence, ans);
                }
            }
            tempWord[i] = originalChar;
        }
    }

    sequence.pop_back(); // backtrack
}

// ---------------------------
// MAIN FUNCTION: Optimized Word Ladder II
// ---------------------------
vector<vector<string>> wordLadderOptimized(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord)) return {};

    // Step 1: BFS to compute levels
    unordered_map<string, int> levelMap = bfsLevels(beginWord, endWord, wordSet);

    // Step 2: Backward DFS to build all shortest sequences
    vector<vector<string>> ans;
    vector<string> sequence;
    dfsBacktrack(endWord, beginWord, levelMap, wordSet, sequence, ans);

    return ans;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    string startWord = "hit";
    string targetWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> sequences = wordLadderOptimized(startWord, targetWord, wordList);

    if (!sequences.empty()) {
        cout << "All shortest transformation sequences (Optimized):\n";
        for (auto &seq : sequences) {
            for (auto &word : seq) cout << word << " ";
            cout << "\n";
        }
    } else {
        cout << "No transformation sequence exists.\n";
    }

    return 0;
}
