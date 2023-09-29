#include <iostream>
#include "func.h"
#include "test/test.h"
#include "test1/test1.h"
#include "test1/test2/test2.h"
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <opencv2/opencv.hpp>

void eigen_test() {
    // Basic Example of cpp
    std::cout << "Example of cpp \n";
    float a = 1.0, b = 2.0;
    std::cout << a << std::endl;
    std::cout << a/b << std::endl;
    std::cout << std::sqrt(b) << std::endl;
    std::cout << std::acos(-1) << std::endl;
    std::cout << std::sin(30.0/180.0*acos(-1)) << std::endl;

    // Example of vector
    std::cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f,2.0f,3.0f);
    Eigen::Vector3f w(1.0f,0.0f,0.0f);
    // vector output
    std::cout << "Example of output \n";
    std::cout << v << std::endl;
    // vector add
    std::cout << "Example of add \n";
    std::cout << v + w << std::endl;
    // vector scalar multiply
    std::cout << "Example of scalar multiply \n";
    std::cout << v * 3.0f << std::endl;
    std::cout << 2.0f * v << std::endl;
    // vector dot multiply
    std::cout << "Example of dot multiply \n";
    std::cout << v.dot(w) << std::endl;
    // vector cross multiply
    std::cout << "Example of cross multiply \n";
    std::cout << v.cross(w) << std::endl;

    // Example of matrix
    std::cout << "Example of matrix \n";
    // matrix definition
    Eigen::Matrix3f i,j;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    // matrix output
    std::cout << "Example of output \n";
    std::cout << i << std::endl;
    // matrix add i + j
    std::cout << "Example of add \n";
    std::cout << i + j << std::endl;
    // matrix scalar multiply i * 2.0
    std::cout << "Example of scalar multiply \n";
    std::cout << i * 2.0 << std::endl;
    // matrix multiply i * j
    std::cout << "Example of multiply \n";
    std::cout << i * j << std::endl;
    // matrix multiply vector i * v
    std::cout << "Example of matrix multiply vector \n";
    std::cout << i * v << std::endl;

    // 给定一个点 P =(2,1), 将该点绕原点先逆时针旋转 45◦，再平移 (1,2), 计算出 变换后点的坐标(要求用齐次坐标进行计算)。
    std::cout << "Example of transform \n";
    Eigen::Vector3f p(2.0f,1.0f,1.0f);
    Eigen::Matrix3f r;
    r << std::cos(45.0/180.0*acos(-1)), -std::sin(45.0/180.0*acos(-1)), 0,
         std::sin(45.0/180.0*acos(-1)), std::cos(45.0/180.0*acos(-1)), 0,
         0, 0, 1;
    Eigen::Matrix3f t;
    t << 1, 0, 1,
         0, 1, 2,
         0, 0, 1;
    std::cout << "The point before transform is: \n";
    std::cout << p << std::endl;
    std::cout << "The point after transform is: \n";
    std::cout << t * r * p << std::endl;
}

void opencv_test() {
    cv::Mat image;
    image = cv::imread("../data/test.png");
    cv::imshow("lena", image);
    cv::waitKey(0);
}

int main() {
    std::cout << "hello" << std::endl;
    func();
    test();
    test1();
    test2();

    // 测试eigen
    // eigen_test();

    // 测试opencv
    opencv_test();

    return 0;
}

