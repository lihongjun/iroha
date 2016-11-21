/*
Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.

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

#include "message.hpp"

<<<<<<< HEAD
namespace object {

Message::Message(
        const std::string& text
):
        text(text)
{}

using Rule = json_parse::Rule;
using Type = json_parse::Type;
using Object = json_parse::Object;

json_parse::Object Message::dump(){
    json_parse::Object obj = json_parse::Object(Type::DICT);
    obj.dictSub.insert( std::make_pair( "text", json_parse::Object(Type::STR, text)));
    return obj;
}
=======
namespace message {

    Message::Message(
            std::string text
    ):
            text(text)
    {}

    using Rule = json_parse::Rule;
    using Type = json_parse::Type;

    json_parse::Object Message::dump(){
        json_parse::Object obj = json_parse::Object(Type::DICT);
        obj.dictSub.insert( std::make_pair( "text", json_parse::Object(Type::STR, text)));
        return obj;
    }

    json_parse::Rule Message::getJsonParseRule(){
        Rule obj = Rule(Type::DICT);
        obj.dictSub.insert( std::make_pair( "text", Rule(Type::STR)));
        return obj;
    }
>>>>>>> master

Rule Message::getJsonParseRule() {
    auto rule = Rule(Type::DICT);
    rule.dictSub.insert( std::make_pair( "text", Rule(Type::STR)));
    return rule;
}
}