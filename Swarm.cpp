#include "Swarm.h"

namespace cop {
Swarm::Swarm() {
	// allocating memory
	// creating NPARTICLES Particle objects
	// Particle constructor will set random coordinates
	m_particles = new Particle[NPARTICLES];
}; // semicolon not needed!?
Swarm::~Swarm() {
	delete[] m_particles;
};
}