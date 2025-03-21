class Complex {
    public:
        int real, imag;

        Complex(int r, int i) : real(r), imag(i) {}

        Complex operator+(const Complex& c) {
            return Complex(real + c.real, imag + c.imag);
        }

        void display() {
            cout << real << " + " << imag << "i" << endl;
        }
};

int main() {
    Complex c1(3, 2), c2(1, 7);
    Complex c3 = c1 + c2; // Using overloaded +
    c3.display();
    return 0;
}
