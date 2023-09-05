#include "clave_gerente.h"

clave_gerente::clave_gerente(QObject *parent)
    : QObject{parent}
{

}

void clave_gerente::clave_nuevo()
{
    OpenSSL_add_all_algorithms();

      // Generate ECC key pair
      EC_KEY *ecKey = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
      EC_KEY_generate_key(ecKey);

      // Save the private key
      FILE *privateKeyFile = fopen("ecc_private_key.pem", "wb");
      PEM_write_ECPrivateKey(privateKeyFile, ecKey, nullptr, nullptr, 0, nullptr, nullptr);
      fclose(privateKeyFile);

      // Save the public key
      FILE *publicKeyFile = fopen("ecc_public_key.pem", "wb");
      PEM_write_EC_PUBKEY(publicKeyFile, ecKey);
      fclose(publicKeyFile);

      // Clean up
      EC_KEY_free(ecKey);
      EVP_cleanup();
}
