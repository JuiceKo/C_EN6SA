#include "SearchingAlgorithm.h"
#include <iostream>

// Définition des membres statiques
unsigned int SearchingAlgorithm::totalComparisons = 0;
unsigned int SearchingAlgorithm::totalSearches    = 0;
double       SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm()
    : numberComparisons(0)
{
}

void SearchingAlgorithm::displaySearchResults(std::ostream& os,
                                              int resultIndex,
                                              int target)
{
    // Mise à jour des stats globales
    ++totalSearches;
    totalComparisons += numberComparisons;

    if (totalSearches != 0)
        averageComparisons = static_cast<double>(totalComparisons) / totalSearches;

    // Affichage
    if (resultIndex == -1) {
        os << "Element " << target << " non trouve.\n";
    } else {
        os << "Element " << target
           << " trouve a l'indice " << resultIndex << ".\n";
    }

    os << "Comparaisons (cette recherche) : " << numberComparisons  << "\n";
    os << "Comparaisons totales           : " << totalComparisons   << "\n";
    os << "Nombre total de recherches     : " << totalSearches      << "\n";
    os << "Moyenne de comparaisons        : " << averageComparisons << "\n\n";
}
