#include "transactionValidator.hpp"

#include "../crypto/signature.hpp"

namespace transactionValidator {

struct Context {
    //TODO:
};

void transactionValidator(/*TODO:*/) {
    logger("initialize_transactionValidator");
    //TODO:
}

bool isValid(Transaction const tx) {
    return signaturesAreValid; // TODO: add more
}

bool signaturesAreValid(Transaction const tx) {
    tx->signatures::foreach { // TODO: learn c++ syntax for this!

    }
    return true; // TODO: change this!
}

};  // namespace transactionValidator