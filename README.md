Cash Flow Minimization

Approach

The problem of finding the absolute minimum number of transactions is NP-hard. Since the constraints do not specify the number of unique people involved, an exact optimal solution using DFS/Backtracking may not be efficient for large inputs.

Therefore, this solution uses a greedy heap-based cash flow minimization approach.

The idea is:

Compute the net balance of every person.
Store all creditors (positive balance) and debtors (negative balance) in separate max-heaps.
Repeatedly settle the maximum possible amount between the current highest creditor and highest debtor.
Continue until all balances become zero.

Algorithm Used

Greedy + Priority Queue (Max Heap)

Complexity Analysis

Time Complexity: O(N + P log P)

Space Complexity: O(P)

where:

N = number of transactions
P = number of unique people
