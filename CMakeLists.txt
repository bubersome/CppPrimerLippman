cmake_minimum_required(VERSION 3.21)
project("CPP_Primer")

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

add_executable(add.cc 1/add.cc)
add_executable(add_item 1/add_item.cc)

add_executable(2compounddecls 2/compounddecls.cc)
add_executable(2convs 2/convs.cc)
add_executable(2dbl_ptr 2/dbl_ptr.cc)
add_executable(2decl-ex 2/dbl_ptr.cc)
add_executable(2escape 2/escape.cc)
add_executable(2inits 2/inits.cc)
add_executable(2literals 2/literals.cc)
add_executable(2ref-ex 2/ref-ex.cc)
add_executable(2Sales_data 2/Sales_data.cc)
add_executable(2scope_levels 2/scope_levels.cc)
add_executable(2unsigned 2/unsigned.cc)
add_executable(2concurssivePower 2/concurssivePower.cc)

add_executable(arrRet 6/arrRet.cc)
add_executable(errMsg_initList 6/errMsg_initList.cc)
add_executable(factorial 6/fact.cc 6/LocalMath.cc)
add_executable(mainmath 6/mainmath.cc 6/LocalMath.cc)
add_executable(count-calls 6/count-calls.cc)
add_executable(fcnptrRet 6/fcnptrRet.cc)
add_executable(good_printmain 6/good_printmain.cc)
add_executable(inline_shorter 6/inline_shorter.cc)
add_executable(mainret 6/mainret.cc)
add_executable(mk_plural 6/mk_plural.cc)
add_executable(ref-fcn 6/ref-fcn.cc)
add_executable(refparms 6/refparms.cc)
add_executable(refret-ex 6/refret-ex.cc)
add_executable(reset 6/reset.cc)
add_executable(stl-arr-fcns 6/stl-arr-fcns.cc)
add_executable(usefcnptr 6/usefcnptr.cc)
add_executable(wdebug 6/wdebug.cc)

add_executable(16compare 16/compare.cc)
add_executable(Array 16/Array.cc)


#target_include_directories(18book PRIVATE 16)
#file(GLOB source_files CONFIGURE_DEPENDS
#        "16/Sales_data.h"
#        "bookexcept.h"
#
#        )
include_directories("16")
add_executable(
        18book 18/book.cc
        16/Sales_data.h
)
#add_library("../16")
#set(HEADER_FILES )