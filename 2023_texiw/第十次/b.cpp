#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool binarySearch(int key, const std::vector<int> &sortedList, std::vector<int> &searchSequence)
{
    int low = 0;
    int high = sortedList.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        searchSequence.push_back(sortedList[mid]);

        if (sortedList[mid] == key) {
            return true; // 查找成功
        } else if (sortedList[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false; // 查找失败
}

std::vector<int> parseInput(const std::string &input)
{
    std::vector<int> numbers;
    std::istringstream iss(input);
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    std::string searchNumberString;
    std::getline(std::cin, searchNumberString);
    int searchNumber = std::stoi(searchNumberString);

    std::string inputString;
    std::getline(std::cin, inputString);
    std::vector<int> sortedList = parseInput(inputString);

    std::vector<int> searchSequence;

    bool found = binarySearch(searchNumber, sortedList, searchSequence);

    if (found) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    for (int num : searchSequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}