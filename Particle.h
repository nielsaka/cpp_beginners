#ifndef PARTICLE_H_
#define PARTICLE_H_ 

namespace cop {
struct Particle {
//private:
//public: 
// break encapsulation for sake of efficiency; no need to go via access method..
// in games, simulations etc. need to make compromises
	double m_x; // "m_" stands for member variable 
	double m_y; // why double? be able to change gradually

// alternatively, use "struct" instead of "class"
// default in class: member objects are private
// default in struct: member objects are public 
public:
	Particle();
	~Particle();
};
}
#endif