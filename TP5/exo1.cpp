#include <tp5.h>
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;


std::vector<string> TP5::names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});


int HashTable::hash(std::string element)
{
    // use this->size() to get HashTable size
    int index = 0;
    // Parcourt tous les caractères de element
    for (char c : element) {
        // Pour chaque caractère -> indice augmenté de valeur du ASCII du caractère
        index += c;
    }
    // Retourne indice modulo taille table hachage -> valeur entre 0 et size-1
    return index % this->size();
}

void HashTable::insert(std::string element)
{
    // use (*this)[i] or this->get(i) to get a value at index i
    // Calcule index où élément doit être inséré avec fonction hash.
    int index = hash(element);
    int i = 0;
    // Itère tant jusqu'à fin table hachage et qu'un élément à son index calculé.
    while (i < this->size() && !(*this)[index].empty()) {
        // On avance d'un index avec boucle (modulo) sur taille table de hachage.
        // On revient au début de table si on est à la fin
        index = (index + 1) % this->size();
        i++;
    }
    // Si nombre essai = table hachage -> emplacements tous occupés
    if (i == this->size()) {
        return;
    }
    // Insère élément à index calculé dans table hachage.
    (*this)[index] = element;
}

/**
 * @brief buildHashTable: fill the HashTable with given names
 * @param table table to fiil
 * @param names array of names to insert
 * @param namesCount size of names array
 */
void buildHashTable(HashTable& table, std::string* names, int namesCount)
{
    for (int i = 0; i < namesCount; i++) {
        table.insert(names[i]);
    }
}

bool HashTable::contains(std::string element)
{
    // Note: Do not use iteration (for, while, ...)
    // Calcule indice hachage de élément avec fonction hash
    int index = hash(element);
    // Récupère valeur stockée dans table hachage à indice index
    std::string value = (*this)[index];
    // Renvoie cette valeur
    return value == element;
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 10;
	w = new HashWindow();
	w->show();

	return a.exec();
}
