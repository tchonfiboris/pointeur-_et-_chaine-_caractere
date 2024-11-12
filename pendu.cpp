#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

std::vector<std::string> mots = {"information", "pendu", "plantain", "okok", "pile"};

std::string choisirMotAleatoire() {
    srand(time(0));
    int index = rand() % mots.size();
    return mots[index];
}

int main() {
    std::string motADeviner = choisirMotAleatoire();
    std::string motCache(motADeviner.length(), '_');

    int erreurs = 0;
    int maxErreurs = 8;
    bool finPartie = false;

    std::cout << "Bienvenue dans le jeu du pendu !" << std::endl;

    while (!finPartie) {
        std::cout << "Mot a deviner : " << motCache << std::endl;
        std::cout << "Proposez une lettre : ";
        char lettre;
        std::cin >> lettre;

        bool lettreTrouvee = false;
        for (int i = 0; i < motADeviner.length(); ++i) {
            if (motADeviner[i] == lettre) {
                motCache[i] = lettre;
                lettreTrouvee = true;
            }
        }

        if (!lettreTrouvee) {
            ++erreurs;
            std::cout << "Incorrect ! Il vous reste " << maxErreurs - erreurs << " erreurs." << std::endl;
            if (erreurs == maxErreurs) {
                std::cout << "Vous avez ete pendu ! Le mot etait : " << motADeviner << std::endl;
                finPartie = true;
            }
        }

        if (motADeviner == motCache) {
            std::cout << "Felicitations ! Vous avez devine le mot : " << motADeviner << std::endl;
            finPartie = true;
        }
    }

    return 0;
}