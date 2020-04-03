#pragma once

#include <iostream>
#include <vector>
#include <fstream>

struct FileContent {
	std::string vadaszNev;
	std::string fajta;
	int suly;
};

inline std::istream& operator>>(std::istream& is, FileContent& e) {
    is >> e.vadaszNev >> e.fajta >> e.suly;
    return is;
}

struct Vadasz {
	std::string vadaszNev;
	bool vanMedve;
};

inline std::ostream& operator<<(std::ostream& os, const Vadasz& e) {
	os << e.vadaszNev << " " << (e.vanMedve?"Igen":"Nem");
	return os;
}

class VadaszEnor {
	public:
		enum Status { norm, abnorm };
		enum Excep { FILE_ERR };
		VadaszEnor(const std::string &fname);
		void first() { read(); next(); }
		void next();
		Vadasz current() const { return fcur; }
		bool end() const { return fend; }
	private:
		std::ifstream f;
		FileContent dx;
		Status sx;
		Vadasz fcur;
		bool fend;
		void read();
};
