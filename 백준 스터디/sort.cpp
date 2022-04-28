#include<iostream>

using namespace std;
//selection sort function
void selectionSort(int arr[]) {
    int indexMin, temp;
    for(int i=0; i<5; i++){
        indexMin = i;
        for(int j=i+1; j<5;j++){
            if(arr[j]<arr[indexMin]){
                indexMin = j;
            }
            temp = arr[indexMin];
            arr[indexMin] = arr[i];
            arr[i] = temp;
        }
    }
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<arr[4]<<"\n";
}


//bubble sort function
void bubbleSort(int arr[]){
    int temp;
    for(int i=0; i<5; i++){
        for(int j=1; j<5; j++){
            if(arr[j]<arr[j-1]){
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<arr[4]<<"\n";
}
//insertion sort function
void insertionSort(int arr[]){
    for(int i=1; i<5; i++){
        int temp = arr[i];
        int prev = i-1;
        while((prev>=0)&&(arr[prev]>temp)){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = temp;
    }
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<arr[4]<<"\n";
}

int main(){
    int arr[5]={5,4,3,2,1};

    selectionSort(arr);

    bubbleSort(arr);

    insertionSort(arr);
    return 0;
}