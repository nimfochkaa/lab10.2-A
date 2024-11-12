#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Speciality { COMPUTER_SCIENCE, PHYSICS, MATH };
string specialityStr[] = { "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

struct Student {
    string lastName;
    int course;
    Speciality speciality;
    int physics;
    int math;
    int informatics;
};

void PhysicalSort(Student* students, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if ((students[j].course > students[j + 1].course) ||
                (students[j].course == students[j + 1].course && students[j].math < students[j + 1].math) ||
                (students[j].course == students[j + 1].course && students[j].math == students[j + 1].math && students[j].lastName < students[j + 1].lastName)) {

                swap(students[j], students[j + 1]);
            }
        }
    }
}

int* IndexSort(const Student* students, const int N) {
    int* indexArray = new int[N];
    for (int i = 0; i < N; ++i)
        indexArray[i] = i;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            int a = indexArray[j];
            int b = indexArray[j + 1];
            if ((students[a].course > students[b].course) ||
                (students[a].course == students[b].course && students[a].math < students[b].math) ||
                (students[a].course == students[b].course && students[a].math == students[b].math && students[a].lastName > students[b].lastName)) {

                swap(indexArray[j], indexArray[j + 1]);
            }
        }
    }
    return indexArray;
}

void PrintIndexSorted(const Student* students, const int* indexArray, const int N) {
    cout << "=================================================================================================" << endl;
    cout << "| �   | �������          | ���� | ������������           | Գ����  | ���������� | ����������� |" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        int idx = indexArray[i];
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(18) << left << students[idx].lastName
            << "| " << setw(4) << right << students[idx].course << " "
            << "| " << setw(24) << left << specialityStr[students[idx].speciality]
            << "| " << setw(7) << right << students[idx].physics << " "
            << "| " << setw(10) << right << students[idx].math << " "
            << "| " << setw(11) << right << students[idx].informatics << " |" << endl;
    }
    cout << "=================================================================================================" << endl;
}

int BinSearch(const Student* students, int N, string lastName, int course, int math) {
    int L = 0, R = N - 1;
    while (L <= R) {
        int m = (L + R) / 2;
        if (students[m].course == course && students[m].math == math && students[m].lastName == lastName)
            return m;
        if ((students[m].course < course) ||
            (students[m].course == course && students[m].math > math) ||
            (students[m].course == course && students[m].math == math && students[m].lastName < lastName)) {
            L = m + 1;
        }
        else {
            R = m - 1;
        }
    }
    return -1;
}

void Create(Student* students, const int N) {
    int speciality;
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;

        cin.ignore();
        cout << " �������: ";
        getline(cin, students[i].lastName);

        while (true) {
            cout << " ���� (1-5): ";
            cin >> students[i].course;
            if (cin.fail() || students[i].course < 1 || students[i].course > 5) {
                cout << "�������! ������ ���� ����� �� 1 �� 5." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else break;
        }

        while (true) {
            cout << " ������������ (0 - ���������� �� ��������, 1 - Գ���� �� �����������, 2 - ������� ��������): ";
            cin >> speciality;
            if (cin.fail() || speciality < 0 || speciality > 2) {
                cout << "�������! ������ �������� �� 0 �� 2." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else {
                students[i].speciality = static_cast<Speciality>(speciality);
                break;
            }
        }

        while (true) {
            cout << " ������ � ������ (1-5): ";
            cin >> students[i].physics;
            if (cin.fail() || students[i].physics < 1 || students[i].physics > 5) {
                cout << "�������! ������ ������ �� 1 �� 5." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else break;
        }

        while (true) {
            cout << " ������ � ���������� (1-5): ";
            cin >> students[i].math;
            if (cin.fail() || students[i].math < 1 || students[i].math > 5) {
                cout << "�������! ������ ������ �� 1 �� 5." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else break;
        }

        while (true) {
            cout << " ������ � ����������� (1-5): ";
            cin >> students[i].informatics;
            if (cin.fail() || students[i].informatics < 1 || students[i].informatics > 5) {
                cout << "�������! ������ ������ �� 1 �� 5." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else break;
        }

        cout << endl;
    }
}

void Print(const Student* students, const int N) {
    cout << "=================================================================================================" << endl;
    cout << "| �   | �������          | ���� | ������������           | Գ����  | ���������� | ����������� |" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(18) << left << students[i].lastName
            << "| " << setw(4) << right << students[i].course << " "
            << "| " << setw(24) << left << specialityStr[students[i].speciality]
            << "| " << setw(7) << right << students[i].physics << " "
            << "| " << setw(10) << right << students[i].math << " "
            << "| " << setw(11) << right << students[i].informatics << " |" << endl;
    }
    cout << "=================================================================================================" << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice, N = 0;
    Student* students = nullptr;

    do {
        cout << "\n����:\n";
        cout << "1. ������ ��� ��������\n";
        cout << "2. ������� ��� ��������\n";
        cout << "3. Գ����� ����������\n";
        cout << "4. �������� ����������\n";
        cout << "5. ����� ��������\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (students != nullptr) delete[] students;
            cout << "������ ������� ��������: ";
            cin >> N;
            students = new Student[N];
            Create(students, N);
            break;
        case 2:
            if (students) Print(students, N);
            else cout << "��� ������! �������� ������ ��� ��������.\n";
            break;
        case 3:
            if (students) {
                PhysicalSort(students, N);
                cout << "��� ���������� �������.\n";
            }
            else cout << "��� ������! �������� ������ ��� ��������.\n";
            break;
        case 4:
            if (students) {
                int* indexArray = IndexSort(students, N);
                PrintIndexSorted(students, indexArray, N);
                delete[] indexArray;
            }
            else cout << "��� ������! �������� ������ ��� ��������.\n";
            break;
        case 5:
            if (students) {
                string lastName;
                int course, math;
                cout << "�������: ";
                cin >> lastName;
                cout << "����: ";
                cin >> course;
                cout << "������ � ����������: ";
                cin >> math;
                int index = BinSearch(students, N, lastName, course, math);
                if (index != -1) cout << "������� ���������: " << students[index].lastName << endl;
                else cout << "�������� �� ��������.\n";
            }
            else cout << "��� ������! �������� ������ ��� ��������.\n";
            break;
        case 0:
            cout << "�����...\n";
            break;
        default:
            cout << "������������ ����! ��������� �����.\n";
            break;
        }
    } while (choice != 0);

    if (students) delete[] students;
    return 0;
}
