class Complex
{
private:
    double real, image;

public:
    Complex(double r = 0.0, double i = 0.0): real(r), image(i) { }
    double getReal() const
    {
        return real;
    }
    double getImage() const
    {
        return image;
    }
    Complex operator + (const Complex &x)
    {
        return Complex(real + x.real, image + x.image);
    }
    Complex operator - (const Complex &x)
    {
        return Complex(real - x.real, image - x.image);
    }
    Complex operator * (const Complex &x)
    {
        return Complex(real * x.real - image * x.image,
                       real * x.image + image * x.real);
    }
    Complex operator / (const Complex &x)
    {
        double r = (real * x.real + image * x.image)
                 / (x.real * x.real + x.image * x.image);
        double i = (image * x.real - real * x.image)
                 / (x.real * x.real + x.image * x.image);
        return Complex(r, i);
    }
    Complex& operator = (const Complex &x)
    {
        real = x.real;
        image = x.image;
        return *this;
    }
    Complex& operator += (const Complex &x)
    {
        real += x.real;
        image += x.image;
        return *this;
    }
    Complex& operator -= (const Complex &x)
    {
        real -= x.real;
        image -= x.image;
        return *this;
    }
    Complex& operator *= (const Complex &x)
    {
        double r = real, i = image;
        real = r * x.real - i * x.image;
        image = r * x.image + i * x.real;
        return *this;
    }
    Complex& operator /= (const Complex &x)
    {
        double r = real, i = image;
        real = (r * x.real + i * x.image)
             / (x.real * x.real + x.image * x.image);
        image = (i * x.real - r * x.image)
              / (x.real * x.real + x.image * x.image);
        return *this;
    }
    friend bool operator == (const Complex &x, const Complex &y)
    {
        return x.real == y.real && x.image == y.image;
    }
    friend bool operator != (const Complex &x, const Complex &y)
    {
        return x.real != y.real || x.image != y.image;
    }
    friend istream& operator >> (istream &in, Complex &x)
    {
        in >> x.real >> x.image;
        return in;
    }
    friend ostream& operator << (ostream &out, const Complex &x)
    {
        out << x.real;
        if (x.image > 0) out << "+" << x.image << "i";
        else if (x.image < 0) out << x.image << "i";
        return out;
    }
};
