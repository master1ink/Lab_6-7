#include <iostream>
#include "function.h"

int main() {
    int R;
    int choice=0;
    struct book *st = nullptr;
    while (true) {
        cout << "\n1. Dynamically allocating memory for an array structures.\n"
                "2. Entering array elements from the keyboard.\n"
                "3. Search for an array element.\n"
                "4. Sorting the array.\n"
                "5. Editing an array element.\n"
                "6. Adding a new element to the end.\n"
                "7. Removes the specified element from the array.\n"
                "8. Insert a new item.\n"
                "9. Writing array elements to a file.\n"
                "10. Reading array elements from a file.\n"
                "11. Displaying array elements on the screen.\n"
                "12. Freeing the memory allocated for the array.\n"
                "13. The end of the program.\n"
                "Input:";
        TestNum(choice);
        switch (choice) {
            case 1:
                cout << "Enter the number of books:";
                TestNum(R);
                MemoryAllocation(st, R);
                break;
            case 2:
                EnterElements(st, R);
                break;
            case 3:
                SearchElement(st, R);
                break;
            case 4:
                BookSort(st, R);
                break;
            case 5:
                ReWriteElement(st, R);
                break;
            case 6:
                AddNewElement(st, R);
                break;
            case 7:
                DeleteElement(st, R);
                break;
            case 8:
                InsertElement(st, R);
                break;
            case 9:
                RemoveSpaces(st, R);
                WriteToFile(st, R);
                AddSpaces(st, R);
                break;
            case 10:
                ReadFromFile(st, R);
                AddSpaces(st, R);
                break;
            case 11:
                OutPutElements(st, R);
                break;
            case 12:
                DeleteMemory(st);
                break;
            case 13:
                EndProgram(st);
                return 0;
            default:
                cout << "You have entered an item that is not in the menu.\n";
                break;
        }
    }
}