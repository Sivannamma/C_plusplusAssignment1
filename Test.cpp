#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;
TEST_CASE ("Test replacement of p and b") {
    string text = "xxx happy yyy";
            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "habby") == string("happy"));
            CHECK(find(text, "hapby") == string("happy"));
            CHECK(find(text, "habpy") == string("happy"));

}


TEST_CASE ("Test replacement of w and v") {
    string text = "windows vista";
            CHECK(find(text, "windows") == string("windows"));
            CHECK(find(text, "Vindovs") == string("windows"));
            CHECK(find(text, "Vindows") == string("windows"));
            CHECK(find(text, "windovs") == string("windows"));
            CHECK(find(text, "WindoVs") == string("windows"));
            CHECK(find(text, "wista") == string("vista"));
            CHECK(find(text, "Wista") == string("vista"));

}

TEST_CASE ("Test replacement of s and z") {
    string text = "suzuki";
            CHECK(find(text, "zusuki") == string("suzuki"));
            CHECK(find(text, "ZuSuki") == string("suzuki"));
            CHECK(find(text, "susuki") == string("suzuki"));
            CHECK(find(text, "zuZuki") == string("suzuki"));
            CHECK(find(text, "ZuSuki") == string("suzuki"));
}

TEST_CASE ("Test replacement of c and q") {
    string text = "control quarantine";
            CHECK(find(text, "cuarantine") == string("quarantine"));
            CHECK(find(text, "Cuarantine") == string("quarantine"));
            CHECK(find(text, "kuarantine") == string("quarantine"));
            CHECK(find(text, "Kuarantine") == string("quarantine"));
            CHECK(find(text, "quarantine") == string("quarantine"));

            CHECK(find(text, "control") == string("control"));
            CHECK(find(text, "Kontrol") == string("control"));
            CHECK(find(text, "qontrol") == string("control"));
            CHECK(find(text, "Qontrol") == string("control"));
}

TEST_CASE ("Test replacement of i and y") {
    string text = "year passing by";
            CHECK(find(text, "Iear") == string("year"));
            CHECK(find(text, "iear") == string("year"));
            CHECK(find(text, "year") == string("year"));
            CHECK(find(text, "passyng") == string("passing"));
            CHECK(find(text, "passYng") == string("passing"));
            CHECK(find(text, "passing") == string("passing"));
            CHECK(find(text, "bI") == string("by"));
            CHECK(find(text, "Bi") == string("by"));
}

TEST_CASE ("Test replacement of o and u") {
    string text = "olala communicate";
            CHECK(find(text, "Ulala") == string("olala"));
            CHECK(find(text, "ulala") == string("olala"));
            CHECK(find(text, "cummonicate") == string("communicate"));
            CHECK(find(text, "cUmmOnicate") == string("communicate"));
            CHECK(find(text, "communicate") == string("communicate"));
            CHECK(find(text, "olala") == string("olala"));

}



TEST_CASE ("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
            CHECK(find(text, "happi") == string("Happi"));
            CHECK(find(text, "Happi") == string("Happi"));
            CHECK(find(text, "HAPPI") == string("Happi"));
            CHECK(find(text, "HaPpI") == string("Happi"));

    text = "Aint NO SuNShinE When SheS GoNE";
            CHECK(find(text, "no") == string("NO"));
            CHECK(find(text, "zONZhYnE") == string("SuNShinE"));
            CHECK(find(text, "VHEN") == string("When"));
            CHECK(find(text, "zHEZ") == string("SheS"));
            CHECK(find(text, "aYNd") == string("Aint"));

    text = "Who CARES iF oNe MoRE LigHt goES oUT";
            CHECK(find(text, "VhU") == string("Who"));
            CHECK(find(text, "KareZ") == string("CARES"));
            CHECK(find(text, "YP") == string("iF"));
            CHECK(find(text, "UnE") == string("oNe"));
            CHECK(find(text, "mUre") == string("MoRE"));
            CHECK(find(text, "lyJhD") == string("LigHt"));
            CHECK(find(text, "JUeZ") == string("goES"));
            CHECK(find(text, "UOd") == string("oUT"));

    text="With Great POWER comEs GreaT ResPonsiBiLiTY";
            CHECK(find(text, "VyDH") == string("With"));
            CHECK(find(text, "JREAd") == string("Great"));
            CHECK(find(text, "FuveR") == string("POWER"));
            CHECK(find(text, "QUMeZ") == string("comEs"));
            CHECK(find(text, "rEZFuNzyPYlyDI") == string("ResPonsiBiLiTY"));
            CHECK(find(text, "rezBUnSIFYlyDy") == string("ResPonsiBiLiTY"));


}
TEST_CASE ("Test words with same length") {
    string text = "woman womag";
            CHECK(find(text, "vumaj") == string("womag"));
            CHECK(find(text, "vuman") == string("woman"));
            CHECK(find(text, "VUMAJ") == string("womag"));
            CHECK(find(text, "VUMAN") == string("woman"));

}

TEST_CASE("Testing long sentences") {
    string text = "balze yts fonni pecaoze yds true";
            CHECK(find(text, "false") == string("balze"));
            CHECK(find(text, "its") == string("yts"));
            CHECK(find(text, "funny") == string("fonni"));
            CHECK(find(text, "because") == string("pecaoze"));

    string text1 = "yts nud a fog yts a beadure";
            CHECK(find(text1, "its") == string("yts"));
            CHECK(find(text1, "not") == string("nud"));
            CHECK(find(text1, "A") == string("a"));
            CHECK(find(text1, "bUg") == string("fog"));
            CHECK(find(text1, "feaTure") == string("beadure"));

    string text2 = "requrzya yz mi lybe";
            CHECK(find(text2, "recursia") == string("requrzya"));
            CHECK(find(text2, "is") == string("yz"));
            CHECK(find(text2, "My") == string("mi"));
            CHECK(find(text2, "LiFe") == string("lybe"));
}

TEST_CASE("Testing b f p") {
    string text = "bob bhe builder";
            CHECK(find(text, "fop") == string("bob"));
            CHECK(find(text, "phe") == string("bhe"));
            CHECK(find(text, "puilder") == string("builder"));

    string text1 = "popcorn and fries makes a women smile";
            CHECK(find(text1, "bobqorn") == string("popcorn"));
            CHECK(find(text1, "aNt") == string("and"));
            CHECK(find(text1, "brYEZ") == string("fries"));
            CHECK(find(text1, "macEz") == string("makes"));
            CHECK(find(text1, "vuMen") == string("women"));
            CHECK(find(text1, "zmYle") == string("smile"));
}
TEST_CASE("Testing g j") {
    string text = "google gave gabi gamba";
            CHECK(find(text, "Goujle") == string("google"));
            CHECK(find(text, "jawe") == string("gave"));
            CHECK(find(text, "jafy") == string("gabi"));
            CHECK(find(text, "jamfa") == string("gamba"));

    string text1 = "jasMine josaPhine";
            CHECK(find(text1, "gaZmynE") == string("jasMine"));
            CHECK(find(text1, "guzabhyNe") == string("josaPhine"));
}

TEST_CASE("Testing d t") {
    string text = "dOodle turtle DamDi";
            CHECK(find(text, "touTlE") == string("dOodle"));
            CHECK(find(text, "dorDle") == string("turtle"));
            CHECK(find(text, "TamTy") == string("DamDi"));

    string text1 = "TiC tAc TOE";
            CHECK(find(text1, "dyq") == string("TiC"));
            CHECK(find(text1, "dak") == string("tAc"));
            CHECK(find(text1, "due") == string("TOE"));
}

