# C++ getline() Note

�O�@�ؼзǮw��ơA�Ω�q��J�y��Ū���r�Ŧ�Φ�C���O<string>���Y���@�����C getline()��Ʊq��J�y�������r�šA�ñN����[��r�Ŧ��H�A����J��w�ɦr�šC�o�˰��ɡA���e�b�r�Ŧ��Hstr���s�x���ȱN�Q��J�r�Ŧ����(�p�G��)�C

getline()��ƥi�H��ؤ覡��ܡG

1. �Ϊk:

   ```
   istream& getline(istream& is, 
              string& str, char delim);
   ```

   **�ѼơG**

   - **is:**���Oistream������H�A���i�D��Ʀ����q��BŪ����J���y�C
   - **str:**�o�O�@�Ӧr�Ŧ��H�A�q�y��Ū����J��A�N��J�s�x�b����H���C
   - **delim:**���O�w�ɦr�šA���i�D��Ʀb�F��Ӧr�ūᰱ��Ū���i�@�B����J�C

   **��^�ȡG**����ƪ�^�P�@���ѼƱ�������J�y�ۦP����J�y�C

2. �Ϊk:

   ```
   istream& getline (istream& is, string& str);
   ```

   �ĤG���n���P�Ĥ@���n���X�G�ۦP�C�ߤ@���ϧO�O�A��̤���������w�ɦr�šC

   **�ѼơG**

   - **is:**���Oistream������H�A���i�D��Ʀ����q��BŪ����J���y�C
   - **str:**�o�O�@�Ӧr�Ŧ��H�A�q�y��Ū����J��A�N��J�s�x�b����H���C

   **��^�ȡG**����ƪ�^�P�@���ѼƱ�������J�y�ۦP����J�y�C

�U�Ѫ��{�Ǻt�ܤFgetline()��ƪ��u�@

**�d��1�G**

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

**��J�G**

```
Harsh Agarwal
```

**��X�G**

```
Hello, Harsh Agarwal welcome to GfG!
```

**�d��2�G**�ڭ̥i�H�ϥ�getline()��Ʈھڦr�Ť��Υy�l�C���ڭ̬ݤ@�ӥܨҡA�F�Ѧp�󧹦����ާ@�C

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

**��J�G**

```
Hello, Faisal Al Mamun. Welcome to GfG!
```

**��X�G**

```
Hello,
Faisal
Al
Mamun.
Welcome
to
GfG!
```

�`�N�G����ƱN����ũ�(\ n)�r�ŵ������j�šA�åB����ŬO����ƪ����Ŀ�J�C

�U�ѵ��X�F�s��p��ް_���D���ܨҡG

**�ҡG**

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

**��J�G**

```
7
MOHIT KUMAR
```

**��X�G**

```
Your id:7
Hello,  welcome to GfG !
Hello, MOHIT KUMAR welcome to GfG !
```

 