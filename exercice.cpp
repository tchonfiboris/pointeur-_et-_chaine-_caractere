#include<iostream>

// fomction qui calcul la longueur d'un caractere 

int longueur(const char *chaine) {
    int compteur = 0 ;

    while (*chaine != '\0')
    {
        compteur++;
        chaine++;
    }
    return compteur;
    
}

// fonction qui cree une copie modifiable d'une chaine de caractere

void copie (char *&dest, const char *source){
int longueur = 0;
while (source[longueur] != '\0')
{
    ++longueur;
}
dest = new char [longueur + 1] ;

for (int i = 0; i < longueur; ++i)
{
   dest[i] = source[i];
}
dest[longueur] = '\0';

}

// fonction de concatenation d'une chaine de caractere 
void concatene (char *dest, const char *source){
    int LongueurDest = 0 ;
    while (dest [LongueurDest] != '\0')
    {
        ++LongueurDest;
    }
    
    // concatenation d'une chaine de caractere 
    int i = 0 ;
    while (source [i] != '\0')
    {
        dest [LongueurDest] = source [i] ;
        ++LongueurDest;
        ++i;
    }
    dest [LongueurDest] = '\0' ;
}

// fonction de comparaison d'une chaine de caractere
int compare (const char *chaine1, const char *chaine2 ){
int i = 0;

while (chaine1 [i] != '\0' && chaine2 [i] != '\0')
{
    if (chaine1 [i] > chaine2 [i])
    {
        return 1; // la chaine1 est plus grand que la chaine2  
    }if (chaine1 [i] < chaine2 [i])
{
    return -1; // la chaine1 est plus petite que la chaine2
}
    ++i;
}

if (chaine1 [i] =='\0' && chaine2 [i] == '\0')
{
    return 0;  // egale
} else if (chaine1 [i] == '\0') {
    return -1; 
} else {
    return 1;
}

return 0; 

}

// fonction recherche d'un caractere
const char *RechercheChar (const char *chaine, char caractere){
while (*chaine != '\0')
{
    if (*chaine == caractere) {
        return chaine;
    }
    ++chaine;
}
return NULL;
}

// fonction qui inverse un caractere 
void inverse (char *chaine){
    int longueur = 0;

    while (chaine [longueur] != '\0')
    {
        ++longueur;
    }

    for (int i = 0; i < longueur/2; ++i){
        char temp = chaine [i];
        chaine [i] = chaine [longueur - i - 1];
        chaine [longueur - i -1] = temp;
    }
    
}

// fonction minuscule/majuscule
     // majuscule
void to_upper ( char *chaine){
    for (int i = 0; chaine [i] != '\0'; ++i){
        if (chaine [i] >= 'a' && chaine [i] <= 'z'){
            chaine [i] = chaine [i] - 'a' + 'A';
        }
    }
} 
     // minuscule
void to_lower ( char *chaine){
    for (int i = 0; chaine [i] != '\0'; ++i){
        if (chaine [i] >= 'A' && chaine [i] <= 'Z'){
            chaine [i] = chaine [i] - 'A' + 'a';
        }
    }
}      

// fonction qui recherche un mot dans une phrase
char *ChercheMot (const char *phrase, const char *mot){
    while (*phrase != '\0') {
        const char *p = phrase ;
        const char *m = mot ;

        while (*m != '\0' && *p == *m) {
            ++p ;
            ++m ;
        }

        if (*m == '\0') {
            return const_cast<char*> (phrase) ;
        }
        ++phrase ;
    }
    return NULL ;
}

// fonction qui extrais une sous chaine
void SousChaine (const char *source, int debut, int longueur){
if (debut < 0 || longueur < 0){
    std:: cout << "entre une valeur positive " << std::endl ;
    return ;
}

int taillesource = 0 ;
const char *p = source ;

while (*p != '\0') {
    ++ taillesource ;
    ++ p ;
}

if (debut >= taillesource) {
    std:: cout << "le parametre depasse la taille de la chaine " << std::endl ;
    return ;
}
std:: cout << "sous-chaine extraite" ;

for (int i = debut; i < debut + longueur && source [i] != '\0'; ++i) {
   
    std::cout << source[i] ;
}

std::cout << std::endl ;
}

int main () {

const char *phrase = "new bg" ;
const char *mot = "bg" ;
 const char *MaChaine = "tchonfi";
 char caractere = 'k' ;
 char *modifier = NULL;
 char NomConca [50] = "boris";
 const char *chaine1 = "bonjour";
 const char *chaine2 = "bonjour";
 char chaine [] = "ballon";
 const char *source = "je mange le koki" ;
 int debut = 2 ;
 int fin = 8 ;
 


const char *MotTrouver = ChercheMot (phrase, mot);
const char *caracteretrouver = RechercheChar (MaChaine, caractere);
int ResultatComparaison = compare (chaine1, chaine2);
int NombreCaractere = longueur(MaChaine);
copie(modifier, MaChaine);
concatene(NomConca, MaChaine);
SousChaine (source, debut, fin);

// modifier la copie modifiable 
modifier[0] = 'h' ;

std::cout << "ma chaine d'origine :" << MaChaine << std:: endl;
std::cout << "ma chaine contient :"  << NombreCaractere << " caractere" << std::endl;
std::cout << "ma chaine modifier :" << modifier << std:: endl;
std::cout << "ma chaine concatene :" << NomConca << std::endl;

if (ResultatComparaison < 0)
{
    std:: cout << "la chaine1 est plus petite que la chaine2 " << std::endl;
}else if (ResultatComparaison > 0){
    std:: cout << "la chaine1 est plus grande que la chaine2" << std::endl;
}else{
    std::cout << "la chaine1 est egale a la chaine2 " << std::endl;
}

if (caracteretrouver != NULL) {
    std::cout << "le caractere " << caractere << " a ete trouver" << std::endl;
} else {
    std::cout << "le caractere " << caractere << " n'a pas ete trouver." << std::endl;
}

std::cout << "la chaine avant iversion " << chaine << std::endl;
inverse (chaine);
std::cout << "la chaine apres inversion " << chaine << std::endl;

std::cout << "la chaine minuscule : " << chaine << std::endl;
to_upper (chaine);
std::cout << "la chaine majuscule : " << chaine << std::endl;
to_lower (chaine);
std::cout << "la chaine minuscule : " << chaine << std:: endl;

if (MotTrouver != NULL) {
    std::cout << "le mot : " << mot << " a ete trouver" << std::endl ;
} else {
    std::cout << "le mot : " << mot << " n'a pas ete trouver" << std::endl ;
}

delete [] copie ;
return 0;
   
}