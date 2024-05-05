#include <iostream>
#include <string>

using namespace std;

class Jewel{
public:
int xcord;
int ycord;
int jval;

Jewel(const int value, const int xPos, const int yPos){
jval=value;
xcord=xPos;
ycord=yPos;
}

Jewel& operator*(){
this->jval*=2;
return *this;
}

Jewel& operator*=(const Jewel& thing){
this->jval*=2;
return *this;
}

};
