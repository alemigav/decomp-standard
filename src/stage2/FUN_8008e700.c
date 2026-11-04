/* FUN_8008e700
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e700  body 0x8008e700..0x8008e76b  size 108 B
 * body sha256 b0c36da3ad2a20a5365d938384ca87c07b76196edb82d684aa75506390f90e76
 * provider record sha256 dbf56daf6599012c39d57ba1744e8265a755f30216bfb7328a04ff2204b13aec
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e700(void)

{
  char cVar1;
  int unaff_s2;
  
  cVar1 = *(char *)(unaff_s2 + 5) + '\x01';
  *(char *)(unaff_s2 + 5) = cVar1;
  if (cVar1 == '\x01') {
    FUN_8004ac04(0xaf0010,0xe400,2,0);
  }
  else if ((DAT_8010b294 & 0x80) == 0) {
    *(undefined1 *)(unaff_s2 + 5) = 0;
    *(undefined1 *)(unaff_s2 + 4) = 0;
    *(undefined1 *)(unaff_s2 + 3) = 0;
    *(undefined1 *)(unaff_s2 + 2) = 0;
  }
  return;
}
