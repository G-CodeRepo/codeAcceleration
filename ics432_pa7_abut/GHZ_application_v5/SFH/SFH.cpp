#include <cstdlib>
#include <iostream>
//#include "mersenne.cpp"             // code for random number generator
//#include "userintf.cpp"             // define system specific user interface

#include "2Gyr.c"
#include "4Gyr.c"
#include "6Gyr.c"
#include "8Gyr.c"
#include "10Gyr.c"
#include "12Gyr.c"
#include "136Gyr.c"

using namespace std;

/* ******************************************* */
//random number generation   
//must be global.  seeding the random number generator multiple times produces the same 
//random numbers
//int32 seed = (int32)time(0);        // random seed
//CRandomMersenne rg(seed);           // make instance of random number generator
/* ******************************************* */

float generate_birth_date(float radius, float random_num);

/*
int main(int argc, char *argv[])
{
    cout<<"\ntime: "<<generate_birth_date(0,1);
    system("PAUSE");
    return EXIT_SUCCESS;
}
*/

float generate_birth_date(float radius,float random_num) {

	float total_area=0;
	float partial_area=0;
	float partial_segment=0;
	int area=0;
	//float time=0;

	float area_part[8]={0,0,0,0,0,0,0,0}; //using 1-7
	float cumulative_area[8]={0,0,0,0,0,0,0,0}; //using 0-7, where cumulative_area[0]=0

	area_part[1]= ((0+SFR_2Gyr(radius))/2)*1.64;
	area_part[2]= ((SFR_2Gyr(radius)+SFR_4Gyr(radius))/2)*2;
	area_part[3]= ((SFR_4Gyr(radius)+SFR_6Gyr(radius))/2)*2;
	area_part[4]= ((SFR_6Gyr(radius)+SFR_8Gyr(radius))/2)*2;
	area_part[5]= ((SFR_8Gyr(radius)+SFR_10Gyr(radius))/2)*2;
	area_part[6]= ((SFR_10Gyr(radius)+SFR_12Gyr(radius))/2)*2;
	area_part[7]= ((SFR_12Gyr(radius)+SFR_136Gyr(radius))/2)*1.6;

	int i = 0;
	//#pragma omp parallel for shared(total_area) private(i) schedule(dynamic) num_threads(1)
	for (i=1; i<=7;i++) {
	//{
		total_area+=area_part[i];
		cumulative_area[i]=total_area;

		// cout <<"part: "<<i<<endl;
		// cout <<"total area: "<<total_area<<endl;
		// cout <<"cumulative area: "<<cumulative_area[i]<<endl;
	//}	// end of pragma
	}	// end of for loop

	// LOOP UNROLLING
	/*
	total_area+=area_part[1];
	cumulative_area[1]=total_area;

	total_area+=area_part[2];
	cumulative_area[2]=total_area;

	total_area+=area_part[3];
	cumulative_area[3]=total_area;

	total_area+=area_part[4];
	cumulative_area[4]=total_area;

	total_area+=area_part[5];
	cumulative_area[5]=total_area;

	total_area+=area_part[6];
	cumulative_area[6]=total_area;

	total_area+=area_part[7];
	cumulative_area[7]=total_area;
	*/



	partial_area=total_area*random_num;

	//cout <<"\n\npartial_area: "<<partial_area;
	//find the area that the partial area is found
	int j = 0;
	//#pragma omp parallel for private(j) schedule(dynamic) num_threads(1)
	for (j=1; j<=7;j++) {
	//{
		if(partial_area >= cumulative_area[j-1] && partial_area <= cumulative_area[j]) {
			area=j;
			partial_segment=partial_area-cumulative_area[j-1];
			// cout <<"\npartial segment: "<<partial_segment <<"\nArea: "<<area<<endl;
		}       
	//}	// end of pragma                  
	}	// end of for loop


	// LOOP UNROLLING
	/*
	if(partial_area >= cumulative_area[0] && partial_area <= cumulative_area[1]) {
		//area=1;
		partial_segment=partial_area-cumulative_area[0];
		// cout <<"\npartial segment: "<<partial_segment <<"\nArea: "<<area<<endl;
	}  
	if(partial_area >= cumulative_area[1] && partial_area <= cumulative_area[2]) {
		//area=2;
		partial_segment=partial_area-cumulative_area[1];
		// cout <<"\npartial segment: "<<partial_segment <<"\nArea: "<<area<<endl;
	}  
	if(partial_area >= cumulative_area[2] && partial_area <= cumulative_area[3]) {
		//area=3;
		partial_segment=partial_area-cumulative_area[2];
		// cout <<"\npartial segment: "<<partial_segment <<"\nArea: "<<area<<endl;
	}  
	if(partial_area >= cumulative_area[3] && partial_area <= cumulative_area[4]) {
		//area=4;
		partial_segment=partial_area-cumulative_area[3];
		// cout <<"\npartial segment: "<<partial_segment <<"\nArea: "<<area<<endl;
	}  
	if(partial_area >= cumulative_area[4] && partial_area <= cumulative_area[5]) {
		//area=5;
		partial_segment=partial_area-cumulative_area[4];
		// cout <<"\npartial segment: "<<partial_segment <<"\nArea: "<<area<<endl;
	}  
	if(partial_area >= cumulative_area[5] && partial_area <= cumulative_area[6]) {
		//area=6;
		partial_segment=partial_area-cumulative_area[5];
		// cout <<"\npartial segment: "<<partial_segment <<"\nArea: "<<area<<endl;
	}  
	if(partial_area >= cumulative_area[6] && partial_area <= cumulative_area[7]) {
		//area=7;
		partial_segment=partial_area-cumulative_area[6];
		// cout <<"\npartial segment: "<<partial_segment <<"\nArea: "<<area<<endl;
	}
	*/

	if (area==1) {
		//time=((area*2)-2)+ ((partial_segment/area_part[area])*1.64);    
		// cout <<"\n\n\n\n\n partial segment: "<<partial_segment;
		//  cout <<"\n\n area_part[i]: "<<area_part[area]; 
		
		return (((area*2)-2)+ ((partial_segment/area_part[area])*1.64))-0.36;
	} else if (area==2 ||area==3 ||area==4 ||area==5 ||area==6 ) {
		//time=((area*2)-2)+ ((partial_segment/area_part[area])*2);    
		//  cout <<"\n\n\n\n\n partial segment: "<<partial_segment;
		//  cout <<"\n\n area_part[i]: "<<area_part[area]; 
		
		return (((area*2)-2)+ ((partial_segment/area_part[area])*2))-0.36;  
	} else if (area==7) {
		//time=((area*2)-2)+ ((partial_segment/area_part[area])*1.6);  
		// cout <<"\n\n\n\n\n partial segment: "<<partial_segment;
		//  cout <<"\n\n area_part[i]: "<<area_part[area];        
		
		return (((area*2)-2)+ ((partial_segment/area_part[area])*1.6))-0.36;
	} else {
		//return time-0.36; 
		return -0.36;  
 
	}  
}


