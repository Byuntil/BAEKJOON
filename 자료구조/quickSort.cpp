#include<iostream>

using namespace std;
/*
 * 1. 리스트 중에서 하나의 원소 고른다(pivot)
 * 2. 피벗 앞에는 피벗보다 작은 값(작은 값이 나타날 때까지 index감소), 피벗 보다 뒤에는 피벗보다 큰 원소 오도록(큰 값이 나타날 때까지 index증가) 둘로 리스트 나눔
 * 3. 분활된 리스트를 재귀적으로 이 과정을 반복한다.
 */
int data[10] = {4,1,2,3,5,9,6,7,8,10};

void swap(int *i, int *i1) {
    int temp = *i;
    *i=*i1;
    *i1=*i;
}
void quickSort(int arr[], int low, int high){
    if(low >= high)
        return;
    int i = low, j=low;
    int& pivot = arr[high];
    for (; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i++], arr[j]);
        }
    }

    swap(arr[i],pivot);

    quickSort(arr, low, i-1);
    quickSort(arr,i+1, high);
}


int main(){
    cout<<"Before : ";
    for (int i : data) {
        cout<<i<<" ";
    }

    cout<<"\n";

    quickSort(data,0,9);

    cout<<"After : ";
    for (int i : data) {
        cout<<i<<" ";
    }
}