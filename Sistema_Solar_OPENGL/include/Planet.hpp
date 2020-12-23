#ifndef PLANET_H
#define PLANET_H

#include <vector>
#include <string>
#include <armadillo>

class Planet{
	public:
		//variables
		//metodos
	Planet(std::string name_p, std::string name_f);
	Planet();
	void move_and_paint(arma::fmat transf_toMult);
	void set_value_transform(arma::fmat transf);
	float get_value_angle();
	void create_obj();
	void set_color(arma::frowvec new_color);
	void set_color_rgb(float r, float g, float b);
	void set_aceleration(float aceleration);
	void set_position(float position);
	void set_tam(float tam);
	std::string get_planetName();
	arma::fmat get_transf();
	private:
		//variables
		arma::fmat transf;
		float angle;
		Object myPlanet;
		std::string planet_name;
		std::string file_name;
		arma::frowvec color;
		float r;
		float g;
		float b;
		float aceleration;
		float position;
		float tam;
	//metodos
	void rotate_translade();

};

#endif
