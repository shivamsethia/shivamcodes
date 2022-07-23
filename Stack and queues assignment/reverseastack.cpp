
// Input Format :
// The first line of input contains an integer N, denoting the total number of elements in the stack.

// The second line of input contains N integers separated by a single space, representing the order in which the elements are pushed into the stack.
// Output Format:
// The only line of output prints the order in which the stack elements are popped, all of them separated by a single space. 
// Note:
// You are not required to print the expected output explicitly, it has already been taken care of. Just make the changes in the input stack itself.
// Constraints:
// 1 <= N <= 10^3
// -2^31 <= data <= 2^31 - 1

// Time Limit: 1sec 
// Sample Input 1:
// 6
// 1 2 3 4 5 10
// Note:
// Here, 10 is at the top of the stack.
// Sample Output 1:
// 1 2 3 4 5 10
// Note:
// Here, 1 is at the top of the stack.
// Sample Input 2:
// 5
// 2 8 15 1 10
// Sample Output 2:
// 2 8 15 1 10



void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if(input.empty())
        return;
    int v=input.top();
    input.pop();
    reverseStack(input,extra);
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    input.push(v);
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
}
#include <iostream>
#include <stack>
using namespace std;

// #include "solution.h"

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}