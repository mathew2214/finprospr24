#include <iostream>
#include <string>
#include "jewel.hpp"
#include "robber.hpp"
#include "police.hpp"
#include "city.hpp"
#pragma GCC diagnostic ignored "-Wc++17-compat"




using namespace std;






int main(){
srand(100);

City rolla;
rolla.renderCity();
cout<<endl;
//cout<<flush;

for (unsigned int i=0;i<rolla.cityrobbers.size();i++){
rolla.cityrobbers.at(i).move();
//cout<<endl;
}


return 0;
}
