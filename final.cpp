#include <iostream>
#include <string>
#include "jewel.hpp"
#include "robber.hpp"
#include "city.hpp"





using namespace std;






int main(){
srand(100);

City rolla;
rolla.renderCity();
for (unsigned int i=0;i<rolla.cityrobbers.size();i++){
rolla.cityrobbers.at(i).move();
cout<<endl;
}


return 0;
}
