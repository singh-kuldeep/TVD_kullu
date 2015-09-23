#include "math.h"
#include "iostream"


#define gamma 1.4
#define gasconstant 287.14
#define heatcapacityconstantvolume 717.5


using namespace std ;
class eulerflux
{
	
public:
float xeulerflux[5] ; // this is E_e
float yeulerflux[5] ; // this is F_e
float zeulerflux[5] ; // this is G_e

	eulerflux(float density, float xvelocity, float yvelocity, float zvelocity,float temprature){
		

		float pressure = density * gasconstant * temprature ;
		float totalenergy = density*(heatcapacityconstantvolume * temprature + 0.5*(pow(xvelocity,2) + 
			pow(yvelocity,2) + pow(zvelocity,2))) ; 

		xeulerflux[0] = density * xvelocity;
		xeulerflux[1] = density * pow(xvelocity,2) + pressure ;
		xeulerflux[2] = density * xvelocity * yvelocity ; 
		xeulerflux[3] = density * xvelocity * zvelocity ;
		xeulerflux[4] = (totalenergy+pressure)*xvelocity ; 

		yeulerflux[0] = density * yvelocity;
		yeulerflux[1] = density * yvelocity * xvelocity ;
		yeulerflux[2] = density * pow(yvelocity,2) + pressure ; 
		yeulerflux[3] = density * yvelocity * zvelocity ;
		yeulerflux[4] = (totalenergy+pressure)*yvelocity ; 

		zeulerflux[0] = density * zvelocity;
		zeulerflux[1] = density * zvelocity * xvelocity ; 
		zeulerflux[2] = density * yvelocity * zvelocity ;
		zeulerflux[3] = density * pow(zvelocity,2) + pressure ;
		zeulerflux[4] = (totalenergy+pressure)*zvelocity ; 

		// cout <<"pressure "<< pressure << endl ;
		// cout <<"totalenergy "<< totalenergy << endl ;

	};

void printflux() {
	for (int i = 0; i < 5; ++i)
	{
		cout << "xeulerflux [ " << i << " ] component =  " << xeulerflux[i] << endl ;
	}
	for (int i = 0; i < 5; ++i)
	{
		cout << "yeulerflux [ " << i << " ] component =  " << yeulerflux[i] << endl ;
	}
	for (int i = 0; i < 5; ++i)
	{
		cout << "zeulerflux [ " << i << " ] component =  " << zeulerflux[i] << endl ;
	}

	

}
	// ~eulerflux();
	
};