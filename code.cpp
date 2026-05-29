#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<string>> minimizeCashFlow(vector<vector<string>>& records) {

        unordered_map<string, ll> netAmount;

        for (auto& entry : records) {
            string sender = entry[0];
            string receiver = entry[1];
            ll money = stoll(entry[2]);

            netAmount[sender] -= money;
            netAmount[receiver] += money;
        }

        priority_queue<pair<ll, string>> gainers, payers;

        for (auto& [person, amount] : netAmount) {
            if (amount > 0)
                gainers.push({amount, person});
            else if (amount < 0)
                payers.push({-amount, person});
        }

        vector<vector<string>> answer;

        while (!gainers.empty() && !payers.empty()) {

            auto [receiveAmt, receivePerson] = gainers.top();
            gainers.pop();

            auto [payAmt, payPerson] = payers.top();
            payers.pop();

            ll transferAmt = min(receiveAmt, payAmt);

            answer.push_back(
                {payPerson, receivePerson, to_string(transferAmt)});

            if (receiveAmt > payAmt)
                gainers.push({receiveAmt - payAmt, receivePerson});
            else if (payAmt > receiveAmt)
                payers.push({payAmt - receiveAmt, payPerson});
        }

        return answer;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalTransactions;
    cin >> totalTransactions;

    vector<vector<string>> records(
        totalTransactions,
        vector<string>(3)
    );

    for (int i = 0; i < totalTransactions; i++) {
        cin >> records[i][0]
            >> records[i][1]
            >> records[i][2];
    }

    Solution solver;

    vector<vector<string>> result =
        solver.minimizeCashFlow(records);

    for (auto& row : result) {
        cout << row[0] << " "
             << row[1] << " "
             << row[2] << "\n";
    }

    return 0;
}
