#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream file("data3.csv");
    string line;

    if (!file.is_open())
    {
        cout << "無法開啟檔案";
        return 1;
    }

    bool found = false;
    string searchArea;
    cout << "請輸入要找的城市: ";
    cin >> searchArea;

    while (getline(file, line))
    {
        stringstream ss(line);
        string area, city, pm25, datacreationdate, itemunit;

        getline(ss, area, ','); // 以逗號分隔取得地區
        getline(ss, city, ','); // 以逗號分隔取得城市
        getline(ss, pm25, ','); // 取得剩餘部分作為pm25
        getline(ss, datacreationdate, ',');
        getline(ss, itemunit, ',');

        if (area == searchArea)
        {
            cout << "地區   : " << area << endl;
            cout << "PM2.5  : " << pm25 << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "查無此城市" << endl;
    }

    file.close();
    return 0;
}
