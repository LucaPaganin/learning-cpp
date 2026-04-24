#ifndef _GEOMVECTOR_H_
#define _GEOMVECTOR_H_

#include <fstream>

/*
 * La classe vettore implementa un vettore geometrico in tre dimensioni
 */
class GeomVector {

 public:
   
   GeomVector() { Set(0, 0, 0); }

   GeomVector(double x, double y, double z) { Set(x, y, z); }

   virtual ~GeomVector() {}

   void Set(double x, double y, double z)
   { m_x =x; m_y = y; m_z = z; }
   
   void SetX(double x) { m_x = x; }
   void SetY(double y) { m_y = y; }
   void SetZ(double z) { m_z = z; }
   double GetX() const { return m_x; }
   double GetY() const { return m_y; }
   double GetZ() const { return m_z; }


   GeomVector operator+(const GeomVector& v2) const;

   GeomVector operator-(const GeomVector& v2) const;
   
   GeomVector operator-() const;
   
   double operator*(const GeomVector& v2) const;
   
   GeomVector Cross(const GeomVector& v2) const;
   
   /*
    * prodotto per un numero nella forma vettore * numero
    *
    * NOTA: In geometria il prodotto di uno scalare per un vettore gode della
    *       proprieta' commutativa, per cui le operazioni scalare*vettore e
    *       vettore*scalare sono equivalenti.
    *       Questo concetto pero' non vale automaticamente anche all'interno
    *       di un programma C++: in questo caso le due operazioni sono
    *       formalmente distinte, ed e' solo implementandole entrambe, e con
    *       lo stesso algoritmo, che si realizza la loro equivalenza.
    *
    *       Questo operatore definisce il prodotto vettore*numero.
    *       Il caso inverso di numero*vettore e' invece definito in fondo a
    *       questo file, all'esterno della definizione della classe GeomVector,
    *       ed e' implementato in fondo al file GeomVector.cpp
    *       Notate la differenza di sintassi tra i due casi.
    */
   GeomVector operator*(double scalar) const;

   /* divisione per un numero nella forma vettore / numero
    *
    * in questo caso non c'e' bisogno di implementare numero / vettore,
    * perche' si tratta di un'operazione priva di senso matematico.
    */
   GeomVector operator/(double valore) const { return operator*(1./valore); }

   double Modulo() const;
   
   GeomVector Versore() const { return operator/(Modulo()); }
   
 private:

  double m_x;
   double m_y;
   double m_z;
};

GeomVector operator*(double scalar, GeomVector& v);

std::ostream& operator<<(std::ostream& o, const GeomVector& v);
#endif
