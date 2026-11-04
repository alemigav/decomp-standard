/* FUN_80090704
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80090704  body 0x80090704..0x80090757  size 84 B
 * body sha256 3d656d31edddb29dddac1106576a14fbcce95c12ab113603bdc22621e9ae86fe
 * provider record sha256 503e94aee417ff2ac9f1ef428fcfeceffd59c9fc47fdb20d8bb955692ebe50b3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80090704(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = DAT_8012bfb2;
  DAT_8012bfae = 0;
  switch(DAT_8012bf9a) {
  case '\0':
    _DAT_8013a388 = DAT_80112784;
    FUN_8006c070(0);
    DAT_8012bfb2 = FUN_80091738((int)DAT_800e8ca8,(int)DAT_800e8caa);
    FUN_800479c8(DAT_800c52dc + 0x44807U & 0xfffffff8,&DAT_8012f5a0,
                 *(undefined2 *)
                  (&DAT_8012f8ec + (uint)*(ushort *)(&DAT_80130cba + (uint)DAT_8012bfb2 * 8) * 2));
    DAT_8012bf9a = '\x01';
    DAT_8012bf9b = 0;
    DAT_8012bff0 = 0;
    DAT_8012bff2 = 0;
    FUN_80090e10();
    break;
  case '\x01':
    bVar1 = 0xc < DAT_8012bf9b;
    DAT_8012bf9b = DAT_8012bf9b + 1;
    if (bVar1) {
      DAT_8012bf9a = '\x03';
      DAT_8012bf9b = 0;
      FUN_80077adc(0x4090000,0);
    }
    DAT_8012bfd4 = DAT_8012bfd4 + -0x16;
    DAT_8012bfde = DAT_8012bfde + -0x13;
    DAT_8012bfcc = DAT_8012bfcc + 0x15;
    DAT_8012bfd2 = DAT_8012bfd2 + 0x15;
    break;
  case '\x02':
    bVar1 = 0xc < DAT_8012bf9b;
    DAT_8012bf9b = DAT_8012bf9b + 1;
    if (bVar1) {
      DAT_8012bf99 = 2;
      DAT_8012bf9a = '\0';
      DAT_8012bf9b = 0;
    }
    DAT_8012bfd4 = DAT_8012bfd4 + 0x16;
    DAT_8012bfde = DAT_8012bfde + 0x13;
    DAT_8012bfcc = DAT_8012bfcc + -0x15;
    DAT_8012bfd2 = DAT_8012bfd2 + -0x15;
    break;
  case '\x03':
    if (DAT_8012bfc1 == '\0') {
      if (0x50 < DAT_8012bfc0) {
        DAT_8012bfc1 = '\x01';
      }
      DAT_8012bfc0 = DAT_8012bfc0 + 4;
    }
    else {
      if (DAT_8012bfc0 < 10) {
        DAT_8012bfc1 = '\0';
      }
      DAT_8012bfc0 = DAT_8012bfc0 - 4;
    }
    if ((DAT_800e10ec < 0) && (1 < DAT_8012bfb2)) {
      if (((DAT_800df90c & 0x1000) != 0) &&
         ((1 < (byte)(&DAT_8012f970)[DAT_8012bfb2] &&
          (iVar3 = FUN_800837ac(&DAT_800e8d94,(&DAT_8012f970)[DAT_8012bfb2]), iVar3 != 0)))) {
        DAT_8012bfb2 = (&DAT_8012f970)[DAT_8012bfb2];
      }
      if ((((DAT_800df90c & 0x4000) != 0) && (1 < (byte)(&LAB_8012f988)[DAT_8012bfb2])) &&
         (iVar3 = FUN_800837ac(&DAT_800e8d94,(&LAB_8012f988)[DAT_8012bfb2]), iVar3 != 0)) {
        DAT_8012bfb2 = (&LAB_8012f988)[DAT_8012bfb2];
      }
      if (bVar2 != DAT_8012bfb2) {
        DAT_8012bf9a = '\x04';
        FUN_80077adc(0x4040000,0);
      }
    }
    if ((DAT_800df918 & 0x2000) != 0) {
      DAT_8012bf9a = '\x02';
      FUN_80077adc(0x4050000,0);
      FUN_8006c070(_DAT_8013a388);
    }
    if (DAT_8012bf9a == '\x03') {
      FUN_8009109c();
    }
    break;
  case '\x04':
    FUN_800479c8(DAT_800c52dc + 0x44807U & 0xfffffff8,&DAT_8012f5a0,
                 *(undefined2 *)
                  (&DAT_8012f8ec + (uint)*(ushort *)(&DAT_80130cba + (uint)DAT_8012bfb2 * 8) * 2));
    FUN_80090e10();
    DAT_8012bfc0 = 4;
    DAT_8012bfc1 = '\0';
    DAT_8012bf9a = '\x03';
  }
  FUN_80097fd0();
  return;
}
