#include <iostream>

#include "PriorityStack.h"
using namespace std;

void test1();

void test2();

void test3();

void test4();

void test5();

void test6();

int main() {
    int choice;
    char choiceStack;
    char choiseCreateStack;
    bool isCreateStack1 = false;
    bool isCreateStack2 = false;
    int countElement;
    int element;
    int priority;
    int elementGET;
    int priorityGET;
    int priorityGETDelete;
    int priorityCONTAINS;
    int elementCONTAINS;
    char choiceCONTAINS;
    int choiceDELETE;
    int choiceCOUNT;
    int priorityCOUNT;
    int valuePeek;
    int priorityPeek;
    PriorityStack stack1;
    PriorityStack stack2;
    PriorityStack result;
    system("chcp 65001");
    cout << "Мой вариант: " << (int('M') + int('S')) % 6 << endl << endl;
    do {
        cout << "Класс PriorityStack" << endl;
        cout << "Выберите функцию(введите число)" << endl << endl;
        cout << "1.Создать стек" << endl;
        cout << "2. Операции с одним стеком" << endl;
        cout << "\t a. Добавить элемент с приоритетом" << endl;
        cout << "\t b. Извлечь элемент (с удалением из очереди)" << endl;
        cout << "\t c. Вывести количество элементов (всего или с заданным приоритетом)" << endl;
        cout << "\t d. Прочитать элемент без удаления из очереди" << endl;
        cout << "\t e. Извлечь все элементы с определенным приоритетом" << endl;
        cout << "\t f. Проверить наличие элемента с учетом приоритета или без" << endl;
        cout << "\t g. Вывести стек" << endl;

        cout << "3. Объединение двух стеков" << endl;
        cout << "4. Разность двух стеков" << endl;
        cout << "5. Пересечение двух стеков" << endl;
        cout << "6. Сравнить два стека (==)" << endl;
        cout << "7. Сравнить два стека (!=)" << endl;
        cout << "8. Сравнить два стека (>)" << endl;
        cout << "9. Сравнить два стека (<)" << endl;
        cout << "10. Сравнить два стека (>=)" << endl;
        cout << "11. Сравнить два стека (<=)" << endl;
        cout << "12. Очистить стек" << endl;
        cout << "13. Запустить тесты номер 1 для операций с одним с стеком" << endl;
        cout << "14. Запустить тесты номер 2 для операций с одним с стеком" << endl;
        cout << "15. Запустить тесты номер 3 для операций с двумя стеками" << endl;
        cout << "16. Запустить тесты номер 4 для операций с одним с стеком(версия 2)" << endl;
        cout << "17. Запустить тесты номер 5 для операций с одним с стеком(версия 2)" << endl;
        cout << "18. Запустить тесты номер 6 для операций с двумя стеками(версия 2)" << endl;
        cout << "19. Выйти из программы" << endl;
        cin >> choice;
        while (cin.fail() || !(choice > 0 && choice < 20)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Неккоретный ввод" << endl;
            cout << "Введите число от 1 до 19, в зависимости от того, что хотите сделать" << endl;
            cin >> choice;
        }

        switch (choice) {
            case 1:
                if (stack1.count() == 0 && stack2.count() == 0) {
                    cout << "Стек 1 успешно создан" << endl;
                    isCreateStack1 = true;
                } else if (stack1.count() != 0 && stack2.count() == 0) {
                    cout << "Вы хотите создать второй стек?(Y-yes/N-no)" << endl;
                    cin >> choiseCreateStack;
                    while (cin.fail() || (choiseCreateStack != 'Y' && choiseCreateStack != 'N')) {
                        cin.clear();
                        cin.ignore(CHAR_MAX, '\n');
                        cout << "Неккоретный ввод" << endl;
                        cout << "Введите один символ (Y/N)" << endl;
                        cin >> choiseCreateStack;
                    }
                    if (choiseCreateStack == 'N') {
                        cout << "Второй стек не создан" << endl;
                    } else if (choiseCreateStack == 'Y') {
                        cout << "Второй стек успешно создан" << endl;
                        isCreateStack2 = true;
                    }
                } else if (stack1.count() != 0 && stack2.count() != 0) {
                    cout << "Операция невозжна, оба стека уже созданы" << endl;
                    cout << "Если хотите заново создать стек, удалите один из созданных" << endl;
                }
                break;
            case 2:
                if (isCreateStack1 == false && isCreateStack2 == false) {
                    cout << "Вы еще не создали стек, операция не возможна" << endl;
                } else if (isCreateStack1 == true && isCreateStack2 == false) {
                    do {
                        cout << "Работа с первым стеком" << endl;
                        cout << "a. Добавить элемент с приоритетом" << endl;
                        cout << "b. Извлечь элемент (с удалением из стека)" << endl;
                        cout << "c. Вывести количество элементов (всего или с заданным приоритетом)" << endl;
                        cout << "d. Прочитать элемент без удаления из стека" << endl;
                        cout << "e. Извлечь все элементы с определенным приоритетом" << endl;
                        cout << "f. Проверить наличие элемента с учетом приоритета или без" << endl;
                        cout << "g. Вывести стек" << endl;
                        cout << "h. Выйти из программы" << endl << endl;
                        cin >> choiceStack;
                        while (cin.fail() || (choiceStack != 'a' && choiceStack != 'b' && choiceStack != 'c' &&
                                              choiceStack
                                              != 'd' && choiceStack != 'e' && choiceStack != 'f' && choiceStack !=
                                              'g' && choiceStack != 'h')) {
                            cin.clear();
                            cin.ignore(CHAR_MAX, '\n');
                            cout << "Неккоретный ввод" << endl;
                            cout << "Введите один символ, в зависимости от того, что хотите сделать" << endl;
                            cin >> choiceStack;
                        }
                        switch (choiceStack) {
                            case 'a':
                                cout << "Введите кол-во элементов, которые хотите добавить" << endl;
                                cin >> countElement;
                                while (cin.fail() | countElement < 0) {
                                    cin.clear();
                                    cin.ignore(INT_MAX, '\n');
                                    cout << "Неккоретный ввод" << endl;
                                    cout << "Введите целое число" << endl;
                                    cin >> countElement;
                                }
                                for (int i = 0; i < countElement; i++) {
                                    cout << "Введите " << i + 1 << "-ый" << " элемент" << endl;
                                    cin >> element;
                                    while (cin.fail() | element < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> element;
                                    }
                                    cout << "Введите приоритет " << i + 1 << "-ого " << "элемента" << endl;
                                    cin >> priority;
                                    while (cin.fail() | priority < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> priority;
                                    }
                                    stack1.add(element, priority);
                                }
                                break;
                            case 'b':
                                if (stack1.count() == 0) {
                                    cout << "Стек пустой" << endl;
                                } else {
                                    cout << "Введите элемент, который хотите извлечь" << endl;
                                    cin >> elementGET;
                                    while (cin.fail() | elementGET < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> elementGET;
                                    }
                                    cout << "Введите приоритет элемента, который хотите извлечь" << endl;
                                    cin >> priorityGET;
                                    while (cin.fail() | priorityGET < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> priorityGET;
                                    }
                                    if (stack1.get(elementGET, priorityGET)) {
                                        cout << "Элемент " << elementGET << " с приоритетом " << priorityGET <<
                                                " удален из стека" << endl;
                                    } else {
                                        cout << "Элемента " << elementGET << " с приоритетом " << priorityGET <<
                                                " нет в стеке"
                                                << endl;
                                    }
                                }
                                break;
                            case 'c':
                                if (stack1.count() == 0) {
                                    cout << "Стек пуст" << endl;
                                } else {
                                    cout << "Введите цифру" << endl;
                                    cout << "1. Вывести кол-во всего элементов" << endl;
                                    cout << "2. Вывести кол-во элементов с конкретным приоритетом" << endl;
                                    cin >> choiceCOUNT;
                                    while (cin.fail() | (choiceCOUNT != 1 && choiceCOUNT != 2)) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число (1 или 2)" << endl;
                                        cin >> choiceCOUNT;
                                    }
                                    if (choiceCOUNT == 1) {
                                        cout << "Всего элементов в 1 стеке " << stack1.count() << endl;
                                    } else if (choiceCOUNT == 2) {
                                        cout << "Введите приоритет" << endl;
                                        cin >> priorityCOUNT;
                                        while (cin.fail() | priorityCOUNT <= 0) {
                                            cin.clear();
                                            cin.ignore(INT_MAX, '\n');
                                            cout << "Неккоретный ввод" << endl;
                                            cout << "Введите целое положительное число" << endl;
                                            cin >> priorityCOUNT;
                                        }
                                        cout << "Всего элементов c приоритетом " << priorityCOUNT << " в первом стеке "
                                                <<
                                                stack1.count(priorityCOUNT) << endl;
                                    } else {
                                        cout << "Некорректный ввод" << endl;
                                    }
                                }
                                break;
                            case 'd':
                                if (stack1.count() != 0) {
                                    stack1.peek(valuePeek, priorityPeek);
                                    cout << "Элемент " << valuePeek << " с приоритетом " << priorityPeek << endl;
                                } else {
                                    cout << "Стек пуст" << endl;
                                }
                                break;
                            case 'e':
                                if (stack1.count() == 0) {
                                    cout << "Стек пустой" << endl;
                                } else {
                                    cout << "Введите приоритет элементов, которые вы хотите удалить" << endl;
                                    cin >> priorityGETDelete;
                                    while (cin.fail() | priorityGETDelete < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> priorityGETDelete;
                                    }
                                    int *buffer;
                                    int countBuffer = stack1.get(priorityGETDelete, buffer);
                                    cout << "Извлечено " << countBuffer << " элементов с приоритетом " <<
                                            priorityGETDelete <<
                                            ":" << endl;
                                    for (int i = 0; i < countBuffer; i++) {
                                        cout << *(buffer + i) << " ";
                                    }
                                    cout << endl;
                                    delete[] buffer;
                                }
                                break;
                            case 'f':
                                if (stack1.count() == 0) cout << "Стек пуст" << endl;
                                else {
                                    cout << "Введите элемент, наличие которого хотите проверить" << endl;
                                    cin >> elementCONTAINS;
                                    while (cin.fail() | elementCONTAINS < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> elementCONTAINS;
                                    }
                                    cout << "Хотите проверить с учетом приоритета? (Y-yes/N-no)" << endl;
                                    cin >> choiceCONTAINS;
                                    while (cin.fail() || (choiceCONTAINS != 'Y' && choiceCONTAINS != 'N')) {
                                        cin.clear();
                                        cin.ignore(CHAR_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите один символ, в зависимости от того, что хотите сделать" <<
                                                endl;
                                        cin >> choiceCONTAINS;
                                    }
                                    if (choiceCONTAINS == 'Y') {
                                        cout << "Введите приоритет элемента, наличие которого хотите проверить" << endl;
                                        cin >> priorityCONTAINS;
                                        while (cin.fail() | priorityCONTAINS < 0) {
                                            cin.clear();
                                            cin.ignore(INT_MAX, '\n');
                                            cout << "Неккоретный ввод" << endl;
                                            cout << "Введите целое число" << endl;
                                            cin >> elementCONTAINS;
                                        }
                                        if (stack1.contains(elementCONTAINS, priorityCONTAINS)) {
                                            cout << "Элемент " << elementCONTAINS << " с приоритетом " <<
                                                    priorityCONTAINS <<
                                                    " содержится в стеке" << endl;
                                        } else {
                                            cout << "Элемента " << elementCONTAINS << " с приоритетом " <<
                                                    priorityCONTAINS <<
                                                    " нет в стеке" << endl;
                                        }
                                    }
                                }
                                break;
                            case 'g':
                                if (stack1.count() == 0) {
                                    cout << "Стек пуст" << endl;
                                } else {
                                    cout << stack1 << endl;
                                }
                                break;
                        }
                    } while (choiceStack != 'h');
                } else {
                    do {
                        cout << "Работа со вторым стеком" << endl;
                        cout << "a. Добавить элемент с приоритетом" << endl;
                        cout << "b. Извлечь элемент (с удалением из стека)" << endl;
                        cout << "c. Вывести количество элементов (всего или с заданным приоритетом)" << endl;
                        cout << "d. Прочитать элемент без удаления из стека" << endl;
                        cout << "e. Извлечь все элементы с определенным приоритетом" << endl;
                        cout << "f. Проверить наличие элемента с учетом приоритета или без" << endl;
                        cout << "g. Вывести стек" << endl;
                        cout << "h. Выйти из программы" << endl << endl;
                        cin >> choiceStack;
                        while (cin.fail() || (choiceStack != 'a' && choiceStack != 'b' && choiceStack != 'c' &&
                                              choiceStack
                                              != 'd' && choiceStack != 'e' && choiceStack != 'f' && choiceStack !=
                                              'g' && choiceStack != 'h')) {
                            cin.clear();
                            cin.ignore(CHAR_MAX, '\n');
                            cout << "Неккоретный ввод" << endl;
                            cout << "Введите один символ, в зависимости от того, что хотите сделать" << endl;
                            cin >> choiceStack;
                        }
                        switch (choiceStack) {
                            case 'a':
                                cout << "Введите кол-во элементов, которые хотите добавить" << endl;
                                cin >> countElement;
                                while (cin.fail() | countElement < 0) {
                                    cin.clear();
                                    cin.ignore(INT_MAX, '\n');
                                    cout << "Неккоретный ввод" << endl;
                                    cout << "Введите целое число" << endl;
                                    cin >> countElement;
                                }
                                for (int i = 0; i < countElement; i++) {
                                    cout << "Введите " << i + 1 << "-ый" << " элемент" << endl;
                                    cin >> element;
                                    while (cin.fail() | element < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> element;
                                    }
                                    cout << "Введите приоритет " << i + 1 << "-ого " << "элемента" << endl;
                                    cin >> priority;
                                    while (cin.fail() | priority < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> priority;
                                    }
                                    stack2.add(element, priority);
                                }
                                break;
                            case 'b':
                                if (stack2.count() == 0) {
                                    cout << "Стек пустой" << endl;
                                } else {
                                    cout << "Введите элемент, который хотите извлечь" << endl;
                                    cin >> elementGET;
                                    while (cin.fail() | elementGET < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> elementGET;
                                    }
                                    cout << "Введите приоритет элемента, который хотите извлечь" << endl;
                                    cin >> priorityGET;
                                    while (cin.fail() | priorityGET < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> priorityGET;
                                    }
                                    if (stack2.get(elementGET, priorityGET)) {
                                        cout << "Элемент " << elementGET << " с приоритетом " << priorityGET <<
                                                " удален из стека" << endl;
                                    } else {
                                        cout << "Элемента " << elementGET << " с приоритетом " << priorityGET <<
                                                " нет в стеке"
                                                << endl;
                                    }
                                }
                                break;
                            case 'c':
                                if (stack2.count() == 0) {
                                    cout << "Стек пуст" << endl;
                                } else {
                                    cout << "Введите цифру" << endl;
                                    cout << "1. Вывести кол-во всего элементов" << endl;
                                    cout << "2. Вывести кол-во элементов с конкретным приоритетом" << endl;
                                    cin >> choiceCOUNT;
                                    while (cin.fail() | (choiceCOUNT != 1 && choiceCOUNT != 2)) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число (1 или 2)" << endl;
                                        cin >> choiceCOUNT;
                                    }
                                    if (choiceCOUNT == 1) {
                                        cout << "Всего элементов в 1 стеке " << stack2.count() << endl;
                                    } else if (choiceCOUNT == 2) {
                                        cout << "Введите приоритет" << endl;
                                        cin >> priorityCOUNT;
                                        while (cin.fail() | priorityCOUNT <= 0) {
                                            cin.clear();
                                            cin.ignore(INT_MAX, '\n');
                                            cout << "Неккоретный ввод" << endl;
                                            cout << "Введите целое положительное число" << endl;
                                            cin >> priorityCOUNT;
                                        }
                                        cout << "Всего элементов c приоритетом " << priorityCOUNT << " в первом стеке "
                                                <<
                                                stack2.count(priorityCOUNT) << endl;
                                    } else {
                                        cout << "Некорректный ввод" << endl;
                                    }
                                }
                                break;
                            case 'd':
                                if (stack2.count() != 0) {
                                    stack2.peek(valuePeek, priorityPeek);
                                    cout << "Элемент " << valuePeek << " с приоритетом " << priorityPeek << endl;
                                } else {
                                    cout << "Стек пуст" << endl;
                                }
                                break;
                            case 'e':
                                if (stack2.count() == 0) {
                                    cout << "Стек пустой" << endl;
                                } else {
                                    cout << "Введите приоритет элементов, которые вы хотите удалить" << endl;
                                    cin >> priorityGETDelete;
                                    while (cin.fail() | priorityGETDelete < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> priorityGETDelete;
                                    }
                                    int *buffer;
                                    int countBuffer = stack2.get(priorityGETDelete, buffer);
                                    cout << "Извлечено " << countBuffer << " элементов с приоритетом " <<
                                            priorityGETDelete <<
                                            ":" << endl;
                                    for (int i = 0; i < countBuffer; i++) {
                                        cout << *(buffer + i) << " ";
                                    }
                                    cout << endl;
                                    delete[] buffer;
                                }
                                break;
                            case 'f':
                                if (stack2.count() == 0) cout << "Стек пуст" << endl;
                                else {
                                    cout << "Введите элемент, наличие которого хотите проверить" << endl;
                                    cin >> elementCONTAINS;
                                    while (cin.fail() | elementCONTAINS < 0) {
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите целое число" << endl;
                                        cin >> elementCONTAINS;
                                    }
                                    cout << "Хотите проверить с учетом приоритета? (Y-yes/N-no)" << endl;
                                    cin >> choiceCONTAINS;
                                    while (cin.fail() || (choiceCONTAINS != 'Y' && choiceCONTAINS != 'N')) {
                                        cin.clear();
                                        cin.ignore(CHAR_MAX, '\n');
                                        cout << "Неккоретный ввод" << endl;
                                        cout << "Введите один символ, в зависимости от того, что хотите сделать" <<
                                                endl;
                                        cin >> choiceCONTAINS;
                                    }
                                    if (choiceCONTAINS == 'Y') {
                                        cout << "Введите приоритет элемента, наличие которого хотите проверить" << endl;
                                        cin >> priorityCONTAINS;
                                        while (cin.fail() | priorityCONTAINS < 0) {
                                            cin.clear();
                                            cin.ignore(INT_MAX, '\n');
                                            cout << "Неккоретный ввод" << endl;
                                            cout << "Введите целое число" << endl;
                                            cin >> elementCONTAINS;
                                        }
                                        if (stack2.contains(elementCONTAINS, priorityCONTAINS)) {
                                            cout << "Элемент " << elementCONTAINS << " с приоритетом " <<
                                                    priorityCONTAINS <<
                                                    " содержится в стеке" << endl;
                                        } else {
                                            cout << "Элемента " << elementCONTAINS << " с приоритетом " <<
                                                    priorityCONTAINS <<
                                                    " нет в стеке" << endl;
                                        }
                                    }
                                }
                                break;
                            case 'g':
                                if (stack2.count() == 0) {
                                    cout << "Стек пуст" << endl;
                                } else {
                                    cout << stack2 << endl;
                                }
                                break;
                        }
                    } while (choiceStack != 'h');
                }
                break;
            case 3:
                if (isCreateStack1 == false || isCreateStack2 == false) {
                    cout << "Нужно создать два стека" << endl;
                } else {
                    result = stack1 + stack1;
                    cout << result << endl;
                }
                break;
            case 4:
                if (isCreateStack1 == false || isCreateStack2 == false) {
                    cout << "Нужно создать два стека" << endl;
                } else {
                    result = stack1 - stack2;
                    cout << result << endl;
                }
                break;
            case 5:
                if (isCreateStack1 == false || isCreateStack2 == false) {
                    cout << "Нужно создать два стека" << endl;
                } else {
                    result = stack1 & stack2;
                    cout << result << endl;
                }
                break;
            case 6:
                if (isCreateStack1 == false || isCreateStack2 == false) {
                    cout << "Нужно создать два стека" << endl;
                } else {
                    if (stack1 == stack2) {
                        cout << "Два стека равны" << endl;
                    } else {
                        cout << "Два стека не равны" << endl;
                    };
                }
                break;
            case 7:
                if (isCreateStack1 == false || isCreateStack2 == false) {
                    cout << "Нужно создать два стека" << endl;
                } else {
                    if (stack1 != stack2) {
                        cout << "Два стека не равны" << endl;
                    } else {
                        cout << " Два стека равны" << endl;
                    }
                }
                break;
            case 8:
                if (isCreateStack1 == false || isCreateStack2 == false) {
                    cout << "Нужно создать два стека" << endl;
                } else {
                    if (stack1 > stack2) {
                        cout << "Стек 1 больше стека 2" << endl;
                    } else {
                        cout << "Стек 1 не больше стека 1" << endl;
                    }
                }
                break;
            case 9:
                if (isCreateStack1 == false || isCreateStack2 == false) {
                    cout << "Нужно создать два стека" << endl;
                } else {
                    if (stack1 < stack2) {
                        cout << "Стек 1 меньше стека 2" << endl;
                    } else {
                        cout << "Стек 1 не меньше стека 2" << endl;
                    }
                }
                break;
            case 10:
                if (isCreateStack1 == false || isCreateStack2 == false) {
                    cout << "Нужно создать два стека" << endl;
                } else {
                    if (stack1 >= stack2) {
                        cout << "Стек 1 больше или равен 2-ого стека" << endl;
                    } else {
                        cout << "Стек 1 меньше 2-ого стека" << endl;
                    }
                }
                break;
            case 11:
                if (isCreateStack1 == false || isCreateStack2 == false) {
                    cout << "Нужно создать два стека" << endl;
                } else {
                    if (stack1 <= stack2) {
                        cout << "Стек 1 меньше или равен 2-ого стека" << endl;
                    } else {
                        cout << "Стек 1 больше 2-ого стека" << endl;
                    }
                }
                break;

            case 12:
                cout << "Какой хотите очистить стек?" << endl;
                cout << "Введите число 1 или 2" << endl;
                cin >> choiceDELETE;
                while (cin.fail() || !(choiceDELETE == 1 || choiceDELETE == 2)) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Неккоретный ввод" << endl;
                    cout << "Введите число от 1 до 2, в зависимости от того, что хотите сделать" << endl;
                    cin >> choiceDELETE;
                }
                if (choiceDELETE == 1) {
                    if (isCreateStack1 == true) {
                        stack1.clear();
                    } else {
                        cout << "Вы еще не создавали первый стек" << endl;
                    }
                }
                if (choiceDELETE == 2) {
                    if (isCreateStack2 == true) {
                        stack2.clear();
                    } else {
                        cout << "Вы еще не создавали второй стек" << endl;
                    }
                }
                break;
            case 13:
                test1();
                break;
            case 14:
                test2();
                break;
            case 15:
                test3();
                break;
            case 16:
                test4();
                break;
            case 17:
                test5();
                break;
            case 18:
                test6();
                break;
        }
    } while (choice != 19);
}

void test1() {
    PriorityStack stack1Test1;
    int testGetpriorityTest1;
    int *bufferGetTest1;

    cout << "Тест функции Add" << endl;

    cout << "Добавление элементов: " << "(10,10); (11,11); (3,2); (5,1); (4,6); (5,7)" << endl;
    stack1Test1.add(10, 10);
    stack1Test1.add(11, 11);
    stack1Test1.add(3, 2);
    stack1Test1.add(5, 1);
    stack1Test1.add(4, 6);
    stack1Test1.add(5, 7);
    cout << "Вывод стека" << endl << endl;
    cout << stack1Test1 << endl;

    cout << endl;

    cout << "Тест функции Get" << endl;

    cout << "Извлекаем из стека (3,2) (с удалением из стека)" << endl;
    int priorityTest1 = 3;
    int valueTest2 = 2;

    if (stack1Test1.get(valueTest2, priorityTest1)) {
        cout << "Элемент (3,2) удален из стека" << endl;
    } else {
        cout << "Такого элемента нет в стеке" << endl;
    }
    cout << "Вывод стека" << endl << endl;
    cout << stack1Test1 << endl;

    cout << "Тест функции Count с подсчетом всех элементов" << endl;

    cout << stack1Test1.count() << endl;

    cout << "Вывод стека" << endl << endl;
    cout << stack1Test1 << endl;


    cout << "Тест функции Count с подсчетом всех элементов c приоритетом 11" << endl;

    cout << stack1Test1.count(11) << endl;

    cout << "Вывод стека" << endl << endl;
    cout << stack1Test1 << endl;

    cout << "Тест функции Peek" << endl;
    int value;
    int priority;
    stack1Test1.peek(value, priority);
    cout << "Элемент " << value << " с приоритетом " << priority << endl;
    cout << "Верный ответ: (11 11)" << endl;

    cout << "Тест функции Get" << endl;
    cout << "Извлекаем элементы с приоритетом 6" << endl;

    testGetpriorityTest1 = 6;
    int countBuffer = stack1Test1.get(testGetpriorityTest1, bufferGetTest1);
    cout << "Извлечено " << countBuffer << " элементов с приоритетом " <<
            testGetpriorityTest1 <<
            ":" << endl;
    for (int i = 0; i < countBuffer; i++) {
        cout << *(bufferGetTest1 + i) << " ";
    }
    cout << endl;
    delete[] bufferGetTest1;

    cout << endl;
    cout << stack1Test1 << endl;
    cout << "Тест функции Contains" << endl;
    cout << "Проверяем есть ли в стеке элемент (5,1)" << endl;
    if (stack1Test1.contains(5, 1)) {
        cout << "Да, в стеке есть элемент (5,1)" << endl;
    } else cout << "Нет, такого элемента нет" << endl;
}

void test2() {
    PriorityStack stack1Test2;
    int testGetpriorityTest2;
    int *bufferGetTest2;
    cout << "Тест функции Add" << endl;

    cout << "Добавление элементов: " << "(17,17); (20,20); (25,30); (10,7); (11,15)" << endl;
    stack1Test2.add(17, 17);
    stack1Test2.add(20, 20);
    stack1Test2.add(25, 30);
    stack1Test2.add(10, 7);
    stack1Test2.add(11, 15);
    cout << "Вывод стека" << endl << endl;
    cout << stack1Test2 << endl;
    cout << endl;

    cout << "Тест функции Get" << endl;

    cout << "Извлекаем из стека (2,2) (с удалением из стека)" << endl;
    int priorityTest1 = 2;
    int valueTest2 = 2;
    if (stack1Test2.get(valueTest2, priorityTest1)) {
        cout << "Элемент (2,2) удален из стека" << endl;
    } else {
        cout << "Такого элемента нет" << endl;
    }
    cout << "Вывод стека" << endl << endl;
    cout << stack1Test2 << endl;

    cout << "Тест функции Count с подсчетом всех элементов" << endl;

    cout << stack1Test2.count() << endl;

    cout << "Вывод стека" << endl << endl;
    cout << stack1Test2 << endl;


    cout << "Тест функции Count с подсчетом всех элементов c приоритетом 11" << endl;

    cout << stack1Test2.count(11) << endl;

    cout << "Вывод стека" << endl << endl;
    cout << stack1Test2 << endl;

    cout << "Тест функции Peek" << endl;
    int value;
    int priority;
    stack1Test2.peek(value, priority);
    cout << "Элемент " << value << " с приоритетом " << priority << endl;
    cout << "Верный ответ: (25,30)" << endl;

    cout << "Тест функции Get" << endl;
    cout << "Извлекаем элементы с приоритетом 6" << endl;

    testGetpriorityTest2 = 6;
    int countBuffer = stack1Test2.get(testGetpriorityTest2, bufferGetTest2);
    cout << "Извлечено " << countBuffer << " элементов с приоритетом " <<
            testGetpriorityTest2 <<
            ":" << endl;
    for (int i = 0; i < countBuffer; i++) {
        cout << *(bufferGetTest2 + i) << " ";
    }
    cout << endl;
    delete[] bufferGetTest2;

    cout << endl;
    cout << stack1Test2 << endl;

    cout << "Тест функции Contains" << endl;
    cout << "Проверяем есть ли в стеке элемент (10,100)" << endl;
    if (stack1Test2.contains(10, 100)) {
        cout << "Да, в стеке есть элемент (10,100)" << endl;
    } else cout << "Нет, такого элемента нет" << endl;
}

void test3() {
    PriorityStack stack1Test3;
    stack1Test3.add(17, 17);
    stack1Test3.add(20, 20);
    stack1Test3.add(25, 30);
    stack1Test3.add(10, 7);
    stack1Test3.add(11, 15);

    PriorityStack stack2Test3;
    stack2Test3.add(12, 11);
    stack2Test3.add(22, 5);
    stack2Test3.add(29, 2);
    stack2Test3.add(10, 10);
    stack2Test3.add(16, 5);

    PriorityStack resultTest3;

    cout << "Тест operator+" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    cout << "Результирующий стек" << endl;
    resultTest3 = stack1Test3 + stack2Test3;

    cout << resultTest3 << endl;
    cout << "Верный ответ: (29, 2) (16, 5) (22, 5) (10, 7) (10, 10) (12, 11) (11, 15) (17, 17) (20, 20) (25, 30)" <<
            endl;
    cout << "Тест operator-" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    cout << "Результирующий стек" << endl;
    resultTest3 = stack1Test3 - stack2Test3;
    cout << resultTest3 << endl;
    cout << "Верный ответ: (10, 7) (11, 15) (17, 17) (20, 20) (25, 30)" << endl;

    cout << "Тест operator&" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    cout << "Результирующий стек" << endl;
    resultTest3 = stack1Test3 & stack2Test3;
    cout << resultTest3 << endl;
    cout << "Верный ответ: Стек " << endl;


    cout << "Тест operator==" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 == stack2Test3) {
        cout << "Стеки равны" << endl;
    } else {
        cout << "Стеки не равны" << endl;
    }
    cout << "Верный ответ: стеки не равны" << endl;

    cout << "Тест operator!=" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 != stack2Test3) {
        cout << "Стеки не равны" << endl;
    } else {
        cout << "Стеки равны" << endl;
    }

    cout << "Верный ответ: стеки не равны" << endl;


    cout << "Тест operator>" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 > stack2Test3) {
        cout << "Стек1 больше стек2" << endl;
    } else {
        cout << "Стек1 не больше стек2" << endl;
    }
    cout << "Верный ответ: Стек1 больше стек2" << endl;
    cout << "Тест operator<" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 < stack2Test3) {
        cout << "Стек1 меньше стек2" << endl;
    } else {
        cout << "Стек1 не меньше стек2" << endl;
    }
    cout << "Верный ответ: Стек1 не меьнше стек2" << endl;
    cout << "Тест operator>=" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 >= stack2Test3) {
        cout << "Стек1 больше или равен стек2" << endl;
    } else {
        cout << "Стек1 меньше стек2" << endl;
    }
    cout << "Верный ответ: стек1 больше или равен стек2" << endl;

    cout << "Тест operator<=" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 <= stack2Test3) {
        cout << "Стек1 меньше или равен стек2" << endl;
    } else {
        cout << "Стек1 больше стек2" << endl;
    }
    cout << "Верный ответ: стек1 больше стек2" << endl;
}


void test4() {
    PriorityStack stack1Test1;
    int testGetpriorityTest1;
    int *bufferGetTest1;

    cout << "Тест функции Add" << endl;

    cout << "Добавление элементов: " << "(3,3); (12,19); (3,3); (8,3); (1,6); (13,7)" << endl;
    stack1Test1.add(3, 3);
    stack1Test1.add(12, 19);
    stack1Test1.add(3, 3);
    stack1Test1.add(8, 3);
    stack1Test1.add(1, 6);
    stack1Test1.add(13, 7);
    cout << "Вывод стека" << endl << endl;
    cout << stack1Test1 << endl;

    cout << endl;

    cout << "Тест функции Get" << endl;

    cout << "Извлекаем из стека (8,3) (с удалением из стека)" << endl;
    int priorityTest1 = 8;
    int valueTest2 = 3;

    if (stack1Test1.get(valueTest2, priorityTest1)) {
        cout << "Элемент (8,3) удален из стека" << endl;
    } else {
        cout << "Такого элемента нет в стеке" << endl;
    }
    cout << "Вывод стека" << endl << endl;
    cout << stack1Test1 << endl;

    cout << "Тест функции Count с подсчетом всех элементов" << endl;

    cout << stack1Test1.count() << endl;

    cout << "Вывод стека" << endl << endl;
    cout << stack1Test1 << endl;


    cout << "Тест функции Count с подсчетом всех элементов c приоритетом 3" << endl;

    cout << stack1Test1.count(3) << endl;

    cout << "Вывод стека" << endl << endl;
    cout << stack1Test1 << endl;

    cout << "Тест функции Peek" << endl;
    int value;
    int priority;
    stack1Test1.peek(value, priority);
    cout << "Элемент " << value << " с приоритетом " << priority << endl;
    cout << "Верный ответ: (12 19)" << endl;

    cout << "Тест функции Get" << endl;
    cout << "Извлекаем элементы с приоритетом 7" << endl;

    testGetpriorityTest1 = 7;
    int countBuffer = stack1Test1.get(testGetpriorityTest1, bufferGetTest1);
    cout << "Извлечено " << countBuffer << " элементов с приоритетом " <<
            testGetpriorityTest1 <<
            ":" << endl;
    for (int i = 0; i < countBuffer; i++) {
        cout << *(bufferGetTest1 + i) << " ";
    }
    cout << endl;
    delete[] bufferGetTest1;

    cout << endl;
    cout << stack1Test1 << endl;
    cout << "Тест функции Contains" << endl;
    cout << "Проверяем есть ли в стеке элемент (100,100)" << endl;
    if (stack1Test1.contains(100, 100)) {
        cout << "Да, в стеке есть элемент (100,100)" << endl;
    } else cout << "Нет, такого элемента нет" << endl;
}

void test5() {
    PriorityStack stack1Test2;
    int testGetpriorityTest2;
    int *bufferGetTest2;
    cout << "Тест функции Add" << endl;

    cout << "Добавление элементов: " << "(32,10); (10,20); (19,32); (10,2)" << endl;
    stack1Test2.add(32, 10);
    stack1Test2.add(10, 20);
    stack1Test2.add(19, 32);
    stack1Test2.add(10, 2);
    cout << "Вывод стека" << endl << endl;
    cout << stack1Test2 << endl;
    cout << endl;

    cout << "Тест функции Get" << endl;

    cout << "Извлекаем из стека (0,0) (с удалением из стека)" << endl;
    int priorityTest1 = 0;
    int valueTest2 = 0;
    if (stack1Test2.get(valueTest2, priorityTest1)) {
        cout << "Элемент (0,0) удален из стека" << endl;
    } else {
        cout << "Такого элемента нет" << endl;
    }
    cout << "Вывод стека" << endl << endl;
    cout << stack1Test2 << endl;

    cout << "Тест функции Count с подсчетом всех элементов" << endl;

    cout << stack1Test2.count() << endl;

    cout << "Вывод стека" << endl << endl;
    cout << stack1Test2 << endl;


    cout << "Тест функции Count с подсчетом всех элементов c приоритетом 100" << endl;

    cout << stack1Test2.count(100) << endl;

    cout << "Вывод стека" << endl << endl;
    cout << stack1Test2 << endl;

    cout << "Тест функции Peek" << endl;
    int value;
    int priority;
    stack1Test2.peek(value, priority);
    cout << "Элемент " << value << " с приоритетом " << priority << endl;
    cout << "Верный ответ: (19,32)" << endl;

    cout << "Тест функции Get" << endl;
    cout << "Извлекаем элементы с приоритетом 10" << endl;

    testGetpriorityTest2 = 10;
    int countBuffer = stack1Test2.get(testGetpriorityTest2, bufferGetTest2);
    cout << "Извлечено " << countBuffer << " элементов с приоритетом " <<
            testGetpriorityTest2 <<
            ":" << endl;
    for (int i = 0; i < countBuffer; i++) {
        cout << *(bufferGetTest2 + i) << " ";
    }
    cout << endl;
    delete[] bufferGetTest2;

    cout << endl;
    cout << stack1Test2 << endl;

    cout << "Тест функции Contains" << endl;
    cout << "Проверяем есть ли в стеке элемент (10,20)" << endl;
    if (stack1Test2.contains(10, 20)) {
        cout << "Да, в стеке есть элемент (10,20)" << endl;
    } else cout << "Нет, такого элемента нет" << endl;
}

void test6() {
    PriorityStack stack1Test3;
    stack1Test3.add(34, 17);
    stack1Test3.add(20, 20);
    stack1Test3.add(3, 27);
    stack1Test3.add(10, 10);
    stack1Test3.add(30, 30);

    PriorityStack stack2Test3;
    stack2Test3.add(34, 17);
    stack2Test3.add(20, 5);
    stack2Test3.add(3, 10);
    stack2Test3.add(10, 10);
    stack2Test3.add(16, 5);

    PriorityStack resultTest3;

    cout << "Тест operator+" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    cout << "Результирующий стек" << endl;
    resultTest3 = stack1Test3 + stack2Test3;

    cout << resultTest3 << endl;
    cout << "Верный ответ: (16, 5) (20, 5) (3, 10) (10, 10) (10, 10) (34, 17) (34, 17) (20, 20) (3, 27) (30, 30)" <<
            endl;
    cout << "Тест operator-" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    cout << "Результирующий стек" << endl;
    resultTest3 = stack1Test3 - stack2Test3;
    cout << resultTest3 << endl;
    cout << "Верный ответ: (20, 20) (3, 27) (30, 30)" << endl;
    cout << "Тест operator&" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    cout << "Результирующий стек" << endl;
    resultTest3 = stack1Test3 & stack2Test3;
    cout << resultTest3 << endl;
    cout << "Верный ответ: (10, 10) (34, 17)" << endl;

    cout << "Тест operator==" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 == stack2Test3) {
        cout << "Стеки равны" << endl;
    } else {
        cout << "Стеки не равны" << endl;
    }
    cout << "Верный ответ: Стеки не равны" << endl;
    cout << "Тест operator!=" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 != stack2Test3) {
        cout << "Стеки не равны" << endl;
    } else {
        cout << "Стеки равны" << endl;
    }
    cout << "Верный ответ: Стеки не равны" << endl;


    cout << "Тест operator>" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 > stack2Test3) {
        cout << "Стек1 больше стек2" << endl;
    } else {
        cout << "Стек1 не больше стек2" << endl;
    }
    cout << "Верный ответ: Стек1 больше стек2" << endl;
    cout << "Тест operator<" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 < stack2Test3) {
        cout << "Стек1 меньше стек2" << endl;
    } else {
        cout << "Стек1 не меньше стек2" << endl;
    }
    cout << "Верный ответ: Стек1 не меньше стек2" << endl;

    cout << "Тест operator>=" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 >= stack2Test3) {
        cout << "Стек1 больше или равен стек2" << endl;
    } else {
        cout << "Стек1 меньше стек2" << endl;
    }
    cout << "Верный ответ: Стек1 больше или равен стек2" << endl;


    cout << "Тест operator<=" << endl;

    cout << "Первый стек" << endl;
    cout << stack1Test3 << endl;
    cout << "Второй стек" << endl;
    cout << stack2Test3 << endl;
    if (stack1Test3 <= stack2Test3) {
        cout << "Стек1 меньше или равен стек2" << endl;
    } else {
        cout << "Стек1 больше стек2" << endl;
    }
    cout << "Верный ответ: Стек1 больше стек2" << endl;
}
