//////////////////////////////////////////////////////////////
// englobj.h
// objects using English measurements
//////////////////////////////////////////////////////////////
#ifndef DISTANCE_H
#define DISTANCE_H

class Distance {
    private:
        int feet;
        float inches;
    
    public:
        // constructor
        Distance();
        Distance(int ft, float in);

        // member functions
        void getDistance();
        void showDistance() const;
};

#endif

