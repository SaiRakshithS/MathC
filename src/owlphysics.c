#include "owlphysics.h"

    vect acceleration (object a)

        {
            vect acc = scaleall (a.force, (1 / a.mass)) ;
            return acc ;
        }

    vect centreMass (object a[], int numObjects)

        {
            vect centreMass = {0, 0, 0} ;
            double totalMass = 0.0 ;

            for (int i = 0 ; i < numObjects ; i ++)

                {
                    vect temporary = a[i].position ;
                    temporary = scaleall (temporary, a[i].mass) ;       // Finding centre of mass of general polyhedron is a challenge. It can calculate for system of particles.
                                                                        // However, there is no parameter for centre of mass in the "Object" Structure.
                    centreMass = add (centreMass, temporary) ;          // Combining this with "update" function must be thought out.   
                    totalMass += a[i].mass ;
                }

            centreMass = scaleall (centreMass, (1 / totalMass)) ;

            return centreMass ;
        }




    vect gravityField (vect point, object a)

        {
            vect r ;

            r = sub (a.position, point) ;

            double grav = (G * a.mass) / magnSquare (r) ;

            r = normailize (r) ;                                    // This works perfectly fine for spheres and point objects. Should create a new gravity function
                                                                    // for polyhedra. Might be challenging, since they don't obey Shell Theorem.        
            vect gravityField ;

            gravityField = scaleall (r, grav) ;

            return gravityField ;
        }

    double gravityEnergy (object a, object b)

        {
            vect r = sub (a.position, b.position) ;
            double gravityEnergy = (G * a.mass * b.mass) / magn (r) ;

            return gravityEnergy ;
        }

    void applyGravity (object a[], int numObjects)

        {
            for (int i = 0 ; i <= numObjects - 1 ; i ++)

                {
                    for (int j = i + 1 ; j < numObjects ; j ++)

                        {
                            vect gravOnI = gravityField (a[i].position, a[j]) ;
                            vect gravOnJ = gravityField (a[j].position, a[i]) ;

                            gravOnI = scaleall (gravOnI, a[i].mass) ;
                            gravOnJ = scaleall (gravOnJ, a[j].mass) ;

                            a[i].force = add (a[i].force, gravOnI) ;
                            a[j].force = add (a[j].force, gravOnJ) ;

                            double gravEnergy = gravityEnergy (a[i], a[j]) ;

                            a[i].energy += gravEnergy ;
                            a[j].energy += gravEnergy ;

                        }
                }
        }




    vect electricField (vect point, object a, double permittivity)

        {
            vect r ;

            r = sub (a.position, point) ;

            double elec = (a.charge) / (4 * PI * permittivity) / magnSquare (r) ;

            r = normailize (r) ;

            vect electricField ;

            electricField = scaleall (r, elec) ;

            return electricField ;
        }

    double electricEnergy (object a, object b, double permittivity)

        {
            vect r = sub (a.position, b.position) ;
            double electricEnergy = (a.charge * b.charge) / (4 * PI * permittivity) / magn (r) ;

            return electricEnergy ;
        }

    void applyElectric (object a[], int numObjects, double permittivity)

        {
            for (int i = 0 ; i <= numObjects - 1 ; i ++)

                {
                    for (int j = i + 1 ; j < numObjects ; j ++)

                        {
                            vect elecOnI = electricField (a[i].position, a[j], permittivity) ;
                            vect elecOnJ = electricField (a[j].position, a[i], permittivity) ;
                                                                                                    // See gravity section.
                            elecOnI = scaleall (elecOnI, a[i].charge) ;
                            elecOnJ = scaleall (elecOnJ, a[j].charge) ;

                            a[i].force = add (a[i].force, elecOnI) ;
                            a[j].force = add (a[j].force, elecOnJ) ;

                            double elecEnergy = electricEnergy (a[i], a[j], permittivity) ;

                            a[i].energy += elecEnergy ;
                            a[j].energy += elecEnergy ;

                        }
                }
        }




    void update (object a[], int numObjects, double delTime)

        {
            for (int i = 0 ; i < numObjects ; i ++)

                {
                    vect acc = acceleration (a[i]) ;
                    a[i].velocity = scaleall (acc, delTime) ;
                    a[i].position = scaleall (a[i].velocity, delTime) ;                             // Apply function takes care of energy. Some issues might remain
                }                                                                                   // as far as accuracy is concerned, and efficient use of "delTime"
        }


        

    void rotPoly (object a, int numVertices, vect n, double angle)

        {
            for (int i = 0 ; i < numVertices ; i ++)

                {
                    a.shape.poly.vertex[i] = ( rotQ (a.shape.poly.vertex[i], n, angle) ).im ;
                }

            a.shape.poly.surfaceNormal = ( rotQ (a.shape.poly.surfaceNormal, n, angle) ).im ;
            a.position = ( rotQ (a.position, n, angle) ).im ;
        }

    void rotCylin (object a, vect n, double angle)

        {
            a.shape.cylinder.surfaceNormal = ( rotQ (a.shape.cylinder.surfaceNormal, n, angle) ).im ;   // Rotation works perfectly fine. Should think about how materials
            a.position = ( rotQ (a.position, n, angle) ).im ;                                           // added by user on top of the surface will transfer over.     
        }                                                                                               // Rotating tangent vector is an idea, but doesn't seem plausible.
            
    void rotSpher (object a, vect n, double angle)

        {
            a.position = ( rotQ (a.position, n, angle) ).im ;
        }

    // Things to do : Add collisions, update "update" funtion to include collisions.
