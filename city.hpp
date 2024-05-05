#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class City{
private:
char citygrid[11][13];

public:
static inline vector<Jewel> cityjewels;
static inline vector<Robber<Jewel>> cityrobbers;
City(){
int numj=0;
Jewel hold(0,0,0);
while (numj<60){
//cout<<numj<<"j ";
for (int i=0;i<11;i++){
for (int f=0;f<13;f++){
if(citygrid[i][f] =='\0' && rand() %2){citygrid[i][f]='J'; numj++; 
hold.xcord=i;
hold.ycord=f;
hold.jval=pow((i + f),2);
cityjewels.push_back(hold);
 goto nwjl;
 }
else if(citygrid[i][f] == '\0'){citygrid[i][f]=' ';goto nwjl;}
}
}
nwjl:;
}
Robber<Jewel> jango;
int numrb=0;
while (numrb<4){
//cout<<numrb<< "b ";
for (int i=0;i<11;i++){
for (int f=0;f<13;f++){
if(citygrid[i][f] ==' ' && rand() %2) {citygrid[i][f]='r'; numrb++; 
jango.xcord=i;
jango.ycord=f;
jango.id=rand();
jango.active=1;
if(numrb<2){
jango.type=0;
}
if(numrb>=2){
jango.type=1;
}
cityrobbers.push_back(jango);
goto nwrb;}


}
}
nwrb:;
}






}

void renderCity(){
int numj=0;
int numrb=0;
for (int i=0;i<11;i++){
for (int f=0;f<13;f++){
cout<<citygrid[i][f];
switch(citygrid[i][f]){
case 'J':
numj++;break;
case 'r':
numrb++;break;
};
}
cout<<endl;
}
cout<<"jewels: "<<numj<<endl;
cout<<"robbers: "<<numrb<<endl;
cout<<"cops: "<<" "<<endl;
}

int jewelnum;
};
