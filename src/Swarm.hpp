/*particle.hpp
houses class and function prototypes for swarm class
for openclless version

Copyright 2018 by Aaron Klapatch,
code derived from http://www.swarmintelligence.org/tutorials.php
along with some help from Dr. Ebeharts presentation at IUPUI.
*/

#ifndef _SWARM_HPP_
#define _SWARM_HPP_

#include <vector>
#include <cmath>
#include <random>
#include <iostream>
#include <cstring>

#define RAN (float)(rng()%1000)/1000
#define DEFAULT_DIM 1
#define DEFAULT_PARTNUM 100
#define DEFAULT_W 1
#define DEFAULT_C1 1.492
#define DEFAULT_C2 1.492

/** Represents a herd, school, or organization
 * of members trying to find the best
 * solution to a problem
 */
class Swarm {
    private:
    
        // Number of particles and Number of dimensions in "problem space"
        size_t partnum, dimnum;
        
        // the best particle position in the swarm
        std::vector<double> gbest;

        // fitness of the best position of the swarm
        double gfitness;

        // The upper and lower bounds of the problem space
        std::vector<double> upperbound, lowerbound;

        // inertial weight and 2 behavioral constants
        float w, c1, c2;

        //particle position, its best position, and its velocity
        std::vector<double> presents, pbests, v;

        //fitnesses of the particle's best position and the current fitness
        std::vector<double> pfitnesses, fitnesses;

    public:

        /// Default constructor.
        /// Makes a swarm with 100 particles and a 1 dimension problem space.
        Swarm();

        /** Makes a Swarm with the specified parameters.
         * @param numparts Number of particles in the swarm.
         * @param numdims Number of dimensions in problem space.
         * @param w How much velocity carries over from update to update. Best left between 0 and 1.
         * @param c1 How much the particle's best position affects the particle's velocity.
         * @param c2 How much the global best affects the individual particle's next position.
         */
        Swarm(size_t numparts,size_t numdims,float w,float c1,float c2);


        /// Destructor.
        /// Frees Heap-allocated memory
        ~Swarm();

        /// Sets the number of particles in the swarm.
        /// Deletes all stored particle data
        void setPartNum(size_t);

        /// Returns number of particles in the swarm.
        size_t getPartNum();

        /// Sets number of dimensions in the problem space.
        /// Deletes all particle data
        void setDimNum(size_t);

        /// Returns number of dimensions in problem space
        size_t getDimNum();

        /// Sets the inertial weight.
        void setWeight(float);

        /// Returns the inertial weight.
        float getWeight();

        /// Sets the constant affecting the pull of particles' best.
        void setC1(float);

        ///  Sets the constant affecting the pull of the global best.
        void setC2(float);

        /// Returns particle best behavioral constant.
        float getC1();

        /// Returns global best behavioral constant.
        float getC2();

        // internal function to reserve vector sizes
        void Reserve(size_t,size_t);

        /** Sets upper and lower bounds for the problem space and distributes linearly between them.
         * @param lowerbound The lower bound in the problemspace.
         * @param upperbound The upper bound in the problem space.
         */ 
        void distribute(std::vector<double> lowerbound, std::vector<double> upperbound);

        /** Updates all particle data values
         * @param times The number of times to update the particle values.
         * @param *fitness Takes in the current position of a particle (offset specifies how far along you are in the array) and returns the particle fitness.
         */
        void update(int times, double (*fitness)(std::vector<double>, size_t) );

        /// Returns position of global best.
        std::vector<double> getGBest();

        /// Returns the fitness of the best particle.
        double getGFitness();

        /// Copies data from the input argument into the particle matrix.
        void setPartData(std::vector<double>);

        /// Returns particle Data.
        std::vector<double> getPartData();
};

#endif
