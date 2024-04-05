# 5B1G0001 / 20240401 /  �Ұ󵧰O

# stringstream 

�O�N�r���ܦ��r�ꭡ�N���@�ˡA�N�r��y�b�̦����X�A����n���O�A�����|�N�Ů�@���y�C�o�˴N��{�F�r�ꪺ�Ů���ΡC

```cpp
#include<iostream>
#include<set>
#include<sstream>           //�������Ӽ��Y�ɮ�
#include<cstring>
using namespace std;
int main()
{
    string str = "i am a boy";
    istringstream stream(str);
    string s;
    while(stream>>s)           // ���stream�����Ȩ�s
    {
        cout<<s<<endl;      //�̦���Xs
    }
    return 0;
}
```

```php
��X �G
i
am
a
boy
```

# C++ getline() sample

"D:\file\C_Plus_Plus\20240401\C++ getline() Note.md"

## getline_sample.cpp

��data.csv��X�K�O�A�å[�W

```cpp
//getline_sample.cpp
/*=============================================================================*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream score("data.csv");
    string line;

    if (score.is_open())
    {
        while (getline(score, line))
        {
            stringstream ss(line);
            string name, id, grade;
            getline(ss, name, ','); // �H�r�����j���o�m�W
            getline(ss, id, ',');   // �H�r�����j���o�Ǹ�
            getline(ss, grade);     // ���o�Ѿl�����@�����Z

            // ��X���T�榡����T
            cout << "�m�W : " << name << "    �Ǹ� : " << id << "    ���Z : " << grade << endl;

        }
        score.close();
    }
    else
    {
        cout << "�L�k�}���ɮ�";
    }

    return 0;
}
/*��X : 
�m�W : �i�T    �Ǹ� : mg123456    ���Z : 50
�m�W : ���|    �Ǹ� : mg000002    ���Z : 45
�m�W : ����    �Ǹ� : mg000001    ���Z : 90*/

```

## getline_sample2.cpp 

�M�����Area��PM2.5

```cpp
//getline_sample2.cpp
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

```

## getline_sample3.cpp 

�d�P�Ǧ��Z

```cpp
// �ޤJ���n�����Y��
#include <iostream>  // ��J��X�y
#include <fstream>   // �ɮ׿�J��X�y
#include <sstream>   // �r���y
#include <string>    // �r��

using namespace std; // �ϥμзǩR�W�Ŷ�

int main()
{
    // ���} CSV �ɮ�
    ifstream score("0401score.csv");
    string line; // �ΨӦs��q�ɮפ�Ū�����C�@����

    // �ˬd�ɮ׬O�_���\�}��
    if (!score.is_open())
    {
        cout << "�L�k�}���ɮ�"; // �Y�L�k�}�ҡA��X���~�T��
        return 1;               // �����{���æ^�ǿ��~�X
    }

    // ��l�Ƥ@���ܼƨӪ�ܬO�_���ؼоǥͪ����Z
    bool found = false;
    string searchName; // �ΨӦs��n�d�ߪ��ǥͩm�W
    cout << "Input search Name : ";
    cin >> searchName; // �q�ϥ�?Ϳ�J���o�n�d�ߪ��m�W

    // �v��Ū�� CSV �ɮסA�ìd��ؼоǥͪ����Z
    while (getline(score, line))
    {
        stringstream ss(line); // �N�C�@�����ഫ���r���y
        string name, id, grade;
        getline(ss, id, ',');   // �H�r�����j���o�Ǹ�
        getline(ss, name, ','); // �H�r�����j���o�m�W
        getline(ss, grade);     // ���o�Ѿl�����@�����Z(�H�欰���)

        // �Y���ؼоǥ͡A��X��m�W�M���Z
        if (name == searchName)
        {
            cout << name << "���Z�O" << grade << endl;
            found = true; // �N found �]���u�A��ܧ��ؼоǥ�
            break;        // ���X�j��A���A�~��d��
        }
    }

    // �Y�����ؼоǥ͡A��X���ܰT��
    if (!found)
    {
        cout << "�d�L���H" << endl;
    }

    // �����ɮ�
    score.close();
    return 0; // �����{���æ^�ǥ��`�����X
}

```

# �ҵ{���I 

�g�bgetline_sample3�̭�