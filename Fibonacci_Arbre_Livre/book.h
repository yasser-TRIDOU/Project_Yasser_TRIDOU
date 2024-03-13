#ifndef PROGGEN_BOOK_H
#define PROGGEN_BOOK_H

#include "Arbre.h"
#include "fstream"
#include <sstream>

class Book {


private:
    Arbre<std::string> Tree;
    std::string filename;
private:

    void readBook(const std::string &filename) {
        std::ifstream inputFile(filename);
        int lineNumber = 0;
        if (inputFile.is_open()) {
            std::string line;
            while (std::getline(inputFile, line)) {
                lineNumber++;
                std::istringstream iss(line);
                std::string word;
                while (iss >> word) {
                    std::string cleanedWord;
                    for (char c: word) {
                        if (std::isalnum(c)) {
                            cleanedWord += c;
                        }
                    }
                    cl<std::string> *noeud;
                    if ((noeud = Tree.BFSrechercheSTL(cleanedWord)) != nullptr) {
                        noeud->occ++;
                        noeud->Ligne.push_back(lineNumber);
                    } else Tree.Inser(cleanedWord, lineNumber);
                }

            }
        } else std::cout << "Impossible d'ouvrire le fichier " << std::endl;

    }

public:
    Book(std::string &fl) : filename(fl) {
        readBook(filename);
    }

    void DisplayOccuurenceWord(const std::string &word) {
        cl<std::string> *noeud;
        noeud = Tree.BFSrechercheSTL(word);
        if (noeud) std::cout << "Le nombre d'occurence du mot " << word << " est " << noeud->occ << std::endl;
        else std::cout << "Le mot n'existe pas " << std::endl;
    }

    void DisplayLinenumberWord(const std::string &word) {
        cl<std::string> *noeud;
        noeud = Tree.BFSrechercheSTL(word);
        for (int v: noeud->Ligne)
            std::cout << "Ligne : " << v << std::endl;
    }


};


#endif //PROGGEN_BOOK_H
