#include <iostream>
#include<queue>
#include<vector>
using namespace std;

class Location2D{
public:
    int row;
    int col;
    Location2D(int r=0, int c=0){
        row = r; col = c;
    }
};

int main(){
    int width = 0, height=0;
    cin>>width>>height;

    char map[width][height];
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cin>>map[i][j];
        }
    }

    return 0;
}