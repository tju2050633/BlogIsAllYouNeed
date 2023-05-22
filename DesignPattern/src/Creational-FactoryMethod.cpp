#include <iostream>
using namespace std;

/*
有两种产品：ConcreteProductA 和 ConcreteProductB
产品实现相同的接口 Product
有两种工厂：ConcreteFactoryA 和 ConcreteFactoryB
工厂实现相同的接口 Factory
工厂A生产产品A，工厂B生产产品B

客户端只需要知道工厂的接口，不需要知道具体的工厂和产品
*/

// 产品

class Product
{
public:
    virtual void use() = 0; // 抽象类
};

class ConcreteProductA : public Product
{
public:
    // 重写
    void use()
    {
        cout << "ConcreteProductA::use()" << endl;
    }
};

class ConcreteProductB : public Product
{
public:
    // 重写
    void use()
    {
        cout << "ConcreteProductB::use()" << endl;
    }
};

// 工厂

class Factory
{
public:
    // 返回抽象产品指针
    virtual Product *createProduct() = 0; // 抽象类
};

class ConcreteFactoryA : public Factory
{
public:
    ConcreteProductA *createProduct()
    {
        cout << "ConcreteFactoryA::createProduct()" << endl;
        return new ConcreteProductA();
    }
};

class ConcreteFactoryB : public Factory
{
public:
    ConcreteProductB *createProduct()
    {
        cout << "ConcreteFactoryB::createProduct()" << endl;
        return new ConcreteProductB();
    }
};

// 客户端

int main()
{
    Factory *factoryA = new ConcreteFactoryA();
    Product *productA = factoryA->createProduct();
    productA->use();

    Factory *factoryB = new ConcreteFactoryB();
    Product *productB = factoryB->createProduct();
    productB->use();

    delete factoryA;
    delete productA;
    delete factoryB;
    delete productB;

    return 0;
}