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
        cout << "�L�k�}���ɮ�";
        return 1;
    }

    bool found = false;
    string searchArea;
    cout << "�п�J�n�䪺����: ";
    cin >> searchArea;

    while (getline(file, line))
    {
        stringstream ss(line);
        string area, city, pm25, datacreationdate, itemunit;

        getline(ss, area, ','); // �H�r�����j���o�a��
        getline(ss, city, ','); // �H�r�����j���o����
        getline(ss, pm25, ','); // ���o�Ѿl�����@��pm25
        getline(ss, datacreationdate, ',');
        getline(ss, itemunit, ',');

        if (area == searchArea)
        {
            cout << "�a��   : " << area << endl;
            cout << "PM2.5  : " << pm25 << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "�d�L������" << endl;
    }

    file.close();
    return 0;
}
