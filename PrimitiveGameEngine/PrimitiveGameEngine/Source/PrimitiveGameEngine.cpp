#include <vector>
#include <map>
#include "PrimitiveGameEngine.h"

using namespace std;

struct vector3
{
    float x, y, z;
};

struct triangle
{
    vector3 points[3];
};

struct mesh
{
    vector<triangle> triangles;
};

struct matrix4x4
{
    float matrix[4][4] = { 0 };
};


class PrimitiveGameEngine : public olcConsoleGameEngine
{
    mesh m_meshCube;
    
public:
    PrimitiveGameEngine()
    {
        m_meshCube.triangles =
        {
            //South
            {
                0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 0.0f
            },
            
            {
                0.0f, 0.0f, 0.0f,
                1.0f, 1.0f, 0.0f,
                1.0f, 0.0f, 0.0f
            },
            
            //East
            {
                1.0f, 0.0f, 0.0f,
                1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 1.0f
            },
            {
                1.0f, 0.0f, 0.0f,
                1.0f, 1.0f, 1.0f,
                1.0f, 0.0f, 1.0f
            },

            //North
            {
                1.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f,
                0.0f, 1.0f, 1.0f
            },
            
            {
                1.0f, 0.0f, 1.0f,
                0.0f, 1.0f, 1.0f,
                0.0f, 0.0f, 1.0f
            },

             //West
             {
                 0.0f, 0.0f, 1.0f,
                 0.0f, 1.0f, 1.0f,
                 0.0f, 1.0f, 0.0f
             },
            
             {
                 0.0f, 0.0f, 1.0f,
                 0.0f, 1.0f, 0.0f,
                 0.0f, 0.0f, 0.0f
             },
            
             //Top
             {
                 0.0f, 1.0f, 0.0f,
                 0.0f, 1.0f, 1.0f,
                 1.0f, 1.0f, 1.0f
             },
            
             {
                 0.0f, 1.0f, 0.0f,
                 1.0f, 1.0f, 1.0f,
                 1.0f, 1.0f, 0.0f
             },
            
             //Bottom
             {
                 1.0f, 0.0f, 1.0f,
                 1.0f, 0.0f, 0.0f,
                 0.0f, 0.0f, 0.0f
             },
            
             {
                 1.0f, 0.0f, 1.0f,
                 0.0f, 0.0f, 0.0f,
                 0.0f, 0.0f, 1.0f
             },
        };

        constexpr float f_near = 0.1f;
        constexpr float f_far = 1000.0f;
        constexpr float f_fov = 90.0f;
        constexpr float f_aspect_ratio = static_cast<float>(ScreenWidth()) / static_cast<float>(ScreenHeight());
        constexpr float f_fov_rad = 1.0f / tanf(f_fov * 0.5f / 180.0f * 3.14159f);
        
        m_sAppName = L"3D Demo";
    }

    bool OnUserCreate() override
    {
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLACK);

        for (auto triangle : m_meshCube.triangles)
        {
            
        }
        
        return true;
    }
};



int main()
{
    PrimitiveGameEngine game;

    if(game.ConstructConsole(256, 240, 4, 4))
    {
        game.Start();
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
