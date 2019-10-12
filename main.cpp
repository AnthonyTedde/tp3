#include <iostream>
#include <string>
#include <sstream>

using namespace std;
/*
 * Global variables
 */
const int NMAX = 10;

/*
 * New type definition
 */
struct people{
    string name;
    char code;
};

/*
 * Functions signature
 */
void display_menu();
void input(people *);
template <typename V> void input(const string, V);

int main() {
    int choice;
    people person[NMAX];
    do{
        display_menu();
        cin >> choice;
        switch(choice){
            case 1: input(person);
        }
    }while(choice != 9);
}

void display_menu(){
    cout << "1. Saisir le tableau et afficher les données"                  << endl;
    cout << "2. Permuter deux à deux les éléments du tableau et afficher"   << endl;
    cout << "3. Trier le tableau suivant le code"                           << endl;
    cout << "4. Trier le tableau suivant le nom"                            << endl;
    cout << "5. Effacer un élément (Position P donnée par l’utilisateur)"   << endl;
    cout << "6. Ajouter un élément (Position P donnée par l’utilisateur)"   << endl;
    cout << "7. Chercher la Position selon nom et code"                     << endl;
    cout << "8. Effacer les doublons (même nom et même code)"               << endl;
    cout << "9. Quitter."                                                   << endl;
}

void input(people * person){
    int N;
    string name;
    char code;
    do{
        cout << "Combien de donnees souhaitez-vous entrer ?" << endl;
        cin >> N;
        if(N > NMAX)
            cout << "Eh non... la taille maximale du tableau est definie à: " << NMAX;
    }while(N > NMAX);

    cout << "Nous allons maintenant entrer les donnees" << endl;
    cin.ignore();

    for(int i = 0; i < N; i++){
        // TODO: entrer le numéro de l'itération.
        input("Veuillez entrer un nom pour l'entree numero", (person + i)->name);
        input("Veuillez entrer un code pour l'entree numero", (person + i)->code);
    }
}

template <typename V> void input(const string prompt, V value){
    string entry;
    V check;
    cout << prompt << endl;
    do{
        getline(cin, entry);
        istringstream sstr(entry);
        if(sstr >> check && sstr.get() == EOF){
            value = check;
            break;
        }
        else cout << "Eh non, recommence..." << endl;
    }while(true);
}
