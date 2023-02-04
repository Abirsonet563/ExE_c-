#include <iostream>
#include <string>

const int NUM_RECORDS = 5;

struct Record {
    int id;
    std::string name;
    int age;
    char gender;
};

int binarySearch(Record records[], int low, int high, int targetID) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (records[mid].id == targetID) {
            return mid;
        }
        if (records[mid].id > targetID) {
            return binarySearch(records, low, mid - 1, targetID);
        }
        return binarySearch(records, mid + 1, high, targetID);
    }
    return -1;
}

int main() {
    Record records[NUM_RECORDS] = {
        { 1001, "John Doe", 27, 'M' },
        { 1002, "Jane Doe", 25, 'F' },
        { 1003, "Bob Smith", 32, 'M' },
        { 1004, "Alice Johnson", 29, 'F' },
        { 1005, "Charlie Brown", 35, 'M' }
    };

    int targetID;
    std::cout << "Enter ID number: ";
    std::cin >> targetID;

    int result = binarySearch(records, 0, NUM_RECORDS - 1, targetID);
    if (result == -1) {
        std::cout << "ID not found." << std::endl;
    } else {
        std::cout << "Name: " << records[result].name << std::endl;
        std::cout << "Age: " << records[result].age << std::endl;
        std::cout << "Gender: " << records[result].gender << std::endl;
    }

    return 0;
}
