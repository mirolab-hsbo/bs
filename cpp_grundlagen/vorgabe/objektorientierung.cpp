#include <iostream>
#include <string>

using namespace std;

class Information{
	private:
		string textinfo;
	public:
	    Information(){} // Äquivalent zum default-Konstruktor
	    Information(std::string text){ // alternativer Konstruktor
	        textinfo = text;
	    }
		string get_textinfo() {
			return textinfo;	// alternativ: return this.textinfo
		}
		void set_textinfo(string tinf);
};

void Information::set_textinfo(string tinf){
	textinfo = tinf;	// alternativ: this.textinfo = tinf;
}

int main(){
	Information info_default;
	Information info_helloworld("Hello World"); // Aufruf des alternativen Konstruktors
	info_default.set_textinfo("Test"); // direkter Zugriff über Punktoperator
	Information *infoptr;
	infoptr = &info_default;
	cout << infoptr->get_textinfo() << endl; // indirekter Zugriff über Pointer und Pfeiloperator
	cout<<info_helloworld.get_textinfo()<<endl;
	return 0;
}
