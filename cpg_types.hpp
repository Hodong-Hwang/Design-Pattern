/*
    Author: Thomas Kim
    First Edit: July 12, 2021
*/

#ifndef _CPG_TYPES_HPP
#define _CPG_TYPES_HPP

#include <iostream>
#include <concepts>
#include <vector>
#include <tuple>
#include <string>
#include <cstring>

namespace cpg // C++ Programmers' Group
{
    namespace types
    {
        template<typename Type>
        std::string type_tO_sTring()
        {
            #ifdef __FUNCSIG__
                std::string fname(__FUNCSIG__);
                const char* to_str = "tO_sTring<";
                size_t len = strlen(to_str);
                auto pos = fname.find("tO_sTring<");
                fname = fname.substr(pos+len);
                return fname.substr(0, fname.find_last_of('>'));
            #else
                
                std::string fname(__PRETTY_FUNCTION__);
                
                #ifdef __clang_major__
                    const char* ftext = "[Type = ";
                    auto pos = fname.find(ftext) + strlen(ftext);
                    fname = fname.substr(pos);
                    fname.pop_back();
                    return fname;

                #elif defined(__ICL)
                    const char* ftext = "type_tO_sTring<";
                    auto pos = fname.find(ftext) + strlen(ftext);
                    fname = fname.substr(pos);
                    pos = fname.find_last_of('>');
                    return fname.substr(0, pos);
                #else
                    const char* ftext = "[with Type = ";
                    auto pos = fname.find(ftext) + strlen(ftext);
                    fname = fname.substr(pos);
                    pos = fname.find_first_of(';');
                    return fname.substr(0, pos);
                 #endif
             #endif

        } // end of type_tO_sTring()

    } // end of namespace types

} // end of namespace types

#define Cpg_GetTypeName(type_arg) cpg::types::type_tO_sTring<type_arg>()
#define Cpg_GetTypeCategory(instance_arg) cpg::types::type_tO_sTring<decltype(instance_arg)>()

#endif // end of file _CPG_TYPES_HPP