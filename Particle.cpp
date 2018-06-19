#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace cop{
Particle::Particle(): m_x(0), m_y(0) {
	init();
};
Particle::~Particle() {}; // nothing happens??

void Particle::init() {
	// reset coordinates
	m_x = 0;
	m_y = 0;

	m_direction = (2.0 * M_PI * rand() / RAND_MAX);
	m_speed = 0.01 * rand() / RAND_MAX;
	m_speed *= m_speed;
}

void Particle::update(int interval) {
	// side-effects!!

	m_direction += interval * 0.00008;

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

	// if off screen, reset to center
	if (m_x <= -1.0 || m_x >= 1.0) {
		init(); // call to this_particle_object.init() !! knows for which object to call init()
	}
	if (m_y <= -1.0 || m_y >= 1.0) {
		init();	
	}

	//recenter at random
	if (rand() < RAND_MAX / 100) {
		init();
	}
}; 

}
