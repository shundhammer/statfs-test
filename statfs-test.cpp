// Test for the statfs() syscall
//
// Build with
//
//   make statfs-test
//
// (No Makefile needed)

#include <sys/statfs.h>
#include <iostream>     // cout, cerr, endl

using std::cout, std::cerr, std::endl, std::hex, std::dec;


int main( int argc, char *argv[] )
{
    if ( argc != 2 )
    {
        char * progName = argv[0];
        cerr << "Usage:  " << progName << " <path>" << endl;
        exit( 1 );
    }

    char * path = argv[1];
    struct statfs fs;

    int ret = statfs( path, &fs );

    cout << "statfs() for " << path << ":" << endl;
    cout << "  filesystem type:  0x" << hex << fs.f_type << dec << endl;
    cout << "  total blocks:     " << fs.f_blocks << endl;
    cout << "  free  blocks:     " << fs.f_bfree  << endl;
    cout << "  available blocks: " << fs.f_bavail << endl;
    cout << "  fragment size:    " << fs.f_frsize << endl;

    return 0;
}
