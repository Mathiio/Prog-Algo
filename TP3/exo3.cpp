#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct SearchTreeNode : public Node
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;


    void initNode(int value)
    {
        // init initial node without children
        this->left = nullptr;
        this->right = nullptr;
        this->value = value;
    }

	void insertNumber(int value) {
    // create a new node to insert
    SearchTreeNode* newNode = new SearchTreeNode(value);
    newNode->initNode(value);


    // traverse the tree to find the right position to insert the new node
    SearchTreeNode* currentNode = this;
    while (true) {
        if (value < currentNode->value) {
            if (currentNode->left == nullptr) {
                currentNode->left = newNode;
                return;
            } else {
                currentNode = currentNode->left;
            }
        } else if (value > currentNode->value) {
            if (currentNode->right == nullptr) {
                currentNode->right = newNode;
                return;
            } else {
                currentNode = currentNode->right;
            }
        } else {
            // the value already exists in the tree, no need to insert
            delete newNode;
            return;
        }
    }
    }

    

	uint height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        if (this->isLeaf()) {
            return 1;
        } else {
        // calculate the height of the left and right subtrees recursively
        uint leftHeight = this->left ? this->left->height() : 0;
        uint rightHeight = this->right ? this->right->height() : 0;
        
        // return the maximum height plus 1 for the node itself
        return std::max(leftHeight, rightHeight) + 1;
        }
    }

	uint nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        uint count = 1; // count the current node

        // if there is a left child, add its count to the total count
        if (this->left != nullptr) {
            count += this->left->nodesCount();
        }
        // if there is a right child, add its count to the total count
        if (this->right != nullptr) {
            count += this->right->nodesCount();
        }  
    return count;
	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        return (this->left == nullptr && this->right == nullptr);
	}

	void allLeaves(Node* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree
        if (this->isLeaf()) {
            // if current node is a leaf, add it to the array
            leaves[leavesCount] = this;
            leavesCount++;
        } else {
            // if the current node is not a leaf, recursively call
            // allLeaves function on its left and right children
        if (this->left != nullptr) {
            this->left->allLeaves(leaves, leavesCount);
        }
        if (this->right != nullptr) {
            this->right->allLeaves(leaves, leavesCount);
        }
    }
	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
        if (this->left != nullptr) {
            this->left->inorderTravel(nodes, nodesCount);
        }
        nodes[nodesCount] = this;
        nodesCount++;
        if (this->right != nullptr) {
            this->right->inorderTravel(nodes, nodesCount);
        }
	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
        // add the current node to the array
        nodes[nodesCount] = this;
        nodesCount++;

        // recursively call the function on the left subtree
        if (this->left != nullptr) {
            this->left->preorderTravel(nodes, nodesCount);
        }

        // recursively call the function on the right subtree
        if (this->right != nullptr) {
            this->right->preorderTravel(nodes, nodesCount);
        }
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
            // traverse the left subtree
        if (this->left != nullptr) {
            this->left->postorderTravel(nodes, nodesCount);
        }

        // traverse the right subtree
        if (this->right != nullptr) {
            this->right->postorderTravel(nodes, nodesCount);
        }

        // add the current node to the array
        nodes[nodesCount] = this;
        nodesCount++;
	}

    

	Node* find(int value) {
        // find the node containing value
		// Start searching from the root of the tree
        SearchTreeNode* currentNode = this;

        // Traverse the tree until the node containing the value is found or
        // we reach a leaf node
        while (currentNode != nullptr) {
            if (value < currentNode->value) {
                // If the value is less than the value of the current node, go left
                currentNode = currentNode->left;
            } else if (value > currentNode->value) {
                // If the value is greater than the value of the current node, go right
                currentNode = currentNode->right;
            } else {
                // The value has been found, return the current node
                return currentNode;
            }
        }

        // If the value is not found in the tree, return null pointer
        return nullptr;
	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    SearchTreeNode(int value) : Node(value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<SearchTreeNode>();
	w->show();

	return a.exec();
}