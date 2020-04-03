#include "vadaszEnor.h"

VadaszEnor::VadaszEnor(const std::string &fname) {
    f.open(fname);
    if(f.fail()) throw FILE_ERR;
}

void VadaszEnor::next() {
	fend = ( sx == abnorm );
	if(!fend) {
		fcur.vanMedve = false;
		fcur.vadaszNev = dx.vadaszNev;
		while( sx == norm && fcur.vadaszNev == dx.vadaszNev ) {
			fcur.vanMedve = fcur.vanMedve || ( dx.fajta == "medve" );
			read();
		}
	}
}

void VadaszEnor::read() {
    f >> dx;
    if (f.fail()) sx = abnorm;
    else sx = norm;
}