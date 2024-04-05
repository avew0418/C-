//getline_sample3.cpp
/*=============================================================================*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream score("0401score.csv");
    string line;

    if (!score.is_open())
    {
        cout << "�L�k�}���ɮ�";
        return 1;
    }

    bool found = false;
    string searchName;
    cout << "Input search Name : ";
    cin >> searchName;

    while (getline(score, line))
    {
        stringstream ss(line);
        string name, id, grade;
        getline(ss, id, ',');   // �H�r�����j���o�Ǹ�
        getline(ss, name, ','); // �H�r�����j���o�m�W
        getline(ss, grade);     // ���o�Ѿl�����@�����Z

        if (name == searchName)
        {
            cout << name << "���Z�O" << grade << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "�d�L���H" << endl;
    }

    score.close();
    return 0;
}

