#include "HSVtoRGB.h"

void HSVtoRGB( uint8_t *r, uint8_t *g, uint8_t *b, uint8_t hue, uint8_t s, uint8_t v )
{
    int f;
    long p, q, t;

    if( s == 0 )
    {
        // easy - just shades of grey.
        *r = *g = *b = v;
        return;
    }

    // special case, treat hue=0 as black
    //if ( hue == 0) {
    //    *r = *g = *b = 0;
    //}
 
    // hue is from 1-240, where 40=60deg, 80=120deg, so we can fit into a byte
    f = ((hue%40)*255)/40;
    hue /= 40;
 
    p = (v * (256 - s))/256;
    q = (v * ( 256 - (s * f)/256 ))/256;
    t = (v * ( 256 - (s * ( 256 - f ))/256))/256;
 
    switch( hue ) {
    case 0:
        *r = v;
        *g = t;
        *b = p;
        break;
    case 1:
        *r = q;
        *g = v;
        *b = p;
        break;
    case 2:
        *r = p;
        *g = v;
        *b = t;
        break;
    case 3:
        *r = p;
        *g = q;
        *b = v;
        break;
    case 4:
        *r = t;
        *g = p;
        *b = v;
        break;
    default:
        *r = v;
        *g = p;
        *b = q;
        break;
    }
}
 
