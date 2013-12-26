#include <cmdparser.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace std;

int main(int argc, char* argv[]) {

  CmdParser cmdParser(argc, argv);

  cmdParser.addGroup("Generic options:")
    .add("input-file")
    .add("output-file")
    .add("--type", "type of algorithm");

  cmdParser
    .addGroup("Other options:")
    .add("--verbose", "log everythings while running program", "false")
    .add("--config", "filename of configuration", "config.txt");

  cmdParser
    .addGroup("Example: ./example -f a.txt -o b.txt --verbose");

  if ( !cmdParser.isOptionLegal() )
    cmdParser.showUsageAndExit();

  string a = cmdParser[1];
  string b = cmdParser[2];
  string type = cmdParser["--type"];
  bool verbose = cmdParser["--verbose"];
  string config_file = cmdParser["--config"];

  //cmdParser.showAll();
  cout << a << endl;
  cout << b << endl;
  cout << type << endl;
  cout << verbose << endl;
  cout << config_file << endl;

  return 0;
}
