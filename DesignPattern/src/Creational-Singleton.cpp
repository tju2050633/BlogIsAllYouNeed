#include <iostream>
using namespace std;

// 单例
class Singleton
{
private:
    static Singleton *instance;

    // 构造函数要私有，不允许外部创建实例
    Singleton()
    {
    }

    ~Singleton()
    {
        if (instance != NULL)
            delete instance;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == NULL)
        {
            instance = new Singleton();
        }
        return instance;
    }

    void use()
    {
        cout << "Singleton::use()" << endl;
    }
};

// 静态成员变量必须在类外初始化
Singleton * Singleton::instance = NULL;

int main()
{
    Singleton *singleton = Singleton::getInstance();
    singleton->use();

    return 0;
}