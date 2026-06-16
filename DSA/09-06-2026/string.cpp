#include "iostream"
#include "cstring"
#include "unordered_map"
using namespace std;

int main()
{
    // we need to know the character arrays first to understand the string
    // yaha pe character array ke elements join ho ke isliye a rahe hy kyu ke ye numbers me convert ho rahe hy. Ap jb tk characters array ko null character ke sath end nahi krte tu wo aik valid string nahi bnta.
    char characters[3] = {'a', 'a', '\0'};
    cout << characters << endl; // joined array elements like aa
    cout << strlen(characters) << endl;

    // if we simply print arrays we are seeing address
    int marks[2] = {101, 102};
    cout << marks << endl; // address

    // string literals

    // yaha pe behind the scene array hi bnta hy jis waja se hum log like array string ke chars ko access kr skte hy. Aur ye explicitly null chars ke sath end ho jata hy.
    char str[] = "Ahmed";
    cout << str << endl;    // Ahmed
    cout << str[2] << endl; // m

    // taking input into chars array
    char alphabets[14] = {};
    // cin >> alphabets;           // cin doesn't take the character after the space. In order to solve this problem, we will use cin.getline() function.
    // cin.getline(alphabets, 14); // getline(string, size, delimiter?)

    for (char ch : alphabets)
    {
        cout << ch << endl;
    };

    // character array have some limitation. So, we use string.

    // string is also the part of STL:
    string studentName = "Abu Dujana";
    cout << studentName << endl;

    // concatinating strings
    string firstName = "Muhammad";
    string lastName = " Farooq";

    // concatenation
    cout << (firstName + lastName) << endl; // Muhammad Farooq
    // comparing
    cout << (firstName == lastName) << endl; // 0 means false

    // looping over the strings
    // string have also length function
    for (int i = 0; i < firstName.length(); i++)
    {
        cout << firstName[i] << endl;
    }

    // taking input into string
    // string hello;
    // cin >> hello; // cin doesn't take the character after the space. In order to solve this problem, we will use cin.getline() function.
    // cout << hello << endl;

    // ASCII: It is a character encoding system. Capital A map to 65, small a map to 97, number zero 0 map to 48, and space to 32.

    // reverse a string:
    string passwrod = "apnapassword";
    int i = 0;
    int j = passwrod.length() - 1;
    while (i < j)
    {
        swap(passwrod[i], passwrod[j]);
        i++, j--;
    }
    cout << passwrod << endl;

    // count vowel in the string
    string hello = "hello";
    int count = 0;
    for (char ch : hello)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            count++;
        }
    }
    cout << count << endl; // 2

    // palindrome: means reading from start and end seem like same like mam will be mam either you read from forward or from back
    string m1 = "mam";
    int l = 0;
    int m = m1.length() - 1;
    while (l < m)
    {
        if (m1[l] == m1[m])
        {
            l++;
            m--;
        }
        else
        {
            cout << "This world is not palindrome." << endl;
        }
    };

    // if: else not run then means palindrome

    // remove all coccurences of part from string

    string part = "ello";
    string str1 = "absdfellsellodfsellod";

    while (str1.length() > 0 && str1.find(part) < str1.length())
    {
        str1.erase(str1.find(part), part.length());
    }
    cout << str1 << endl;

    // jewels and stones:
    // https://leetcode.com/problems/jewels-and-stones

    // Understand the problem first:

    // hme aik jewels aur stone name ke int array dia hua hy hum ne ye dekhna hy kitne stones jewels hy. Yaad rekhea ga ke letters case sensitive.
    // is ko hum log brute force se asani kr skte hy iske ilawa hashmap ko use kr ke operations ko km kr skte hy.

    string jewels = "aA";
    string stones = "aAAbbbb";
    int count1 = 0;

    // brute force: O(N * M)
    for (char stone : stones)
    {
        for (char jewel : jewels)
        {
            if (stone == jewel)
            {
                count1++;
                break;
            }
        }
    }

    cout << count1 << endl;

    // Using Hashmap: O(N + m)

    unordered_map<char, int> freq;

    // Count frequency of each stone
    for (char stone : stones)
    {
        freq[stone]++;
    }

    int count2 = 0;

    // Add frequencies of all jewels
    for (char jewel : jewels)
    {
        if (freq.find(jewel) != freq.end())
        {
            count2 += freq[jewel];
        }
    }

    cout << count2 << endl;
    
    return 0;
}