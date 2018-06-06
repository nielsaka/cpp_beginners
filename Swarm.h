#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace cop {
class Swarm {
private:
	// programme does not know yet that it is going to be an array!
	// arrays and pointers = very similar;
	Particle* m_particles; 
public:
	// does it matter where I place const?
	// static = same for all instances
	static int const NPARTICLES = 5000;
public:
	Swarm();
	~Swarm(); // what is "virtual"??
	void update();
	// const so nothing can be changed.
	// second const: pointer (=address?) is const, so can't point at something 
	// else.
	// first const: target (=contents of address?) is const, so can't change 
	// target either (?)
	// but the Particles in m_particles were not const before!? so how can the
	// contents of m_particles now be const?
	// TODO: EXPERIMENT!
	const Particle* const get_particles() {return m_particles;};
};
}
# endif