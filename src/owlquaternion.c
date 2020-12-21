#include <stdio.h>
#include <math.h>
#include "owlquaternion.h"

    quaternion conjugateQ (quaternion a)

        {
            quaternion result ;

            result.re = a.re ;
            result.im = scaleall (a.im, -1.0) ;   

            return result ;
        }

    double modQ (quaternion a)

        {
            double result ;

            result = (a.re * a.re) + magnSquare (a.im) ;
            result = sqrt (result) ;

            return result ;
        }

    quaternion inverseQ (quaternion a)

        {
            quaternion result = conjugateQ (a) ;

            result.re = result.re * modQ (a) ;
            result.im = scaleall(result.im, modQ (a)) ;

            return result ;
        }

    quaternion addQ (quaternion a, quaternion b)

        {
            quaternion result ;

            result.re = a.re + b.re ;
            result.im = add (a.im, b.im) ;

            return result ;
        }

    quaternion subQ (quaternion a, quaternion b)

        {
            quaternion result ;

            result.re = a.re - b.re ;
            result.im = sub (a.im, b.im) ;

            return result ;
        }

    quaternion mul2Q (quaternion a, quaternion b)

        {
            quaternion result ;

            result.re = ( a.re * b.re ) - dot (a.im, b.im) ;

            a.im = scaleall (a.im, b.re) ;
            b.im = scaleall (b.im, a.re) ;

            result.im = add (a.im, b.im) ;
            result.im = add (result.im, cross (a.im, b.im)) ;

            return result ;
        }

    quaternion mul3Q (quaternion a, quaternion b, quaternion c)

        {
            quaternion result ;

            result = mul2Q (a, b) ;
            result = mul2Q (result, c) ;

            return result ;
        }

    quaternion rot (vect a, vect n, double angle)

        {
            quaternion result ;

            quaternion pure ;
            pure.re = 0.0 ;
            pure.im = a ;

            quaternion rotator ;
            rotator.re = cos (angle / 2) ;
            rotator.im = normalize (n) ;
            rotator.im = scaleall (rotator.im, sin (angle / 2)) ;

            result = mul3Q (rotator, pure, conjugateQ (rotator)) ;

            return result ;
        }

    void printQ (quaternion a)
        
        {
            printf ("%lf + %lf i + %lf j + %lf k\n", a.re, a.im.x, a.im.y, a.im.z) ;
        }

    void scanQ (quaternion* a)
        
        {
            scanf ("%lf %lf %lf %lf", &a -> re, &a -> im.x, &a -> im.y, &a -> im.z) ;
        }


    // Some doubts on whether the quaternion library is actually necessary. They are very useful for multiple rotations, but not satisfied with present utility.
