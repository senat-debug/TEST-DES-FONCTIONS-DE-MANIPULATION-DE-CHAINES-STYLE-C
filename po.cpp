#include <iostream>

// Prototypes des fonctions

size_t LongueurChaine(const char* chaine);
void CopierChaine(char* destination, const char* source);
void ConcatenerChaines(char* destination, const char* source);
char* TrouverCaractere(const char* chaine, char caractere);
size_t CompterOccurrences(const char* chaine, char caractere);
void CopierMemoire(void* destination, const void* source, size_t taille);
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille);
void ExtraireSousChaine(char* destination, const char* source, size_t debut, size_t longueur);
size_t DiviserChaine(const char* chaine, char separateur, char resultat[][100], size_t max_resultats);
int ComparerChaines(const char* chaine1, const char* chaine2);
void ConvertirMinuscules(char* chaine);
bool EstChaineNumerique(const char* chaine);

// Implémentations des fonctions

// Tâche 1: Calcul de la longueur
size_t LongueurChaine(const char* chaine) {
    const char* debut = chaine;
    while (*chaine != '\0') {
        chaine++;
    }
    return chaine - debut;
}

// Tâche 2: Copie de chaîne
void CopierChaine(char* destination, const char* source) {
    // Copie le caractère, avance les pointeurs, s'arrête après '\0'
    while ((*destination++ = *source++) != '\0') {}
}

// Tâche 3: Concaténation
void ConcatenerChaines(char* destination, const char* source) {
    // Trouver la fin de destination
    while (*destination != '\0') {
        destination++;
    }
    // Copier source à la suite
    while ((*destination++ = *source++) != '\0') {}
}

// Tâche 4: Recherche de caractère
char* TrouverCaractere(const char* chaine, char caractere) {
    while (*chaine != '\0') {
        if (*chaine == caractere) {
            return (char*)chaine;
        }
        chaine++;
    }
    // Gère la recherche de '\0'
    if (caractere == '\0') {
        return (char*)chaine; 
    }
    return nullptr;
}

// Tâche 5: Comptage d'occurrences
size_t CompterOccurrences(const char* chaine, char caractere) {
    size_t compteur = 0;
    while (*chaine != '\0') {
        if (*chaine == caractere) {
            compteur++;
        }
        chaine++;
    }
    return compteur;
}
// Tâche 6: Extraction de sous-chaîne
void ExtraireSousChaine(char* destination, const char* source,
                         size_t debut, size_t longueur) {
    size_t len_source = LongueurChaine(source);

    if (debut >= len_source) {
        *destination = '\0';
        return;
    }

    size_t i = 0;
    // Copie jusqu'à la longueur souhaitée ou la fin de la source
    while (i < longueur && source[debut + i] != '\0') {
        destination[i] = source[debut + i];
        i++;
    }

    destination[i] = '\0';
}

// Tâche 7: Division de chaîne
size_t DiviserChaine(const char* chaine, char separateur,
                      char resultat[][100], size_t max_resultats) {
    size_t compteur_resultats = 0;
    const char* debut_sous_chaine = chaine;
    size_t index_chaine = 0;
    size_t len = LongueurChaine(chaine);

    while (index_chaine <= len && compteur_resultats < max_resultats) {
        
        bool est_separateur = chaine[index_chaine] == separateur;
        bool est_fin_chaine = chaine[index_chaine] == '\0';

        if (est_separateur || est_fin_chaine) {
            
            size_t longueur_sous_chaine = (size_t)(&chaine[index_chaine] - debut_sous_chaine);
            
            if (longueur_sous_chaine > 0) {
                
                size_t len_to_copy = longueur_sous_chaine < 99 ? longueur_sous_chaine : 99;

                for (size_t j = 0; j < len_to_copy; j++) {
                    resultat[compteur_resultats][j] = debut_sous_chaine[j];
                }
                
                resultat[compteur_resultats][len_to_copy] = '\0';
                compteur_resultats++;
            }
            
            debut_sous_chaine = &chaine[index_chaine + 1];
        }
        
        if (est_fin_chaine) break;

        index_chaine++;
    }

    return compteur_resultats;
}



// Tâche 8: fonction memoire
void CopierMemoire(void* destination, const void* source, size_t taille) {
    unsigned char* dest = (unsigned char*)destination;
    const unsigned char* src = (const unsigned char*)source;

    for (size_t i = 0; i < taille; i++) {
        dest[i] = src[i];
    }
}

// Tâche 9: Initialisation de blocs mémoire
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille) {
    unsigned char* ptr = (unsigned char*)zone;

    for (size_t i = 0; i < taille; i++) {
        ptr[i] = valeur;
    }
}


// Tâche 10: Comparaison des chaines
int ComparerChaines(const char* chaine1, const char* chaine2) {
    while (*chaine1 != '\0' && *chaine2 != '\0') {
        if (*chaine1 != *chaine2) {
            return (int)*chaine1 - (int)*chaine2;
        }
        chaine1++;
        chaine2++;
    }
    return (int)*chaine1 - (int)*chaine2;
}

// Tâche 11: Conversion en minuscules
void ConvertirMinuscules(char* chaine) {
    while (*chaine != '\0') {
        if (*chaine >= 'A' && *chaine <= 'Z') {
            *chaine += 32; // Différence ASCII entre 'A' et 'a'
        }
        chaine++;
    }
}

// Tâche 12: Vérification numérique
bool EstChaineNumerique(const char* chaine) {
    if (*chaine == '\0') {
        return false;
    }

    if (*chaine == '-') {
        chaine++;
        if (*chaine == '\0') {
            return false;
        }
    }

    while (*chaine != '\0') {
        if (*chaine < '0' || *chaine > '9') {
            return false;
        }
        chaine++;
    }

    return true;
}

// Programme Principal de Test (main)

int main() {
    std::cout << "=== TEST DES FONCTIONS DE MANIPULATION DE CHAINES STYLE C ===" << std::endl;
    std::cout << "Compilé avec C++ et CLang++" << std::endl << std::endl;
    
    // Test 1: Longueur de chaîne
    char message[] = "Bonjour le monde";
    std::cout << "1. Longueur de '" << message << "': " << LongueurChaine(message) << std::endl;
    
    // Test 2: Copie de chaîne
    char copie[50];
    CopierChaine(copie, message);
    std::cout << "2. Copie: '" << copie << "'" << std::endl;
    
    // Test 3: Concaténation
    char salutation[100] = "Hello ";
    ConcatenerChaines(salutation, "World!");
    std::cout << "3. Concaténation: '" << salutation << "'" << std::endl;
    
    // Test 4: Recherche de caractère
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        std::cout << "4. Caractère 'j' trouvé à la position: " << (position - message) << std::endl;
    } else {
        std::cout << "4. Caractère 'j' non trouvé" << std::endl;
    }
    
    // Test 5: Comptage d'occurrences
    std::cout << "5. Occurrences de 'o' dans '" << message << "': " 
              << CompterOccurrences(message, 'o') << std::endl;
    
    // Test 6: Extraction de sous-chaîne
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    std::cout << "6. Sous-chaîne (pos 3, longueur 5): '" << sous_chaine << "'" << std::endl;
    
    
    // Test 7: Division de chaîne
    char phrase[] = "pomme,orange,banane,kiwi";
    char fruits[10][100];
    size_t nb_fruits = DiviserChaine(phrase, ',', fruits, 10);
    
    std::cout << "7. Division de '" << phrase << "':" << std::endl;
    for (size_t i = 0; i < nb_fruits; i++) {
        std::cout << "   [" << i << "] " << fruits[i] << std::endl;
    }

     // Test 8: Fonctions mémoire (CopierMemoire)
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    std::cout << "8. Copie mémoire (5 octets): '" << zone2 << "'" << std::endl;
    
    // Test 9: Fonctions mémoire (InitialiserMemoire)
    char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    std::cout << "9. Initialisation mémoire: '" << zone3 << "'" << std::endl;
    // Test 10: Comparaison de chaînes
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    std::cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " 
              << resultat_comparaison << std::endl;
    
    // Test 11: Conversion minuscules
    char mixte[] = "Hello World!";
    std::cout << "11. Avant conversion: '" << mixte << "'" << std::endl;
    ConvertirMinuscules(mixte);
    std::cout << "    Après conversion: '" << mixte << "'" << std::endl;
    
    // Test 12: Vérification numérique
    char numerique[] = "12345";
    char non_numerique[] = "12a45";
    std::cout << "12. '" << numerique << "' est numérique: " 
              << (EstChaineNumerique(numerique) ? "OUI" : "NON") << std::endl;
    std::cout << "    '" << non_numerique << "' est numérique: " 
              << (EstChaineNumerique(non_numerique) ? "OUI" : "NON") << std::endl;
    
    return 0;
}
// coder par YOUBISSI NGATCHEUSSI 25P921

