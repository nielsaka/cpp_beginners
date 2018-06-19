#ifndef PARTICLE_H_
#define PARTICLE_H_ 

namespace cop {
struct Particle {
private:
	double m_speed;
	double m_direction;
//private:
//public: 
// break encapsulation for sake of efficiency; no need to go via access method..
// in games, simulations etc. need to make compromises
public:
	double m_x; // "m_" stands for member variable 
	double m_y; // why double? be able to change gradually

// alternatively, use "struct" instead of "class"
// default in class: member objects are private
// default in struct: member objects are public 
public:
	void init();
	Particle();
	~Particle();
	void update(int interval);
};
}
#endif