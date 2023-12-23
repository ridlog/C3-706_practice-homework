#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool linearProbe(int key, std::vector<int> &hashTable, std::vector<int> &searchSequence)
{
    int index = key % 199;
    int i = 0;
    while (hashTable[index] != -1) {
        searchSequence.push_back(hashTable[index]);
        if (hashTable[index] == key) {
            return true; // 查找成功
        }
        index = (index + 1) % 200;
        i++;
        if (i >= 200) {
            return false; // 查找失败，哈希表已满
        }
    }
    return false; // 查找失败，未找到对应的键
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
    std::vector<int> numbers = parseInput(inputString);

    std::vector<int> hashTable(200, -1);

    bool found = false;
    std::vector<int> searchSequence;

    for (int num : numbers) {
        int index = num % 199;
        int i = 0;
        while (hashTable[index] != -1) {
            index = (index + 1) % 200;
            i++;
            if (i >= 200) {
                std::cout << "False" << std::endl;
                return 0;
            }
        }
        hashTable[index] = num;
        if (num == searchNumber) {
            found = true;
        }
    }

    if (found) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    linearProbe(searchNumber, hashTable, searchSequence);

    for (int num : searchSequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
