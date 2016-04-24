//
// Created by Pedro Soares on 4/23/16.
//

#include "RsaString.h"

void Tigre::RsaString::setValue(std::string value) {
    this->value = value;
}

void Tigre::RsaString::setKeysPath(std::string publicKeyPath, std::string privateKeyPath) {
    this->publicKeyPath = publicKeyPath;
    this->privateKeyPath = privateKeyPath;
}

std::string Tigre::RsaString::getPublickeypath(){
    return this->publicKeyPath;
}

std::string Tigre::RsaString::getPrivatekeypath(){
    return this->publicKeyPath;
}

std::string Tigre::RsaString::getValue(){
    return this->value;
}

void Tigre::RsaString::gerarChaves(){
    RSA::PrivateKey rsaPrivate;
    rsaPrivate.GenerateRandomWithKeySize(rng, 2048);

    RSA::PublicKey rsaPublic(rsaPrivate);

    SavePrivateKey(privateKeyPath, rsaPrivate);
    SavePublicKey(publicKeyPath, rsaPublic);
}

void Tigre::RsaString::carregarChaves() {
    LoadPrivateKey(privateKeyPath, privateKey);
    LoadPublicKey(publicKeyPath, publicKey);
}

void Tigre::RsaString::Encryption(){
    std::string plain = this->value;
    std::string cipher;
    RSAES_OAEP_SHA_Encryptor e( publicKey );

    StringSource( plain, true,
                  new PK_EncryptorFilter( rng, e,
                                          new StringSink( cipher )
                  ) // PK_EncryptorFilter
    ); // StringSource
    this->value = cipher;
}

void Tigre::RsaString::Decryption() {
    std::string cipher = this->value;
    std::string recovered;
    RSAES_OAEP_SHA_Decryptor d( privateKey );

    StringSource( cipher, true,
                  new PK_DecryptorFilter( rng, d,
                                          new StringSink( recovered )
                  ) // PK_EncryptorFilter
    ); // StringSource

    this->value = recovered;
}


//-------------------------------------------------------------//


void Tigre::RsaString::SavePrivateKey(const string& filename, const RSA::PrivateKey& key)  {
    // http://www.cryptopp.com/docs/ref/class_byte_queue.html
    ByteQueue queue;
    key.DEREncodePrivateKey(queue);

    Save(filename, queue);
}

void Tigre::RsaString::SavePublicKey(const string& filename, const RSA::PublicKey& key)  {
    // http://www.cryptopp.com/docs/ref/class_byte_queue.html
    ByteQueue queue;
    key.DEREncodePublicKey(queue);

    Save(filename, queue);
}

void Tigre::RsaString::Save(const string& filename, const CryptoPP::BufferedTransformation& bt)  {
    FileSink file(filename.c_str());

    bt.CopyTo(file);
    file.MessageEnd();
}


//-------------------------------------------------------------//


void Tigre::RsaString::LoadPrivateKey(const string& filename, RSA::PrivateKey& key)  {
    ByteQueue queue;

    Load(filename, queue);
    key.BERDecodePrivateKey(queue, false /*optParams*/, queue.MaxRetrievable());
}

void Tigre::RsaString::LoadPublicKey(const string& filename, RSA::PublicKey& key)  {
    ByteQueue queue;

    Load(filename, queue);
    key.BERDecodePublicKey(queue, false /*optParams*/, queue.MaxRetrievable());
}

void Tigre::RsaString::Load(const string& filename, CryptoPP::BufferedTransformation& bt)  {
    FileSource file(filename.c_str(), true /*pumpAll*/);

    file.TransferTo(bt);
    bt.MessageEnd();
}