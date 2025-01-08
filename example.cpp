#include <iostream>
#include <math.h>
#include "zet_plot.h"


int main(int argc, char **argv) {


	std::vector<double> x = {10,20,33,43,56,6,82,39,20,-1,-25,-3,-46,-50,-6,-99,-20,-10};
	std::vector<double> y = {1,25,3,46,50,6,99,20,10,-10,-20,-33,-43,-56,-6,-82,-39,-20};
	zet_plot pl(300,300,"example");
	pl.plot(x,y);
	pl.color_point('r');
	pl.show();

	std::vector<double> x1;
	std::vector<double> y1;
	for(double i = 0;i<100;i+=5)x1.push_back(i);
	for(double i = 0;i<100;i+=5)y1.push_back(i);
	zet_plot pl1(300,300,"example(ramp function)");
	pl1.plot(x1,y1);
	pl1.color_point('k');
	pl1.show();

	std::vector<double> x2;
	std::vector<double> y2;
	for(double i = 0;i<100;i+=5)x2.push_back(i);
	for(double i = 0;i<100;i+=5)y2.push_back(30);
	zet_plot pl2(300,300,"example(unit_step function)");
	pl2.plot(x2,y2);
	pl2.color_point('b');
	pl2.show();
	
	std::vector<double> x3;
	std::vector<double> y3;
	for(double i = 0;i<200;i++)x3.push_back(i);
	for(double i = 0;i<200;i++)y3.push_back(sin(1.0*3.14*(1/50.0)*x3[i])*50.0);
	zet_plot pl3(500,400,"example(sin wave)");
	pl3.plot(x3,y3);
	pl3.color_point('y');
	pl3.show();

	std::vector<double> x4;
	std::vector<double> y4;
	for(double i = 0;i<200;i++)x4.push_back(i);
	for(double i = 0;i<200;i++)y4.push_back(cos(1.0*3.14*(1/50.0)*x4[i])*50.0);
	zet_plot pl4(500,400,"example(cos wave)");
	pl4.plot(x4,y4);
	pl4.color_point('m');
	pl4.show();

	return 0;
}
