#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv) {
    struct stat stat_buf;
    long runs;

    if ( argc != 2 || (runs = atol(argv[1])) <= 0 ) {
	    fprintf( stderr, "Usage: %s <number of runs>\n", argv[0] );
        exit( 1 );
    }

    while ( --runs > 0 ) {
	    if ( lstat( "/", &stat_buf ) ) {
	        fprintf( stderr, "OMGWTF - Failed lstat!?\n" );
	        exit( 1 );
	    }
    }

    return 0;
}
