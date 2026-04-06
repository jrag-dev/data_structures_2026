#ifndef DVD_H
#define DVD_H

#include <string>


class DVD
{
    private:
        std::string name;
        int release_year;
        std::string director;
    public:
        // CONSTRUCTORS
        DVD();
        DVD(std::string _name, int _release_year, std::string _director);
        DVD(const DVD& other_dvd);
        // SETTERS AND GETTERS
        std::string get_name() const;
        int get_release_year() const;
        std::string get_director() const;
        void set_name(std::string _name);
        void set_release_year(int _release_year);
        void set_director(std::string _director);
        // DESTRUCTOR
        ~DVD();
        // métodos adicionales
        void show_dvd_info() const;
};

#endif