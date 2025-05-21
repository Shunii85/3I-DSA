#include <bits/stdc++.h>
#define SMAX 100
#define INPUT_SIZE 400
using namespace std;

class Stack {
private:
    int box[SMAX];
    int sp;

public:
    Stack() {
        sp = 0;
    }
    bool empty();
    void push(int num);
    void pop();
    int top();
};

bool Stack::empty() {
    return (sp == 0);
}
void Stack::push(int num) {
    box[sp] = num;
    sp++;
}

void Stack::pop() {
    sp--;
}

int Stack::top() {
    return box[sp - 1];
}

void polish_calc(char in, Stack& s) {
    int op1 = 0;
    int op2 = 0;
    switch (in){
        case ' ':
            break;
        case '+':
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            s.push(op1 + op2);
            break;
        case '-':
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            s.push(op2 - op1);
        case '*':
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            s.push(op1 * op2);
        case '/':
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            s.push(op2 / op1);
        default:
            s.push(in - '0');
    }
}

int main() {
    Stack s;
    string input;
    getline(cin, input, '\n');


    int i = 0;
    while (i < input.length()){
        char in = input[i];
        polish_calc(in, s);
    }

    cout << s.top() << endl;
    
}