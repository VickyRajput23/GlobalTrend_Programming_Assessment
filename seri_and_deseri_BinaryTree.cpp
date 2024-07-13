#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Serializes
    string serialize(TreeNode* root) {
        if (!root) return "# ";
        
        string leftSerialized = serialize(root->left);
        string rightSerialized = serialize(root->right);
        
        return to_string(root->val) + " " + leftSerialized + rightSerialized;
    }

    // Deserializes
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserializeHelper(ss);
    }

private:
    TreeNode* deserializeHelper(istringstream& ss) {
        string val;
        ss >> val;
        
        if (val == "#") return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
        
        return node;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "# ";
        }
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    Codec codec;
    string serializedTree = codec.serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;
    
    TreeNode* deserializedTree = codec.deserialize(serializedTree);
    cout << "Deserialized Tree (Level Order): ";
    printTree(deserializedTree);
    
    return 0;
}
