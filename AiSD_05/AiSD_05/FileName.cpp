#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkBrackets(const string& str) {
    stack<char> s;
    for (char ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) {
                return false; // Скобка закрывается, но стек пустой
            }
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return false; // Скобка закрывается, но не соответствует открывающей скобке на вершине стека
            }
        }
    }
    return s.empty(); // Стек должен быть пустым в конце, если все скобки сбалансированы
}

int main() {
    setlocale(LC_ALL, "ru");

    string str;
    cout << "Введите строку со скобками: ";
    getline(cin, str);

    if (checkBrackets(str)) {
        cout << "Скобки расставлены верно" << endl;
    }
    else {
        cout << "Скобки расставлены неверно" << endl;
    }

    return 0;
}
