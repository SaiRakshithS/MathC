#ifndef QUATERNION_H_
#define QUATERNION_H_

    #include "vector.h"


    typedef struct

        {
            double re ;
            vect im ;

        } quaternion ;

    quaternion conjugateQ (quaternion) ;


    double modQ (quaternion) ;


    quaternion inverseQ (quaternion) ;


    quaternion addQ (quaternion, quaternion) ;


    quaternion subQ (quaternion, quaternion) ;


    quaternion mul2Q (quaternion, quaternion) ;


    quaternion mul3Q (quaternion, quaternion, quaternion) ;


    vect rot (vect, vect, double) ;


#endif
