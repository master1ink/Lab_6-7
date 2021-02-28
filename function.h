#include <cstdio>
#include <cstdlib>
using namespace std;

void TestNum(int &R);
void MemoryAllocation(struct book* &st, int &R);
void DeleteMemory(struct book* &st);
void EndProgram(struct book* &st);
void EnterElements(struct book* &st, int &R);
void OutPutElements(struct book* &st, int &R);
void ReadFromFile(struct book* &st, int &R);
void WriteToFile(struct book* &st, int &R);
void SearchElement(struct book* &st, int &R);
void BookSort(struct book *&st, int &R);
void ReWriteElement(struct book* &st, int &R);
void AddNewElement(struct book* &st, int &R);
void DeleteElement(struct book* &st, int &R);
void InsertElement(struct book* &st, int &R);
void RemoveSpaces(struct book* &st, int &R);
void AddSpaces(struct book* &st, int &R);

struct book
{
    char author[255]="null";
    char title[255]="null";
    int year=0;
    int page=0;
    int circulation=0;
};
