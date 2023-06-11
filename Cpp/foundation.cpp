#include <iostream>

int main(int argc, char* argv[]) {
    // 检查是否提供了足够的参数
    if (argc < 3) {
        std::cout << "请提供两个参数" << std::endl;
        return 1;
    }

    // 获取命令行参数
    std::string arg1 = argv[1];
    std::string arg2 = argv[2];

    // 打印参数
    std::cout << "参数1: " << arg1 << std::endl;
    std::cout << "参数2: " << arg2 << std::endl;

    return 0;
}
