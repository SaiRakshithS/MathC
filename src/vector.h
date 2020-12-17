#ifndef VECTOR_H_
#define VECTOR_H_

    typedef struct

        {
            double x ;
            double y ;                                                      // VECTOR //
            double z ;
        } vect ;



    double dot (vect, vect) ;                                               // DOT PRODUCT //



    vect cross (vect, vect) ;                                               // CROSS PRODUCT //



    double magn (vect) ;                                                    // MAGNITUDE OF VECTOR //



    vect scaleall (vect, double) ;                                          // SCALE ALL DIMENSIONS //



    vect scale (vect, double, double, double) ;                             // SCALE INDIVIDUALLY //



    double angle (vect, vect) ;                                             // ANGLE BETWEEN A AND B //



    double box (vect, vect, vect) ;                                         // TRIPLE / BOX PRODUCT //



    vect rotX (vect, double) ;                                              // ROTATE ABOUT X AXIS //



    vect rotY (vect, double) ;                                              // ROTATE ABOUT Y AXIS //



    vect rotZ (vect, double) ;                                              // ROTATE ABOUT Z AXIS //



    vect shearX (vect, double, double) ;                                    // SHEAR ABOUT X AXIS



    vect shearY (vect, double, double) ;                                    // SHEAR ABOUT Y AXIS //



    vect shearZ (vect, double, double) ;                                    // SHEAR ABOUT Z AXIS //



    vect add (vect, vect) ;                                                 // ADD //



    vect sub (vect, vect) ;                                                 // SUBTRACT //



    vect cylin (vect) ;                                                     // CONVERT TO CYLINDRICAL //



    vect spher (vect) ;                                                     // CONVERT TO SPHERICAL //


    vect revCylin (vect) ;                                                  // CYLINDRICAL TO RECTANGULAR //


    vect revSpher (vect) ;                                                  // SPHERICAL TO RECTANGULAR //


    vect spherToCylin (vect) ;                                              // SPHERICAL TO CYLINDRICAL //


    vect cylinToSpher (vect) ;                                              // CYLINDRICAL TO SPHERICAL //

    
    void printVect (vect) ;                                                 // PRINT VECTOR //


    void scanVect (vect*) ;                                                 // GET VECTOR //


#endif

