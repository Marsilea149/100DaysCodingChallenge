/** Goal: Find the intersecion of two arrays **/
#include <iostream>
#include <map>

int *findIntersection(int const arr1[], int const m, int const arr2[], int const n)
{
    int q = std::min(m, n);
    int *arrRes = new int[q];
    // create an map for arr1, find element in this map for elements in arr2
    std::map<int, bool> map;
    for (int i = 0; i < m; ++i)
    {
        map.insert(std::pair<int, bool>(arr1[i], true));
    }
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        auto it = map.find(arr2[i]);
        if (it != map.end())
        {
            arrRes[j] = arr2[i];
            ++j;
        }
    }

    return arrRes;
}

int main()
{
    // int arr1[] = {1, 3, 4, 6};
    // int arr2[] = {2, 3, 7, 8, 6};
    // int arrRes[] = findIntersection(arr1, arr2);
    // std::cout << "Input array 1 is: " << arr1 << " , input array 2 is: " << arr2 << std::endl;
    // std::cout << "Intersection array is: " << arrRes << std::endl;

    int arr1[] = {1, 3, 4, 6};
    int arr2[] = {2, 3, 7, 8, 6};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    int q = std::min(m, n);
    int *arrRes = findIntersection(arr1, m, arr2, n);
    std::cout << "Input array 1 is: " << arr1 << " , input array 2 is: " << arr2 << std::endl;

    std::cout << "Intersection array is: " << std::endl;
    for (int i = 0; i < q; ++i)
    {
        if (arrRes[i])
            std::cout << arrRes[i] << ", ";
    }
    std::cout << std::endl;
}