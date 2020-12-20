#ifndef PHYSICS_H_
#define PHYSICS_H_

#define G  6.672                     // Do change value of constants as you please.
#define H  6.626                     // They are scaled up to give understandable values.
#define PI 3.141592653589793


    #include "quaternion.h"
    

        typedef struct

            {
                vect amplitude ;

                double frequency ;
                double wavelength ;
                double inPhase ;

                double energy ;

            } wave ;

        typedef struct

            {
                vect surfaceNormal ;
                vect vertex[] ;

            } polyhedron ;

        typedef struct

            {
                vect surfaceNormal ;

                double radius ;
                double height ;

            } cylinder ;

        typedef struct

            {
                double radius ;
                vect centre ;

            } sphere ;

        typedef union

            {
                polyhedron poly ;
                sphere spher ;
                cylinder cylinder ;

            } model ;

        typedef struct

            {
                double charge ;
                double temp ;
                double energy ;

                double mass ;
                vect position ;
                vect velocity ;
                vect force ;

                double momentInertia ;
                vect refPoint ;
                vect angVelocity ;
                vect torque ;

                model shape ;

            } object ;


        vect acceleration (object) ;

        vect centreMass (object[], int) ;



        vect gravityField (vect, object) ;

        double gravityEnergy (object, object) ;

        void applyGravity (object[], int) ;



        vect electricField (vect, object, double) ;

        double electricEnergy (object, object, double) ;

        void applyElectric (object[], int, double) ;



        void update (object[], int, double) ;



        void rotPoly (object, int, vect, double) ;

        void rotCylin (object, vect, double) ;

        void rotSpher (object, vect, double) ;

#endif
