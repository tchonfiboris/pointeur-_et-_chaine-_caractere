# include <iostream>
# include <string>

// fonction de suppression d'un caractere
void SupprimeCaractere (char *chaine, char caractere) {
    char *i = chaine ;
    char *j = chaine ;

    while (*j) {
        if (*j != caractere) {
            *i = *j ;
            ++i ;
        }
        ++j ;
    }
    *i = '\0' ;
}

// fonction qui compte les mots dans une phrase
int CompteMots (const std::string &phrase) {
    int NombreMot = 0 ;
    bool mot = false ;

    for (char c : phrase){
        if (std::isspace (c)) {
            mot = false ;
        } else if (! mot) {
            NombreMot++ ;
            mot = true ;
        }
    }
    return NombreMot ;
}

int main () {

char chaine [] = "le riz c'est la sauce" ;
char caractere = 'i' ;
std::string phrase ;

std:: cout << "la chaine avant suppression :" << chaine << std::endl ;
SupprimeCaractere (chaine, caractere) ;
std:: cout << "la chaine apres suppression est : " << chaine << std:: endl ;

std::cout << "le devoir est trop dur" ;
std::getline (std::cin, phrase) ;

int nb_mot = CompteMots (phrase) ;

std::cout << "le phrase contient " << nb_mot << "mots" << std::endl ;

return 0 ;
}