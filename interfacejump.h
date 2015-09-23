
#include "math.h"
#include "iostream"

#define gamma 1.4
#define gasconstant 287.14
#define heatcapacityconstantvolume 717.5

using namespace std ;



class interfacejump
{
public:
	float deltadensity ;
	float deltaxmomentum ;
	float deltaymomentum ;
	float deltazmomentum ;
	float deltattotalenergy ;

	interfacejump(float leftdensity, float leftxvelocity, float leftyvelocity, float leftzvelocity,
	 float lefttemperature, float rightdensity, float rightxvelocity, float rightyvelocity,
	 float rightzvelocity, float righttemperature)
	{

		float deltax = 0.01 ;
		float deltay = 0.01 ;
		float deltaz = 0.01 ;
		float interfacevolume = deltax*deltay*deltaz ;

		float lefttotalenergy = leftdensity* (heatcapacityconstantvolume * lefttemperature + 
				0.5*(pow(leftxvelocity,2) + pow(leftyvelocity,2) + pow(leftzvelocity,2))) ;

		float righttotalenergy = rightdensity *(heatcapacityconstantvolume * righttemperature + 
				0.5*(pow(rightxvelocity,2) + pow(rightyvelocity,2) + pow(rightzvelocity,2))) ;


		deltadensity = interfacevolume * (rightdensity -leftdensity) ;
		deltaxmomentum = interfacevolume * ((rightdensity*rightxvelocity)-(leftdensity*leftxvelocity)); 
		deltaymomentum = interfacevolume * ((rightdensity*rightyvelocity)-(leftdensity*leftyvelocity)); 
		deltazmomentum = interfacevolume * ((rightdensity*rightzvelocity)-(leftdensity*leftzvelocity)); 
		deltattotalenergy = interfacevolume *( righttotalenergy -lefttotalenergy) ;

	}
	


float jumpprint(){
	cout<<"deltadensity" << deltadensity << endl ; 
	cout<<"deltaxmomentum"<< deltaxmomentum << endl ;
	cout<<"deltaymomentum"<< deltaymomentum << endl ;
	cout<<"deltazmomentum"<< deltazmomentum << endl ;
	cout<<"deltattotalenergy"<< deltattotalenergy << endl ; 
}

};
 // interfacejump(){

	
	
// }	