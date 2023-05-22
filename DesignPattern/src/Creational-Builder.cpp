#include <iostream>
#include <string>
using namespace std;

/*

*/

// 产品
class Product
{
private:
    string partA;
    string partB;
    string partC;

public:
    void setPartA(string partA)
    {
        this->partA = partA;
    }

    void setPartB(string partB)
    {
        this->partB = partB;
    }

    void setPartC(string partC)
    {
        this->partC = partC;
    }

    void use()
    {
        cout << "Product::use()" << endl;
        cout << "partA: " << partA << endl;
        cout << "partB: " << partB << endl;
        cout << "partC: " << partC << endl;
    }
};

// 建造者
class Builder
{
public:
    virtual ~Builder()
    {
    }

    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;

    virtual Product *getProduct() = 0;
};

// 具体建造者
class ConcreteBuilder : public Builder
{
private:
    Product *product;

public:
    ConcreteBuilder()
    {
        product = new Product();
    }

    void buildPartA()
    {
        cout << "ConcreteBuilder::buildPartA()" << endl;
        product->setPartA("partA");
    }

    void buildPartB()
    {
        cout << "ConcreteBuilder::buildPartB()" << endl;
        product->setPartB("partB");
    }

    void buildPartC()
    {
        cout << "ConcreteBuilder::buildPartC()" << endl;
        product->setPartC("partC");
    }

    Product *getProduct()
    {
        return product;
    }
};

// 指挥者
class Director
{
private:
    Builder *builder;

public:
    Product *construct()
    {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();

        return builder->getProduct();
    }

    void setBuilder(Builder *builder)
    {
        this->builder = builder;
    }
};

// 客户端

int main()
{
    Builder *builder = new ConcreteBuilder();
    Director director;
    director.setBuilder(builder);

    Product *product = director.construct();

    product->use();

    delete builder;
    delete product;

    return 0;
}