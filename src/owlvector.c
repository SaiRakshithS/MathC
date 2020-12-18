#include <stdio.h>
#include <math.h>
#include "vector.h"

    double dot (vect a, vect b)

        {
            double dot = (a.x * b.x) + (a.y * b.y) + (a.z + b.z) ;              // DOT PRODUCT //
            return dot ;
        }

    vect cross (vect a, vect b)

        {
            vect cross ;

            cross.x = (a.y * b.z) - (a.z * b.y) ;
            cross.y = (a.z * b.x) - (a.x * b.z) ;                               // CROSS PRODUCT //
            cross.z = (a.x * b.y) - (a.y * b.x) ;

            return cross ;
        }

    double magn (vect a)

        {
            double magn = sqrt ((a.x * a.x) + (a.y * a.y) + (a.z * a.z)) ;
            return magn ;                                                       // MAGNITUDE //
        }

    double magnSquare (vect a)

        {
            double magnSquare = (a.x * a.x) + (a.y * a.y) + (a.z * a.z) ;      // SQUARE OF MAGNITUDE //
            return magnSquare ;
        }

    vect scaleall (vect a, double b)

        {
            a.x *= b ;
            a.y *= b ;                                                         // SCALE ALL COMPONENTS//
            a.z *= b ;

            return a ;
        }

    vect scale (vect a, double p, double q, double r)

        {
            a.x *= p ;
            a.y *= q ;                                                         // SCALE EACH COMPONENT //
            a.z *= r ;

            return a ;
        }

    double angle (vect a, vect b)

        {
            double dotP = dot (a, b) ;
            double magnit = magn (a) * magn (b) ;                              // ANGLE BETWEEN VECTORS //
            double cos = dotP / magnit ;
            double angle = acos (cos) ;

            return angle ;
        }

    double box (vect a, vect b, vect c)

        {
            vect cros = cross (b, c) ;
            double box = dot (a, cros) ;                                       // TRIPLE / BOX / MIXED PRODUCT //

            return box ;
        }

    vect rotX (vect a, double angle)

        {
            vect result ;

            result.x = a.x ;
            result.y = (a.y * cos (angle)) - (a.z * sin (angle)) ;             // ROTATE ABOUT X AXIS //
            result.z = (a.y * sin (angle)) + (a.z * cos (angle)) ;

            return result ;
        }

    vect rotY (vect a, double angle)

        {
            vect result ;

            result.x = (a.z * sin (angle)) + (a.x * cos (angle)) ;
            result.y = a.y ;                                                   // ROTATE ABOUT Y AXIS //
            result.z = (a.y * cos (angle)) - (a.x * sin (angle)) ;

            return result ;
        }

    vect rotZ (vect a, double angle)

        {
            vect result ;

            result.x = (a.x * cos (angle)) - (a.y * sin (angle)) ;
            result.y = (a.x * sin (angle)) + (a.y * cos (angle)) ;             // ROTATE ABOUT Z AXIS //
            result.z = a.z ;

            return result ;
        }

    vect shearX (vect a, double shY, double shZ)

        {
            vect result ;

            result.x = a.x ;
            result.y = a.y + (shY * a.x) ;                                     // SHEAR IN X AXIS //
            result.z = a.z + (shZ * a.z) ;

            return result ;
        }

    vect shearY (vect a, double shX, double shZ)

        {
            vect result ;

            result.x = a.x + (shX * a.y) ;
            result.y = a.y ;                                                   // SHEAR IN Y AXIS //
            result.z = a.z + (shZ * a.z) ;

            return result ;
        }

    vect shearZ (vect a, double shX, double shY)

        {
            vect result ;

            result.x = a.x + (shX * a.z) ;
            result.y = a.y + (shY * a.z) ;                                     // SHEAR IN Z AXIS //
            result.z = a.z ;

            return result ;
        }

    vect add (vect a, vect b)

        {
            vect result ;

            result.x = a.x + b.x ;
            result.y = a.y + b.y ;                                            // ADD //
            result.z = a.z + b.z ;

            return result ;
        }

    vect sub (vect a, vect b)

        {
            vect result ;

            result.x = a.x - b.x ;
            result.y = a.y - b.y ;                                            // SUBTRACT //
            result.z = a.z - b.z ;

            return result ;
        }

    vect normalize (vect a)
        
        {
            vect unit ;
            unit = scaleall (a, magn (a)) ;                                  // NORMALIZE A VECTOR //
            
            return unit ;
        }

    vect cylin (vect a)

        {
            vect result ;

            double r = sqrt ((a.x * a.x) + (a.y * a.y)) ;                   // CONVERT FROM RECTANGULAR TO CYLINDRICAL //
            double theta = atan2 (a.y, a.x) ;

            result.x = r ;
            result.y = theta ;
            result.z = a.z ;

            return result ;
        }

    vect spher (vect a)

        {
            vect result ;

            double r = sqrt ((a.x * a.x) + (a.y * a.y) + (a.z * a.z)) ;    // CONVERT FROM RECTANGULAR TO SPHERICAL //
            double theta = atan2 (a.y, a.x) ;
            double phi = acos (a.z / r) ;

            result.x = r ;
            result.y = theta ;
            result.z = phi ;

            return result ;
        }

    vect revCylin (vect a)

        {
            vect result ;

            result.x = a.x * cos (a.y) ;                                  // CONVERT FROM CYLINDRICAL TO RECTANGULAR //
            result.y = a.x * sin (a.y) ;
            result.z = a.z ;

            return result ;
        }

    vect revSpher (vect a)

        {
            vect result ;

            result.x = a.x * sin (a.z) * cos (a.y) ;
            result.y = a.x * sin (a.z) * sin (a.y) ;                     // CONVERT FROM SPHERICAL TO RECTANGULAR //
            result.z = a.x * cos (a.z) ;

            return result ;
        }

    vect spherToCylin (vect a)

        {
            vect result ;

            result.x = a.x * cos (a.z) ;
            result.y = a.y ;                                             // CONVERT FROM SPHERICAL TO CYLINDRICAL //
            result.z = a.x * sin (a.z) ;

            return result ;
        }

    vect cylinToSpher (vect a)

        {
            vect result ;

            double phi = sqrt ((a.x * a.x) + (a.z * a.z)) ;

            result.x = phi  ;
            result.y = a.y ;                                             // CONVERT FROM CYLINDRICAL TO SPHERICAL //
            result.z = acos (a.z / phi) ;

            return result ;
        }


    void printVect (vect a)

        {
            printf ("(%lf, %lf, %lf)", a.x, a.y, a.z) ;                 // PRINT A VECTOR //
        }

    void scanVect (vect* a)

        {
            scanf ("%lf, %lf, %lf", &a -> x, &a -> y, &a -> z) ;       // GET A VECTOR //
        }

