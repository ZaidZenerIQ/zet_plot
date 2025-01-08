#ifndef __ZET_PLOT_H__
#define __ZET_PLOT_H__

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <vector>
#include <map>

class Draw_z : public Fl_Widget {
std::vector<double> x_vec = {0};
std::vector<double> y_vec;
int color = 0;
public:
    Draw_z(int X, int Y, int W, int H, const char*L=0) : Fl_Widget(X,Y,W,H,L){}
    virtual void draw() override {
	double org_point_x = (w()+x()-1)/2;
	double org_point_y = (h()+y()-1)/2;
	const double size_of_point = 3.0;
	std::cout<<"x:"<<x()<<" y:"<<y()<<'\n';
	std::cout<<"ox:"<<org_point_x<<" oy:"<<org_point_y<<'\n';
        fl_color(FL_WHITE); 
	fl_rectf(x(),y(),w(),h());
        fl_color(FL_BLACK);
	fl_line((w()+x()-1)/2,y(),(w()+x()-1)/2,h()+y()-1);
	fl_line(x(),(h()+x()-1)/2,w()+x()-1,(h()+x()-1)/2);
        fl_color(color);
	for(int i = 0;i<x_vec.size();i++){
		if(org_point_x+x_vec[i]<w()+x()-1 && org_point_y+y_vec[i]*-1<h()+y()-1){
			fl_circle(org_point_x+x_vec[i],org_point_y+y_vec[i]*-1,size_of_point);
		}
	}
	
    }
    void set_x_vec(std::vector<double> new_x){
		this->x_vec = new_x;
    }
    void set_y_vec(std::vector<double> new_y){
		this->y_vec = new_y;
    }
    void set_color(int clr){
		this->color = clr;
    }
};

class zet_plot{
std::vector<double> x = {0};
std::vector<double> y = {0};
int cc = FL_RED;
int w = 0;
int h = 0;
std::string name = "";
public:
	zet_plot(int w,int h,std::string name):w(w),h(h),name(name){}
	auto show(){
	  if(this->w == 0 || this->h == 0){
			this->w = 300;
			this->h = 300;
	 }
	         Fl_Double_Window win(0,0,w,h,name.c_str());
		 Draw_z draw_m(10, 10, win.w()-20, win.h()-20);
		 draw_m.set_x_vec(x);
		 draw_m.set_y_vec(y);
		 draw_m.set_color(cc);
    	  	 win.show();
	  	return Fl::run();
	}
	void plot(std::vector<double> xaxis,std::vector<double> yaxis){
		if(xaxis.size() == yaxis.size()){
			this->x = xaxis;
			this->y = yaxis;
		}
		else{
			std::cerr << "x and y not the same size\n";
			std::cerr << "x is " << xaxis.size()<<'\n';
			std::cerr << "y is " << yaxis.size()<<'\n';
		}
	}
	void color_point(char c){
		std::map<char,int> colrs = {{'r',FL_RED},{'b',FL_BLUE},
					    {'k',FL_BLACK},{'g',FL_GREEN},
					    {'m',FL_DARK_MAGENTA},{'y',FL_DARK_YELLOW}};
		cc = colrs[c];
	}
};

#endif
