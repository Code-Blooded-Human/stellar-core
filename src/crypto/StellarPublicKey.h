#ifndef __STELLARPUBLICKEY__
#define __STELLARPUBLICKEY__

// Copyright 2014 Stellar Development Foundation and contributors. Licensed
// under the ISC License. See the COPYING file at the top-level directory of
// this distribution or at http://opensource.org/licenses/ISC

//#include "lib/base58/Base58Data.h"
#include "util/types.h"
#include "generated/StellarXDR.h"

/*
one half of the signing key
*/
namespace stellar
{

class StellarPublicKey //: public Base58Data
{
    typedef enum
    {
        VER_NONE = 1,
        VER_NODE_PUBLIC = 122, // n
        VER_NODE_PRIVATE = 102, // h
        VER_ACCOUNT_ID = 0, // g
        VER_ACCOUNT_PUBLIC = 67, // p
        VER_ACCOUNT_PRIVATE = 101, // h
        VER_SEED = 33 // s
    } PublicKeyType;

    bool mIsValid;

  public:
    StellarPublicKey();

    StellarPublicKey(const Blob& publicKey, PublicKeyType type);
    StellarPublicKey(const std::string& base58Key, PublicKeyType type);

    bool setKey(const std::string& base58Key, PublicKeyType type);

    void clear();

    uint160 getAccountID() const;

    bool verifySignature(uint256 const& hash,
                         Blob const& vchSig) const;
    bool verifySignature(uint256 const& hash,
                         const std::string& strSig) const;

    std::string base58AccountID() const;
    std::string base58Key() const;
};
}

#endif
