#include "GeomVector.h"

#include <iostream>
#include <cmath>

using namespace std;


GeomVector GeomVector::operator+(const GeomVector& v2) const
{
   GeomVector v;
   v.SetX(m_x + v2.GetX());
   v.SetY(m_y + v2.GetY());
   v.SetZ(m_z + v2.GetZ());
   return v;
}


GeomVector GeomVector::operator-() const
{
   /* sfrutta operator-(double scalar), moltiplicando per -1 */
   return this->operator*(-1);
}



GeomVector GeomVector::operator-(const GeomVector& v2) const
{
   return GeomVector(m_x - v2.m_x, m_y - v2.m_y, m_z - v2.m_z);
}


double GeomVector::operator*(const GeomVector& v2) const
{
   return m_x*v2.m_x + m_y*v2.m_y + m_z*v2.m_z;
}


GeomVector GeomVector::operator*(double scalar) const
{
   return GeomVector(scalar*m_x, scalar*m_y, scalar*m_z);
}


double GeomVector::Modulo() const
{
   // sfrutta l'implementazione del prodotto scalare
   //
   // NOTA: this e' una parola chiave del C++ che indica il puntatore
   //       dell'oggetto in questione
   return sqrt( (*this) * (*this) );
}



GeomVector GeomVector::Cross(const GeomVector& v2) const {
   double vx = m_y * v2.m_z  -  m_z * v2.m_y;
   double vy = m_z * v2.m_x  -  m_x * v2.m_z;
   double vz = m_x * v2.m_y  -  m_y * v2.m_x;
   return GeomVector(vx, vy, vz);
}

GeomVector operator*(double scalar, GeomVector& v)
{
   // sfrutta l'implementazione di vettore*numero
   return v*scalar;
}


ostream& operator<<(ostream& o, const GeomVector& v)
{
   o << "(" << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ")"
     << flush;
   return o;
}
