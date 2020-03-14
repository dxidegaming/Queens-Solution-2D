#include <iostream>

using namespace std;


int main()
{

    int myArray[8][8] = {1}, row, col = 0, counter = 0;

nextC:
    col++;
        if (col == 8)
            goto outPut;
            row = -1;


nextR:
    row++;
        if(row == 8)
            goto backTrack;


    //row test
    for(int a=0; a<col; a++)
        if(myArray[row][a] == 1)
           goto nextR;

    //up diagonal test
    for(int a=1; (row - a) >= 0 && (col - a) >= 0; a++)
        if(myArray[row-a][col-a] == 1)
           goto nextR;
    

    //down diagonal test
    for(int a=1; row+a < 8 && col - a >= 0; a++)
        if(myArray[row+a][col-a] == 1)
            goto nextR;


    
    myArray[row][col] = 1;
    goto nextC;


backTrack:
        --col;
        if(col<0)
            return 0;
        row=0;
        while(myArray[row][col] != 1)
            row++;
            myArray[row][col] = 0;
        goto nextR;



outPut:{
    counter++;
    cout << "SOLUTION " << counter << endl;
    for(int a=0; a < 8; a++){
        for(int b=0; b < 8; b++){
            cout << myArray[a][b];}
        cout << endl;}
    cout << endl;

    goto backTrack;}
    
}


