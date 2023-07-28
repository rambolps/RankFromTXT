#include <iostream>
#include <string>
#include <vector>
#include "RankGame.h"


bool lessThanEQ(std::string one, std::string two) {
    std::cout << "Do you like \"" << one << "\" less than or equal to \"" << two << "\" [Y / n]: ";

    char answer;
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y') {

        std::cout << "true" << std::endl;
        return true;
    }
    else {
        std::cout << "false" << std::endl;
        return false;
    }


}

bool lessThan(std::string one, std::string two) {
    std::cout << "Do you like \"" << one << "\" less than \"" << two << "\" [Y / n]: ";

    char answer;
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        std::cout << "true" << std::endl;
        return true;
    }
    else {
        std::cout << "false" << std::endl;
        return false;
    }
}

bool moreThan(std::string one, std::string two) {
    std::cout << "Do you like \"" << one << "\" more than \"" << two << "\" [Y / n]: ";

    char answer;
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        std::cout << "true" << std::endl;
        return true;
    }
    else {
        std::cout << "false" << std::endl;
        return false;
    }
}



void reverseArray(std::string arr[], int start, int end)
{
    while (start < end)
    {
        std::string temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void insertionSort(std::string arr[], int n)
{
    int i, j;
    std::string key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && moreThan(arr[j], key)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(std::string array[], int const left, int const mid,
    int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new std::string[subArrayOne],
        * rightArray = new std::string[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (lessThanEQ(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo])) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(std::string array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void tierSort(std::string array[], int  numChoices, int numTiers) {

    std::vector<std::vector<std::string>> tiers;
    tiers.resize(numTiers);
    for (auto& i : tiers)
        i.resize(numChoices);

    for (int i = 0; i < numChoices; i++) {
        std::cout << "What tier would you like " << array[i] << ": ";
        char pTier;
        std::cin >> pTier;

        int ipTier = pTier - '0';


    }
}

std::string* rankGame(std::string choices[], int numChoices) {

    std::string* rankedChoices = choices;


    std::cout << "Would You Like To Use Pre-Tier Your Options (Recommended!) [Y / n]: ";
    char answerT;
    std::cin >> answerT;

    if (answerT == 'y' || answerT == 'Y') {

        std::cout << "How many tiers would you like? (Max " << numChoices << " Tiers): ";
        char cTier;
        std::cin >> cTier;

        int iTier = cTier - '0';

        if (iTier > numChoices) {
            iTier = numChoices;
        }

        tierSort(rankedChoices, numChoices, iTier);
    }

    std::cout << "Would You Like To Use Insertion sort (NOT Recommended!) [Y / n]: ";
    char answerI;
    std::cin >> answerI;


    if (answerI == 'y' || answerI == 'Y') {
        insertionSort(rankedChoices,numChoices);
    }
    else {
        //TODO add tiers
        mergeSort(rankedChoices, 0, numChoices - 1);
    }

    reverseArray(rankedChoices, 0, numChoices - 1);

    return rankedChoices;
}