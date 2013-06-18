#ifndef OW_PHYSICS_SIMULATOR_H
#define OW_PHYSICS_SIMULATOR_H

#include "owPhysicsConstant.h"
#include "owHelper.h"
#include "owOpenCLSolver.h"

class owPhysicsFluidSimulator
{
public:
	owPhysicsFluidSimulator(void);
	owPhysicsFluidSimulator(owHelper * helper);
	~owPhysicsFluidSimulator(void);
	float * getposition_cpp() { return position_cpp; };
	float * getvelocity_cpp() { return velocity_cpp; };
	float * getdensity_cpp() { ocl_solver->read_density_buffer( density_cpp ); return density_cpp; };
	unsigned int * getparticleIndex_cpp() { ocl_solver->read_particleIndex_buffer( particleIndex_cpp ); return particleIndex_cpp; };
	//TODO helper functions delete after fix!!
	float * getelasticConnectionsData_cpp() { return elasticConnectionsData_cpp; };
	double simulationStep();
private:
	owOpenCLSolver * ocl_solver;
	float * position_cpp;			// everywhere in the code %variableName%_cpp means that we create 
	float * velocity_cpp;			// and initialize in 'ordinary' memory some data, which will be 
	float * elasticConnectionsData_cpp; // copied later to OpenCL buffer %variableName% 
	//Helper arrays
	float * density_cpp;
	unsigned int * particleIndex_cpp;
	float * acceleration_cpp;//TODO REMOVE after fixing
	owHelper * helper;
};

#endif //OW_PHYSICS_SIMULATOR_H