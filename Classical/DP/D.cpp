#include <bits/stdc++.h>
using namespace std;

//FOR UNIQUE ELEMENTS -> THINK FOR NON-UNIQUE ELEMENTS ITS VERY EZE

/* NOTES : 
 * If the added element isn't appended in the set(it is placed somewhere in middle),
 * it must be between two elements, x & y such that, x <= new_element <= y
 * It can be proved that y or x can be replaced by the new_element as far as
 * "Longest Increasing Subsequence"  is concerned, i.e. x is equivalent to new_element
 * & new_element is equivalent to y.
 * Removing any 1 out of the 3 will be the result of our answer
 */

void see_whats_going_on(set<int> &st) {
	for(auto it : st)
		cout << it << " ";
	cout << endl;
}

int t, n;

int main() {
	set<int> st;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t;
		st.insert(t);
		auto it = st.find(t);
		if(++it != st.end())
			st.erase(it);
		see_whats_going_on(st);
	}
	cout << st.size() << endl;
	return 0;
}
