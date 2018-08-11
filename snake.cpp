#include<bits\stdc++.h>
#include <conio.h>
#include<unistd.h>
using namespace std;

int l = 20,b = 20;
int x = l/2,y = b/2;
int fx,fy;
int i,j;
int di;
char c;
bool gameover = false;

int tailx[20];
int taily[20];
int tempx,tempy;

int food=1;

genfood(){
	fx =1+ rand() % l;
	fy =1+ rand() % b;
}

direction(){

	c = getch();
	switch(c){
		case 'w':
			if(di!=2){ di = 8;}
			break;
		case 'a':
			if(di!=6){ di = 4;}
			break;
		case 's':
			if(di!=8){ di = 2;}
			break;
		case 'd':
			if(di!=4){ di = 6;}
			break;
		case 'x':
			gameover = true;
			break;

	}
}

update(){

	switch(di){
		case 8:
		y--;
		break;

		case 2:
		y++;
		break;

		case 4:
		x--;
		break;

		case 6:
		x++;
		break;
	}
}

display(){

	system("CLS");

		for(i=0;i<=l;i++){
			for(j=0;j<= b;j++){
				if((x+y*b)==(j+i*b)){cout<<"O";}					//head
				//else if((j+i*b)==(tailx[j]+taily[i]*b)){cout<<"o";}	//tail
				else if((j+i*b)==(fx+fy*b)){cout<<"x";}				//food
				else if(i==0||j==0||i==l||j==b){cout<<"$";}			//walls
				else{cout<<" ";}			
			
			}
			cout<<endl;
		}
		cout<<food;
		cout<<fx<<" "<<fy;
}


int main(int argc, char const *argv[])
{
	genfood();
	while(true){

		
		if(kbhit()) direction();
		else if((x==fx)&&(y==fy)){
			food++;
			genfood();
			}
		update();
		display();

		
		if(gameover)break;

		sleep(1);
	};
	
}