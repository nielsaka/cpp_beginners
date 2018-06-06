#include "Particle.h"
#include <stdlib.h>

namespace cop{
Particle::Particle() {
	m_x = 2 * (double)rand() / RAND_MAX - 1;
	m_y = 2.0 * rand() / RAND_MAX - 1; // will be double as well!

	// the 2.0 is really important here
	// otherwise the first part is integer and decimal part cut-off !?
	// even better, place brackets around first multiplication to make
	// sure it is double
	xspeed = (2.0 * rand() / RAND_MAX  - 1) * 0.001;
	yspeed = (2.0 * rand() / RAND_MAX  - 1) * 0.001;
};
Particle::~Particle() {}; // nothing happens??

void Particle::update() {

	// side-effects!!
	m_x += xspeed;
	m_y += yspeed;

	if (m_x < -1.0 || m_x >= 1.0) {
		xspeed *= -1;
	}
	if (m_y < -1.0 || m_y >= 1.0) {
		yspeed *= -1;
	}
}; 

}
