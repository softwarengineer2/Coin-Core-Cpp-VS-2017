#include <iostream>
#include <cassert>

#include <hdkeys.h>
#include <Base58Check.h>

#include <sstream>

using namespace Coin;
using namespace std;

int main()
{
	string extendedKey = "", childNum = "";
	cout << "Extended Key:";
	cin >> extendedKey;
	cout << "Child Num:";
	cin >> childNum;

    try {
        uchar_vector extkey;
        if (!fromBase58Check(extendedKey, extkey))
            throw runtime_error("Invalid extended key.");

        uint32_t childnum = strtoull(childNum.c_str(), NULL, 0);

        HDKeychain hdkeychain(extkey);
        hdkeychain = hdkeychain.getChild(childnum);

        cout << "Extended : "<<toBase58Check(hdkeychain.extkey()) << endl;
        cout << "Result   : "<<uchar_vector(hdkeychain.key()).getHex() << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }
 
    return 0;
}
