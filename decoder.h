#include <iostream>
#include <string>

class Cube
{
public:
    Cube();
    ~Cube();

public:
    std::string StartEncoding(const std::string &line, const std::string &key);
    
public:
    std::string get_key_for_decryption() const;
    std::string get_coded_line() const;
    int get_how_many_cubes(const std::string & line) const;

private:
    std::string m_coded_line = "";
    std::string m_decryption_key = "";

private:
    static const int VertexNumber = 8 ;
    mutable int m_cubesNumber {};
    char m_cubes_tops [VertexNumber] {};        
    Cube* cubes = new Cube [m_cubesNumber] ();

private:
    void key_decryption(const std::string &);
    void entering_tops_symbols(const std::string &);

private:
    void TurnAround_UP(char*);
    void TurnAround_DOWN(char*);
    void TurnAround_LEFT(char*);
    void TurnAround_RIGHT(char*);
};

