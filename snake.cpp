#include<bits\stdc++.h>
#include <conio.h>
#include<unistd.h>
using namespace std;

int l = 20,b = 20;
int x = l/2,y = b/2;			//head coordinates
int fx,fy;						//food coordinates
int i,j;
int di;
char c;
bool gameover = false;

int tailx[20];
int taily[20];
int tempx,tempy;

int food=1;

genfood(){						//generates random coordinates for food
	fx =1+ rand() % l;
	fy =1+ rand() % b;
	food++;
}

direction(){					//chages the direction 

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

update(){					//updates the head and tail coordinates periodically

	tempx = x;
	tempy = y;

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

	for(i=0;i<food;i++){
		swap(tailx[i],tempx);
		swap(taily[i],tempy);
	}

}

display(){									//prints the game 

	system("CLS");
		int k = 0;
		for(i=0;i<=l;i++){
			for(j=0;j<= b;j++){
				if((j+i*b)==(tailx[k]+taily[k]*b)){cout<<"o";k++;}		//tail
				else if((x+y*b)==(j+i*b)){cout<<"O";}					//head														
				else if((j+i*b)==(fx+fy*b)){cout<<"x";}				//food
				else if(i==0||j==0||i==l||j==b){cout<<"$";}			//walls
				else{cout<<" ";}
			}

			cout<<endl;
		}
		cout<<food;
}


int main(int argc, char const *argv[])
{
	genfood();
	while(true){

		
		if(kbhit()) direction();
		else if((x==fx)&&(y==fy)){
			genfood();
			}
		update();
		display();

		
		if(gameover)break;

		//sleep(0);
	};
	
}

