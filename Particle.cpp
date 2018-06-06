#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace cop{
Particle::Particle(): m_x(0), m_y(0) {
	m_direction = (2.0 * M_PI * rand() / RAND_MAX);
	m_speed = 0.0001 * rand() / RAND_MAX;
};
Particle::~Particle() {}; // nothing happens??

void Particle::update(int interval) {
	// side-effects!!

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);


	m_x += xspeed * interval;
	m_y += yspeed * interval;
	/*
	if (m_x <= -1.0 || m_x >= 1.0) {
		m_direction += M_PI;
	}
	if (m_y <= -1.0 || m_y >= 1.0) {
		m_direction += M_PI;
	}
	*/
}; 

}
