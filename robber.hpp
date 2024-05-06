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

void move(){
int decide=0;
vector<int> validmoves;
for (int i=0;i<8;i++){
validmoves.push_back(i);}
cout<<"valid moves is: ";

//get valid moves
//first, make sure we cant go out of bounds. 
switch (xcord){
case 10:
validmoves.erase(validmoves.begin()+4);

};



for (unsigned int i=0;i<validmoves.size();i++){
cout<<validmoves.at(i)<<" ";
}
}
};

