#pragma once
class Sort
{
private:
    int* v;
    int size;
public:
    // add constuctors
    Sort(int nr_elem, int min, int max);
    Sort(int* vec, int n);
    Sort(int nr, ...);
    Sort(const char *sir);
    Sort();
    ~Sort();
      void InsertSort(bool ascendent = true);
    void QuickSort(bool ascendent = true);
    void BubbleSort(bool ascendent =false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};