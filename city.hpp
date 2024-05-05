#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class City{



public:
static const int cityxsize=11;
static const int cityysize=13;
char citygrid[cityysize][cityxsize];
static inline vector<Jewel> cityjewels;
static inline vector<Robber<Jewel>> cityrobbers;
City(){
int numj=0;
Jewel hold(0,0,0);
while (numj<60){
//cout<<numj<<"j ";
for (int i=0;i<cityysize;i++){
for (int f=0;f<cityxsize;f++){
if(citygrid[i][f] =='\0' && rand() %2){citygrid[i][f]='J'; numj++; 
hold.ycord=i;
hold.xcord=f;
hold.jval=pow((i + f),2);
cityjewels.push_back(hold);
 goto nwjl;
 }
else if(citygrid[i][f] == '\0'){citygrid[i][f]='0';goto nwjl;}
}
}
nwjl:;
}
Robber<Jewel> jango;
int numrb=0;
while (numrb<4){
//cout<<numrb<< "b ";
for (int i=0;i<cityysize;i++){
for (int f=0;f<cityxsize;f++){
if(citygrid[i][f] =='0' && rand() %2) {citygrid[i][f]='r'; numrb++; 
jango.ycord=i;
jango.xcord=f;
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


for (int i=0;i<cityysize;i++){
for (int f=0;f<cityxsize;f++){
if(citygrid[i][f]=='\0'){citygrid[i][f]='0';}
}}


}

void renderCity(){
int numj=0;
int numrb=0;
for (int i=0;i<cityysize;i++){
for (int f=0;f<cityxsize;f++){
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
