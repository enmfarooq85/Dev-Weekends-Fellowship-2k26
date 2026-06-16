#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    // Create an unordered map (Hash Map)
    unordered_map<string, int> students;

    // Insert using make_pair
    students.insert(make_pair("farooq", 2));

    // Insert using [] operator
    students["ahsan"] = 3;

    // Accessing values
    cout << "farooq: " << students["farooq"] << endl;

    // If key doesn't exist, [] creates it with default value 0
    cout << "hello: " << students["hello"] << endl;

    // Size of map
    cout << "Size: " << students.size() << endl;

    // Check if key exists
    cout << "Contains hadi? " << students.count("hadi") << endl;
    cout << "Contains hello? " << students.count("hello") << endl;

    // Remove a key
    students.erase("farooq");

    cout << "Size after erase: " << students.size() << endl;

    // Iterate through the map
    cout << "\nMap Contents:\n";
    for (const auto &entry : students)
    {
        cout << entry.first << " -> " << entry.second << endl;
    }

    return 0;
}