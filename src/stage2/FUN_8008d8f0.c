/* FUN_8008d8f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d8f0  body 0x8008d8f0..0x8008dbff  size 784 B
 * body sha256 cc8d302d15e8c7ff2bb3f3444dd4288e3e5c922fac04083fc1accf31583d0c0c
 * provider record sha256 2ddd220cdfe14512bb96d820e43e6d92dbec3c82691b306b6418edf89fddbbd5
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008d8f0(void)

{
  byte bVar1;
  char cVar3;
  int iVar2;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int unaff_s1;
  int unaff_s2;
  
  *(undefined1 *)(unaff_s1 + 0x16) = 1;
  uVar6 = (uint)*(byte *)(unaff_s1 + 0xc);
  if (DAT_800e10ec < 0) {
    if (((*(ushort *)(unaff_s2 + 0x1825c) & 0x2000) != 0) &&
       ((int)uVar6 < (int)(*(byte *)(unaff_s2 + 0x21488) - 1))) {
      if (*(char *)(unaff_s2 + uVar6 * 4 + 0x2181a) == '\x01') {
        *(byte *)(unaff_s1 + 0xc) = *(byte *)(unaff_s1 + 0xc) + 1;
      }
      *(char *)(unaff_s1 + 0xc) = *(char *)(unaff_s1 + 0xc) + '\x01';
    }
    if ((*(ushort *)(unaff_s2 + 0x1825c) & 0x8000) != 0) {
      bVar1 = *(byte *)(unaff_s1 + 0xc);
      uVar4 = (uint)bVar1;
      if ((uVar4 != 0) && (uVar4 != 10)) {
        if (*(char *)(unaff_s2 + uVar4 * 4 + 0x2181a) == '\x02') {
          if (uVar4 == 1) {
            cVar3 = bVar1 + 1;
          }
          else {
            cVar3 = bVar1 - 1;
          }
          *(char *)(unaff_s1 + 0xc) = cVar3;
        }
        *(char *)(unaff_s1 + 0xc) = *(char *)(unaff_s1 + 0xc) + -1;
      }
    }
    if ((*(ushort *)(unaff_s2 + 0x1825c) & 0x4000) != 0) {
      bVar1 = *(byte *)(unaff_s1 + 0xc);
      cVar3 = bVar1 + 2;
      if ((int)(*(byte *)(unaff_s2 + 0x21488) - 2) <= (int)(uint)bVar1) {
        if (bVar1 != 10) goto LAB_8008da30;
        cVar3 = '\x01';
      }
      *(char *)(unaff_s1 + 0xc) = cVar3;
    }
LAB_8008da30:
    if ((*(ushort *)(unaff_s2 + 0x1825c) & 0x1000) != 0) {
      bVar1 = *(byte *)(unaff_s1 + 0xc);
      if (bVar1 == 10) {
        *(undefined1 *)(unaff_s1 + 1) = 2;
        FUN_80077adc(0x4050000,0);
        goto LAB_8008dbd4;
      }
      if (bVar1 < 2) {
        *(undefined1 *)(unaff_s1 + 0xc) = 10;
      }
      else {
        *(byte *)(unaff_s1 + 0xc) = bVar1 - 2;
      }
    }
    if (uVar6 != *(byte *)(unaff_s1 + 0xc)) {
      FUN_80077adc(0x4040000,0);
    }
  }
  if (((*(uint *)(unaff_s2 + 0x18268) & 0x1000) == 0) ||
     (*(char *)(unaff_s2 + (uint)*(byte *)(unaff_s1 + 0xc) * 4 + 0x21818) == '\0')) {
    if ((*(uint *)(unaff_s2 + 0x18268) & 0x2000) == 0) {
      if (((DAT_800df918 & 0x4000) != 0) && (DAT_8012bfae == '\x01')) {
        FUN_80077adc(0x4050000,0);
        DAT_8012bf99 = 0;
      }
    }
    else {
      FUN_80077adc(0x4050000,0);
      *(undefined1 *)(unaff_s1 + 1) = 2;
    }
    goto LAB_8008dbd4;
  }
  DAT_8013a380 = 0;
  bVar1 = *(byte *)(unaff_s2 + (uint)*(byte *)(unaff_s1 + 0xc) * 4 + 0x21818);
  if (bVar1 < 0x14) {
    uVar5 = 1;
    if (bVar1 != 4) goto LAB_8008db30;
    iVar2 = FUN_800837ac(&DAT_800e8ce0,0x7e);
    FUN_80097364((uint)(iVar2 != 0) << 1 | 1,1);
    DAT_8013a380 = 1;
  }
  else {
    uVar5 = 0;
LAB_8008db30:
    FUN_80097364(uVar5,0);
  }
  FUN_80077adc(0x4060000,0);
  *(undefined1 *)(unaff_s1 + 2) = 3;
  *(undefined1 *)(unaff_s1 + 3) = 0;
  *(short *)(unaff_s1 + 0x48) = *(short *)(unaff_s1 + 0x48) + 0x41;
LAB_8008dbd4:
  FUN_8008c25c(0x10,0xaf,2,*(undefined1 *)(unaff_s2 + (uint)*(byte *)(unaff_s1 + 0xc) * 4 + 0x21818)
              );
  FUN_800962fc(*(undefined1 *)(unaff_s2 + (uint)*(byte *)(unaff_s1 + 0xc) * 4 + 0x2181a));
  return;
}
