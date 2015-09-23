
#include "math.h"
#include "iostream"

#define gamma 1.4
#define gasconstant 287.14
#define heatcapacityconstantvolume 717.5

using namespace std ;

class interfacevector
{
public:
	float interfacedensity ;
	float interfacexvelocity ;
	float interfaceyvelocity ;
	float interfacezvelocity ;
	float interfaceenthalpy ;

	interfacevector(float leftdensity, float leftxvelocity, float leftyvelocity, float leftzvelocity,
	 float lefttemperature, float rightdensity, float rightxvelocity, float rightyvelocity,
	  float rightzvelocity, float righttemperature )
	{

		float leftpressure = leftdensity * gasconstant * lefttemperature ;
		float lefttotalenergy = leftdensity* (heatcapacityconstantvolume * lefttemperature + 
			0.5*(pow(leftxvelocity,2) + pow(leftyvelocity,2) + pow(leftzvelocity,2))) ;
		float leftenthalpy = (lefttotalenergy + leftpressure)/ leftdensity ; 

		float rightpressure = rightdensity * gasconstant * righttemperature ;
		float righttotalenergy = rightdensity *(heatcapacityconstantvolume * righttemperature + 
			0.5*(pow(rightxvelocity,2) + pow(rightyvelocity,2) + pow(rightzvelocity,2))) ;
		float rightenthalpy = (righttotalenergy + rightpressure)/ rightdensity ; 
		

		interfacedensity = sqrt(leftdensity*rightdensity) ; 

		interfacexvelocity  = (leftxvelocity + rightxvelocity*sqrt(rightdensity/leftdensity)) /
		(1+sqrt(rightdensity/leftdensity));

		interfaceyvelocity  = (leftyvelocity + rightyvelocity*sqrt(rightdensity/leftdensity)) /
		(1+sqrt(rightdensity/leftdensity));

		interfacezvelocity  = (leftzvelocity + rightzvelocity*sqrt(rightdensity/leftdensity)) /
		(1+sqrt(rightdensity/leftdensity));

		interfaceenthalpy = (leftenthalpy + rightenthalpy*(sqrt(rightdensity/leftdensity))) / 
		(1+sqrt(rightdensity/leftdensity)) ;

	}

	void interfacevectorprint(){
		cout << "interfacedensity   = " << interfacedensity << endl ;
		cout << "interfacexvelocity = " << interfacexvelocity << endl ;
		cout << "interfaceyvelocity = " << interfaceyvelocity << endl ;
		cout << "interfacezvelocity = " << interfacezvelocity << endl ;
		cout << "interfaceenthalpy  = " << interfaceenthalpy << endl;
		}

	float interfaceeigenvalue () {
		// for now h is constant 
		float deltax = 0.01 ;
		float hx = 1.0/deltax ;
		float hy = 0.0 ;
		float hz = 0.0 ;
		float hn = 1/deltax ; // delta x is also constant 
		float Ucont = interfacexvelocity * hx + interfaceyvelocity * hy +
		interfacezvelocity*hz ;

		float interfacesoundvelocity = sqrt((gamma-1)*(interfaceenthalpy - 0.5*(pow(interfacexvelocity,2) + 
			pow(interfaceyvelocity,2)+pow(interfacezvelocity,2)))) ;

		float eigenvalue[5] ; //defining the eigenvalue using 5 element array

		eigenvalue[0] = Ucont - interfacesoundvelocity * hn ;
		eigenvalue[1] = Ucont ;
		eigenvalue[2] = Ucont ;
		eigenvalue[3] = Ucont ;
		eigenvalue[4] = Ucont + interfacesoundvelocity * hn ;
		return eigenvalue[1] ;

	}


	float interfaceeigenmatirx(){
		float interfaceeigenmatirxR [5][5] ; // this function will define this eigenvalue matrix R

		float deltax = 0.01 ;
		float hx = 1.0 /deltax ;
		float hy = 0.0 ;
		float hz = 0.0 ;
		float hn = 1.0 /deltax ; // delta x is also constant 
		float hdesx = hx / hn ;
		float hdesy = hy / hn ;
		float hdesz = hz / hn ;


		float q_interface = sqrt(pow(interfacexvelocity,2)+pow(interfaceyvelocity,2)+pow(interfacezvelocity,2)) ;

		float interfacesoundvelocity = sqrt((gamma-1)*(interfaceenthalpy - 0.5*(pow(interfacexvelocity,2) + 
			pow(interfaceyvelocity,2)+pow(interfacezvelocity,2)))) ;


		// phi = (interfacexvelocity*hdesx+ interfaceyvelocity * hdesy + interfacezvelocity*hdesz);

		interfaceeigenmatirxR [0][0] = 1 ;
		interfaceeigenmatirxR [0][1] = 1 ;
		interfaceeigenmatirxR [0][2] = 0 ;
		interfaceeigenmatirxR [0][3] = 0 ;
		interfaceeigenmatirxR [0][4] = 1 ;

		interfaceeigenmatirxR [1][0] = interfacexvelocity - hdesx *interfacesoundvelocity ;
		interfaceeigenmatirxR [1][1] = interfacexvelocity ;
		interfaceeigenmatirxR [1][2] = hdesy ;
		interfaceeigenmatirxR [1][3] = hdesz ;
		interfaceeigenmatirxR [1][4] = interfacexvelocity + hdesx*interfacesoundvelocity;

		interfaceeigenmatirxR [2][0] = interfaceyvelocity - hdesy *interfacesoundvelocity ;
		interfaceeigenmatirxR [2][1] = interfaceyvelocity ;
		interfaceeigenmatirxR [2][2] = hdesz ;
		interfaceeigenmatirxR [2][3] = hdesx ;
		interfaceeigenmatirxR [2][4] = interfaceyvelocity + hdesy*interfacesoundvelocity;
		
		interfaceeigenmatirxR [3][0] = interfacezvelocity - hdesz *interfacesoundvelocity ;
		interfaceeigenmatirxR [3][1] = interfacezvelocity ;
		interfaceeigenmatirxR [3][2] = hdesx ;
		interfaceeigenmatirxR [3][3] = hdesy ;
		interfaceeigenmatirxR [3][4] = interfacezvelocity + hdesz*interfacesoundvelocity;

		interfaceeigenmatirxR [4][0] = interfaceenthalpy - hdesx*interfacexvelocity*interfacesoundvelocity -
		hdesy*interfaceyvelocity*interfacesoundvelocity - hdesz*interfacezvelocity*interfacesoundvelocity ;
		interfaceeigenmatirxR [4][1] = 0.5*pow(q_interface,2) ;
		interfaceeigenmatirxR [4][2] = hdesx*interfacezvelocity + hdesz*interfaceyvelocity + 
		hdesy*interfacexvelocity ;
		interfaceeigenmatirxR [4][3] = hdesy*interfacezvelocity + hdesx*interfaceyvelocity + 
		hdesz*interfacexvelocity ;
		interfaceeigenmatirxR [4][4] =  interfaceenthalpy + hdesx*interfacexvelocity*interfacesoundvelocity +
		hdesy*interfaceyvelocity*interfacesoundvelocity + hdesz*interfacezvelocity*interfacesoundvelocity ;
		

	// printing the eigenvector matrix

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				cout << interfaceeigenmatirxR[i][j] << "    " ;
			}
			cout << endl ;
		}

	}

// ~interfacevector();
	
};