/*
 * Problem Statement: Accounts Merge (Merging Details)
 *
 * Given a list of accounts where each account has a name and associated email
 * addresses, merge accounts that share at least one common email.
 * After merging, each account should contain all unique emails sorted
 * alphabetically. The order of accounts in the output does not matter.
 *
 * Core Concept:
 * - Use Disjoint Set (Union-Find) to connect accounts sharing emails.
 * - Map each email to its first encountered account index.
 * - Union accounts when a shared email is found.
 * - Finally, collect emails for each ultimate parent and sort them.
 *
 * Steps:
 * 1. Assign each account a unique index and initialize DSU.
 * 2. Map emails to account indices and perform union:
 *    - For each email in an account:
 *        a. If email is new, store email -> index mapping.
 *        b. If email exists, unite current account index with mapped index.
 * 3. Collect emails for each ultimate parent:
 *    - Iterate through email -> index map.
 *    - For each email, find its ultimate parent and add the email to that parent's list.
 * 4. Construct the final merged accounts:
 *    - For each non-empty parent list:
 *        a. Sort emails alphabetically.
 *        b. Prepend the account name.
 *        c. Add to the result.
 *
 * Time Complexity:
 * - O(T * α + E log E), where T = total emails, E = emails per merged account.
 *
 * Space Complexity:
 * - O(N + T), for DSU and storing emails.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DISJOINT SET (UNION-FIND)
// ---------------------------
struct DisjointSet {
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool unite(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return false;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

// ---------------------------
// ACCOUNTS MERGE FUNCTION
// ---------------------------
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DisjointSet dsu(n);
    unordered_map<string,int> emailToIndex;

    // Step 1 & 2: Map emails and union accounts
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < accounts[i].size(); j++) {
            string email = accounts[i][j];
            if(emailToIndex.count(email)) {
                dsu.unite(i, emailToIndex[email]);
            } else {
                emailToIndex[email] = i;
            }
        }
    }

    // Step 3: Collect emails per ultimate parent
    vector<set<string>> mergedEmails(n);
    for(auto &[email, idx] : emailToIndex) {
        int parent = dsu.findParent(idx);
        mergedEmails[parent].insert(email);
    }

    // Step 4: Construct final answer
    vector<vector<string>> result;
    for(int i = 0; i < n; i++) {
        if(!mergedEmails[i].empty()) {
            vector<string> account;
            account.push_back(accounts[i][0]); // name
            account.insert(account.end(), mergedEmails[i].begin(), mergedEmails[i].end());
            result.push_back(account);
        }
    }

    return result;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"John","johnnybravo@mail.com"},
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"Mary","mary@mail.com"}
    };

    vector<vector<string>> merged = accountsMerge(accounts);

    cout << "Merged Accounts:\n";
    for(auto &acc : merged) {
        for(auto &s : acc) cout << s << " ";
        cout << "\n";
    }

    return 0;
}
