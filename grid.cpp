#include <iostream>
#include <map>
#include <array>
#include <string>
#include <cctype>
using namespace std;

class grid
{
private:
    /* data */
    int storedX = 4;
    int storedY = 4;
    int xPosition = 4;
    int yPosition = 4;
    map<string, array<char, 9>> gridArrays;
public:
    grid(/* args */);
    ~grid();
    void memoryWipe();
    void generateGrid();
    string checkBoundary();
    void processInput(char directionalInput);
    void updateGrid();
    void printGrid();
    void replaceX();
};

grid::grid(/* arg s */)
{
}

grid::~grid()
{
}

void grid::generateGrid(){
    for (int i=0; i<9; i++){
        if (i==4){
            gridArrays["gridNumber" + to_string(i)] = {'o','o','o','o','X','o','o','o','o'};
        }
        else{
        gridArrays["gridNumber" + to_string(i)] = {'o','o','o','o','o','o','o','o','o'};
    }
    }
}

void grid::processInput(char directionalInput){
    if (directionalInput == 'w' || directionalInput == 'W'){ /*copy paste ftw*/
        xPosition--;
    }
    if (directionalInput == 's' || directionalInput == 'S'){
    xPosition++;
    }
    if (directionalInput == 'a' || directionalInput == 'A'){
    yPosition--;
    }
    if (directionalInput == 'd' || directionalInput == 'D'){
    yPosition++;
    }

}

string grid::checkBoundary(){ /*need to change this for no input, which is done!*/

    if (xPosition < 0){ /*i know, i also could write this much more efficiently*/
        xPosition++;
    } 
    if (yPosition < 0){
        yPosition++;
    } 
    if (xPosition > 8){
    xPosition--;
    } 
    if (yPosition > 8){
        yPosition--;
    } 
    if (xPosition < 0 || xPosition > 8 || yPosition <0 || yPosition >8)
    {
        return  "You cannot move that way";
    } /*I probably could code out a way to make the grid loop like pac-man, but i gotta save that for another project*/
    else{return"good";}
}

void grid::printGrid(){
    for (const auto& pair : gridArrays) {
        for (char c : pair.second) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }  
}
void grid::replaceX(){
    gridArrays["gridNumber"+ to_string(storedX)][storedY]='o';
    storedX = xPosition;
    storedY = yPosition;
}

void grid::updateGrid(){
    gridArrays["gridNumber"+to_string(xPosition)][yPosition]='X';
}

void grid::memoryWipe(){
    gridArrays.clear();
}

int main(){
    cout << "Init.WAV\n";
    grid newGrid;
    newGrid.generateGrid();
    newGrid.printGrid();
    char inputA='x';
    while (inputA != 'e'){        
        cout << "|| Up: W || Down: S || Right: D || Left: A || Exit: E || \n";
        cout << "Enter a direction: \n";
        cin >> inputA;
        cin.ignore();

        inputA = char(tolower(inputA));
        if (inputA=='e'||inputA =='E'){
            newGrid.memoryWipe();
            return 0;
        }

        else{
             newGrid.processInput(inputA);
            string checkingB = newGrid.checkBoundary();
            if (checkingB=="good"){
                newGrid.replaceX();
                newGrid.updateGrid();
                newGrid.printGrid();
            }else{
                cout << checkingB;
            }
        }
    }
    return 0;
    /*ok, im struggling to directly formulate this out, because c++ still doesn't directly fit in my brain*/
    /*I'm gonna write out pseudo code for what im going for, then translate it to the language*/

    /*error; if the location is out of bounds for 'X' movement, display a "You cannot move that way" message, and have no changes occur*/

};

/*For the grid creation class, I would like to keep it simple
The first step is to generate 9 lists that contain '0' with a singular 'X' in list4
because we are going off of index numbering

  0 1 2 3
0
1
2    just writing it out, lower is higher for y
3    and lower is left for x


*/