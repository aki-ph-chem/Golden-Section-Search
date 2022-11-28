#include <iostream>
#include <vector>
#include <cstdlib>

int bin_search(std::vector<int>& array, int key){
    int left = 0, right = (int)array.size() - 1; 
    while(right >= left){
        int mid = left + (right - left)/2;
        if(array[mid] == key) return mid;
        else if(array[mid] > key) right = mid - 1;
        else if(array[mid] < key) left = mid + 1;
    }
    return -1;
}

int main(void){
    std::vector<int> array = {1,2,3,4,5,6,7,8,9,10};
    std::cout << bin_search(array, 7) << std::endl;
}
