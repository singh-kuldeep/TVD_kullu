#include "math.h"
#include "iostream"


#define gamma 1.4
#define gasconstant 287.14
#define heatcapacityconstantvolume 717.5

using namespace std ;
	
class varaiblevector
{


public:
	float density , xmomentum ,ymomentum ,zmomentum, totalenery ;

// constructor
	varaiblevector(float density1, float xvelocity, float yvelocity, float zvelocity,float temprature)
	{
	 density = density1 ; 
	 xmomentum = density1*xvelocity ;
	 ymomentum = density1*yvelocity ;
	 zmomentum = density1*zvelocity ; 
	 totalenery = density1* ( heatcapacityconstantvolume * temprature + 0.5 * 
	 	(pow(xvelocity,2) + pow(yvelocity,2) + pow(zvelocity,2)) ) ;
	}

	

	void print() {
		cout << "density" << density <<endl ;
		cout << "xmomentum   " << xmomentum <<endl ;
		cout << "ymomentum   " << ymomentum <<endl ;
		cout << "zmomentum   " << zmomentum <<endl ;
		cout << "totalenery  " << totalenery <<endl ;
		// return 0;
	}


	// ~varaiblevector() {
	// 	std::cout<< "fucking out"<<std::endl;
	// }
	
};