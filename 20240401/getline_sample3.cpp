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
        cout << "無法開啟檔案";
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
        getline(ss, id, ',');   // 以逗號分隔取得學號
        getline(ss, name, ','); // 以逗號分隔取得姓名
        getline(ss, grade);     // 取得剩餘部分作為成績

        if (name == searchName)
        {
            cout << name << "成績是" << grade << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "查無此人" << endl;
    }

    score.close();
    return 0;
}

