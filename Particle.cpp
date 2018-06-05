#include "Particle.h"
#include <stdlib.h>

namespace cop{
Particle::Particle() {
	m_x = 2 * (double)rand() / RAND_MAX - 1;
	m_y = 2.0 * rand() / RAND_MAX - 1; // will be double as well!
};
Particle::~Particle() {}; // nothing happens??
}
