#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "function.h"

void TestNum(int &R) {
    char numb[25], *p=numb, *end;
    bool if_num= true;
    gets(numb);
    while (*p) {
        if(!isdigit(*p++)) {
            if_num= false;
        }
        if (if_num) {
            R=strtol(numb, &end, 10);
        } else {
            R=0;
        }
    }
}

void RemoveSpaces(book* &st, int &R) {
    string temp;
    char c='.';

    for (int i = 0; i < R; ++i) {
        temp = st[i].title;
        for(char & j : temp){
            if(j == ' ')
                j = c;
        }
        strcpy(st[i].title, temp.c_str());
    }

    for (int i = 0; i < R; ++i) {
        temp = st[i].author;
        for(char & j : temp){
            if(j == ' ')
                j = c;
        }
        strcpy(st[i].author, temp.c_str());
    }
}

void AddSpaces(book* &st, int &R) {
    string temp;
    char c=' ';

    for (int i = 0; i < R; ++i) {
        temp = st[i].title;
        for(char & j : temp){
            if(j == '.')
                j = c;
        }
        strcpy(st[i].title, temp.c_str());
    }

    for (int i = 0; i < R; ++i) {
        temp = st[i].author;
        for(char & j : temp){
            if(j == '.')
                j = c;
        }
        strcpy(st[i].author, temp.c_str());
    }
}

void MemoryAllocation(book* &st, int& R) {
        if (st == nullptr) {
            st = new (nothrow) book[R];
            if (st != nullptr && R!=0) {
                cout << "Memory was allocated successfully.\n";
            } else {
                cout << "Error! No memory has been allocated.\n";
                delete[] st;
                st = nullptr;
            }
        } else {
            cout << "Memory already allocated.\n";
        }
}

void DeleteMemory(book* &st) {
    if (st != nullptr) {
        delete[] st;
        st = nullptr;
        cout << "The memory has been freed.\n";
    } else {
        cout << "No memory has been allocated.\n";
    }
}

void EndProgram(book* &st) {
    if (st != nullptr) DeleteMemory(st);
    cout << "The program has ended.\n";
}

void EnterElements(book* &st, int &R) {
    if (st == nullptr) {
        cout << "No memory has been allocated.\n";
    } else {
        for (int i = 0; i < R; ++i) {
            cout << "\nBook number " << i+1 << "\n";
            cout << "The title of the book:";
            gets(st[i].title);
            cout << "The author of the book:";
            gets(st[i].author);
            cout << "The year of publishing:";
            TestNum(st[i].year);
            cout << "Number of pages:";
            TestNum(st[i].page);
            cout << "Circulation of the book:";
            TestNum(st[i].circulation);
        }
    }
}

void OutPutElements(book* &st, int &R) {
    if (st == nullptr || R==0) {
        cout << "The array has no elements.\n";
    } else {
        cout << "-------------------------------------------------------------------------\n"
                "|Nr.  |        Title        |     Author     | Year | Pages |Circulation|\n";
        for (int i = 0; i < R; i++)
        {
            printf("-------------------------------------------------------------------------\n"
                   "|%5d|%21s|%16s|%6d|%7d|%11d|\n",
                   i+1, st[i].title, st[i].author, st[i].year,
                   st[i].page, st[i].circulation);
        }
        cout << "-------------------------------------------------------------------------\n";
    }
}

void ReadFromFile(book* &st, int& R) {
    if (st != nullptr && R != 0) {
        ifstream in("Data.txt");
        if (!in) {
            cout << "Error! File can't be opened.\n";
        } else {
            for (int i = 0; i < R; ++i) {
                in >> st[i].title >> st[i].author >> st[i].year >> st[i].page >> st[i].circulation;
            }
            cout << "Elements from the file were read.\n";
        }
    } else {
        cout << "No memory has been allocated.\n";
    }
}

void WriteToFile(book* &st, int &R) {
    if (st != nullptr && R != 0) {
        ofstream ofs("Data.txt");
        if (!ofs) {
            cout << "Error! File can't be opened.\n";
        } else {
            for (int i = 0; i < R; ++i) {
                ofs << st[i].title << "\t" << st[i].author << "\t" << st[i].year << "\t" << st[i].page << "\t"
                    << st[i].circulation << "\n";
            }
            cout << "Elements have been written to file.\n";
        }
    } else {
        cout << "No memory or no item has been allocated.\n";
    }
}

void SearchElement(book* &st, int &R) {
    int choose=0;
    int a=0;
    book s{};
    bool search= false;
    if (st == nullptr) {
        cout << "The array has no elements.\n";
    } else {
        restart:
        cout << "Select search type:\n"
                "\t1. Search by author.\n"
                "\t2. Search by title.\n"
                "\t3. Search by year.\n"
                "Input:";
        TestNum(choose);
        switch (choose) {
            case 1:
                cout << "Enter an author name: ";
                gets(s.author);
                cout << "\n-------------------------------------------------------------------------\n"
                        "|Nr.  |        Title        |     Author     | Year | Pages |Circulation|\n";
                for (int i = 0; i < R; ++i) {
                    if (!(strcmp(st[i].author, s.author))) {
                        printf("-------------------------------------------------------------------------\n"
                               "|%5d|%21s|%16s|%6d|%7d|%11d|\n",
                               i+1, st[i].title, st[i].author, st[i].year,
                               st[i].page, st[i].circulation);
                        search = true;
                    }
                }
                printf("-------------------------------------------------------------------------\n");
                if (!search) {
                    cout << "The author was not found.\n";
                }
                break;
            case 2:
                cout << "Enter a title: ";
                gets(s.title);
                cout << "\n-------------------------------------------------------------------------\n"
                        "|Nr.  |        Title        |     Author     | Year | Pages |Circulation|\n";
                for (int i = 0; i < R; ++i) {
                    if (!(strcmp(st[i].title, s.title))) {
                        printf("-------------------------------------------------------------------------\n"
                               "|%5d|%21s|%16s|%6d|%7d|%11d|\n",
                               i+1, st[i].title, st[i].author, st[i].year,
                               st[i].page, st[i].circulation);
                        search = true;
                    }
                }
                printf("-------------------------------------------------------------------------\n");
                if (!search) {
                    cout << "The title was not found.\n";
                }
                break;
            case 3:
                cout << "Enter a year: ";
                TestNum(a);
                cout << "\n-------------------------------------------------------------------------\n"
                        "|Nr.  |        Title        |     Author     | Year | Pages |Circulation|\n";
                for (int i = 0; i < R; ++i) {
                    if (st[i].year==a) {
                        printf("-------------------------------------------------------------------------\n"
                               "|%5d|%21s|%16s|%6d|%7d|%11d|\n",
                               i+1, st[i].title, st[i].author, st[i].year,
                               st[i].page, st[i].circulation);
                        search = true;
                    }
                }
                printf("-------------------------------------------------------------------------\n");
                if (!search) {
                    cout << "The year was not found.\n";
                }
                break;
            default:
                cout << "You have entered an item that is not in the menu.\n";
                goto restart;
        }
    }
}

void BookSort(book* &st, int &R) {
    int choose=0;
    book temp;
    if (st == nullptr) {
        cout << "The array has no elements.\n";
    } else {
        restart:
        cout << "Select sort type:\n"
                "\t1. Sort by page.\n"
                "\t2. Sort by year.\n"
                "\t3. Sort by circulation.\n"
                "Input:";
        TestNum(choose);
        switch (choose) {
            case 1:
                for (int i = 0; i < R; i++) {
                    for (int j = R-1; j >=i+1; j--)
                    {
                        if (st[j].page > st[j - 1].page)
                        {
                            temp = st[j];
                            st[j] = st[j-1];
                            st[j-1] = temp;
                        }
                    }
                }
                cout << "The array has been sorted.\n";
                break;
            case 2:
                for (int i = 0; i < R; i++) {
                    for (int j = R-1; j >=i+1; j--)
                    {
                        if (st[j].year > st[j - 1].year)
                        {
                            temp = st[j];
                            st[j] = st[j-1];
                            st[j-1] = temp;
                        }
                    }
                }
                cout << "The array has been sorted.\n";
                break;
            case 3:
                for (int i = 0; i < R; i++) {
                    for (int j = R-1; j >=i+1; j--)
                    {
                        if (st[j].circulation > st[j - 1].circulation)
                        {
                            temp = st[j];
                            st[j] = st[j-1];
                            st[j-1] = temp;
                        }
                    }
                }
                cout << "The array has been sorted.\n";
                break;
            default:
                cout << "You have entered an item that is not in the menu.\n";
                goto restart;
        }
    }
}

void ReWriteElement(book* &st, int &R) {
    int itemID=0, choose=0;
    if (st== nullptr) {
        cout << "The array has no elements.\n";
    } else {
        cout << "Enter the number of a book you want to edit.\n"
                "Input: ";
        TestNum(itemID);
        if (itemID > 0 && itemID <= R + 1) {
            restart:
            cout << "\n\t1. Change title.\n"
                    "\t2. Change author.\n"
                    "\t3. Change year.\n"
                    "\t4. Change number of pages.\n"
                    "\t5. Change circulation.\n"
                    "\t6. End.\n"
                    "Input: ";
            TestNum(choose);

            switch (choose) {
                case 1:
                    cout << "\nEnter new title: ";
                    gets(st[itemID - 1].title);
                    goto restart;
                case 2:
                    cout << "\nEnter new author name: ";
                    gets(st[itemID - 1].author);
                    goto restart;
                case 3:
                    cout << "\nEnter new year: ";
                    TestNum(st[itemID - 1].year);
                    goto restart;
                case 4:
                    cout << "\nEnter new number of pages: ";
                    TestNum(st[itemID - 1].page);
                    goto restart;
                case 5:
                    cout << "\nEnter new circulation: ";
                    TestNum(st[itemID - 1].circulation);
                    goto restart;
                case 6:
                    break;
                default:
                    cout << "\nYou have entered an item that is not in the menu.\n";
                    goto restart;
                }
        } else {
            cout << "You have entered an item that is not in the array.\n";
        }
    }
}

void AddNewElement(book* &st, int &R) {
    if (st != nullptr) {
        book* NewBook = new (nothrow) book[R + 1];
        for (int i = 0; i < R; ++i) {
            NewBook[i] = st[i];
        }
        cout << "Enter data for the book " << R + 1 << "\n" << "The title of the book:";
        gets(NewBook[R].title);
        cout << "The author of the book:";
        gets(NewBook[R].author);
        cout << "The year of publishing:";
        TestNum(NewBook[R].year);
        cout << "Number of pages:";
        TestNum(NewBook[R].page);
        cout << "Circulation of the book:";
        TestNum(NewBook[R].circulation);
        R++;
        delete[] st;
        st = NewBook;
    } else {
        cout << "No memory has been allocated.\n";
    }
}

void DeleteElement(book* &st, int &R) {
    if (st != nullptr && R != 0) {
        int i = 0;
        R--;
        book *NewBook = new book[R];
        cout << "Enter the book number: ";
        TestNum(i);
        i--;
        if (i > R) {
            cout << "You have entered an item that is not in the array.\n";
        } else {
            for (; i < R; ++i) {
                st[i] = st[i + 1];
            }
            for (int j = 0; j < R; ++j) {
                NewBook[j] = st[j];
            }
            delete[] st;
            st = NewBook;
            cout << "The book has been deleted.\n";
        }
    } else {
        cout << "No memory or no item has been allocated.\n";
    }
}

void InsertElement(struct book* &st, int &R) {
    if (st != nullptr && R != 0) {
        int pos = 0;
        cout << "Enter position: ";
        TestNum(pos);
        pos--;
        book *NewBook = new(nothrow) book[R + 1];
        for (int i = 0; i < R; i++) {
            if (i < pos) {
                NewBook[i] = st[i];
            } else {
                NewBook[i + 1] = st[i];
            }
        }
        cout << "\nEnter data for the book " << pos + 1 << "\n" << "The title of the book:";
        gets(NewBook[pos].title);
        cout << "The author of the book:";
        gets(NewBook[pos].author);
        cout << "The year of publishing:";
        TestNum(NewBook[pos].year);
        cout << "Number of pages:";
        TestNum(NewBook[pos].page);
        cout << "Circulation of the book:";
        TestNum(NewBook[pos].circulation);
        R++;
        delete[] st;
        st = NewBook;
    } else {
        cout << "No memory or no item has been allocated.\n";
    }
}