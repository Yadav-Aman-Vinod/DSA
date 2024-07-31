/*
Stack is (LIFO) last in first out data structure.
Stores data inform like a vertical tower
push() - to add to top
pop() - to remove from top
ex: 1
    2
    3
    4
(now add 5)
(it will become)
    5
    1
    2
    3
    4
(now remove 5)
(it will become)
    1
    2
    3
    4
(to access 4 in the bottom, we have to pop everything on the top till 4)
(it will become)
    4

Stack can be used in:
1. Undo/redo in text-editor;
2. Moving back and forward between browser;
3. Backtracking algorithm like using it in a maze;
*/


/*
//(Basic Stack)

#include <iostream>
using namespace std;
#include <stack>

int main() {
    stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

   cout << "Top element is: " << myStack.top() << endl; // 30

    myStack.pop();
    cout << "Top element after pop is: " << myStack.top() << endl; // 20

    cout << "Stack size is: " << myStack.size() << endl; // 2

    return 0;
}
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack;
    int choice;
    int value;

    while (true) {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                myStack.push(value);
                cout << value << " pushed onto the stack.\n";
                break;
            case 2:
                if (!myStack.empty()) {
                    cout << myStack.top() << " popped from the stack.\n";
                    myStack.pop();
                } else {
                    cout << "Stack is empty. Cannot pop.\n";
                }
                break;
            case 3:
                if (!myStack.empty()) {
                    cout << "Top element is: " << myStack.top() << endl;
                } else {
                    cout << "Stack is empty.\n";
                }
                break;
            case 4:
                cout << "Stack size is: " << myStack.size() << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

