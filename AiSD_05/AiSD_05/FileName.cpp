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
                return false; // ������ �����������, �� ���� ������
            }
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return false; // ������ �����������, �� �� ������������� ����������� ������ �� ������� �����
            }
        }
    }
    return s.empty(); // ���� ������ ���� ������ � �����, ���� ��� ������ ��������������
}

int main() {
    setlocale(LC_ALL, "ru");

    string str;
    cout << "������� ������ �� ��������: ";
    getline(cin, str);

    if (checkBrackets(str)) {
        cout << "������ ����������� �����" << endl;
    }
    else {
        cout << "������ ����������� �������" << endl;
    }

    return 0;
}
