// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/ext/brigand/list.hpp>

#include <boost/hana/assert.hpp>
#include <boost/hana/core/to.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/type.hpp>

#include <support/seq.hpp>

#include <brigand/sequences/list.hpp>
namespace hana = boost::hana;


struct t1; struct t2; struct t3; struct t4;

int main() {
    // Conversion from any `Foldable` containing `type`s
    auto foldable = ::seq;
    auto to_list = hana::to<hana::ext::brigand::list_tag>;
    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        to_list(foldable()),
        brigand::list<>{}
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        to_list(foldable(hana::type_c<t1>)),
        brigand::list<t1>{}
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        to_list(foldable(hana::type_c<t1>, hana::type_c<t2>)),
        brigand::list<t1, t2>{}
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        to_list(foldable(hana::type_c<t1>, hana::type_c<t2>, hana::type_c<t3>)),
        brigand::list<t1, t2, t3>{}
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        to_list(foldable(hana::type_c<t1>, hana::type_c<t2>, hana::type_c<t3>, hana::type_c<t4>)),
        brigand::list<t1, t2, t3, t4>{}
    ));
}
