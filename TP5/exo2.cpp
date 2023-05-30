#include <QApplication>
#include <QString>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include <tp5.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;


std::vector<string> TP5::names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});

unsigned long int hash(string key)
{
    // taille de l'alphabet ASCII étendu
    const int base = 128; 
    unsigned long int hash_id = 0;
    // Itère sur tous caractère de chaîne key
    for (int i = 0; i < key.size(); i++) {
        // Ajoute produit du code ASCII du caractère actuel et de la puissance de la base à la puissance key.size() - i
        hash_id += key[i] * pow(base, key.size() - i);
    }
    // Retourne nombre entier unique pour chaîne de caractères key
    return hash_id;
}
struct MapNode : public BinaryTree
{

    string key;
    unsigned long int key_hash;

    int value;

    MapNode* left;
    MapNode* right;

    MapNode(string key, int value) : BinaryTree (value)
    {
        this->key = key;
        this->value = value;
        this->key_hash = hash(key);

        this->left = this->right = nullptr;
    }

    /**
     * @brief insertNode insert a new node according to the key hash
     * @param node
     */
    void insertNode(MapNode* node)
    {
        // Si hachage de clé nv nœud est inférieur à hachage de clé noeud actuel (noeud passé en paramètre)
        // On insère nv nœud dans sous-arbre gauche du noeud actuel
        if (node->key_hash < this->key_hash) {
            // Si sous-arbre gauche du noeud actuel nul 
            if (this->left == nullptr) {
                // insère nv noeud en enfant gauche du noeud actuel
                this->left = node;
                // Si non nul -> déjà enfant gauche
            } else {
                // Recherche de bonne position d'insertion dans sous-arbre gauche
                // Appel récursif de insertNode de enfant gauche avec nv nœud en paramètre
                this->left->insertNode(node);
            }
        }
        // Si hachage de clé nv nœud est supérieur à hachage de clé noeud actuel (noeud passé en paramètre)
        // On insère nv nœud dans sous-arbre droit du noeud actuel
        else if (node->key_hash > this->key_hash) {
            // Si sous-arbre droit du noeud actuel nul 
            if (this->right == nullptr) {
                // insère nv noeud en enfant droit du noeud actuel
                this->right = node;
                // Si non nul -> déjà enfant droit
            } else {
                // Recherche de bonne position d'insertion dans sous-arbre droit
                // Appel récursif de insertNode de droit gauche avec nv nœud en paramètre
                this->right->insertNode(node);
            }
        }
    }

    void insertNode(string key, int value)
    {
        this->insertNode(new MapNode(key, value));
    }

    virtual ~MapNode() {}
    QString toString() const override {return QString("%1:\n%2").arg(QString::fromStdString(key)).arg(value);}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

struct Map
{
    Map() {
        this->root = nullptr;
    }

    /**
     * @brief insert create a node and insert it to the map
     * @param key
     * @param value
     */
    void insert(string key, int value)
    {
        // Crée nouveau noeud avec "key" et "value"
        MapNode* new_node = new MapNode(key, value);
        // Vérifie si racine arbre nulle
        if (this->root == nullptr) {
            // Si oui -> place nv noeud à racine arbre
            this->root = new_node;
            // Si racine arbre non nulle -> noeud existant dans arbre
        } else {
            // Appel fonction "insertNode" du noeud racine avec nv noeud en paramètre
            // Fonction qui insère nv noeud à bonne position dans arbre en fonction de valeur hachage de clé
            this->root->insertNode(new_node);
        }
    }

    /**
     * @brief get return the value of the node corresponding to key
     * @param key
     * @return
     */
    int get(string key)
    {
        // Calcule hash de la clé
        unsigned long int key_hash = hash(key);

        // Cherche clé dans arbre binaire de recherche
        MapNode* current = root;
        while (current != nullptr) {
            // Si clé trouvée
            if (key_hash == current->key_hash) {
                return current->value;
            // Si clé dans sous-arbre gauche
            } else if (key_hash < current->key_hash) {
                current = current->left;
            // Si clé dans sous-arbre droit
            } else {
                current = current->right;
            }
        }

        // Si clé non trouvé
        return -1;
    }

    MapNode* root;
};


int main(int argc, char *argv[])
{
    srand(time(NULL));
	Map map;
    std::vector<std::string> inserted;

    map.insert("Yolo", 20);
    for (std::string& name : TP5::names)
    {
        if (rand() % 3 == 0)
        {
            map.insert(name, rand() % 21);
            inserted.push_back(name);
        }
    }

    printf("map[\"Margot\"]=%d\n", map.get("Margot"));
    printf("map[\"Jolan\"]=%d\n", map.get("Jolan"));
    printf("map[\"Lucas\"]=%d\n", map.get("Lucas"));
    printf("map[\"Clemence\"]=%d\n", map.get("Clemence"));
    printf("map[\"Yolo\"]=%d\n", map.get("Yolo"));
    printf("map[\"Tanguy\"]=%d\n", map.get("Tanguy"));

    printf("\n");
    for (size_t i=0; i<inserted.size()/2; i++)
        printf("map[\"%s\"]=%d\n", inserted[i].c_str(), map.get(inserted[i]));


    std::cout.flush();

    QApplication a(argc, argv);
    MainWindow::instruction_duration = 200;
    w = new MapWindow(*map.root);
    w->show();
    return a.exec();
}
