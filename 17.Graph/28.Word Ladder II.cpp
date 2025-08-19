/*
 * Problem Statement: Word Ladder II - All Shortest Transformation Sequences Using BFS
 *
 * You are given a start word, a target word, and a list of unique words of equal length.
 * The goal is to transform the start word into the target word by changing exactly
 * one character at a time, such that each intermediate word exists in the word list.
 * Unlike Word Ladder I, you need to return all possible shortest transformation sequences.
 *
 * Task: Return a vector of vectors of strings, where each inner vector represents
 *       one shortest transformation sequence. If no sequence exists, return an empty vector.
 *
 * Key Observations:
 * - Each valid transformation represents a unit step in an unweighted graph.
 * - BFS explores the graph level by level, ensuring shortest sequences are found first.
 * - Words should only be removed from the word set after processing an entire BFS level
 *   to allow multiple shortest paths through the same intermediate word.
 *
 * Intuition:
 * 1. Convert the word list into an unordered_set for O(1) lookup.
 * 2. Initialize a queue storing vectors of strings (sequences), starting with {startWord}.
 * 3. Initialize a level counter and a vector used_on_level to track words used at current BFS level.
 * 4. While the queue is not empty:
 *     - Dequeue the current sequence.
 *     - If its length exceeds the current level:
 *         - Increment level.
 *         - Remove all words in used_on_level from the word set.
 *         - Clear used_on_level.
 *     - For the last word in the sequence:
 *         - If it is the target, add the sequence to ans if it is shortest.
 *         - Otherwise, generate all valid one-letter transformations:
 *             - For each new word in the set:
 *                 - Append it to the current sequence and enqueue.
 *                 - Add it to used_on_level.
 *                 - Pop it back to restore the sequence for other transformations.
 * 5. Return ans containing all shortest sequences.
 *
 * Time Complexity:
 * - Highly input-dependent; baseline is O(N * WordLength * 26 * Number_of_Shortest_Paths),
 *   due to generating neighbors for each word and copying sequences in the queue.
 *
 * Space Complexity:
 * - O(N * WordLength) for word set.
 * - O(Number_of_Shortest_Paths * Max_Path_Length * WordLength) for queue and ans storage.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// BFS to find all shortest transformation sequences (Word Ladder II)
// ---------------------------
vector<vector<string>> wordLadderAllSequences(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    vector<vector<string>> ans;
    if (wordSet.find(endWord) == wordSet.end()) return ans;

    queue<vector<string>> q;
    q.push({beginWord});
    int level = 1;
    vector<string> used_on_level;
    used_on_level.push_back(beginWord);

    while (!q.empty()) {
        vector<string> currentSequence = q.front(); q.pop();

        if (currentSequence.size() > level) {
            level++;
            for (const string &w : used_on_level) wordSet.erase(w);
            used_on_level.clear();
        }

        string currentWord = currentSequence.back();
        if (currentWord == endWord) {
            if (ans.empty() || currentSequence.size() == ans[0].size())
                ans.push_back(currentSequence);
            continue;
        }

        for (int i = 0; i < currentWord.size(); i++) {
            char originalChar = currentWord[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                currentWord[i] = ch;
                if (wordSet.count(currentWord)) {
                    currentSequence.push_back(currentWord);
                    q.push(currentSequence);
                    used_on_level.push_back(currentWord);
                    currentSequence.pop_back();
                }
            }
            currentWord[i] = originalChar;
        }
    }

    return ans;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    string startWord = "hit";
    string targetWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> sequences = wordLadderAllSequences(startWord, targetWord, wordList);

    if (!sequences.empty()) {
        cout << "All shortest transformation sequences:\n";
        for (auto &seq : sequences) {
            for (auto &word : seq) cout << word << " ";
            cout << "\n";
        }
    } else {
        cout << "No transformation sequence exists.\n";
    }

    return 0;
}
