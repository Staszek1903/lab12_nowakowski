#include "ctablica.h"

CTablica::CTablica()
{

}

std::pair<int, int> CTablica::bubble_sort()
{
    int SwapCounter=0;
    int ComparisonCounter=0;
    for(int i=0;i<tab.size();i++){
        for(int j=1;j<tab.size()-i;j++)
        {
            ComparisonCounter++;
            if(tab[j-1]>tab[j])
                {
                    std::swap(tab[j-1], tab[j]);
                    SwapCounter++;
                }
        }
    }
    return std::make_pair<int,int> (int(ComparisonCounter), int(SwapCounter));

    //std::pair <int, int> p;
    //return p;
    //int x,y;
    //return std::make_pair<int,int>(x,y);
}

std::pair<int, int> CTablica::quick_sort_lomuto(int indexA, int indexB)
{

    if(indexA>=indexB)return std::make_pair<int,int>(0,0);

    int pivotValue, b;
    int SwapCounter=2;
    int ComparisonCounter=0;
    int pivotIndex = (indexA+ indexB)/2;
    pivotValue = tab[pivotIndex];

    std::swap (tab[pivotIndex], tab[indexB]);
    b = indexA;

    for(int a =indexA; a < indexB; a++) {
            ComparisonCounter++;
        if(tab[a] <= pivotValue)
            {
                std::swap (tab[a], tab[b]);
                SwapCounter++;
                b++;
            }
    }
    std::swap(tab[b], tab[indexB]);


    auto result1 = quick_sort_lomuto(indexA,b-1 );

    auto result2 = quick_sort_lomuto(b+1, indexB);
    ComparisonCounter += result1.first+result2.first;
    SwapCounter+=result1.second+result2.second;
    return std::make_pair<int,int> (int(ComparisonCounter), int(SwapCounter));
}

std::pair<int, int> CTablica::quick_sort_hoare(int indexA, int indexB)
{

   if(indexA>=indexB)return std::make_pair<int,int>(0,0);
   int s=(indexA+indexB)/2;
   int pivotValue=tab[s], a=indexA, b=indexB;
   int SwapCounter=0;
   int ComparisonCounter=0;
   while (a<=b)
   {
       ComparisonCounter++;
      while (tab[a]<pivotValue){
            ComparisonCounter++;
            a++;
            }
      while (tab[b]>pivotValue){
            ComparisonCounter++;
            b--;
      }
      if (a<=b)
      {
         std::swap(tab[a], tab[b]);
         SwapCounter++;
         a++; b--;
      }
   }
   std::pair <int, int> result1, result2;
   if (b>indexA)
      result1 = quick_sort_hoare(indexA,b);
   if (a<indexB)
      result2 = quick_sort_hoare(a,indexB);
      ComparisonCounter += result1.first+result2.first;
    SwapCounter+=result1.second+result2.second;
    return std::make_pair<int,int> (int(ComparisonCounter), int(SwapCounter));

}

std::pair<int, int> CTablica::heap_sort()
{
    std::pair<int,int> result_temp, result;

    for (int i = tab.size() / 2 - 1; i >= 0; i--){
        result_temp = heapify(tab.size(), i);
        result.first += result_temp.first;
        result.second += result_temp.second;
    }

    for (int i=tab.size()-1; i>=0; i--)
    {

        std::swap(tab[0], tab[i]);
        result.second ++;


        result_temp = heapify(i, 0);
        result.first += result_temp.first;
        result.second += result_temp.second;
    }

    return result;
}

std::pair<int,int> CTablica::heapify(int heapSize, int i)
{
    int ComparisonCounter =3;
    int SwapCounter=0;
    int largestItem = i;
    int leftChild = 2*i+1 ;
    int rightChild = 2*i + 2;


    if (leftChild < heapSize && tab[leftChild] > tab[largestItem])
        largestItem = leftChild;


    if (rightChild < heapSize && tab[rightChild] > tab[largestItem])
        largestItem = rightChild;

    std::pair<int,int> result;

    if (largestItem != i)
    {
        std::swap(tab[i], tab[largestItem]);
        SwapCounter=1;

        result = heapify(heapSize, largestItem);
    }

    ComparisonCounter += result.first;
    SwapCounter+=result.second;

    return std::make_pair<int,int> (int(ComparisonCounter), int(SwapCounter));
}
