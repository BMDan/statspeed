#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv) {
    register long i;
    int rv;
    struct stat *stat_buf;
    long runs;

    if ( argc != 2 || (runs = atoi(argv[1])) <= 0 ) {
	fprintf( stderr, "Usage: %s <number of runs>\n", argv[0] );
	exit( 1 );
    }

    if ( !( stat_buf = malloc(sizeof(struct stat)) ) ) {
	fprintf( stderr, "Failed to alloc.\n" );
	exit( 1 );
    }

    for ( i = 0; i < runs; i++ ) {
	if ( lstat( "/", stat_buf ) ) {
	    fprintf( stderr, "OMGWTF - Failed lstat!?\n" );
	    exit( 1 );
	}
    }

    return 0;
}
