/* FUN_8005280c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005280c  body 0x8005280c..0x80052bbb  size 944 B
 * body sha256 7076088c0800957fc4b9419a94d80a428ae4c447e1a7c293bb48becdf354d3cd
 * provider record sha256 4a4a8ca147c5fac0a119befc9b6055551e13bdf0cc605a7e2c943663e21039e0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80052980) */
/* WARNING: Removing unreachable block (ram,0x800529c8) */
/* WARNING: Removing unreachable block (ram,0x800529d4) */

void FUN_8005280c(void)

{
  uint uVar1;
  
  if (((DAT_800e10ec & 0x2000) == 0) && ((DAT_800e110c & 0x8000) == 0)) {
    DAT_80112974 = FUN_80052e58(&DAT_8010bfd8);
    DAT_80112975 = FUN_80052e58(&DAT_8010c124);
  }
  else {
    DAT_80112975 = 0;
    DAT_80112974 = 0;
  }
  DAT_800df908 = DAT_800df904;
  FUN_80051140();
  DAT_800df91c = DAT_800df914;
  if ((DAT_800e10ec & 0x2000) == 0) {
    DAT_800df904 = ~((uint)(byte)DAT_800df8bc |
                    (uint)DAT_800df8e0._2_1_ * 0x1000000 + (uint)(byte)DAT_800df8e0 * 0x10000 +
                    (uint)DAT_800df8bc._2_1_ * 0x100);
  }
  else {
    DAT_800df904 = ~((uint)(byte)DAT_800df8bc |
                    (uint)DAT_800df8e0._2_1_ * 0x1000000 + (uint)(byte)DAT_800df8e0 * 0x10000 +
                    (uint)DAT_800df8bc._2_1_ * 0x100);
    if ((DAT_800e10ec & 0x40000000) == 0) {
      DAT_800e10ec = DAT_800e10ec | 0x1000;
    }
    else {
      DAT_800df904 = 0;
      DAT_800e8606 = 1;
    }
    DAT_8010b294 = 0;
    DAT_8010b295 = 0;
    DAT_8010b296 = 0;
    DAT_8010b297 = 0;
  }
  DAT_800df914 = 0;
  uVar1 = 0xf;
  while( true ) {
    if ((DAT_800df904 & *(ushort *)(&UNK_8010bfac + (uVar1 & 0xff) * 2)) != 0) {
      DAT_800df914 = DAT_800df914 | 1 << (uVar1 & 0x1f);
    }
    if ((uVar1 & 0xff) == 0) break;
    uVar1 = uVar1 - 1;
  }
  if ((DAT_800e1110 & 0x1000000) == 0) {
    if ((DAT_8010bfd0 & 0x1000000) == 0) goto LAB_80052acc;
    DAT_8010bfd0 = 0;
    DAT_800df91c = DAT_800df914;
  }
  else {
    DAT_8010bfd0 = DAT_800e1110;
    DAT_800df914 = DAT_800df914 & 0x3c00;
  }
  DAT_800df8c1 = 0;
  DAT_800df8c0 = 0;
LAB_80052acc:
  DAT_800df90c = DAT_800df904._2_2_;
  DAT_800df908 = (DAT_800df908 ^ DAT_800df904) & DAT_800df904;
  DAT_800df918 = (DAT_800df91c ^ DAT_800df914) & DAT_800df914;
  DAT_800df910 = (undefined2)(DAT_800df904 >> 0x10);
  uVar1 = DAT_800df908;
  DAT_800df90e = DAT_800df908._2_2_;
  DAT_800df912 = (undefined2)(DAT_800df908 >> 0x10);
  if ((DAT_800df908 & DAT_800e917c) == 0) {
    if (DAT_8010bfd4 != '\0') {
      if ((DAT_800df904 & DAT_800e917c) != 0) {
        DAT_8010bfd4 = DAT_8010bfd4 + -1;
      }
      DAT_800e10ec = DAT_800e10ec & 0x7fffffff;
      return;
    }
    DAT_8010bfd4 = (undefined1)DAT_800e9180;
  }
  else {
    DAT_8010bfd4 = DAT_800e9180._0_1_;
  }
  DAT_800e10ec = DAT_800e10ec | 0x80000000;
  DAT_800df908 = uVar1;
  return;
}
