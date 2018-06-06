#include "Swarm.h"

namespace cop {
Swarm::Swarm(): last_time(0) {
	// allocating memory
	// creating NPARTICLES Particle objects
	// Particle constructor will set random coordinates
	m_particles = new Particle[NPARTICLES];
}; // semicolon not needed!?
Swarm::~Swarm() {
	delete[] m_particles;
};
void Swarm::update(int elapsed) {

	int interval = elapsed - last_time;

	for (int i = 0; i < Swarm::NPARTICLES; ++i)
	{
		m_particles[i].update(interval);
	}
	last_time = elapsed;
}
}