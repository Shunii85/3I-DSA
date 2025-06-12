#define QMAX 100000
#include <bits/stdc++.h>
using namespace std;

struct Process {
    string name;
    int time;
};

class Queue {
private:
    Process p_pool[QMAX];
    int front;
    int back;
public:
    Queue() {
        front = back = 0;
    }
    bool empty();
    void enqueue(Process item);
    void dequeue();
    Process top();
};

bool Queue::empty() {
    return (back == front);
}

void Queue::enqueue(Process item) {
    p_pool[back] = item;
    back = (back + 1) % QMAX;
}
void Queue::dequeue() {
    front = (front + 1) % QMAX;
}

Process Queue::top() {
    return p_pool[front];
}

int main() {
    int n, q, time;
    string p_name;
    Queue que;
    cin >> n >> q;

    int i = 0;
    while (i < n){
        cin >> p_name >> time;
        Process p = { p_name, time };
        que.enqueue(p);
        i++;
    }
    
    int now = 0;
    while (!que.empty()){
        Process p = que.top();
        
        if(p.time <= q) {
            now += p.time;
            cout << p.name << " " << now << endl;
            que.dequeue();
        } else {
            now += q;
            p.time -= q;
            que.dequeue();
            que.enqueue(p);
        }
    }
}