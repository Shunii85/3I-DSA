#include <bits/stdc++.h>
using namespace std;
enum Command {
  INSERT,
  EXTRACT,
  END
};

Command getCommandEnum(const string cmd) {
  if(cmd == "insert") return INSERT;
  if(cmd == "extract") return EXTRACT;
  return END;
}

int main() {
  priority_queue<int> h;
  string cmd;
  int num;
  vector<pair<string, int>> m;

  while (true){
    cin >> cmd;
    if(cmd == "end") break;
    if(cmd == "extract") {
      m.push_back(make_pair(cmd, 0));
    } else {
      cin >> num;
      m.push_back(make_pair(cmd, num));
    }
  }
  
  for(const auto& p : m) {
    switch (getCommandEnum(p.first)){
      case INSERT:
        h.push(p.second);
        break;

      case EXTRACT:
        cout << h.top() << endl;
        h.pop();
        break;

      case END:
        break;
    }
  }
}