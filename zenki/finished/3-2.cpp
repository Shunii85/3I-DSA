// 根付き木

#include <bits/stdc++.h>
#define NODE_MAX 100000
using namespace std;

struct Node {
    int id = -1;
    int parent = -1;
    int depth;
    string type;
    vector<Node*> children;
};

bool compare_id(Node& n1, Node& n2) {
    return (n1.id < n2.id);
}

void calc_depth(Node& n, int now_dep) {
    now_dep += 1;
    for(auto& child : n.children) {
        child->depth = now_dep;
        if(child->children.size()) calc_depth(*child, now_dep);
    }
}

int main() {
    int n, id, k;
    array<Node, NODE_MAX> nodes;

    cin >> n;
    for(int i=0; i<n; i++){
        // 親
        cin >> id >> k;
        if(nodes[id].id == -1) {
            Node node;
            node.id = id;
            nodes[id] = node;
        }

        Node* node = &nodes[id];

        // 子ども
        for(int j=0; j<k; j++){
            int c_id;
            cin >> c_id;
            if(nodes[c_id].id == -1) {
                Node child;
                child.id = c_id;
                nodes[c_id] = child;
            }

            nodes[c_id].parent = node->id;
            node->children.push_back(&(nodes[c_id]));
        }
        if(node->children.size() == 0){
            node->type = "leaf";
        } else {
            node->type = "internal node";
        }

    }
    
    // rootを検索 depthを計算
    for (auto& node: nodes){
        if(node.parent == -1) {
            node.type = "root";
            node.depth = 0;
            calc_depth(node, 0);
        } 
    }


    // 出力
    for (int i = 0; i<n; i++){
        Node node = nodes[i];
        if(node.id != -1) {
            cout << "node " << node.id << ": parent = " << node.parent << ", depth = " << node.depth << ", " << node.type << ", ";
           
            cout << "[";
            for (int i = 0; i < node.children.size(); i++) {
                cout << node.children[i]->id;
                if (i != node.children.size() - 1)
                    cout << ", ";
            }
            cout << "]" << std::endl;
        }
    }
    
}