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
        // Initialise noeuds sans enfants
        this->left = nullptr;
        this->right = nullptr;
        this->value = value;
    }

	void insertNumber(int value) {
    // Crée un nouveau noeud
    SearchTreeNode* newNode = new SearchTreeNode(value);
    // Lance initialisation noeud avec value
    newNode->initNode(value);


    // Parcourir arbre pour trouver position du nouveau noeud
    // Définit noeud actuel
    SearchTreeNode* currentNode = this;
    // Tant qu'on ne trouve pas place pour nouveau noeud.
    while (true) {
        // Si valeur nouveau noeud inférieure à valeur noeud actuel
        if (value < currentNode->value) {
            // Si noeud actuel a pas fils gauche
            if (currentNode->left == nullptr) {
                // Insère nouveau noeud sur fils gauche du noeud actuel.
                currentNode->left = newNode;
                return;
                // Si noeud actuel a déjà fils gauche
            } else {
                // Noeud actuel égal fils gauche puis recherche continue
                currentNode = currentNode->left;
            }
            // Si valeur nouveau noeud supérieure à valeur du noeud actuel
        } else if (value > currentNode->value) {
            // Si noeud actuel a pas fils droit
            if (currentNode->right == nullptr) {
                // Insère nouveau noeud sur fils droit du noeud actuel.
                currentNode->right = newNode;
                return;
                // Si noeud actuel a déjà fils droit
            } else {
                // Noeud actuel égal fils droit puis recherche continue
                currentNode = currentNode->right;
            }
            // Si valeur nouveau noeud existe deja on insère pas
        } else {
            delete newNode;
            return;
        }
    }
    }

    

	uint height() const	{
        if (this->isLeaf()) {
            return 1;
        } else {
        // Calcule hauteur branche droite avec récursivité
        uint leftHeight = this->left ? this->left->height() : 0;
        uint rightHeight = this->right ? this->right->height() : 0;
        
        // Renvoi hauteur maximale plus 1 pour compter noeud actuel
        return std::max(leftHeight, rightHeight) + 1;
        }
    }

	uint nodesCount() const {
        // Compter noeud actuel
        uint count = 1; 

        // Si enfant gauche existe, comptabiliser dans somme totale
        if (this->left != nullptr) {
            count += this->left->nodesCount();
        }
        // Si enfant droit existe, comptabiliser dans somme totale
        if (this->right != nullptr) {
            count += this->right->nodesCount();
        }  
    return count;
	}

	bool isLeaf() const {
        // Renvoi true si arbre a pas enfants
        return (this->left == nullptr && this->right == nullptr);
	}

    // fill leaves array with all leaves of this tree
	void allLeaves(Node* leaves[], uint& leavesCount) {
        // Si noeud actuel a pas enfants
        if (this->isLeaf()) {
            // Ajoute noeud actuel au tableau
            leaves[leavesCount] = this;
            // Met à jour nombre de fuilles  du tableau
            leavesCount++;
        // Si noeud actuel a enfants 
        } else {
        // Si noeud actuel a pas enfant gauche
        if (this->left != nullptr) {
            this->left->allLeaves(leaves, leavesCount);
        }
        // Si noeud actuel a pas enfant droit
        if (this->right != nullptr) {
            this->right->allLeaves(leaves, leavesCount);
        }
    }
	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // Vérifie si noeud actuel a enfant gauche
        if (this->left != nullptr) {
            // Rappel de la fonction sur enfant gauche noeud actuel
            this->left->inorderTravel(nodes, nodesCount);
        }
        // Ajoute noeud actuel dans tableau de nodes à indice nodesCount.
        nodes[nodesCount] = this;
        // Incrémente nodesCount
        nodesCount++;
        // Vérifie si noeud actuel a enfant gauche
        if (this->right != nullptr) {
            // Rappel de la fonction sur enfant droit noeud actuel
            this->right->inorderTravel(nodes, nodesCount);
        }
	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // Ajoute noeud courant au tableau nodes à indice nodesCount
        nodes[nodesCount] = this;
        // Incrémente nodesCount
        nodesCount++;

        // Vérifie si noeud actuel a enfant gauche
        if (this->left != nullptr) {
            // Rappel de la fonction sur enfant gauche noeud actuel
            this->left->preorderTravel(nodes, nodesCount);
        }

        // Vérifie si noeud actuel a enfant droit
        if (this->right != nullptr) {
            // Rappel de la fonction sur enfant droit noeud actuel
            this->right->preorderTravel(nodes, nodesCount);
        }
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // Vérifie si noeud actuel a enfant gauche
        if (this->left != nullptr) {
            // Rappel de la fonction sur enfant gauche noeud actuel
            this->left->postorderTravel(nodes, nodesCount);
        }

        // Vérifie si noeud actuel a enfant gauche
        if (this->right != nullptr) {
            // Rappel de la fonction sur enfant droit noeud actuel
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