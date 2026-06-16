#include "vector"
#include "iostream"
#include "string"
using namespace std;

// Array:

// Array is a collection of elements.

// Characterstics of Array:

// Data stored in the contigous memory locations.
// Elements must be of same type (but some languages support different type).
// It allows multiple values to be stored under a single name and accessed using an index.
// Size of array can be determined using sizeof() operator. (Space Occupation)
// Array indexing start from zero not from one. Indexing can be positive and negative.
// Once array is declared, then it's size remains constant throughout the program.

int main()
{
    // hum array ko kese bna skte hy pehle hum log dataType specify kre ge then name likhe ge then hum square brackets lgae ge aur us me size mention kre ge
    int students[3];

    // hume log array me at the time of declaration values assign bi kr skte hy
    string teachers[2] = {"Asad", "Arham"};

    // hum log array ke size ko skip bi kr skte hy jis waja se hmare array ka size elements ke mutabiq adjus ho jaye ga
    string professors[] = {"Azam", "Abid"}; // 2 size ka array bn jaye ga aur us me ye values assign ho jaye gi

    // hum ne memory me marks name ka array bnaea jis ka size four ho ga aur us me hum log four elements hi sto re kr skte hy is se ziada nahi km ki koi validation nahi.
    int marks[4] = {1, 3, 4, 5};

    // yaha hum marks name ka array bna rahe hy jis ka size hum ne defined nahi kia tu is waja se hum log is me jitne marzi chaye elements dal skte hy.
    // double marks[] = {1, 3, 4};

    // ye oeprator hme btaea ga ke marks array kitni space le raha hy aik int 4 bytes leta hy tu agr hum log 4bytes ko array elements count se multiplu krwae to 16 ana chaie marks ka size.
    int sizeOfMarks = sizeof(marks);
    cout << "How much size of marks array: " << sizeOfMarks << endl; // 1 6
    // ab ye hme marks ke array me stored elements kitne hy wo btae ga simple hum yaha size nikal ke usko 4bytes pe divide kr rahe hy
    cout << "How many elements in the marks array: " << sizeOfMarks / sizeof(int) << endl; // 4

    cout << "First element of marks array: " << marks[0] << endl; // 1
    // last element apka length of array - 1 ho ga hamesha is case me 4 - 1 => 3
    cout << "Last element of marks array: " << marks[3] << endl; // 5

    // ab hum tmam elements ko access krna cha rahe hy using loop
    for (int i = 0; i < sizeof(marks) / sizeof(int); i++)
    {
        cout << i << "th index element of marks: " << marks[i] << endl;
    }

    // array ke hr element ka aik address hota hy jaha pe store hota hy
    // aik cheeez hoti hy apki indexing
    // hum log array ke elements to like address se aru indexing se bi access kr skte hy but feasible way indexing and behind the scene apki addresses manage ho rahe hote hy

    // ye me indexing ke through uta raha ho value
    cout << "Indexed based value of first element of teachers: " << teachers[0] << endl;

    // ye me direct address ke through uta raha ho value
    // ab yaha pe ye cheeze ho rahi hy ke (teachers + 0) ka mtlb BASE_ADDRESS + (i * data_type)
    cout << "Address based value of first element of teachers: " << *(teachers + 0) << endl;

    // Types of array in terms of dimension:
    // 1D, 2D, 3D, Multi-Dimensional

    // 1D:
    int oneD[2] = {1001, 1002};
    // 2D:
    int twoD[2][1] = {{1001}, {1002}};
    // 3D:
    int threeD[2][1][1] = {{{1001}}, {{1002}}};
    // Multi-Dimensional:
    string multiD[2][2][2][2][2] =
        {
            {{{{"Asad", "Azam"},
               {"Abid", "Azam"}},
              {{"Ali", "Usman"},
               {"Hamza", "Bilal"}}},
             {{{"Zain", "Omar"},
               {"Khan", "Shah"}},
              {{"Noor", "Saad"},
               {"Irfan", "Hassan"}}}},
            {{{{"Ayan", "Rehan"},
               {"Talha", "Raza"}},
              {{"Fahad", "Asif"},
               {"Noman", "Daniyal"}}},
             {{{"Imran", "Javed"},
               {"Sami", "Waqas"}},
              {{"Arham", "Yasir"},
               {"Kashan", "Faisal"}}}}};

    // Types of array in terms of memory management:
    // static array // size should be allocated at compile time, stack based, auto memory managemenet
    // dynamic array // size can be allocated during the runtime, heap based, custom memory management, oftern declared with vector syntax, also can be created using the new operator

    // static:
    int laptops[9];

    // dynamic:
    vector<string> studentName = {"Bazid Khan", "Babu"};
    int *rollNumbers = new int[5];

    // Basic Operations in array specially with the static array:

    // insert: means adding an element to array
    int hello[5] = {};
    hello[0] = 1;

    // update: means adding the another element on previous array element
    hello[0] = 2;

    // read: means accessing the element of array
    cout << hello[0] << endl;

    // delete: means removing the element from array
    int ids[3] = {1001, 1002, 1003};
    int n = sizeof(ids) / sizeof(int);

    for (int i = 2; i < n - 1; i++)
    {
        ids[i] = ids[i + 1];
    }
    n--;

    for (int i = 0; i < n - 1; i++)
    {
        cout << ids[i] << endl;
    };

    // Note: In static array, size and memory will not free.

    // Basic methods of dynamic(vector) array for performing insertion, updation, deletion and reading:

    // studentName.push_back("Abdul Rehman");           // add element at end
    // studentName.pop_back();                          // remove last element studentName
    // studentName.size();                              // returns number of elements
    // studentName.empty();                             // checks vector is empty or not studentName
    // studentName.clear();                             // removes all elements studentName
    // studentName.front();                             // first element
    // studentName.back();                              // last element of studentName
    // studentName.at(0);                               // access element safely (with bounds check)
    // studentName[0];                                  // access element directly (no safety check) studentName
    // studentName.insert(studentName.begin(), "Khan"); // insert element at beginning
    // studentName.erase(studentName.begin());          // remove element at given position studentName
    // studentName.begin();                             // iterator to first element
    // studentName.end();                               // iterator to one past last element studentName
    // studentName.emplace_back(20);                    // faster version of push_back

    // linear Search: An algorithm for traversing on the array one by one and finding something from array.

    // return the index of 103 element using linear search
    int collogeID[4] = {101, 102, 103, 104};
    for (int i = 0; i < sizeof(collogeID) / sizeof(int); i++)
    {
        if (collogeID[i] == 1003)
        {
            cout << i << endl;
            return;
        }
    };

    // LEETCODE PROBLEM:
    // https://leetcode.com/problems/running-sum-of-1d-array/

    // Understand the problem first:

    // hme aik array dia gia hy nums name ka. aur uno ne running sum ko is trah define kia hy ke at the current position hum log zero se le kr us current position tk ja skte hy aur elements ko plus kr skte hy. hume running sum return krna hy nums array ka.

    // Example: 01
    vector<int> nums = {1, 2, 3, 4};
    // looping over the vector array nums
    vector<int> result = nums; // copy original array

    // O(N)^2
    for (int i = 0; i < nums.size(); i++)
    {
        int runningSum = 0;

        for (int j = 0; j <= i; j++)
        {
            runningSum += nums[j];
        }

        result[i] = runningSum;
    }

    // O(N):
    for (int i = 1; i < nums.size(); i++)
    {
        // yaha pe hum log just carrying sum ko le ke current me plus kr rahe jis se hmara solution linear me a raha hy. aur start bi one se kr rahe hy kyu ke agr one se krte tu pir us se pehle koi sum hy nahi that's why zero se start kr rahe hy.
        nums[i] += nums[i - 1];
    }

    return 0;
}