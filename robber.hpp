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
Robber(const Robber& other){//cloneing a robber. 
xcord=other.xcord;
ycord=other.ycord;
type=other.type;
id=rand();
active=other.active;
//random distribute loot, not copy. 
vector<Jewel> ebag,obag,nbag;
ebag=other.rbag;
for (int i=0; i<ebag.size();i++){
if(rand() % 2){
nbag.push_back(ebag.at(i));
}
else{
obag.push_back(ebag.at(1));
}
}
//other.rbag=obag;
this->rbag=nbag;
other.clearbg();
}

Robber& operator--(){
totalval -=rbag.back().jval;
rbag.pop_back();
}
void clearbg(){
rbag.clear();
}

};

