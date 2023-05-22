#include <iostream>
using namespace std;

// 产品A

class ProductA
{
public:
    virtual void use() = 0; // 抽象类
};

class ConcreteProductA1 : public ProductA
{
public:
    // 重写
    void use()
    {
        cout << "ConcreteProductA1::use()" << endl;
    }
};

class ConcreteProductA2 : public ProductA
{
public:
    // 重写
    void use()
    {
        cout << "ConcreteProductA2::use()" << endl;
    }
};

// 产品B

class ProductB
{
public:
    virtual void use() = 0; // 抽象类
};

class ConcreteProductB1 : public ProductB
{
public:
    // 重写
    void use()
    {
        cout << "ConcreteProductB1::use()" << endl;
    }
};

class ConcreteProductB2 : public ProductB
{
public:
    // 重写
    void use()
    {
        cout << "ConcreteProductB2::use()" << endl;
    }
};

// 工厂

class Factory
{
public:
    // 返回抽象产品指针
    virtual ProductA *createProductA() = 0; // 抽象类
    virtual ProductB *createProductB() = 0; // 抽象类
};

class ConcreteFactory1 : public Factory
{
public:
    ConcreteProductA1 *createProductA()
    {
        cout << "ConcreteFactoryA1::createProduct()" << endl;
        return new ConcreteProductA1();
    }

    ConcreteProductB1 *createProductB()
    {
        cout << "ConcreteFactoryB1::createProduct()" << endl;
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public Factory
{
public:
    ConcreteProductA2 *createProductA()
    {
        cout << "ConcreteFactoryA2::createProduct()" << endl;
        return new ConcreteProductA2();
    }

    ConcreteProductB2 *createProductB()
    {
        cout << "ConcreteFactoryB2::createProduct()" << endl;
        return new ConcreteProductB2();
    }
};

// 客户端

int main()
{
    Factory *factory1 = new ConcreteFactory1();
    ProductA *productA1 = factory1->createProductA();
    ProductB *productB1 = factory1->createProductB();
    productA1->use();
    productB1->use();

    Factory *factory2 = new ConcreteFactory2();
    ProductA *productA2 = factory2->createProductA();
    ProductB *productB2 = factory2->createProductB();
    productA2->use();
    productB2->use();

    delete factory1;
    delete productA1;
    delete productB1;

    delete factory2;
    delete productA2;
    delete productB2;

    return 0;
}