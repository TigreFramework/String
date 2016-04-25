# Tigre String
#### Descrição
Classe String em C++ para manipula funções como explode/split, replace, encriptação/decriptação RSA entre outras.
<br/>


### Compilação

Para fazer a compilação do arquivo de teste e as bibliotecas estaticas siga os passos abaixo.

##### Windows

Em breve faço os passos para compilação em Windows.

##### Linux/Mac
Primeiro compile as dependencias do Rsa do seguinte modo:
```
cd include/cryptopp563/
make
cp libcryptopp.a ../../
cd ../../
```
Depois compile o projeto do seguinte modo:
```
mkdir build
cd build/
cmake ../
build
./teste
```

### Uso

##### Parentesco entre String e RsaString

A classe String pode ser usada com a classe RsaString ou separadamente,
se usada junta deverá manter o include e o parentesco do seguinte modo:

```
#include "RsaString.h"
namespace Tigre {
    class String : public RsaString {
```

Caso queiras usar separadamente, deixa a classe do seguinte modo:

```
namespace Tigre {
    class String {
```

Note que o exemplo acima removou o include do RsaString. Pois se mantiveres
o parentesco irá dar erro de compilação pois a Classe String remove o
atributo value caso seja feito o include do RsaString.

##### Usando String e RsaString

Para usar a classe String é muito facil, primeiramente irá setar o
namespace <b>Tigre</b> para facilitar, depois crie uma variável do tipo String
e adicione um valor qualquer (int, float, double, sdt::string, char * e char[]). Veja o exemplo:

```
#include "String.h"
using namespace Tigre;

int main() {
    String rs = "Olá Mundo";
    std::cout << "Valor da Variável rs: " << rs << "\n\n";
    return 0;
}
```

Para usar a classe RsaString é possivel de 2 modos, com a classe String e sem a classe String.
Com a classe string, é só utilizar o parentes entre as duas como citado
no uso acima e fazer a encriptação e decriptação do seguinte modo:

```
#include "String.h"
using namespace Tigre;

int main() {
    String rs = "Olá Mundo";
    rs.setKeysPath("rsa-public.pem", "rsa-private.pem");
    rs.gerarChaves(); //gera novas chaves (privada e publica)
    rs.carregarChaves(); //carrega as chaves gerada anteriormente dos arquivos ou as já criadas em outras execuções
    std::cout << "Valor Original: " << rs << "\n\n";
    rs.Encryption(); // encripta o valor da String
    std::cout << "Valor Criptado: " << rs << "\n\n";
    rs.Decryption(); // decripta o valor da String
    std::cout << "Valor Descriptado: " << rs << "\n\n";
    return 0;
}
```

Para usar separadamente, faça do seguinte modo:

```
#include "RsaString.h"
using namespace Tigre;

int main() {
    RsaString rs;
    rs.setValue("Olá Mundo"); // Informar onde salvar e carregar as chaves RSA
    rs.setKeysPath("rsa-public.pem", "rsa-private.pem");
    rs.gerarChaves(); //gera novas chaves (privada e publica)
    rs.carregarChaves(); //carrega as chaves gerada anteriormente dos arquivos ou as já criadas em outras execuções
    std::cout << "Valor Original: " << rs.getValue() << "\n\n";
    rs.Encryption(); // encripta o valor da String
    std::cout << "Valor Criptado: " << rs.getValue() << "\n\n";
    rs.Decryption(); // decripta o valor da String
    std::cout << "Valor Descriptado: " << rs.getValue() << "\n\n";
    return 0;
}
```