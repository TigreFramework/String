//
// Created by Pedro Soares on 4/19/16.
//

#include "String.h"

Tigre::String::String() {
    this->value = "";
}

Tigre::String::String(const String &s) {
    this->value = s.value;
}

Tigre::String::String(std::string s) {
    this->value = s;
}

Tigre::String::String(const char s[]){
    this->value = s;
}

Tigre::String::String(int i){
    this->value = std::to_string(i);
}

Tigre::String::String(float i){
    this->value = std::to_string(i);
}

Tigre::String::String(double i){
    this->value = std::to_string(i);
}

Tigre::String::~String() {

}

std::string Tigre::String::getValue(){
    return this->value;
}

// trim from both ends
void Tigre::String::Trim() {
    this->value.erase(std::find_if(this->value.rbegin(), this->value.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), this->value.end());
    this->value.erase(this->value.begin(), std::find_if(this->value.begin(), this->value.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
}


int Tigre::String::Count() {
    return (int) this->value.size();
}

std::vector<Tigre::String> Tigre::String::explode(String delimitador) {
    std::vector<Tigre::String> result;
    int last_push = 0;

    for (int i=0; i < this->value.size() && i+delimitador.Count()-1 < this->value.size(); i++) {
        if(this->value.substr(i, delimitador.Count()) == delimitador){
            result.push_back(this->value.substr(last_push, i-last_push));
            last_push = i+delimitador.Count();
        }
    }

    if(last_push < this->value.size()){
        result.push_back(this->value.substr(last_push, this->value.size()-last_push));
    }

    return result;
}

void Tigre::String::replace(String valor_a, String valor_b) {
    String result = "";

    std::vector<Tigre::String> peaces = this->explode(valor_a);

    for(int i=0; i < peaces.size(); i++){
        if(i+1 < peaces.size()) {
            result += peaces[i] + valor_b;
        } else {
            if(this->value.substr(this->value.size()-valor_a.Count(), valor_a.Count() ) != valor_a){
                result += peaces[i];
            } else {
                result += peaces[i] + valor_b;
            }
        }
    }
    this->value = result.value;
}

void Tigre::String::urlDecode() {
    String ret;
    char ch;
    int i, ii;
    this->replace("+", " ");
    this->replace("%2B", "+");
    for (i=0; i<this->Count(); i++) {
        if (int(this->value[i])==37) {
            sscanf(this->value.substr(i+1,2).c_str(), "%x", &ii);
            ch=static_cast<char>(ii);
            ret+=ch;
            i=i+2;
        } else {
            ret+= char(this->value[i]);
        }
    }
    this->value = ret.value;
}

void Tigre::String::urlEncode() {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (std::string::const_iterator i = this->value.begin(), n = this->value.end(); i != n; ++i) {
        std::string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char) c);
        escaped << std::nouppercase;
    }

    this->value = escaped.str();
}

Tigre::String Tigre::String::aleatorio(int len) {
    char alfabeto[] = {
            '0', '1', '2', '3', '4', '5', '6', '7',
            '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
            'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
            'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
            'W', 'X', 'Y', 'X', 'a', 'b', 'c', 'd',
            'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
            'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
            'u', 'v', 'w', 'x', 'y', 'z', '*', '#'
    };

    char palavra[len+1];

    for (int i = 0; i < len; i++) {
        palavra[i] = alfabeto[ rand() % 64 ]; /* 62 é o tamanho do alfabeto */
    }

    palavra[len] = '\0';

    return palavra;
}



/**
*  Operações básicas
**/

/*std::ostream & Tigre::operator<<(std::ostream &os, const Tigre::String& p)  {
    return os << p.value;
}*/

std::istream & Tigre::operator>>(std::istream& os, const Tigre::String& p)  {
    return os >> p.value;
}

char& Tigre::String::operator[](std::size_t idx){
    return this->value[idx];
}

Tigre::String& Tigre::String::operator+=(const Tigre::String& rhs) {
    this->value += rhs.value;
    return *this;
}

Tigre::String& Tigre::String::operator=(const Tigre::String& rhs) {
    this->value = rhs.value;
    return *this;
}

Tigre::String Tigre::operator+(Tigre::String lhs, const Tigre::String& rhs){
    lhs += rhs;
    return lhs;
}

bool Tigre::operator==(const String& lhs, const String& rhs){
    return (lhs.value == rhs.value);
}

bool Tigre::operator!=(const String& lhs, const String& rhs){
    return !(lhs.value == rhs.value);
}
