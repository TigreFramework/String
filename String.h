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
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/objects.h>
#include <openssl/x509.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>


#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

namespace Tigre {

    class RsaException : public std::exception {
        public:
            /** Constructor (C strings).
             *  @param message C-style string error message.
             *                 The string contents are copied upon construction.
             *                 Hence, responsibility for deleting the \c char* lies
             *                 with the caller.
             */
            explicit RsaException(const char* message):
                    msg_(message)
            {
            }

            /** Constructor (C++ STL strings).
             *  @param message The error message.
             */
            explicit RsaException(const std::string& message):
                    msg_(message)
            {}

            /** Destructor.
             * Virtual to allow for subclassing.
             */
            virtual ~RsaException() throw (){}

            /** Returns a pointer to the (constant) error description.
             *  @return A pointer to a \c const \c char*. The underlying memory
             *          is in posession of the \c Exception object. Callers \a must
             *          not attempt to free the memory.
             */
            virtual const char* what() const throw (){
                return msg_.c_str();
            }

        protected:
            /** Error message.
             */
            std::string msg_;

    };

    class String {

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


            void public_encrypt();
            void private_decrypt();

            void private_encrypt();
            void public_decrypt();

            static void setRsaKey(String publico, String privado, bool isFile);


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
            RSA * createRSA(unsigned char * key,int publico);
            RSA * createRSAWithFilename(char * filename, int publico);

            static std::string publicKey;
            static std::string privateKey;
            static bool isFile;

            //bool isCripted;
            int cript_len;
            std::string value;


    };
}

#endif //STRING_STRING_H



