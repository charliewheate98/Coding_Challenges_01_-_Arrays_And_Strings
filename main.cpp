#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

// --------------------------------------------------------------------
// One Away Challenge
// --------------------------------------------------------------------
bool EditCompare(string & a, string & b)
{
    // O(ab)          | Time Complexsity
    // O(sizeof(ab))  | Space Complexsity
    int num_edits = 0;

    // O(1)
    if (a == b) 
        return 0;
    if (a.length() == 0 && b.length() == 0) 
        return 0;

    for (auto i = 0; i < a.length();)
    {                                       // O(ab)
        for (auto j = 0; j < b.length();)
        {
            if (a[i] != b[j]) { // O(1)
                num_edits++;

                ++i; ++j; 
            }
            else { ++i; ++j; }
        }
    }

    return num_edits == 1 ? true : false; // O(1)
}

// --------------------------------------------------------
// String Compression Challenge
// --------------------------------------------------------
// O(a)
void outputCompressedString(string & a)
{
    for (auto i = 0; i < a.length(); i++)
    {
        int count = 1;

        while (i < a.length() && a[i] == a[i+1])
        {
            count++;
            i++;
        }

        cout << a[i] << count;
    }
    cout << endl << endl << endl;
}

// --------------------------------------------
// Rotate Matrix Challenge
// --------------------------------------------
// O(n)
void reverse(vector<int> & v) {
    int start = 0;
    int end = v.size() - 1;

    while (start < end) {
        swap(v[start], v[end]);
        start++;
        end--;
    }
}
void RotateMatrix(vector<vector<int>> & m)
{
    // O(row+col)
    int row = m.size();
    int col = m[0].size();

    for (auto i = 0; i < row; ++i)
    {
        for (auto j = 0; j < col; ++j)
        {
            // O(1)
            swap(m[i][j], m[j][i]); 
        }
    }
        
    for (auto i = 0; i < row; ++i) {
        // O(n)
        reverse(m[i]);
    }
}

// --------------------------------------------
// Zero Matrix Challenge
// --------------------------------------------
// O(row+col+fill array operation) | fill operation is linear
void ZeroMatrix(vector<vector<int>> & m)
{
    int zero_col = 0;

    for (auto i = 0; i < m.size(); ++i)
    {
        for (auto j = 0; j < m[0].size(); ++j)
        {
            if (m[i][j] == 0) {
                zero_col = j;
                std::fill(m[i].begin(), m[i].end(), 0);
                break;
            }
        }
    }

    for (auto i = 0; i < m.size(); ++i)
        m[i][zero_col] = 0;
}

// --------------------------------------------
// String Rotation Challenge
// --------------------------------------------
// O(n) (linear as it compares until a match is found)
bool isSubString(string & s1, string & s2)
{
    return (s1.length() == s2.length() && (s1 + s2).find(s2) != std::string::npos);
}

int main(int argc, char* argv[])
{
    /////////////////////////////////////
    // Detect Edits Challenge
    /////////////////////////////////////
    string a = "pal";
    string b = "pal";
    //cout << EditCompare(a, b) << endl;
    /////////////////////////////////////

    /////////////////////////////////////
    // String Compression Challenge
    string comp = "aabcccccaaa";
    //outputCompressedString(comp);
    /////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Rotate matrix Challenge
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<vector<int>> image =
    {
        {0, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    //RotateMatrix(image);
    //for (auto i = 0; i < image.size(); i += 3)
    //{
    //    for (auto j = 0; j < image[0].size(); ++j)
    //    {
    //        cout << image[i][j] << " " << image[i+1][j] << " " << image[i + 2][j] << endl;
    //    }
    //}
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Zero Matrix Challenge
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*ZeroMatrix(image);
    for (auto i = 0; i < image.size(); ++i)
    {
        for (auto j = 0; j < image[0].size(); j += 3)
        {
            cout << image[i][j] << " " << image[i][j + 1] << " " << image[i][j + 2] << endl;
        }
    }*/
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////
    // String Rotation Challenge    
    /////////////////////////////////////
    string str_a = "waterbottle";
    string str_b = "erbottlewat";
    if (isSubString(str_a, str_b))
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    /////////////////////////////////////

    system("pause");
    return EXIT_SUCCESS;
}