bool lemonadeChange( int *bills, int billsSize ) {

    int nota5 = 0;
    int nota10 = 0;

    for ( int i = 0; i < billsSize; i++ ) {

        if ( bills[i] == 5 ) {
            nota5++;
        } else if ( bills[i] == 10 && nota5 >= 1 ) {
            nota5--;
            nota10++;
        } else if ( bills[i] == 20 && nota5 >= 1 && nota10 >= 1 ) {
            nota5--;
            nota10--;
        } else if ( bills[i] == 20 && nota5 >= 3 ) {
            nota5 -= 3;
        } else {
            return false;
        }
    }

    return true;
}