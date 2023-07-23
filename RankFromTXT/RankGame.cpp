#include <iostream>
#include <string>


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

int partition(std::string arr[], int start, int end)
{

    std::string pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (lessThanEQ(arr[i],pivot))
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (lessThanEQ(arr[i], pivot)) {
            i++;
        }

        while (moreThan(arr[j], pivot)) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(std::string arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
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

std::string* rankGame(std::string choices[], int numChoices) {

    std::string* rankedChoices = choices;


    quickSort(rankedChoices, 0, numChoices - 1);
    reverseArray(rankedChoices, 0, numChoices - 1);


    return rankedChoices;
}