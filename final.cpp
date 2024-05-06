#include <iostream>
#include <string>
#include "jewel.hpp"
#include "robber.hpp"
#include "police.hpp"
#include "city.hpp"
//#pragma GCC diagnostic ignored "-Wc++17-compat"

//todo: fix pickuploot, impliment the entirety of policing, impliment end conditions other than out of turns,impliment robber tripping, impliment robber greediness


using namespace std;






int main(){
srand(100);

City rolla;
rolla.renderCity();
cout<<endl;
//cout<<flush;
for (int k=0;k<30;k++){

for (unsigned int i=0;i<cityrobbers.size();i++){
cityrobbers.at(i).move();
//cout<<endl;
}



rolla.renderCity();
cout<<endl;
}

cout<<"summary: "<<endl;
for (unsigned int i=0;i<cityrobbers.size();i++){
switch (cityrobbers.at(i).type){
case 0:
cout<<"Ordinary";break;
case 1:
cout<<"Greedy";break;};
cout<<" Robber id: "<<cityrobbers.at(i).id<<endl;
cout<<"     Final number of jewels picked up: "<<cityrobbers.at(i).rbag.size()<<endl;

}
return 0;
}
