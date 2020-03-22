#include <iostream>
#include <stdexcept>
#include "PhoneticFinder.hpp"
using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
using namespace doctest;

const int MIN_TESTS = 100;

struct ReporterCounter: public ConsoleReporter {
    ReporterCounter(const ContextOptions& input_options)
            : ConsoleReporter(input_options) {}

    void test_run_end(const TestRunStats& run_stats) override {
        if (run_stats.numAsserts >= MIN_TESTS) {
            std::cout << 100 << std::endl;
        } else {
            std::cout << "Please write at least " << MIN_TESTS << " tests! " <<  std::endl << 0  << std::endl;
        }
    }
};

REGISTER_REPORTER("counter", 1, ReporterCounter);

int main() {
    string text = "Dond vorri be haffy";
    cout << phonetic::find(text, "dont") << endl;   // should print "Dond"
    cout << phonetic::find(text, "worry") << endl;   // should print "vorri"
    cout << phonetic::find(text, "Be") << endl;   // should print "be"
    cout << phonetic::find(text, "happy") << endl;   // should print "haffy"
    try {
        cout << phonetic::find(text, "happ") << endl;   // should throw an exception - "happ" is not a full word in the sentence
    } catch (exception ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Did not find the word 'happ' in the text"
    }

    Context context;
    context.addFilter("reporters", "counter");
    context.run();

    return 0;
}
