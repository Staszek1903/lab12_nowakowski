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
    // Build heap (rearrange array)
    for (int i = tab.size() / 2 - 1; i >= 0; i--)
        heapify(tab.size(), i);

    // One by one extract an element from heap
    for (int i=tab.size()-1; i>=0; i--)
    {
        // Move current root to end
        std::swap(tab[0], tab[i]);

        // call max heapify on the reduced heap
        heapify(i, 0);
    }
    return std::make_pair<int,int> (0,0);
}

void CTablica::heapify(int heapSize, int i)
{

    int largestItem = i;  // Initialize largest as root
    int leftChild = 2*i+1 ;  // left = 2*i +1
    int rightChild = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (leftChild < heapSize && tab[leftChild] > tab[largestItem])
        largestItem = leftChild;

    // If right child is larger than largest so far
    if (rightChild < heapSize && tab[rightChild] > tab[largestItem])
        largestItem = rightChild;

    // If largest is not root
    if (largestItem != i)
    {
        std::swap(tab[i], tab[largestItem]);

        // Recursively heapify the affected sub-tree
        heapify(heapSize, largestItem);
    }
}
