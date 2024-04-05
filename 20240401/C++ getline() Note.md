# C++ getline() Note

是一種標準庫函數，用於從輸入流中讀取字符串或行。它是<string>標頭的一部分。 getline()函數從輸入流中提取字符，並將其附加到字符串對象，直到遇到定界字符。這樣做時，先前在字符串對象str中存儲的值將被輸入字符串替換(如果有)。

getline()函數可以兩種方式表示：

1. 用法:

   ```
   istream& getline(istream& is, 
              string& str, char delim);
   ```

   **參數：**

   - **is:**它是istream類的對象，它告訴函數有關從何處讀取輸入的流。
   - **str:**這是一個字符串對象，從流中讀取輸入後，將輸入存儲在此對象中。
   - **delim:**它是定界字符，它告訴函數在達到該字符後停止讀取進一步的輸入。

   **返回值：**此函數返回與作為參數接受的輸入流相同的輸入流。

2. 用法:

   ```
   istream& getline (istream& is, string& str);
   ```

   第二個聲明與第一個聲明幾乎相同。唯一的區別是，後者不接受任何定界字符。

   **參數：**

   - **is:**它是istream類的對象，它告訴函數有關從何處讀取輸入的流。
   - **str:**這是一個字符串對象，從流中讀取輸入後，將輸入存儲在此對象中。

   **返回值：**此函數返回與作為參數接受的輸入流相同的輸入流。

下麵的程序演示了getline()函數的工作

**範例1：**

```
// C++ program to demonstrate getline() function 
  
#include <iostream> 
#include <string> 
using namespace std; 
  
int main() 
{ 
    string str; 
  
    cout << "Please enter your name:\n"; 
    getline(cin, str); 
    cout << "Hello, " << str 
         << " welcome to GfG !\n"; 
  
    return 0; 
}
```

**輸入：**

```
Harsh Agarwal
```

**輸出：**

```
Hello, Harsh Agarwal welcome to GfG!
```

**範例2：**我們可以使用getline()函數根據字符分割句子。讓我們看一個示例，了解如何完成此操作。

```
// C++ program to understand the use of getline() function 
  
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    string S, T; 
  
    getline(cin, S); 
  
    stringstream X(S); 
  
    while (getline(X, T, ' ')) { 
        cout << T << endl; 
    } 
  
    return 0; 
}
```

**輸入：**

```
Hello, Faisal Al Mamun. Welcome to GfG!
```

**輸出：**

```
Hello,
Faisal
Al
Mamun.
Welcome
to
GfG!
```

注意：此函數將換行符或(\ n)字符視為分隔符，並且換行符是此函數的有效輸入。

下麵給出了新行如何引起問題的示例：

**例：**

```
// C++ program to demonstrate 
// anomaly of delimitation of 
// getline() function 
#include <iostream> 
#include <string> 
using namespace std; 
  
int main() 
{ 
    string name; 
    int id; 
  
    // Taking id as input 
    cout << "Please enter your id:\n"; 
    cin >> id; 
  
    // Takes the empty character as input 
    cout << "Please enter your name:\n"; 
    getline(cin, name); 
  
    // Prints id 
    cout << "Your id:" << id << "\n"; 
  
    // Prints nothing in name field 
    // as "\n" is considered a valid string 
    cout << "Hello, " << name 
         << " welcome to GfG !\n"; 
  
    // Again Taking string as input 
    getline(cin, name); 
  
    // This actually prints the name 
    cout << "Hello, " << name 
         << " welcome to GfG !\n"; 
  
    return 0; 
}
```

**輸入：**

```
7
MOHIT KUMAR
```

**輸出：**

```
Your id:7
Hello,  welcome to GfG !
Hello, MOHIT KUMAR welcome to GfG !
```

 