#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <random>
using namespace std;

class City {


public:
bool fiftyFifty() {//rand was just not working very well. so we're doing this now. 
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1); 
    int result = dis(gen);
    return result == 0;
}

  static const int cityxsize = 11;
  static const int cityysize = 13;
  char citygrid[cityysize][cityxsize]; //so much headache all from the mandate that this be a c-array, as opposed to vectory of arbitrary data
  
  static inline vector<Police> rollapd;
  static inline vector<Jewel> cityjewels;
  static inline vector<Robber<Jewel>> cityrobbers;
  
  
  
  
  City() {
Jewel hold(0,0,0);
//replace all of our nulls with zeroes. 
for (int i=0;i<cityysize;i++){
for (int k=0;k<cityxsize;k++){
citygrid[i][k]='0';
}
}


//now to make 60 random Jewel's
for (int i=0;i<cityysize;i++){
for (int k=0;k<cityxsize;k++){
if(cityjewels.size() <60 && fiftyFifty() && citygrid[i][k]=='0'){
citygrid[i][k]='J';
hold.ycord=i;
hold.xcord=k;
hold.jval=pow((i + k),2);
cityjewels.push_back(hold);

}

}
}
//cout<<"added "<<cityjewels.size() <<" jewels."<<endl;


//now to make our robbers
Robber<Jewel> jango;
for (int i=0;i<cityysize;i++){
for (int k=0;k<cityxsize;k++){
if(cityrobbers.size() <5 && fiftyFifty() && citygrid[i][k]=='0'){
citygrid[i][k]='r';
jango.id=rand();
jango.ycord=i;
jango.xcord=k;
jango.active=1;
if(cityrobbers.size()<2){
jango.type=1;
}
if(cityrobbers.size()>=2){
jango.type=2;
}
cityrobbers.push_back(jango);}
}}
//now to make our police. 
Police wigum;
for (int i=0;i<cityysize;i++){
for (int k=0;k<cityxsize;k++){
if(rollapd.size() <3 && fiftyFifty() && citygrid[i][k]=='0'){
citygrid[i][k]='p';
wigum.ycord=i;
wigum.xcord=k;
wigum.id=rand();
rollapd.push_back(wigum);
}}}
}

  void renderCity() {
    int numj = 0;
    int numrb = 0;
    int numpd = 0;
    for (int i = 0; i < cityysize; i++) {
      for (int f = 0; f < cityxsize;f++) {
 
        cout << citygrid[i][f];
        switch (citygrid[i][f]){
        case 'J':
        numj++;break;
        case 'r':
        numrb++;break;
        case 'p':
        numpd++;break;
        case 'R':
        numj+=2;
        };
       
      }
      
     cout <<flush<<endl;
    }


    cout << "jewels(J): " << numj << endl;
    cout << "robbers(r): " << numrb << endl;
    cout << "cops(p): "<<numpd<<endl;
    cout<<"two robbers at same house(R)"<<endl;    
  }


};
