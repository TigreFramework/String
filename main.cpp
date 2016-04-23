#include <iostream>
#include "String.h"

//using namespace Tigre;

int main() {
    Tigre::String::setRsaKey("public.pem", "private.pem", true);

    Tigre::String s = "Hello, World My Friend";
    //Tigre::String j = "Pedro Soares";



    std::cout << "'" << s << "'\n\n";

    s.public_encrypt();

    //std::cout << "'" << s << "'\n\n";

    s.private_decrypt();

    std::cout << "'" << s << "'\n\n";

    return 0;
}