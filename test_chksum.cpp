#include <stdio.h>
#include <stdlib.h>

typedef unsigned char octet;
//
// int chksum(octet *s, int bytes, int initial)
//
// compute the one's complement checksum used in most IP protocols.
//
// parameters:
//   s:       address of block (string) to be checksummed
//   bytes:   number of bytes to checksum (an odd number of bytes is allowed)
//   initial: checksum from a previous block (this allows a checksum to be
//            computed for a set of non-contiguous blocks)
// return value:
//   one's complement checksum
//
// Note: the checksum this function provides must usually
// be complemented before it is placed in the packet:
//
//    ip->header_checksum[0] = 0; // initial checksum value must be 0
//    ip->header_checksum[1] = 0;
//    int sum = chksum((octet *)ip,20,0);
//    ip->header_checksum[0] = ~sum >> 8;
//    ip->header_checksum[1] = ~sum & 0xff;
//   
int chksum(octet *s, int bytes, int initial)
{
   long sum = initial;
   int i;
   for ( i=0; i<bytes-1; i+=2 )
   {
      sum += s[i]*256 + s[i+1];
   }
   //
   // handle the odd byte
   //
   if ( i < bytes ) sum += s[i]*256;
   //
   // wrap carries back into sum
   //
   while ( sum > 0xffff ) sum = (sum & 0xffff) + (sum >> 16);
   return sum;
}

int main(int argc, char *argv[])
{
  octet ip_header[20] = {0x45, 0x00, 0x00, 0x54, 0xb1, 0xab, 0x40, 0x00, 0x40, 0x01, 0x7d, 0x5b, 0x81, 0x7b, 0x04, 0x5b, 0x81, 0x7b, 0x04, 0x51};

  // make the checksum to 0 first
  ip_header[10] = 0;
  ip_header[11] = 0;
  
  int sum1 = chksum(ip_header, 20, 0);
  octet chk1 = ~sum1 >> 8;
  octet chk2 = ~sum1 & 0xff;
  printf("chk1 = %02x\n", chk1);
  printf("chk2 = %02x\n", chk2);

}
