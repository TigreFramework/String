//
// Created by Pedro Soares on 4/23/16.
//

#ifndef RSA_RSASTRING_H
#define RSA_RSASTRING_H

#include "rsa.h"
using CryptoPP::RSA;
using CryptoPP::InvertibleRSAFunction;
using CryptoPP::RSAES_OAEP_SHA_Encryptor;
using CryptoPP::RSAES_OAEP_SHA_Decryptor;

#include "sha.h"
using CryptoPP::SHA1;

#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::PK_EncryptorFilter;
using CryptoPP::PK_DecryptorFilter;

#include "files.h"
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "secblock.h"
using CryptoPP::SecByteBlock;

#include "cryptlib.h"
using CryptoPP::Exception;
using CryptoPP::DecodingResult;

#include <string>
using std::string;

#include <exception>
using std::exception;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <queue.h>
using CryptoPP::ByteQueue;

#include <assert.h>

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

    class RsaString {

        public:
            /*RsaString(std::string value) : value(value) {}
            RsaString(std::string value, std::string publicKeyPath, std::string privateKeyPath) :
                    value(value), publicKeyPath(publicKeyPath), privateKeyPath(privateKeyPath) {}
*/
            RsaString(){}

            void setValue(std::string value);
            void setKeysPath(std::string publicKeyPath, std::string privateKeyPath);
            std::string getPublickeypath();
            std::string getPrivatekeypath();
            std::string getValue();

            void gerarChaves();
            void carregarChaves();
            void Encryption();
            void Decryption();

            void SavePrivateKey(const string& filename, const RSA::PrivateKey& key);
            void SavePublicKey(const string& filename, const RSA::PublicKey& key);
            void Save(const string& filename, const CryptoPP::BufferedTransformation& bt);

            void LoadPrivateKey(const string& filename, RSA::PrivateKey& key);
            void LoadPublicKey(const string& filename, RSA::PublicKey& key);
            void Load(const string& filename, CryptoPP::BufferedTransformation& bt);


    protected:
            std::string value;
    private:
            RSA::PrivateKey privateKey;
            RSA::PublicKey publicKey;
            AutoSeededRandomPool rng;
            std::string publicKeyPath;
            std::string privateKeyPath;

    };

}


#endif //RSA_RSASTRING_H
