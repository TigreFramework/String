//
// Created by Pedro Soares on 4/19/16.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <stdio.h>

#include "RsaString.h"


#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

namespace Tigre {

    class String : public RsaString {

        public:
            String();
            String(const String &s);
            String(std::string s);
            String(const char s[]);
            String(double s);
            String(float s);
            String(int s);

            ~String();

            int Count();
            std::vector<Tigre::String> explode(String delimitador);
            void replace(String valor_a, String valor_b);
            void urlDecode();
            void urlEncode();
            String aleatorio(int tamanho);

            char& operator[](std::size_t idx);
            String& operator+=(const String& rhs);


            friend std::ostream & operator << (std::ostream &os, const String & p_oParagraph) {
                return os << p_oParagraph.value ;
            }

            friend std::istream & operator>>(std::istream& os, const String& p);
            friend String operator+(String lhs, const String& rhs);
            friend bool operator==(const String& lhs, const String& rhs);
            friend bool operator!=(const String& lhs, const String& rhs);

        private:
            #ifndef RSA_RSASTRING_H
            std::string value;
            #endif


    };
}

#endif //STRING_STRING_H



