# 5B1G0001 / 20240401 /  課堂筆記

# stringstream 

是將字串變成字串迭代器一樣，將字串流在依次拿出，比較好的是，它不會將空格作為流。這樣就實現了字串的空格切割。

```cpp
#include<iostream>
#include<set>
#include<sstream>           //必須有該標頭檔案
#include<cstring>
using namespace std;
int main()
{
    string str = "i am a boy";
    istringstream stream(str);
    string s;
    while(stream>>s)           // 抽取stream中的值到s
    {
        cout<<s<<endl;      //依次輸出s
    }
    return 0;
}
```

```php
輸出 ：
i
am
a
boy
```

# C++ getline() sample

"D:\file\C_Plus_Plus\20240401\C++ getline() Note.md"

## getline_sample.cpp

把data.csv輸出便是，並加上

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
            getline(ss, name, ','); // 以逗號分隔取得姓名
            getline(ss, id, ',');   // 以逗號分隔取得學號
            getline(ss, grade);     // 取得剩餘部分作為成績

            // 輸出正確格式的資訊
            cout << "姓名 : " << name << "    學號 : " << id << "    成績 : " << grade << endl;

        }
        score.close();
    }
    else
    {
        cout << "無法開啟檔案";
    }

    return 0;
}
/*輸出 : 
姓名 : 張三    學號 : mg123456    成績 : 50
姓名 : 李四    學號 : mg000002    成績 : 45
姓名 : 王五    學號 : mg000001    成績 : 90*/

```

## getline_sample2.cpp 

尋找對應Area的PM2.5

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

```

## getline_sample3.cpp 

查同學成績

```cpp
// 引入必要的標頭檔
#include <iostream>  // 輸入輸出流
#include <fstream>   // 檔案輸入輸出流
#include <sstream>   // 字串串流
#include <string>    // 字串

using namespace std; // 使用標準命名空間

int main()
{
    // 打開 CSV 檔案
    ifstream score("0401score.csv");
    string line; // 用來存放從檔案中讀取的每一行資料

    // 檢查檔案是否成功開啟
    if (!score.is_open())
    {
        cout << "無法開啟檔案"; // 若無法開啟，輸出錯誤訊息
        return 1;               // 結束程式並回傳錯誤碼
    }

    // 初始化一個變數來表示是否找到目標學生的成績
    bool found = false;
    string searchName; // 用來存放要查詢的學生姓名
    cout << "Input search Name : ";
    cin >> searchName; // 從使用?芨擗J取得要查詢的姓名

    // 逐行讀取 CSV 檔案，並查找目標學生的成績
    while (getline(score, line))
    {
        stringstream ss(line); // 將每一行資料轉換成字串串流
        string name, id, grade;
        getline(ss, id, ',');   // 以逗號分隔取得學號
        getline(ss, name, ','); // 以逗號分隔取得姓名
        getline(ss, grade);     // 取得剩餘部分作為成績(以行為單位)

        // 若找到目標學生，輸出其姓名和成績
        if (name == searchName)
        {
            cout << name << "成績是" << grade << endl;
            found = true; // 將 found 設為真，表示找到目標學生
            break;        // 跳出迴圈，不再繼續查找
        }
    }

    // 若未找到目標學生，輸出提示訊息
    if (!found)
    {
        cout << "查無此人" << endl;
    }

    // 關閉檔案
    score.close();
    return 0; // 結束程式並回傳正常結束碼
}

```

# 課程重點 

寫在getline_sample3裡面