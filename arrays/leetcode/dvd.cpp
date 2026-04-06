#include "dvd.h"
#include <iostream>
#include <string>


// Default constructor
DVD::DVD() : name("DVD without name"), release_year(2000), director("Director without name") {
    std::cout << "\nDVD created successfully." << std::endl;
}

// Destructor completo
DVD::DVD(std::string _name, int _release_year, std::string _director) 
: name(_name), release_year(_release_year), director(_director) {
    std::cout << "\nDVD(" << _name << ", " << _release_year <<  "," << _director << " ), ";
    std::cout << "created successfully." << std::endl;
}

// Copy Destructor
DVD::DVD(const DVD& other_dvd) 
    : name(other_dvd.name + " (copy)"), release_year(other_dvd.release_year), director(other_dvd.director) {
    std::cout << "\nDVD(" << name << ", " << release_year <<  "," << director << " ), ";
    std::cout << "copied successfully." << std::endl;
} 

// Destructor
DVD::~DVD() {
    std::cout << "\nDVD(" << name << ", " << release_year <<  "," << director << " ), ";
    std::cout << "deleted successfully." << std::endl;
}

// Getter and setters
std::string DVD::get_name() const {
    return name;
}

int DVD::get_release_year() const {
    return release_year;
}

std::string DVD::get_director() const {
    return director;
}

void DVD::set_name(std::string _name) {
    this->name = _name;
}

void DVD::set_release_year(int _release_year) {
    this->release_year = _release_year;
}

void DVD::set_director(std::string _director) {
    this->director = _director;
}

void DVD::show_dvd_info() const {
    std::cout << this->name << ", directed by " << this->director << ", released in " << this->release_year << std::endl;
}