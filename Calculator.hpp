#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <cmath>
#include <math.h>
#include <iostream>
#include <algorithm>

const double m_pi = std::atan(1)*4;


class Calculator
{
  private:
    int m_option;
    int n_x;
    int n_y;
    double n_z;
    int n_pow;
    char n_op;

    bool is_running{true};
  
  public:
    Calculator() = default;
    ~Calculator(){};

    // clears extraneous input from the buffer
    void clearExtra()
    {
      // ignores all of the characters up until newline
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // == USER INPUTS ==
    int ask_option()
    {
      int _option{};
      std::cin >> _option;
      if(std::cin.fail())
      {
        std::cin.clear();
        clearExtra();
      }
      clearExtra();

      return _option;
    }


    int ask_int()
    {
      int _num{};
      std::cin >> _num;
      if(std::cin.fail())
      {
        std::cin.clear(); // clears the fail io flag (so that future io operations work ok)
        clearExtra();
      }
      clearExtra(); // clear buffer in case first character is good input

      return _num;
    }

    double ask_double()
    {
      double _num{};
      std::cin >> _num;
      if(std::cin.fail())
      {
        std::cin.clear();
        clearExtra();
      }
      clearExtra();

      return _num;
    }



    double ask_angle()
    {
      double _angle{};
      std::cin >> _angle;
      if(std::cin.fail())
      {
        std::cin.clear();
        clearExtra();
      }
      clearExtra();

      _angle = (_angle * m_pi) / 180; // reconvert into radians
      return _angle;
    }


    char ask_op()
    {
      while(true)
      {
        char _operator{};
        std::cin >> _operator;
        if(std::cin.fail())
        {
          std::cin.clear();
          clearExtra();
        }
        clearExtra();

        switch(_operator)
        {
          case '+': return _operator;
          case '-': return _operator;
          case '*': return _operator;
          case '/': return _operator;
          case '%': return _operator;
          default:
            std::cerr << "Error: Invalid operator \n";
        }
      }
    }

    // == OPERATIONS ==
    int add(int x, int y) {return x + y;}
    int subtract(int x, int y) {return x - y;}
    int multiply(int x, int y) {return x * y;}
    int divide(int x, int y) { return x / y;}
    int modulo(int x, int y) {return x % y;}

    double sine(double x) {return (double)std::sin(x);}
    double cosine(double x) {return (double)std::cos(x);}
    double tangent(double x) {return (double)std::tan(x);}
    double cosecant(double x) {return (double)1/std::sin(x);}
    double secant(double x) {return (double)1/std::cos(x);}
    double cotangent(double x) {return (double)1/std::tan(x);}
    double arcsin(double x) {return (double)std::asin(x);}
    double arccos(double x) {return (double)std::acos(x);}
    double arctan(double x) {return (double)std::atan(x);}
    double arccsc(double x) {return (double)1/std::asin(x);}
    double arcsec(double x) {return (double)1/std::acos(x);}
    double arccot(double x) {return (double)1/std::atan(x);}

    double log(double x) {return std::log(x);}
    double exp(double x) {return std::exp(x);}
    double pow(double x, int y) {return std::pow(x,y);}
    double sqrt(double x) {return std::sqrt(x);}
    double recipr(double x) {return 1/x;}

    int fact(int x) // factorial of a number
    {
      int _res{};
      for(int i{0}; i<=x; ++i)
      {
        _res *= i;
      }
      return _res;
    }


    int perform_basic_operation()
    {
      switch(n_op)
      {
        case '+': return add(n_x,n_y); break;
        case '-': return subtract(n_x,n_y); break;
        case '*': return multiply(n_x,n_y); break;
        case '/': return divide(n_x,n_y); break;
        case '%': return modulo(n_x,n_y); break;

        default: return 0; break;
      }
    }

    double perform_trig_operation()
    {
      switch(m_option)
      {
        case 1: return sine(n_z); break;
        case 2: return cosine(n_z); break;
        case 3: return tangent(n_z); break;
        case 4: return cosecant(n_z); break;
        case 5: return secant(n_z); break;
        case 6: return cotangent(n_z); break;

        default: return 0; break;
      }
    }

    double perform_inverse_trig_operation()
    {
      switch(m_option)
      {
        case 1: return cosecant(n_z); break;
        case 2: return secant(n_z); break;
        case 3: return cotangent(n_z); break;
        case 4: return arccsc(n_z); break;
        case 5: return arcsec(n_z); break;
        case 6: return arccot(n_z); break;

        default: return 0; break;
      }
    }

    double perform_sci_operation()
    {
      switch(m_option)
      {
        case 1: return log(n_z); break;
        case 2: return exp(n_z); break;
        case 3: return pow(n_z,n_pow); break;
        case 4: return sqrt(n_z); break;
        case 5: return recipr(n_z); break;
        case 6: return fact(n_x); break;

        default: return 0; break;
      }
    }

    void basic_operation()
    {
      std::cout << "Enter 2 numbers: \n";
      n_x = ask_int();
      n_y = ask_int();
      
      std::cout << "Enter an operator (+,-,*,/,%): \n";
      n_op = ask_op();

      std::cout << n_x << " " << n_op << " " << n_y << " = " << perform_basic_operation() << '\n';
      is_running = false;
    }

    void trigonometric_operation()
    {
      std::cout << "Choose:\n1.Standard trigonometric functions\n2.Inverse trigonometric functions\n";
      int _option{};
      std::cin >> _option;
      switch(_option)
      {
        case 1: // standard trig
          std::cout << "Select function:\n1.sin()\n2.cos()\n3.tan()\n4.csc()\n5.sec()\n6.cot()\n";
          m_option = ask_option();
      
          std::cout << "Enter angle in degrees: \n";
          n_z = ask_angle();

          std::cout << "θ = " << perform_trig_operation() << " radians" << '\n';
          break;
        
        case 2: // inverse trig
          std::cout << "Select function:\n1.arcsin()\n2.arccos()\n3.arctan()\n4.arccsc()\n5.arcsec()\n6.arccot()\n";
          m_option = ask_option();
      
          std::cout << "Enter angle in degrees: \n";
          n_z = ask_angle();

          std::cout << "θ = " << perform_inverse_trig_operation() << " radians\n";
          break;
        
        default:
          std::cerr << "Error: Something went wrong\n"; break;
      }

      is_running = false;
    }

    void scientific_operation()
    {
      std::cout << "Select function:\n1.log()\n2.exp()\n3.pow()\n4.sqrt()\n5.recipr()\n6.factorial()\n";
      m_option = ask_option();

      std::cout << "Enter number:";
      n_z = ask_double();

      if(m_option == 3)
      {
        std::cout << "Enter power:";
        n_pow = ask_int();
      }

      std::cout << "Result: " << perform_sci_operation() << '\n';
      is_running = false;
    }

    void run()
    {
      while(is_running)
      {
        std::cout << "Select operation type:\n1.Basic operation (+,-,*,/,%)" << 
        "\n2.Trigonometric operation (sin,cos,tan,etc.)" <<
        "\n3.Scientific calculator(pow,log,sqrt,etc.)\n4.Unit conversions \n";

        m_option = ask_option();
        switch(m_option)
        {
          case 1: basic_operation(); break;
          case 2: trigonometric_operation(); break;
          case 3: scientific_operation(); break;
          

          default:
            std::cerr << "Error: Error \n"; break;
        }
      }
    }

    
};

#endif //!CALCULATOR_HPP
