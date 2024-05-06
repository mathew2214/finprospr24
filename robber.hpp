#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>class Robber{

public:
static inline int totalval;
int xcord;
int ycord;
int id=rand();
int active;
//0/1 inactive/active. 
vector<Jewel> rbag;
int type;
//0=ordinary
//1=greedy

int mobile=1;
//1=mobile
//0=being a lazy bum
Robber(){}
Robber (const Robber& other) {//cloneing a robber. 
xcord=other.xcord;
ycord=other.ycord;
type=other.type;
id=rand();
active=other.active;
//random distribute loot, not copy. 
vector<Jewel> ebag,obag,nbag;
ebag=other.rbag;
for (unsigned int i=0; i<ebag.size();i++){
if(rand() % 2){
nbag.push_back(ebag.at(i));
}
else{
obag.push_back(ebag.at(1));
}
}
vector<Jewel>& unconstdrbag =const_cast<vector<Jewel>&>(other.rbag);
unconstdrbag=obag;
this->rbag=nbag;


}

Robber& operator--(){
totalval -=rbag.back().jval;
rbag.pop_back();
}


int findvecnum(vector<int> uwu, int tgt){
int rst=0;
for (unsigned int i=0;i<uwu.size();i++){
if(uwu.at(i)==tgt){rst=i;}
}

return rst;

}


void move(){
int decide=0;
int destx=xcord;
int desty=ycord;
vector<int> validmoves;
for (int i=0;i<8;i++){
validmoves.push_back(i);}
//cout<<xcord<<", "<<ycord<<" ";
//cout<<"valid moves is: ";

// get valid moves
// make sure we cant go out of bounds. 

switch (xcord){
case 10:
if(validmoves.at(findvecnum(validmoves,4)) == 4){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,4));}
if(validmoves.at(findvecnum(validmoves,2)) == 2){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,2));}
if(validmoves.at(findvecnum(validmoves,7)) == 7){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,7));}
break;
case 0:
if(validmoves.at(findvecnum(validmoves,3)) == 3){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,3));}
if(validmoves.at(findvecnum(validmoves,0)) == 0){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,0));}
if(validmoves.at(findvecnum(validmoves,5)) == 5){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,5));}
break;
};
switch (ycord){
case 0:
if(validmoves.at(findvecnum(validmoves,0)) == 0){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,0));}
if(validmoves.at(findvecnum(validmoves,1)) == 1){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,1));}
if(validmoves.at(findvecnum(validmoves,2)) == 2){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,2));}
break;
case 12:
if(validmoves.at(findvecnum(validmoves,5)) == 5){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,5));}
if(validmoves.at(findvecnum(validmoves,6)) == 6){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,6));}
if(validmoves.at(findvecnum(validmoves,7)) == 7){validmoves.erase(validmoves.begin()+ findvecnum(validmoves,7));}
break;
};
decide=validmoves.at(rand() % validmoves.size());
//now that we've decided a valid move, lets get the coordinates of our target cell.
switch (decide){
case 0:
destx--;
desty--;
break;
case 1:
desty--;
break;
case 2:
destx++;
desty--;
break;
case 3:
destx--;
break;
case 4:
destx++;
break;
case 5:
destx--;
desty++;
break;
case 6:
desty++;
break;
case 7:
destx++;
desty++;
};
//now weve got our destination coordinates. destx and desty.
//now to handle things based on whats at our destination, and perform the move if need be
switch (citygrid[desty][destx]){
case '0':
citygrid[desty][destx]='r';
citygrid[ycord][xcord]='0';
xcord=destx;
ycord=desty;
break;
case 'r':
citygrid[desty][destx]='R';
citygrid[ycord][xcord]='0';
break;
};


}
};

