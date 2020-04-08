//
// Created by Luke on 2020/4/8.
//

#include <iostream>
#include <cstddef>
using namespace std;

namespace DataStructure{
    typedef struct Node{
        Node(int v) {
            left = nullptr;
            right = nullptr;
            val = v;
        }
        Node* left;
        Node* right;
        int val;
    }Node;
    class BinarySearchTree{
    public:
        BinarySearchTree() {
        }
        void InitRoot(int val) {
            root = new Node(val);
        }

        Node* Insert(int val) {
            Node* node = root;
            while(node != nullptr) {
                if (node->val == val){
                    return NULL;
                }
                Node* child = node->val > val ? node->left:node->right;
                if (child == nullptr) {
                    if (node->val >val) {
                        node->left = new Node(val);
                        node = node->left;
                    } else {
                        node->right = new Node(val);
                        node->right;
                    }
                    node = child;
                    break;
                }
                node = child;

            }
            return node;
        }
        Node* Find(int val) {
            Node* node = root;
            while(node != nullptr) {
                if (node->val == val ){
                    return node;
                }
                Node* child = node->val > val ? node->left:node->right;

                if (child == nullptr)
                    return nullptr;
                node = child;
            }
            return node;
        }
        void Delete(Node* parent, Node* child){
            Node* target = child;
            while(child != NULL) {
                if (parent->left == child) {
                    parent->left = child->left;

                } else {
                    parent->right = child->left;
                }
            }
        }
        void Delete(int val) {
            Node* node = root;
            if (node == nullptr ) {
                return ;
            }

            if (node->val == val) {
                node->left->right =
            }

            while(node != nullptr) {
                if (node->val == val ){
                    return ;
                }
                Node* child = node->val > val ? node->left:node->right;

                if (child == nullptr)
                    return ;
                node = child;
            }
        }
    private:
        Node* root;
    };
}

int main() {

}