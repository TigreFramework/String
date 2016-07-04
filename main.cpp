#include <iostream>
#include "String.h"

using namespace Tigre;

/*    #link_directories(./include/cryptopp563/)


    #find_library(cryptopp ./include/cryptopp563/)
    #target_link_libraries(cryptopp ./include/cryptopp563/)
    #link_libraries(cryptopp ./include/cryptopp563/)
*/

int main() {

    String rs = ("Hello World, é tetra");//, "rsa-public.pem", "rsa-private.pem");
    rs.setKeysPath("rsa-public.pem", "rsa-private.pem");
    rs.gerarChaves(); //gera novos arquivos
    rs.carregarChaves();

    std::cout << "Original: " << rs << "\n\n";

    rs.Encryption();

    std::cout << "Criptado: " << rs << "\n\n";

    rs.Decryption();

    std::cout << "Descriptado: " << rs << "\n\n";

    return 0;
}