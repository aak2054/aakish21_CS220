#include<stdio.h>
#include<math.h>


double distance(double lat1,double lat2,double lng1,double lng2){
     double R = 3958.756;
     lat1 = lat1*M_PI/180;
     lat2 = lat2*M_PI/180;
     lng1 = lng1*M_PI/180;
     lng2 = lng2*M_PI/180;
    
     double x = pow(sin((lat2 - lat1)/2),2) + cos(lat1)*cos(lat2)*pow(sin(lng2-lng1)/2,2);
     
     double y = 2* atan2(sqrt(x),sqrt(1-x));

     double distance = R*y;

    return  distance;
}