// Grid points 
// Boundary condition 
// Initial condition are given

#include "iostream"
#include "varaiblevector.h"
#include "eulerflux.h"
#include "interfacevector.h"
#include "interfacejump.h"


#define gamma 1.4
#define gasconstant 287.14
#define heatcapacityconstantvolume 717.5

using namespace std ; 


// float add(varaiblevector a, varaiblevector b)
// {
// 	return a.density+b.density;
// }

int main () {

int i = 2 ; // just for now we want to update the point (5,5,5) for next time step  
float variables_vector[5][5] = {  // randomly choose the five vectors 
	{1,1,3,3,3},
	{1,1,0,0,0},
	{4,1,3,3,1}, // this is the point where we want to update the 
	{5,1,3,3,1},
	{2,2,5,5,5}

} ; 

// varaiblevector vectorleft(1,1,3,3,3);
// varaiblevector vectorright(5,1,3,3,1);

// eulerflux fluxleft(1,1,3,3,3) ;

eulerflux rightflux(variables_vector[i][0],variables_vector[i][1],variables_vector[i][2],
	variables_vector[i][3],variables_vector[i][4]) ; // only Euler flux vector at i,j,k interface

interfacevector interfacexvector(variables_vector[i][0],variables_vector[i][1],variables_vector[i][2],
	variables_vector[i][3],variables_vector[i][4],variables_vector[i+1][0],variables_vector[i+1][1],
	variables_vector[i+1][2],variables_vector[i+1][3],variables_vector[i+1][4]) ; // interface vector at i+0.5,j,k

interfacejump jumpvetor(variables_vector[i][0],variables_vector[i][1],variables_vector[i][2],
	variables_vector[i][3],variables_vector[i][4],variables_vector[i+1][0],variables_vector[i+1][1],
	variables_vector[i+1][2],variables_vector[i+1][3],variables_vector[i+1][4]) ;
	
	// rightflux.printflux() ;

	// cout << rightflux.xeulerflux[1] << endl  ;

	interfacexvector.interfaceeigenmatirx() ;
	// cout << "totalenergy  jump =  " << jumpvetor.deltattotalenergy  << endl;

	// jumpvetor.jumpprint() ;

	return 0;
}