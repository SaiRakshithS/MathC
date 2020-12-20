#ifndef QUATERNION_H_
#define QUATERNION_H_

    #include "vector.h"


    typedef struct

        {
            double re ;
            vect im ;

        } quaternion ;

    quaternion conjugateQ (quaternion) ;                                // CONJUGATE OF QUATERNION //


    double modQ (quaternion) ;                                         // MODULUS OF QUATERNION //


    quaternion inverseQ (quaternion) ;                                // INVERSE OF QUATERNION //


    quaternion addQ (quaternion, quaternion) ;                       // ADD 2 QUATERNIONS //


    quaternion subQ (quaternion, quaternion) ;                      // SUBTRACT 2 QUATERNIONS //


    quaternion mul2Q (quaternion, quaternion) ;                     // MULTIPLY 2 QUATERNIONS //


    quaternion mul3Q (quaternion, quaternion, quaternion) ;        // MULTIPLY 3 QUATERNIONS //


    quaternion rot (vect, vect, double) ;                               // ROTATE A VECTOR ABOUT A VECTOR BY AN ANGLE //


#endif
