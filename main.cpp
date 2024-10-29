#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

class Electric_Field{
  private:
    double *E = nullptr;

  public:
    ~Electric_Field()= default;


    static Electric_Field E_default(){
      Electric_Field E{};
      E.E = (double*) malloc(sizeof(double)*3);
      E.E[0] = 0;
      E.E[1] = 0;
      E.E[2] = 0;
      return E;
    };

    static Electric_Field E_components(double x, double y, double z){
      Electric_Field E{};
      E.E = (double*) malloc(sizeof(double)*3);
      E.E[0] = x;
      E.E[1] = y;
      E.E[2] = z;

      return E;
    };

  double calculateMagnitude(){
    double x = this->E[0];
    double y = this->E[1];
    double z = this->E[2];
    return sqrt(x*x + y*y + z*z);
  };

  double calculateInnerProduct(){
    double x = this->E[0];
    double y = this->E[1];
    double z = this->E[2];

    return x*y*z; //u1(0,x) u1*v1 = 0 u2*v2=x*y;
  };

  double getX(){
    return this->E[0];
  }
  double getY(){
    return this->E[1];
  }
  double getZ(){
    return this->E[2];
  }

  void setX(double x){
    this->E[0] = x;
  }

  void setY(double y){
    this->E[1] = y;
  }

  void setZ(double z){
    this->E[2] = z;
  }
};

class Magnetic_Field{
private:
  double *M = nullptr;
public:
  ~Magnetic_Field()= default;


  static Magnetic_Field M_default(){
    Magnetic_Field M{};
    M.M = (double*) malloc(sizeof(double)*3);
    M.M[0] = 0;
    M.M[1] = 0;
    M.M[2] = 0;
    return M;
  };

  static Magnetic_Field M_components(double x, double y, double z){
    Magnetic_Field M{};
    M.M = (double*) malloc(sizeof(double)*3);
    M.M[0] = x;
    M.M[1] = y;
    M.M[2] = z;

    return M;
  };

  double calculateMagnitude(){
    double x = this->M[0];
    double y = this->M[1];
    double z = this->M[2];
    return sqrt(x*x + y*y + z*z);
  };

  double* calculateUnitVector(double* vector) {
    vector =  (double *) malloc(3 * sizeof(double));
    double magnitude = this->calculateMagnitude();
    vector[0] = this->M[0]/magnitude;
    vector[1] = this->M[1]/magnitude;
    vector[2] = this->M[2]/magnitude;
    return vector;
  }

  double getX(){
    return this->M[0];
  }
  double getY(){
    return this->M[1];
  }
  double getZ(){
    return this->M[2];
  }

  void setX(double x){
    this->M[0] = x;
  }

  void setY(double y){
    this->M[1] = y;
  }

  void setZ(double z){
    this->M[2] = z;
  }
};


int main() {
  double x = 1e5, y = 10.9, z = 1.7e2;
  Electric_Field E1 = Electric_Field::E_default();
  Electric_Field E2 = Electric_Field::E_components(x, y, z);

  Magnetic_Field M1 = Magnetic_Field::M_default();
  Magnetic_Field M2 = Magnetic_Field::M_components(x,y,z);


  E1.setX(x-1e2);
  E1.setY(y+30);
  E1.setZ(z+1e2);

  M1.setX(10);
  M1.setY(10);
  M1.setZ(10);

  double* vec = nullptr;
  vec = M1.calculateUnitVector(vec);

  cout << "E1 magnitude: " << E1.calculateMagnitude() << endl;
  cout << "E2 magnitude: " << E2.calculateMagnitude() << endl;
  cout << "M1 magnitude: " << M1.calculateMagnitude() << endl;
  cout << "M2 magnitude: " << M2.calculateMagnitude() << endl;
  cout << "M1 unit vector: x=" << vec[0] << " y=" << vec[1] << " z=" << vec[2] << endl;

  free(vec);

  return 0;
}