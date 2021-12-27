#include "decoder.h"

Cube::Cube() {
    
}

Cube::~Cube() {
    delete[] cubes;
    cubes = nullptr;
}

std::string Cube::get_coded_line() const {
    return m_coded_line;
}

std::string Cube::get_key_for_decryption() const {
    return m_decryption_key;
};

int  Cube::get_how_many_cubes(const std::string &line) const {
    m_cubesNumber = (((line.size() - 1) / VertexNumber) + 1);
    return m_cubesNumber;
}

void Cube::entering_tops_symbols(const std::string &line) {
    int countForLine = 0;
    for(int i {}; i < m_cubesNumber; i++) {
        if(line.size() > VertexNumber) {
            for(int j {}; j < VertexNumber && countForLine < line.size(); j++) {
                cubes[i].m_cubes_tops[j] = line[countForLine];
                countForLine++;
            }
        }else {
            for(int j {}; j < line.size(); j++) {
                cubes[i].m_cubes_tops[j] = line[countForLine];
                countForLine++;
            }
        }
    }
}

void Cube::key_decryption(const std::string &key) {
    int cubeDecide = key[0] - '1';
    m_decryption_key = m_decryption_key + key[0] ;

    for(int i {}; i < key.size(); i++) {
        switch (key[i]) {
        case 'u':
        case 'U':
            TurnAround_UP(cubes[cubeDecide].m_cubes_tops);
            m_decryption_key = m_decryption_key + ':' + 'd';
            break;

        case 'd':
        case 'D':
            TurnAround_DOWN(cubes[cubeDecide].m_cubes_tops);
            m_decryption_key = m_decryption_key + ':' + 'u';
            break;

        case 'l':
        case 'L':
            TurnAround_LEFT(cubes[cubeDecide].m_cubes_tops);
            m_decryption_key = m_decryption_key + ':' + 'r';
            break;

        case 'r':
        case 'R':
            TurnAround_RIGHT(cubes[cubeDecide].m_cubes_tops);
            m_decryption_key = m_decryption_key + ':' + 'l';
            break;
        }
    }
}

void Cube::TurnAround_UP(char* cubeTop) {
    char tmp = cubeTop[0];
    cubeTop[0] = cubeTop[4];
    cubeTop[4] = cubeTop[5];
    cubeTop[5] = cubeTop[1];
    cubeTop[1] = tmp;
    tmp = cubeTop[2];
    cubeTop[2] = cubeTop[3];
    cubeTop[3] = cubeTop[7];
    cubeTop[7] = cubeTop[6];
    cubeTop[6] = tmp;
}

void Cube::TurnAround_DOWN(char* cubeTop) {
    char tmp = cubeTop[0];
    cubeTop[0] = cubeTop[1];
    cubeTop[1] = cubeTop[5];
    cubeTop[5] = cubeTop[4];
    cubeTop[4] = tmp;
    tmp = cubeTop[2];
    cubeTop[2] = cubeTop[6];
    cubeTop[6] = cubeTop[7];
    cubeTop[7] = cubeTop[3];
    cubeTop[3] = tmp;
}

void Cube::TurnAround_LEFT(char* cubeTop){
    char tmp = cubeTop[0];
    cubeTop[0] = cubeTop[3];
    cubeTop[3] = cubeTop[7];
    cubeTop[7] = cubeTop[4];
    cubeTop[4] = tmp;
    tmp = cubeTop[2];
    cubeTop[2] = cubeTop[6];
    cubeTop[6] = cubeTop[5];
    cubeTop[5] = cubeTop[1];
    cubeTop[1] = tmp;
}

void Cube::TurnAround_RIGHT(char* cubeTop) {
    char tmp = cubeTop[0];
    cubeTop[0] = cubeTop[4];
    cubeTop[4] = cubeTop[7];
    cubeTop[7] = cubeTop[3];
    cubeTop[3] = tmp;
    tmp = cubeTop[2];
    cubeTop[2] = cubeTop[1];
    cubeTop[1] = cubeTop[5];
    cubeTop[5] = cubeTop[6];
    cubeTop[6] = tmp;
}

std::string Cube::StartEncoding(const std::string &line, const std::string &key) {

                    /******         Size of Cubes array             ******/

    m_cubesNumber = (((line.size() - 1) / VertexNumber) + 1);

                    /******    Entering tops symbols from line      ******/

    entering_tops_symbols(line);

                    /*******           Key decryption               ******/

    key_decryption(key);

                    /*******            Get coded line              ******/
    
    for(int i {}; i < m_cubesNumber; i++) {
            m_coded_line = m_coded_line + cubes[i].m_cubes_tops;
    }
    return m_coded_line;
};
