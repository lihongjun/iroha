/*
Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.
http://soramitsu.co.jp

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef CORE_DOMAIN_TRANSFER_HPP_
#define CORE_DOMAIN_TRANSFER_HPP_

#include "../objects/domain.hpp"
#include "../objects/asset.hpp"
#include "../objects/message.hpp"

#include <string>
#include <iostream>
#include "../../service/json_parse.hpp"

namespace command {

<<<<<<< HEAD
template <typename T>
class Transfer: public T {

   std::string senderPublicKey;
   std::string receiverPublicKey;
  public:

    Transfer(
        std::string senderPubkey,
        std::string receiverPubkey,
        std::string name,
        int value
    );

    std::string getCommandName() const{
        return "Transfer";
    }

    using Rule = json_parse::Rule;
    using Type = json_parse::Type;
    using Object = json_parse::Object;

    Transfer(
        Object obj
    );

    Object dump() {
        Object obj = Object(Type::DICT);
        obj.dictSub.insert( std::make_pair(    "name", Object(Type::STR, getCommandName())));
        obj.dictSub.insert( std::make_pair(  "object", T::dump()));
        obj.dictSub.insert( std::make_pair(  "sender", Object(Type::STR, senderPublicKey)));
        obj.dictSub.insert( std::make_pair("receiver", Object(Type::STR, receiverPublicKey)));
        return obj;
    }

    static Rule getJsonParseRule() {
            auto rule = Rule(Type::DICT);
            rule.dictSub.insert( std::make_pair( "name", Rule(Type::STR)));
            rule.dictSub.insert( std::make_pair( "object", T::getJsonParseRule()));
            rule.dictSub.insert( std::make_pair( "sender", Rule(Type::STR)));
            rule.dictSub.insert( std::make_pair("receiver", Rule(Type::STR)));
            return rule;
=======
    template<typename T,
        std::enable_if_t<
            std::is_base_of<AbsObject, T>::value,std::nullptr_t
        > = nullptr
    >
    class Transfer : public Command{
        std::unique_ptr<T> object;
    public:
        Transfer(std::unique_ptr<T> object):
            object(std::move(object))
        {}

        std::string getCommandName() const{
            return "Transfer";
        }

        ~Transfer() {

        };

        using Object = json_parse::Object;
        using Rule = json_parse::Rule;
        using Type = json_parse::Type;

        Object dump() {
            Object obj = Object(Type::DICT);
            obj.dictSub.insert( std::make_pair( "command", Object(Type::STR, getCommandName())));
            obj.dictSub.insert( std::make_pair( "object", object->dump()));
            return obj;
        }

        Rule getJsonParseRule() {
            Rule obj = Rule(Type::DICT);
            obj.dictSub.insert( std::make_pair( "command", Rule(Type::STR)));
            obj.dictSub.insert( std::make_pair( "object", object->getJsonParseRule()));
            return obj;
>>>>>>> master
        }
    };

};  // namespace command

#endif  // CORE_DOMAIN_TRANSACTIONS_TRANSFERTRANSACTION_HPP_
