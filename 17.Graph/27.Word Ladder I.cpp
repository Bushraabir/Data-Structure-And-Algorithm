/*
 * Problem Statement: Word Ladder I - Shortest Transformation Sequence Using BFS
 *
 * You are given a start word, a target word, and a list of unique words of equal length.
 * The goal is to transform the start word into the target word by changing exactly
 * one character at a time, such that each intermediate word exists in the word list.
 *
 * Task: Return the length of the shortest transformation sequence. If no sequence
 *       exists, return 0.
 *
 * Key Observations:
 * - Each valid transformation represents a unit step, modeling an unweighted graph.
 * - BFS is ideal because it explores transformations level by level, guaranteeing
 *   the shortest path when the target word is first encountered.
 * - Using an unordered_set allows O(1) average-time checks and also tracks visited words.
 *
 * Intuition:
 * 1. Convert the word list into an unordered_set for fast lookup and removal (visited tracking).
 * 2. Initialize a queue and enqueue the start word with sequence length 1.
 * 3. While the queue is not empty:
 *     - Dequeue the current word and its sequence length.
 *     - If current word is the target, return the sequence length.
 *     - For each character position in the word:
 *         - Try replacing it with all letters 'a' to 'z'.
 *         - If the new word exists in the set:
 *             - Enqueue the new word with length +1.
 *             - Remove it from the set to mark as visited.
 * 4. If the target word is never reached, return 0.
 *
 * Time Complexity:
 * - O(N * WordLength * 26), where N = number of words, WordLength = length of each word.
 *   Each word can be processed once, for each character (WordLength), trying 26 letters.
 *
 * Space Complexity:
 * - O(N * WordLength), for storing the queue and the word set.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// BFS to find shortest transformation sequence (Word Ladder)
// ---------------------------
int wordLadderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    wordSet.erase(beginWord);

    while (!q.empty()) {
        auto [currentWord, length] = q.front(); q.pop();

        if (currentWord == endWord) return length;

        for (int i = 0; i < currentWord.size(); i++) {
            char originalChar = currentWord[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                currentWord[i] = ch;
                if (wordSet.find(currentWord) != wordSet.end()) {
                    q.push({currentWord, length + 1});
                    wordSet.erase(currentWord);
                }
            }
            currentWord[i] = originalChar;
        }
    }

    return 0; // No transformation sequence exists
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    string startWord = "hit";
    string targetWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int length = wordLadderLength(startWord, targetWord, wordList);

    if (length > 0)
        cout << "Length of shortest transformation sequence: " << length << "\n";
    else
        cout << "No transformation sequence exists.\n";

    return 0;
}
