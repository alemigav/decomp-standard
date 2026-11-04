/* FUN_8009c370
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009c370  body 0x8009c370..0x8009c593  size 548 B
 * body sha256 be6354e7a10719c86a7f7ffb78e3c7add3f98cacab798acd5cd3abb991daa2b5
 * provider record sha256 c98c25d99bed0e81503acd56a5544abc29eac6e3002d729a9ccc1ab3e27b211c
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8009c370(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_800e8ca8;
  _DAT_8013a440 = FUN_80025b0c();
  DAT_800e8ca8 = 0xffff;
  FUN_800762b0();
  DAT_800e8ca8 = uVar1;
  FUN_8009c660();
  FUN_8006c070(1);
  do {
    if (((400 < DAT_80132744) && (DAT_80132729 != '\0')) && ((DAT_800df90c & 0x20) != 0)) {
      if (DAT_8013272c == '\0') {
        DAT_8013272c = '\x01';
        if ((DAT_800e110c & 0x20) != 0) {
          func_0x80004b5c();
        }
        FUN_80077430(0x5a,0x18);
        DAT_800e920a = 1;
        DAT_8013272b = 0;
        DAT_80132728 = 0;
        FUN_8009ced8();
        DAT_8013272b = 3;
        DAT_80132728 = 0;
        FUN_8009ced8();
        DAT_8013273a = 0;
        DAT_8013273e = DAT_8013273c;
        if (DAT_8013273c == 2) {
          DAT_8013272e = 7;
        }
        else if (DAT_8013273c < 3) {
          DAT_8013272e = 6;
        }
        else {
          if (DAT_8013273c != 3) {
            DAT_8013273c = 4;
            goto LAB_8009c4fc;
          }
          DAT_8013272e = 10;
        }
        DAT_8013273c = 4;
      }
LAB_8009c4fc:
      if (DAT_8013272c == '\x02') {
        DAT_8013273e = 4;
        DAT_8013273c = 4;
        DAT_8013272c = '\x03';
        DAT_8013272a = 3;
      }
    }
    (*(code *)(&PTR_FUN_801321d0)[DAT_8013272a])();
    (*(code *)(&PTR_func_8009d018_801321e0)[DAT_8013273c])();
    FUN_8009e584();
    DAT_80132744 = DAT_80132744 + 1;
    if (DAT_80132744 == 0xffffffff) {
      DAT_80132744 = 0x191;
    }
    FUN_8004cd88(1);
  } while( true );
}
